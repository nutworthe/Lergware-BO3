#include "menu.h"

ImColor menu_rgb()
{

	{
		if (flHue > 255.0f)
			flHue = 0.0f;
	}

	ImColor EspPnDColorsrgb_menu = ImColor::HSV(flHue, 1.f, 1.f, 0.7f);
	return EspPnDColorsrgb_menu;
}

void rgbstyle()
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	vec2_t res = { desktop.right, desktop.bottom };

	ImColor menu_rgb_c = menu_rgb();

	auto& style = ImGui::GetStyle();

	ImGui::SetNextWindowSize(ImVec2(res.x / 4.4, res.y / 2.5), ImGuiCond_Once);

	style.Colors[ImGuiCol_Separator] = ImColor(20, 20, 20, 200);
	style.Colors[ImGuiCol_SeparatorActive] = ImColor(20, 20, 20, 200);
	style.Colors[ImGuiCol_SeparatorHovered] = ImColor(20, 20, 20, 200);
	style.Colors[ImGuiCol_PlotLines] = ImColor(210, 210, 210, 255);
	style.Colors[ImGuiCol_PlotLinesHovered] = menu_rgb_c;
	style.Colors[ImGuiCol_PlotHistogram] = ImColor(210, 210, 210, 255);
	style.Colors[ImGuiCol_PlotHistogramHovered] = menu_rgb_c;
	style.Colors[ImGuiCol_Text] = ImColor(245, 245, 245, 255);
	style.Colors[ImGuiCol_Border] = ImColor(18, 18, 18, 255);
	style.Colors[ImGuiCol_WindowBg] = ImColor(30, 30, 30, 255);
	style.Colors[ImGuiCol_TitleBg] = menu_rgb_c;
	style.Colors[ImGuiCol_TitleBgActive] = menu_rgb_c;
	style.Colors[ImGuiCol_TitleBgCollapsed] = menu_rgb_c;
	style.Colors[ImGuiCol_Button] = ImColor(20, 20, 20, 200);			// button color
	style.Colors[ImGuiCol_ButtonActive] = menu_rgb_c;	// button color when pressed
	style.Colors[ImGuiCol_ButtonHovered] = ImColor(100, 100, 100, 100);
	style.Colors[ImGuiCol_CheckMark] = menu_rgb_c;
	style.Colors[ImGuiCol_FrameBg] = ImColor(18, 18, 18, 255);
	style.Colors[ImGuiCol_FrameBgActive] = ImColor(18, 18, 18, 255);
	style.Colors[ImGuiCol_FrameBgHovered] = ImColor(18, 18, 18, 255);
	style.Colors[ImGuiCol_Header] = menu_rgb_c;			// for collapsing headers , etc
	style.Colors[ImGuiCol_HeaderActive] = ImColor(24, 24, 24, 255);
	style.Colors[ImGuiCol_HeaderHovered] = menu_rgb_c;
	style.Colors[ImGuiCol_ResizeGrip] = ImColor(24, 24, 24, 255);		// the resize grip thing bottom right
	style.Colors[ImGuiCol_ResizeGripActive] = menu_rgb_c;	// when you hold it / active
	style.Colors[ImGuiCol_ResizeGripHovered] = ImColor(24, 24, 24, 255);
	style.Colors[ImGuiCol_SliderGrab] = menu_rgb_c;
	style.Colors[ImGuiCol_SliderGrabActive] = menu_rgb_c;
	style.Colors[ImGuiCol_Tab] = menu_rgb_c;
	style.Colors[ImGuiCol_MenuBarBg] = menu_rgb_c;
	style.Colors[ImGuiCol_TabHovered] = ImColor(5, 5, 5, 255);
	style.Colors[ImGuiCol_TabActive] = ImColor(5, 5, 5, 255);
	style.Colors[ImGuiCol_TabUnfocused] = menu_rgb_c;
	style.Colors[ImGuiCol_TabUnfocusedActive] = ImColor(5, 5, 5, 255);
	style.Colors[ImGuiCol_TextSelectedBg] = menu_rgb_c;

	style.WindowPadding = ImVec2(6, 4);
	style.WindowRounding = 10.f;
	style.FramePadding = ImVec2(5, 2);
	style.FrameRounding = 4.0f;
	style.ItemSpacing = ImVec2(7, 1);
	style.ItemInnerSpacing = ImVec2(1, 1);
	style.TouchExtraPadding = ImVec2(0, 0);
	style.IndentSpacing = 6.0f;
	style.ScrollbarSize = 12.0f;
	style.ScrollbarRounding = 16.0f;
	style.GrabMinSize = 20.0f;
	style.GrabRounding = 2.0f;
	style.WindowTitleAlign.x = 0.50f;
	style.FrameBorderSize = 0.0f;
	style.WindowBorderSize = 1.0f;
	style.ItemInnerSpacing = ImVec2(5, 0);
}

void runstyle()
{

	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	vec2_t res = { desktop.right, desktop.bottom };

	auto& style = ImGui::GetStyle();

	ImGui::SetNextWindowSize(ImVec2(res.x / 4.4, res.y / 2.5), ImGuiCond_Once);

	style.Colors[ImGuiCol_Separator] = ImColor(20, 20, 20, 200);
	style.Colors[ImGuiCol_SeparatorActive] = ImColor(20, 20, 20, 200);
	style.Colors[ImGuiCol_SeparatorHovered] = ImColor(20, 20, 20, 200);
	style.Colors[ImGuiCol_PlotLines] = ImColor(210, 210, 210, 255);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImColor(255, 200, 0, 255);
	style.Colors[ImGuiCol_PlotHistogram] = ImColor(210, 210, 210, 255);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImColor(255, 200, 0, 255);
	style.Colors[ImGuiCol_Text] = ImColor(245, 245, 245, 255);
	style.Colors[ImGuiCol_Border] = ImColor(18, 18, 18, 255);
	style.Colors[ImGuiCol_WindowBg] = ImColor(30, 30, 30, 255);
	style.Colors[ImGuiCol_TitleBg] = ImColor(255, 200, 0, 200);
	style.Colors[ImGuiCol_TitleBgActive] = ImColor(255, 200, 0, 200);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(255, 200, 0, 200);
	style.Colors[ImGuiCol_Button] = ImColor(20, 20, 20, 200);			// button color
	style.Colors[ImGuiCol_ButtonActive] = ImColor(255, 200, 0, 200);	// button color when pressed
	style.Colors[ImGuiCol_ButtonHovered] = ImColor(100, 100, 100, 100);
	style.Colors[ImGuiCol_CheckMark] = ImColor(255, 200, 0, 200);
	style.Colors[ImGuiCol_FrameBg] = ImColor(18, 18, 18, 255);
	style.Colors[ImGuiCol_FrameBgActive] = ImColor(18, 18, 18, 255);
	style.Colors[ImGuiCol_FrameBgHovered] = ImColor(18, 18, 18, 255);
	style.Colors[ImGuiCol_Header] = ImColor(255, 200, 0, 200);			// for collapsing headers , etc
	style.Colors[ImGuiCol_HeaderActive] = ImColor(24, 24, 24, 255);
	style.Colors[ImGuiCol_HeaderHovered] = ImColor(255, 200, 0, 200);
	style.Colors[ImGuiCol_ResizeGrip] = ImColor(24, 24, 24, 255);		// the resize grip thing bottom right
	style.Colors[ImGuiCol_ResizeGripActive] = ImColor(24, 24, 24, 255);	// when you hold it / active
	style.Colors[ImGuiCol_ResizeGripHovered] = ImColor(24, 24, 24, 255);
	style.Colors[ImGuiCol_SliderGrab] = ImColor(255, 200, 0, 200);
	style.Colors[ImGuiCol_SliderGrabActive] = ImColor(255, 200, 0, 200);
	style.Colors[ImGuiCol_Tab] = ImColor(255, 200, 0, 200);
	style.Colors[ImGuiCol_MenuBarBg] = ImColor(255, 200, 0, 200);
	style.Colors[ImGuiCol_TabHovered] = ImColor(5, 5, 5, 255);
	style.Colors[ImGuiCol_TabActive] = ImColor(5, 5, 5, 255);
	style.Colors[ImGuiCol_TabUnfocused] = ImColor(255, 200, 0, 200);
	style.Colors[ImGuiCol_TabUnfocusedActive] = ImColor(5, 5, 5, 255);
	style.Colors[ImGuiCol_TextSelectedBg] = ImColor(255, 200, 0, 200);

	style.WindowPadding = ImVec2(6, 4);
	style.WindowRounding = 10.f;
	style.FramePadding = ImVec2(5, 2);
	style.FrameRounding = 4.0f;
	style.ItemSpacing = ImVec2(7, 1);
	style.ItemInnerSpacing = ImVec2(1, 1);
	style.TouchExtraPadding = ImVec2(0, 0);
	style.IndentSpacing = 6.0f;
	style.ScrollbarSize = 12.0f;
	style.ScrollbarRounding = 16.0f;
	style.GrabMinSize = 20.0f;
	style.GrabRounding = 2.0f;
	style.WindowTitleAlign.x = 0.50f;
	style.FrameBorderSize = 0.0f;
	style.WindowBorderSize = 1.0f;
	style.ItemInnerSpacing = ImVec2(5, 0);

}

const char* aims[]{ "Closest to crosshair", "Closest to player" };

const char* bones[]{ "Best", "Head", "Body", "Custom" };

namespace menu
{
	bool is_open()
	{
		return open;
	}

	void draw()
	{

		if (menurgb)
		{
			rgbstyle();
		}
		else
		{
			runstyle();
		}

		if (is_open())
		{
			*(int*)((DWORD64)GetModuleHandleA(NULL) + 0x17E71335) = 0;
			ImGui::Begin("lergware", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
			{
				if (ImGui::BeginTabBar("Main", ImGuiTabBarFlags_NoTooltip))
				{
					if (ImGui::BeginTabItem("Aimbot"))
					{
						ImGui::Dummy(ImVec2(0.0f, 5.0f));

						ImGui::Checkbox("Active", &aimbot_active);

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Checkbox("Visibility", &visibility_check);

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Checkbox("No Recoil", &no_recoil);

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Checkbox("ADS Check", &ads_check);

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Combo("Aimbot type", &aimbot_type, aims, IM_ARRAYSIZE(aims));

						ImGui::Combo("Bonescan", &bone_type, bones, IM_ARRAYSIZE(bones));

						static std::string previewValue = "";

						if (ImGui::BeginCombo("Bones", previewValue.c_str()))
						{
							previewValue = "";
							for (size_t i = 0; i < IM_ARRAYSIZE(boneSel); i++) {
								ImGui::Selectable(boneSel[i], &selected[i], ImGuiSelectableFlags_::ImGuiSelectableFlags_DontClosePopups);

								if (selected[i]) {
									vec.push_back(boneSel[i]);
								}
							}
							ImGui::EndCombo();
						}

						ImGui::EndTabItem();
					}

					if (ImGui::BeginTabItem("Visuals"))
					{

						ImGui::Dummy(ImVec2(0.0f, 5.0f));

						ImGui::Checkbox("Enemies", &enemy_active);

						ImGui::SameLine();

						ImGui::Dummy(ImVec2(254.9f, 0.0f));

						ImGui::SameLine();

						ImGui::Text("Friendlies");

						ImGui::SameLine();

						ImGui::Checkbox("##Friendlies", &friendly_active);

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Checkbox("Filled", &filled_boxes);

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Checkbox("Unfilled", &unfilled_boxes);

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Checkbox("Corners", &corner_esp);

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Checkbox("Snaplines", &Snaplines);

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Checkbox("Healthbars", &Healthbars);

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Checkbox("Skeletons", &skeleton_esp);

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Checkbox("Player Name", &player_names);

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Checkbox("RGB Enemies", &rgb_enemy);

						ImGui::SameLine();

						ImGui::Dummy(ImVec2(203.5f, 0.0f));

						ImGui::SameLine();

						ImGui::Text("RGB Friendlies");

						ImGui::SameLine();

						ImGui::Checkbox("##RGBFriendlies", &rgb_friendly);

						ImGui::Dummy(ImVec2(0.0f, 3.0f));
						ImGui::SetNextItemWidth(90);

						ImGui::InputFloat("Boldness", &boldness, .25);
						if (boldness > 3)
							boldness = 3;
						else if (boldness < .25)
							boldness = .25;

						ImGui::SameLine();

						ImGui::Dummy(ImVec2(190.f, 0.0f));

						ImGui::SameLine();

						ImGui::Text("Enemies");
						ImGui::SameLine();
						ImGui::ColorEdit3("##EspBoxColorEditor", (float*)&enemy_colors, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::SetNextItemWidth(160);

						ImGui::Combo("##RGBSpeed", &speed_sel, speed_selection, IM_ARRAYSIZE(speed_selection));
						if (speed_sel == 0)
							rgb_speed = 0.3f;
						else if (speed_sel == 1)
							rgb_speed = 0.75f;
						else if (speed_sel == 2)
							rgb_speed = 1.2f;
						else if (speed_sel == 3)
							rgb_speed = 1.5f;

						ImGui::SameLine();

						ImGui::Dummy(ImVec2(168.0f, 0.0f));

						ImGui::SameLine();

						ImGui::Text("Friendlies");
						ImGui::SameLine();
						ImGui::ColorEdit3("##FriendlyEspBoxColorEditor", (float*)&friendly_colors, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::EndTabItem();

					}

					friends::friends_list();
					/*
					if (ImGui::BeginTabItem("Lobby"))
					{
						//future in lobby player list

						ImGui::EndTabItem();
					}
					*/
					if (ImGui::BeginTabItem("Tools"))
					{

						ImGui::Dummy(ImVec2(0.0f, 2.0f));

						if (ImGui::Button("Crash All"))
						{
							Cmd_ExecuteSingleCommand(0, 0, "callvote map \"^H\xff\xff\xff\deez\"", false);
						}

						ImGui::SameLine();

						if (ImGui::Button("Crash Server"))
						{
							LobbyClientMsg_SendModifiedStats(0, 1);
						}

						ImGui::SameLine();

						if (ImGui::Button("End Game"))
						{
							char buf[255];
							__int64 _server_id = dwProcessBase + 0x569D250;
							sprintf_s(buf, "mr %d -1 endround", *(DWORD*)_server_id);
							CL_AddReliableCommand(0, buf);
						}

						ImGui::SameLine();

						if (ImGui::Button("SL"))
						{
							CL_AddReliableCommand(0, "sl 1488 88");
						}

						ImGui::Dummy(ImVec2(0.0f, 2.0f));

						ImGui::Separator();

						ImGui::Dummy(ImVec2(0.0f, 2.0f));

						ImGui::Separator();

						static auto join_input = ""s;

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::InputTextWithHint("##JOIN", "STEAM ID", &join_input);
						ImGui::SameLine();

						if (ImGui::Button("Join##STEAMID"))
						{
							LobbyVM_JoinEvent(0, std::stoull(join_input), JoinType::JOIN_TYPE_PARTY);
						}

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Separator();

						static auto cbuf_input = ""s;

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::InputTextWithHint("##CBUF", "CBUF", &cbuf_input);
						ImGui::SameLine();

						if (ImGui::Button("Send##CBUF"))
						{
							Cbuf_AddText(0, cbuf_input.data());
						}

						static auto single_input = ""s;

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::InputTextWithHint("##SINGLE", "SINGLE", &single_input);
						ImGui::SameLine();

						if (ImGui::Button("Send##SINGLE"))
						{
							Cmd_ExecuteSingleCommand(0, 0, single_input.data(), false);
						}

						static auto reliable_input = ""s;

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::InputTextWithHint("##RELIABLE", "RELIABLE", &reliable_input);

						ImGui::SameLine();

						if (ImGui::Button("Send##RELIABLE"))
						{
							CL_AddReliableCommand(0, reliable_input.data());
						}

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Separator();

						static auto crash_input = ""s;

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::InputTextWithHint("##CRASH", "CRASH", &crash_input);
						ImGui::SameLine();

						if (ImGui::Button("Send##CRASH"))
						{
							exploit::send_crash(std::stoull(crash_input));
						}

						static auto popup_input = ""s;

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::InputTextWithHint("##POP-UP", "POP-UP", &popup_input);
						ImGui::SameLine();

						if (ImGui::Button("Send##POP-UP"))
						{
							exploit::send_popup(std::stoull(popup_input));
						}

						static auto oob_input = ""s;

						ImGui::Dummy(ImVec2(0.0f, 3.0f));
						/*
						ImGui::InputTextWithHint("##OOBS", "OOBS", &oob_input);
						ImGui::SameLine();

						if (ImGui::Button("Send##OOB"))
						{
							//need way to find netaddr by XUID, Exists In Friends List In Some Form.
						}

						ImGui::Dummy(ImVec2(0.0f, 3.0f));
						*/

						ImGui::Separator();

						static auto callvote_input = ""s;

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::InputTextWithHint("##Callvote", "CALLVOTE", &callvote_input);

						ImGui::SameLine();

						if (ImGui::Button("Send"))
						{
							char cmd[255];
							sprintf_s(cmd, "callvote map \"%s\"", callvote_input.data());
							CL_AddReliableCommand(0, cmd);
						}

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Separator();

						ImGui::Dummy(ImVec2(0.0f, 3.0f));



						{
							void CBUF(int al, char* a2);
						}

						ImGui::EndTabItem();
					}

					if (ImGui::BeginTabItem("Misc"))
					{
						ImGui::Dummy(ImVec2(0.0f, 2.0f));

						ImGui::Checkbox("RGB", &menurgb);

						ImGui::SameLine();

						ImGui::Checkbox("HATR", &inf_hatr);

						ImGui::SameLine();

						ImGui::Checkbox("Crypto", &ct);

						ImGui::SameLine();

						ImGui::Checkbox("Divinium", &div_loop);

						ImGui::Dummy(ImVec2(0.0f, 2.0f));

						ImGui::Separator();

						ImGui::Dummy(ImVec2(0.0f, 2.0f));

						ImGui::Separator();

						static auto nameBuffer = ""s;

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::InputTextWithHint("##NAME", "NAME", &nameBuffer);
						ImGui::SameLine();

						if (ImGui::Button("Set##NAME"))
						{
							strncpy_s(spoofName, sizeof(spoofName), nameBuffer.data(), -1);
							RenamePreGame(spoofName);
						}

						static auto clan_input = ""s;

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::InputTextWithHint("##CLAN", "CLAN", &clan_input);
						ImGui::SameLine();

						if (ImGui::Button("Set##CLAN"))
						{
							LiveStats_SetClanTagText(0, clan_input.data());
						}

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Separator();

						static auto print_bold = ""s;

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::InputTextWithHint("##iPrintBold", "PRINT BOLD", &print_bold);

						ImGui::SameLine();

						if (ImGui::Button("Print"))
						{
							char Buffer[1030];
							sprintf_s(Buffer, "< \"%s\"\n", print_bold.data());
							SV_GameSendServerCommand(0, 1, (char*)Buffer);
						}

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::Separator();

						ImGui::Dummy(ImVec2(0.0f, 3.0f));

						ImGui::EndTabItem();

					}

					ImGui::EndTabBar();
				}
				ImGui::End();
			}
		}
		else
		{
			*(int*)((DWORD64)GetModuleHandleA(NULL) + 0x17E71335) = 1;
		}
	}
}