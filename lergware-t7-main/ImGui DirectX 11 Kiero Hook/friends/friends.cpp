#include "friends.hpp"

namespace friends
{
    std::vector<friends_t> friends; 

    void write_to_friends()
	{
		json j{};

		for (const auto& friends : friends)
		{
			j[std::to_string(friends.steam_id)] =
			{
				{ "name", friends.name }
			};
		}

		io::write_file(io::get_json_file(FRIENDS_LIST), j.dump());
	}

    void refresh_friends()
	{
		friends.clear();

		if (const auto json = io::parse_json_file(FRIENDS_LIST); json.is_object())
		{
			for (const auto&[key, value] : json.items())
			{
				friends.emplace_back(friends_t
				{
					std::stoull(key),
					value["name"].get<std::string>()
				});
			}
		}
	}

	void send_info_request_to_friend(friends_t& friends)
	{
		friends.netadr = {};
		instant_message::send_info_request(friends.steam_id);
	}

	void remove_friend(const std::uint64_t steam_id)
	{
		const auto entry = std::find_if(friends.begin(), friends.end(), [=](const auto& friends) { return friends.steam_id == steam_id; });

		if (entry != friends.end())
		{
			friends.erase(entry);
		}

		write_to_friends();
	}

    void friends_list()
	{
        if (ImGui::BeginTabItem("Friends"))
		{
			const auto width = ImGui::GetContentRegionAvail().x;
			
			const auto spacing = ImGui::GetStyle().ItemInnerSpacing.x;
			
			static ImGuiTextFilter filter;
			
			ImGui::TextUnformatted("Search Friends");
			filter.Draw("##search_friend", "Name", width * 0.80f);
			ImGui::SetNextItemWidth(width * 0.80f);

			ImGui::SameLine(0.0f, spacing);

			const auto popup = "Add Friend##add_friend_popup"s;
			
			if (ImGui::Button("Add Friend"))
			{
				ImGui::OpenPopup(popup.data());
			}

			ImGui::SetNextWindowBgAlpha(1.0f);

			if (ImGui::BeginPopupModal(popup.data(), nullptr, ImGuiWindowFlags_NoResize))
			{
				static auto name_input = ""s;
				static auto steam_id_input = ""s;
				
				ImGui::SetNextItemWidth(width * 0.5f);
				ImGui::InputTextWithHint("##name_input", "Name", &name_input);

				ImGui::Separator();

				ImGui::SetNextItemWidth(width * 0.5f);
				ImGui::InputTextWithHint("##steam_id_input", "Steam ID", &steam_id_input);

				ImGui::Separator();

				if (ImGui::MenuItem("Add Friend", nullptr, nullptr, !name_input.empty() && !steam_id_input.empty()))
				{
					friends.emplace_back(friends_t{ utils::atoll(steam_id_input), name_input });
					write_to_friends();

					ImGui::CloseCurrentPopup();
				}

				if (ImGui::MenuItem("Refresh Friends"))
				{
					refresh_friends();
					ImGui::CloseCurrentPopup();
				}

				if (ImGui::IsKeyPressedWithIndex(ImGuiKey_Escape))
				{
					ImGui::CloseCurrentPopup();
				}

				ImGui::EndPopup();
			}

			ImGui::Separator();
			
			ImGui::BeginColumns("Friends", 2, ImGuiColumnsFlags_NoResize);

			ImGui::SetColumnWidth(-1, 28.0f);
			ImGui::TextUnformatted("#");
			ImGui::NextColumn();
			ImGui::TextUnformatted("Friend");
			ImGui::NextColumn();

			ImGui::Separator();

			std::vector<std::uint32_t> indices{};

			for (size_t i = 0; i < friends.size(); ++i)
			{
				indices.emplace_back(i);
			}

			std::sort(indices.begin(), indices.end(), [](const auto& a, const auto& b) { return friends[a].name < friends[b].name; });

			for (const auto& friend_num : indices)
			{
				auto& friends = friends::friends[friend_num];
				const auto netadr = friends.netadr;
				
				if (filter.PassFilter(friends.name))
				{
					ImGui::AlignTextToFramePadding();

					ImGui::TextUnformatted(std::to_string(friend_num));

                    ImGui::NextColumn();

                    ImGui::AlignTextToFramePadding();
					
					const auto selected = ImGui::Selectable(friends.name.data() + "##"s + std::to_string(friend_num));

                    const auto popup = "friend_popup##" + std::to_string(friend_num);
					static auto on_pop_up_loop = false;

					if (selected)
					{
						on_pop_up_loop = false;
						send_info_request_to_friend(friends);
						
						ImGui::OpenPopup(popup.data());
					}

                    if (ImGui::BeginPopup(popup.data(), ImGuiWindowFlags_NoMove))
					{
                        ImGui::MenuItem(friends.name + "##" + std::to_string(friend_num) + "friend_menu_item", nullptr, false, false);

						if (ImGui::IsItemClicked())
						{
							
						}

						if (ImGui::IsItemHovered())
						{
							ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
						}

						if (ImGui::BeginMenu("Rename##" + std::to_string(friend_num)))
						{
							static auto rename_friend_input = ""s;

							ImGui::InputTextWithHint("##" + std::to_string(friend_num), "Name", &rename_friend_input);

							if (ImGui::MenuItem("Rename"))
							{
								if (friends.name != rename_friend_input)
								{
									friends.name = rename_friend_input;

									write_to_friends();
								}
							}

							ImGui::EndMenu();
						}

						if (ImGui::MenuItem("Remove"))
						{
							remove_friend(friends.steam_id);
						}

						ImGui::Separator();

                        if (ImGui::MenuItem(std::to_string(friends.steam_id)))
						{
							ImGui::LogToClipboardUnformatted(std::to_string(friends.steam_id));
						}

                        ImGui::Separator();
						
						if (ImGui::BeginMenu("Join"))
						{
							if (ImGui::MenuItem("Cbuf"))
							{
								const auto command = "join " + std::to_string(friends.steam_id);
								Cbuf_AddText(0, command.data());
							}

							if (ImGui::MenuItem("Normal"))
							{
								LobbyVM_JoinEvent(0, friends.steam_id, JOIN_TYPE_NORMAL);
							}

							if (ImGui::MenuItem("Friend"))
							{
								LobbyVM_JoinEvent(0, friends.steam_id, JOIN_TYPE_FRIEND);
							}

							if (ImGui::MenuItem("Invite"))
							{
								LobbyVM_JoinEvent(0, friends.steam_id, JOIN_TYPE_INVITE);
							}

							if (ImGui::MenuItem("Party"))
							{
								LobbyVM_JoinEvent(0, friends.steam_id, JOIN_TYPE_PARTY);
							}

							if (ImGui::MenuItem("Groups"))
							{
								LobbyVM_JoinEvent(0, friends.steam_id, JOIN_TYPE_GROUPS);
							}

							ImGui::EndMenu();
						}

						ImGui::Separator();

						/*

						if (on_pop_up_loop)
						{
							exploit::send_popup(friends.steam_id);
						}

						if (ImGui::MenuItem("Open popup", nullptr, on_pop_up_loop))
						{
							on_pop_up_loop = !on_pop_up_loop;
						}

						*/

						if (ImGui::MenuItem("Open popup"))
						{
							exploit::send_popup(friends.steam_id);
						}
						
						if (ImGui::MenuItem("Crash"))
						{
							exploit::send_crash(friends.steam_id);
						}
						
						if (ImGui::MenuItem("Immobilize", nullptr, nullptr, netadr.inaddr))
						{
							exploit::send_request_stats_packet(netadr);
						}
						
						if (ImGui::MenuItem("Kick", nullptr, nullptr, netadr.inaddr))
						{
							exploit::send_connect_response_migration_packet(netadr);
						}

						if (ImGui::MenuItem("Migrate", nullptr, nullptr, netadr.inaddr))
						{
							exploit::send_mstart_packet(netadr);
						}

						if (ImGui::BeginMenu("Custom OOB")) {

							ImGui::Dummy(ImVec2(0.0f, 3.0f));

							static auto MSG_NET = ""s;

							ImGui::InputTextWithHint("##MSG_NET", "OOB/STRING", &MSG_NET);

							ImGui::SameLine();

							if (ImGui::MenuItem("Send", nullptr, nullptr, netadr.inaddr))
							{
								send_oob(netadr, MSG_NET);
							}

							ImGui::EndMenu();
						}

                        ImGui::EndPopup();
                    }

                    ImGui::NextColumn();

                    if (ImGui::GetColumnIndex() == 0)
					{
						ImGui::Separator();
					}
                }
            }

			ImGui::EndColumns();
			
            ImGui::EndTabItem();
        }
    }
}