#pragma once
#include "../includes.h"

namespace instant_message
{
	namespace dispatch
	{
		void handle_message(const char* message, const std::uint32_t message_size);
	}

	void send_info_request(const std::uint64_t target_steam_id);
}