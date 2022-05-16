#include "instant_message.hpp"

namespace instant_message
{
	void add_friend_response(const InfoResponseLobby& lobby)
	{
		if (lobby.isValid)
		{
			const auto sess_info{ get_session_info(lobby) };

			netadr_t netadr{};
			dwRegisterSecIDAndKey(&sess_info.sessionID, &sess_info.keyExchangeKey);
			dwCommonAddrToNetadr(&netadr, &sess_info.hostAddress, &sess_info.sessionID);

			for (auto& friends : friends::friends)
			{
				if (lobby.hostXuid == friends.steam_id)
					friends.netadr = netadr;
			}
		}
	}
	
	constexpr auto nonce{ 1111111111u };
	std::unordered_map<std::uint64_t, XSESSION_INFO> players_session_info;
	/*
	LobbyMsg build_info_request()
	{
		char buf[0x20000] = { 0 };
		LobbyMsg lobby_msg{};

		LobbyMsgRW_PrepWriteMsg(&lobby_msg, buf, sizeof buf, MESSAGE_TYPE_INFO_REQUEST, 0);
		LobbyMsgRW_PackageUInt(&lobby_msg, "nonce", &nonce);

		return lobby_msg;
	}

	void send_info_request(const std::uint64_t target_steam_id)
	{
		if (Live_IsDemonwareFetchingDone(0))
		{
			const auto lobby_msg = build_info_request();
			dwInstantSendMessage(0, &target_id, 1, 'h', lobby_msg.msg.data, lobby_msg.msg.cursize);
		}
	}

	void send_info_request(const std::vector<std::uint64_t>& recipients)
	{
		if (Live_IsDemonwareFetchingDone(0))
		{
			const auto lobby_msg = build_info_request();
			dwInstantSendMessage(0, recipients.data(), recipients.size(), 'h', lobby_msg.msg.data, lobby_msg.msg.cursize);
		}
	}
	*/
	void send_info_request(const std::uint64_t target_steam_id)
	{
		if (!Live_IsUserSignedInToDemonware(0))
			return;

		const Msg_InfoRequest message{ 1 };
		LobbyMsg_SendInfoRequest(0, &target_steam_id, 1, &message);
	}
	
	namespace dispatch
	{
		void handle_message(const char* message, const std::uint32_t message_size)
		{
			msg_t msg{};
			MSG_InitReadOnly(&msg, message, message_size);
			MSG_BeginReading(&msg);

			auto type = 0ui8;

			if (MSG_ReadByte(&msg) == '1')
			{
				type = MSG_ReadByte(&msg);
			}

			if (type == 'h')
			{
				if (const auto size{ msg.cursize - msg.readcount }; size < 2048u)
				{
					char data[2048] = { 0 };
					MSG_ReadData(&msg, data, size);

					if (!msg.overflowed)
					{
						LobbyMsg lobby_msg{};
						if (!LobbyMsgRW_PrepReadData(&lobby_msg, data, size))
							return;

						if (lobby_msg.msgType == MESSAGE_TYPE_INFO_RESPONSE)
						{
							Msg_InfoResponse response{};
							if (!MSG_InfoResponse(&response, &lobby_msg))
								return;

							add_friend_response(response.lobby[0]);
						}
					}
				}
			}
		}
	}
}