#include "overlay.h"

ImColor esp_rgb()
{

	{
		if (flHue > 255.0f)
			flHue = 0.0f;
	}

	flHue += (rgb_speed / ImGui::GetIO().Framerate);

	ImColor EspPnDColorsrgb = ImColor::HSV(flHue, 1.f, 1.f, 1.f);
	return EspPnDColorsrgb;
}

ImColor rgb_bg()
{

	{
		if (flHue > 255.0f)
			flHue = 0.0f;
	}

	ImColor EspPnDColorsrgb_bg = ImColor::HSV(flHue, 1.f, 1.f, 0.3f);
	return EspPnDColorsrgb_bg;
}

namespace overlay {

	void draw() {

		RECT desktop;
		const HWND hDesktop = GetDesktopWindow();
		GetWindowRect(hDesktop, &desktop);
		vec2_t res = { desktop.right, desktop.bottom };

		ImGuiWindowFlags window_flags = 0;
		window_flags |= ImGuiWindowFlags_NoBackground;
		window_flags |= ImGuiWindowFlags_NoTitleBar;
		window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
		window_flags |= ImGuiWindowFlags_NoInputs;
		window_flags |= ImGuiWindowFlags_NoDecoration;
		ImGui::SetNextWindowSize(ImVec2(res.x, res.y));
		ImGui::Begin("ovrlay", NULL, window_flags);
		ImGui::SetWindowFontScale(2);
		ImDrawList* draw_list = ImGui::GetWindowDrawList();
		ImGui::SetWindowFontScale(1);

		int min = 0;
		int bestTarget = 0;
		ImColor esp_rgb_c = esp_rgb();
		ImColor rgb_bg_c = rgb_bg();

		if (cg_EntitiesArray > 0) {
			for (int i = 0; i < 1024; i++) {
				if (valid[i] && screen[i][0] > 10 && screen[i][1] > 10)
				{

					ImColor healthBar_c;
					if (health[i] > 90) {
						healthBar_c = ImColor(0, 255, 0);
					}
					else if (health[i] > 70) {
						healthBar_c = ImColor(255, 164, 0);
					}
					else if (health[i] > 50) {
						healthBar_c = ImColor(252, 76, 2);
					}
					else if (health[i] > 30) {
						healthBar_c = ImColor(226, 82, 47);
					}
					else {
						healthBar_c = ImColor(255, 0, 0);
					}

					if (team[i] == false)
					{
						if (enemy_active)
						{

							if (rgb_enemy)
							{

								if (Healthbars)
								{
									float healthHeight = (height[i]) * (health[i] / 100.f);

									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5) + 3, screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5) + 3, head_screen[i][1]), ImColor(0, 0, 0, 255), 4);

									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5) + 3, screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5) + 3, head_screen[i][1]), ImColor(30, 30, 30, 255), 2);

									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5) + 3, screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5) + 3, head_screen[i][1] - height[i] + healthHeight), healthBar_c, 2);
								}

								if (Snaplines)
								{
									//snaplines
									draw_list->AddLine(ImVec2(res.x / 2, res.y - 2), ImVec2(screen[i][0], screen[i][1]), esp_rgb_c);
								}

								//filled rects
								if (filled_boxes) {

									draw_list->AddRectFilled(ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1]), rgb_bg_c);

								}

								if (player_names) {
									//player name

									draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2), (head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)) - .8), ImColor(0, 0, 0), playername[i]);
									draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2), (head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)) + .8), ImColor(0, 0, 0), playername[i]);

									draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2) - .8, head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)), ImColor(0, 0, 0), playername[i]);
									draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2) + .8, head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)), ImColor(0, 0, 0), playername[i]);


									draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2), head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)), esp_rgb_c, playername[i]);

								}

								if (skeleton_esp) {
									//bones
									draw_list->AddLine(ImVec2(j_neckpos_screen[i][0], j_neckpos_screen[i][1]), ImVec2(j_spineupperpos_screen[i][0], j_spineupperpos_screen[i][1]), esp_rgb_c, boldness);
									draw_list->AddLine(ImVec2(j_spineupperpos_screen[i][0], j_spineupperpos_screen[i][1]), ImVec2(j_spinelowerpos_screen[i][0], j_spinelowerpos_screen[i][1]), esp_rgb_c, boldness);

									//right top
									draw_list->AddLine(ImVec2(j_neckpos_screen[i][0], j_neckpos_screen[i][1]), ImVec2(j_shoulder_ripos_screen[i][0], j_shoulder_ripos_screen[i][1]), esp_rgb_c, boldness);
									draw_list->AddLine(ImVec2(j_shoulder_ripos_screen[i][0], j_shoulder_ripos_screen[i][1]), ImVec2(j_elbow_ripos_screen[i][0], j_elbow_ripos_screen[i][1]), esp_rgb_c, boldness);
									draw_list->AddLine(ImVec2(j_elbow_ripos_screen[i][0], j_elbow_ripos_screen[i][1]), ImVec2(j_wrist_ripos_screen[i][0], j_wrist_ripos_screen[i][1]), esp_rgb_c, boldness);

									//right bottom
									draw_list->AddLine(ImVec2(j_spinelowerpos_screen[i][0], j_spinelowerpos_screen[i][1]), ImVec2(j_knee_ripos_screen[i][0], j_knee_ripos_screen[i][1]), esp_rgb_c, boldness);
									draw_list->AddLine(ImVec2(j_knee_ripos_screen[i][0], j_knee_ripos_screen[i][1]), ImVec2(j_ankle_ripos_screen[i][0], j_ankle_ripos_screen[i][1]), esp_rgb_c, boldness);


									//left top
									draw_list->AddLine(ImVec2(j_neckpos_screen[i][0], j_neckpos_screen[i][1]), ImVec2(j_shoulder_lepos_screen[i][0], j_shoulder_lepos_screen[i][1]), esp_rgb_c, boldness);
									draw_list->AddLine(ImVec2(j_shoulder_lepos_screen[i][0], j_shoulder_lepos_screen[i][1]), ImVec2(j_elbow_lepos_screen[i][0], j_elbow_lepos_screen[i][1]), esp_rgb_c, boldness);
									draw_list->AddLine(ImVec2(j_elbow_lepos_screen[i][0], j_elbow_lepos_screen[i][1]), ImVec2(j_wrist_lepos_screen[i][0], j_wrist_lepos_screen[i][1]), esp_rgb_c, boldness);

									//left bottom
									draw_list->AddLine(ImVec2(j_spinelowerpos_screen[i][0], j_spinelowerpos_screen[i][1]), ImVec2(j_knee_lepos_screen[i][0], j_knee_lepos_screen[i][1]), esp_rgb_c, boldness);
									draw_list->AddLine(ImVec2(j_knee_lepos_screen[i][0], j_knee_lepos_screen[i][1]), ImVec2(j_ankle_lepos_screen[i][0], j_ankle_lepos_screen[i][1]), esp_rgb_c, boldness);
								}

								if (unfilled_boxes)
								{
									//outline rect
									draw_list->AddRect(ImVec2(screen[i][0] - (width[i] / 1.5) - 1, screen[i][1] - 1), ImVec2(screen[i][0] + (width[i] / 1.5) - 1, head_screen[i][1] - 1), ImColor(0, 0, 0));
									draw_list->AddRect(ImVec2(screen[i][0] - (width[i] / 1.5) + 1, screen[i][1] + 1), ImVec2(screen[i][0] + (width[i] / 1.5) + 1, head_screen[i][1] + 1), ImColor(0, 0, 0));
									draw_list->AddRect(ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1]), esp_rgb_c, boldness);
								}

								if (corner_esp) {
									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] - (width[i] / 4), screen[i][1]), esp_rgb_c, boldness); // br to middle
									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1] + (width[i] / 2)), esp_rgb_c, boldness); // br to tr middle

									draw_list->AddLine(ImVec2(screen[i][0] + (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] + (width[i] / 4), screen[i][1]), esp_rgb_c, .8); // bl to middle
									draw_list->AddLine(ImVec2(screen[i][0] + (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] + (width[i] / 1.5), screen[i][1] + (width[i] / 2)), esp_rgb_c, boldness); // bl to tl middle

									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5), head_screen[i][1]), ImVec2(screen[i][0] - (width[i] / 4), head_screen[i][1]), esp_rgb_c, boldness); // tr to middle
									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5), head_screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5), head_screen[i][1] - (width[i] / 2)), esp_rgb_c, boldness); // tr to br middle

									draw_list->AddLine(ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1]), ImVec2(screen[i][0] + (width[i] / 4), head_screen[i][1]), esp_rgb_c, boldness); // tl to middle
									draw_list->AddLine(ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1]), ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1] - (width[i] / 2)), esp_rgb_c, boldness); // tl to bl middle
								}

							}
							else
							{
								if (team[i] == false)
								{
									if (Healthbars)
									{
										float healthHeight = (height[i]) * (health[i] / 100.f);

										draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5) + 3, screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5) + 3, head_screen[i][1]), ImColor(0, 0, 0, 255), 4);

										draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5) + 3, screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5) + 3, head_screen[i][1]), ImColor(30, 30, 30, 255), 2);

										draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5) + 3, screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5) + 3, head_screen[i][1] - height[i] + healthHeight), healthBar_c, 2);
									}

									if (Snaplines)
									{
										//snaplines
										draw_list->AddLine(ImVec2(res.x / 2, res.y - 2), ImVec2(screen[i][0], screen[i][1]), ImColor(enemy_colors));
									}

									//filled rects

									if (filled_boxes) {

										draw_list->AddRectFilled(ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1]), ImColor(enemy_colors) - ImColor(0, 0, 0, 130));

									}

									if (player_names) {
										//player name

										draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2), (head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)) - .8), ImColor(0, 0, 0), playername[i]);
										draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2), (head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)) + .8), ImColor(0, 0, 0), playername[i]);

										draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2) - .8, head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)), ImColor(0, 0, 0), playername[i]);
										draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2) + .8, head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)), ImColor(0, 0, 0), playername[i]);


										draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2), head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)), ImColor(enemy_colors), playername[i]);
									}

									if (skeleton_esp) {
										//bones
										draw_list->AddLine(ImVec2(j_neckpos_screen[i][0], j_neckpos_screen[i][1]), ImVec2(j_spineupperpos_screen[i][0], j_spineupperpos_screen[i][1]), ImColor(enemy_colors), boldness);
										draw_list->AddLine(ImVec2(j_spineupperpos_screen[i][0], j_spineupperpos_screen[i][1]), ImVec2(j_spinelowerpos_screen[i][0], j_spinelowerpos_screen[i][1]), ImColor(enemy_colors), boldness);

										//right top
										draw_list->AddLine(ImVec2(j_neckpos_screen[i][0], j_neckpos_screen[i][1]), ImVec2(j_shoulder_ripos_screen[i][0], j_shoulder_ripos_screen[i][1]), ImColor(enemy_colors), boldness);
										draw_list->AddLine(ImVec2(j_shoulder_ripos_screen[i][0], j_shoulder_ripos_screen[i][1]), ImVec2(j_elbow_ripos_screen[i][0], j_elbow_ripos_screen[i][1]), ImColor(enemy_colors), boldness);
										draw_list->AddLine(ImVec2(j_elbow_ripos_screen[i][0], j_elbow_ripos_screen[i][1]), ImVec2(j_wrist_ripos_screen[i][0], j_wrist_ripos_screen[i][1]), ImColor(enemy_colors), boldness);

										//right bottom
										draw_list->AddLine(ImVec2(j_spinelowerpos_screen[i][0], j_spinelowerpos_screen[i][1]), ImVec2(j_knee_ripos_screen[i][0], j_knee_ripos_screen[i][1]), ImColor(enemy_colors), boldness);
										draw_list->AddLine(ImVec2(j_knee_ripos_screen[i][0], j_knee_ripos_screen[i][1]), ImVec2(j_ankle_ripos_screen[i][0], j_ankle_ripos_screen[i][1]), ImColor(enemy_colors), boldness);


										//left top
										draw_list->AddLine(ImVec2(j_neckpos_screen[i][0], j_neckpos_screen[i][1]), ImVec2(j_shoulder_lepos_screen[i][0], j_shoulder_lepos_screen[i][1]), ImColor(enemy_colors), boldness);
										draw_list->AddLine(ImVec2(j_shoulder_lepos_screen[i][0], j_shoulder_lepos_screen[i][1]), ImVec2(j_elbow_lepos_screen[i][0], j_elbow_lepos_screen[i][1]), ImColor(enemy_colors), boldness);
										draw_list->AddLine(ImVec2(j_elbow_lepos_screen[i][0], j_elbow_lepos_screen[i][1]), ImVec2(j_wrist_lepos_screen[i][0], j_wrist_lepos_screen[i][1]), ImColor(enemy_colors), boldness);

										//left bottom
										draw_list->AddLine(ImVec2(j_spinelowerpos_screen[i][0], j_spinelowerpos_screen[i][1]), ImVec2(j_knee_lepos_screen[i][0], j_knee_lepos_screen[i][1]), ImColor(enemy_colors), boldness);
										draw_list->AddLine(ImVec2(j_knee_lepos_screen[i][0], j_knee_lepos_screen[i][1]), ImVec2(j_ankle_lepos_screen[i][0], j_ankle_lepos_screen[i][1]), ImColor(enemy_colors), boldness);
									}

									if (unfilled_boxes)
									{
										//outline rect
										draw_list->AddRect(ImVec2(screen[i][0] - (width[i] / 1.5) - 1, screen[i][1] - 1), ImVec2(screen[i][0] + (width[i] / 1.5) - 1, head_screen[i][1] - 1), ImColor(0, 0, 0));
										draw_list->AddRect(ImVec2(screen[i][0] - (width[i] / 1.5) + 1, screen[i][1] + 1), ImVec2(screen[i][0] + (width[i] / 1.5) + 1, head_screen[i][1] + 1), ImColor(0, 0, 0));
										draw_list->AddRect(ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1]), ImColor(enemy_colors), boldness);
									}

									if (corner_esp) {
										draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] - (width[i] / 4), screen[i][1]), ImColor(enemy_colors), boldness); // br to middle
										draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1] + (width[i] / 2)), ImColor(enemy_colors), boldness); // br to tr middle

										draw_list->AddLine(ImVec2(screen[i][0] + (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] + (width[i] / 4), screen[i][1]), ImColor(enemy_colors), .8); // bl to middle
										draw_list->AddLine(ImVec2(screen[i][0] + (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] + (width[i] / 1.5), screen[i][1] + (width[i] / 2)), ImColor(enemy_colors), boldness); // bl to tl middle

										draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5), head_screen[i][1]), ImVec2(screen[i][0] - (width[i] / 4), head_screen[i][1]), ImColor(enemy_colors), boldness); // tr to middle
										draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5), head_screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5), head_screen[i][1] - (width[i] / 2)), ImColor(enemy_colors), boldness); // tr to br middle

										draw_list->AddLine(ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1]), ImVec2(screen[i][0] + (width[i] / 4), head_screen[i][1]), ImColor(enemy_colors), boldness); // tl to middle
										draw_list->AddLine(ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1]), ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1] - (width[i] / 2)), ImColor(enemy_colors), boldness); // tl to bl middle
									}
								}

							}
						}

					}

					if (team[i] == true)
					{
						if (friendly_active)
						{

							if (rgb_friendly)
							{

								if (Healthbars)
								{
									float healthHeight = (height[i]) * (health[i] / 100.f);

									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5) + 3, screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5) + 3, head_screen[i][1]), ImColor(0, 0, 0, 255), 4);

									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5) + 3, screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5) + 3, head_screen[i][1]), ImColor(30, 30, 30, 255), 2);

									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5) + 3, screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5) + 3, head_screen[i][1] - height[i] + healthHeight), healthBar_c, 2);
								}

								if (Snaplines)
								{
									draw_list->AddLine(ImVec2(res.x / 2, res.y - 2), ImVec2(screen[i][0], screen[i][1]), esp_rgb_c);
								}

								if (filled_boxes) {

									draw_list->AddRectFilled(ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1]), rgb_bg_c);

								}

								if (player_names) {
									draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2), (head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)) - .8), ImColor(0, 0, 0), playername[i]);
									draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2), (head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)) + .8), ImColor(0, 0, 0), playername[i]);

									draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2) - .8, head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)), ImColor(0, 0, 0), playername[i]);
									draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2) + .8, head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)), ImColor(0, 0, 0), playername[i]);


									draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2), head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)), esp_rgb_c, playername[i]);
								}

								if (skeleton_esp) {
									//bones
									draw_list->AddLine(ImVec2(j_neckpos_screen[i][0], j_neckpos_screen[i][1]), ImVec2(j_spineupperpos_screen[i][0], j_spineupperpos_screen[i][1]), esp_rgb_c, boldness);
									draw_list->AddLine(ImVec2(j_spineupperpos_screen[i][0], j_spineupperpos_screen[i][1]), ImVec2(j_spinelowerpos_screen[i][0], j_spinelowerpos_screen[i][1]), esp_rgb_c, boldness);

									//right top
									draw_list->AddLine(ImVec2(j_neckpos_screen[i][0], j_neckpos_screen[i][1]), ImVec2(j_shoulder_ripos_screen[i][0], j_shoulder_ripos_screen[i][1]), esp_rgb_c, boldness);
									draw_list->AddLine(ImVec2(j_shoulder_ripos_screen[i][0], j_shoulder_ripos_screen[i][1]), ImVec2(j_elbow_ripos_screen[i][0], j_elbow_ripos_screen[i][1]), esp_rgb_c, boldness);
									draw_list->AddLine(ImVec2(j_elbow_ripos_screen[i][0], j_elbow_ripos_screen[i][1]), ImVec2(j_wrist_ripos_screen[i][0], j_wrist_ripos_screen[i][1]), esp_rgb_c, boldness);

									//right bottom
									draw_list->AddLine(ImVec2(j_spinelowerpos_screen[i][0], j_spinelowerpos_screen[i][1]), ImVec2(j_knee_ripos_screen[i][0], j_knee_ripos_screen[i][1]), esp_rgb_c, boldness);
									draw_list->AddLine(ImVec2(j_knee_ripos_screen[i][0], j_knee_ripos_screen[i][1]), ImVec2(j_ankle_ripos_screen[i][0], j_ankle_ripos_screen[i][1]), esp_rgb_c, boldness);


									//left top
									draw_list->AddLine(ImVec2(j_neckpos_screen[i][0], j_neckpos_screen[i][1]), ImVec2(j_shoulder_lepos_screen[i][0], j_shoulder_lepos_screen[i][1]), esp_rgb_c, boldness);
									draw_list->AddLine(ImVec2(j_shoulder_lepos_screen[i][0], j_shoulder_lepos_screen[i][1]), ImVec2(j_elbow_lepos_screen[i][0], j_elbow_lepos_screen[i][1]), esp_rgb_c, boldness);
									draw_list->AddLine(ImVec2(j_elbow_lepos_screen[i][0], j_elbow_lepos_screen[i][1]), ImVec2(j_wrist_lepos_screen[i][0], j_wrist_lepos_screen[i][1]), esp_rgb_c, boldness);

									//left bottom
									draw_list->AddLine(ImVec2(j_spinelowerpos_screen[i][0], j_spinelowerpos_screen[i][1]), ImVec2(j_knee_lepos_screen[i][0], j_knee_lepos_screen[i][1]), esp_rgb_c, boldness);
									draw_list->AddLine(ImVec2(j_knee_lepos_screen[i][0], j_knee_lepos_screen[i][1]), ImVec2(j_ankle_lepos_screen[i][0], j_ankle_lepos_screen[i][1]), esp_rgb_c, boldness);
								}

								if (unfilled_boxes)
								{
									draw_list->AddRect(ImVec2(screen[i][0] - (width[i] / 1.5) - 1, screen[i][1] - 1), ImVec2(screen[i][0] + (width[i] / 1.5) - 1, head_screen[i][1] - 1), ImColor(0, 0, 0));
									draw_list->AddRect(ImVec2(screen[i][0] - (width[i] / 1.5) + 1, screen[i][1] + 1), ImVec2(screen[i][0] + (width[i] / 1.5) + 1, head_screen[i][1] + 1), ImColor(0, 0, 0));
									draw_list->AddRect(ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1]), esp_rgb_c, boldness);
								}

								if (corner_esp) {
									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] - (width[i] / 4), screen[i][1]), esp_rgb_c, boldness); // br to middle
									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1] + (width[i] / 2)), esp_rgb_c, boldness); // br to tr middle

									draw_list->AddLine(ImVec2(screen[i][0] + (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] + (width[i] / 4), screen[i][1]), esp_rgb_c, .8); // bl to middle
									draw_list->AddLine(ImVec2(screen[i][0] + (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] + (width[i] / 1.5), screen[i][1] + (width[i] / 2)), esp_rgb_c, boldness); // bl to tl middle

									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5), head_screen[i][1]), ImVec2(screen[i][0] - (width[i] / 4), head_screen[i][1]), esp_rgb_c, boldness); // tr to middle
									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5), head_screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5), head_screen[i][1] - (width[i] / 2)), esp_rgb_c, boldness); // tr to br middle

									draw_list->AddLine(ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1]), ImVec2(screen[i][0] + (width[i] / 4), head_screen[i][1]), esp_rgb_c, boldness); // tl to middle
									draw_list->AddLine(ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1]), ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1] - (width[i] / 2)), esp_rgb_c, boldness); // tl to bl middle
								}

							}
							else
							{

								if (Healthbars)
								{
									float healthHeight = (height[i]) * (health[i] / 100.f);

									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5) + 3, screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5) + 3, head_screen[i][1]), ImColor(0, 0, 0, 255), 4);

									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5) + 3, screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5) + 3, head_screen[i][1]), ImColor(30, 30, 30, 255), 2);

									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5) + 3, screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5) + 3, head_screen[i][1] - height[i] + healthHeight), healthBar_c, 2);
								}

								if (Snaplines)
								{
									
									draw_list->AddLine(ImVec2(res.x / 2, res.y - 2), ImVec2(screen[i][0], screen[i][1]), ImColor(friendly_colors));
								}

								
								if (filled_boxes) {

									draw_list->AddRectFilled(ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1]), ImColor(friendly_colors) - ImColor(0, 0, 0, 130));

								}
								
								if (player_names) {
						
									draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2), (head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)) - .8), ImColor(0, 0, 0), playername[i]);
									draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2), (head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)) + .8), ImColor(0, 0, 0), playername[i]);

									draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2) - .8, head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)), ImColor(0, 0, 0), playername[i]);
									draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2) + .8, head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)), ImColor(0, 0, 0), playername[i]);


									draw_list->AddText(ImVec2(head_screen[i][0] - (ImGui::CalcTextSize(playername[i]).x / 2), head_screen[i][1] - (ImGui::CalcTextSize(playername[i]).y)), ImColor(friendly_colors), playername[i]);
								}

								if (skeleton_esp) {
									//bones
									draw_list->AddLine(ImVec2(j_neckpos_screen[i][0], j_neckpos_screen[i][1]), ImVec2(j_spineupperpos_screen[i][0], j_spineupperpos_screen[i][1]), ImColor(friendly_colors), boldness);
									draw_list->AddLine(ImVec2(j_spineupperpos_screen[i][0], j_spineupperpos_screen[i][1]), ImVec2(j_spinelowerpos_screen[i][0], j_spinelowerpos_screen[i][1]), ImColor(friendly_colors), boldness);

									//right top
									draw_list->AddLine(ImVec2(j_neckpos_screen[i][0], j_neckpos_screen[i][1]), ImVec2(j_shoulder_ripos_screen[i][0], j_shoulder_ripos_screen[i][1]), ImColor(friendly_colors), boldness);
									draw_list->AddLine(ImVec2(j_shoulder_ripos_screen[i][0], j_shoulder_ripos_screen[i][1]), ImVec2(j_elbow_ripos_screen[i][0], j_elbow_ripos_screen[i][1]), ImColor(friendly_colors), boldness);
									draw_list->AddLine(ImVec2(j_elbow_ripos_screen[i][0], j_elbow_ripos_screen[i][1]), ImVec2(j_wrist_ripos_screen[i][0], j_wrist_ripos_screen[i][1]), ImColor(friendly_colors), boldness);

									//right bottom
									draw_list->AddLine(ImVec2(j_spinelowerpos_screen[i][0], j_spinelowerpos_screen[i][1]), ImVec2(j_knee_ripos_screen[i][0], j_knee_ripos_screen[i][1]), ImColor(friendly_colors), boldness);
									draw_list->AddLine(ImVec2(j_knee_ripos_screen[i][0], j_knee_ripos_screen[i][1]), ImVec2(j_ankle_ripos_screen[i][0], j_ankle_ripos_screen[i][1]), ImColor(friendly_colors), boldness);


									//left top
									draw_list->AddLine(ImVec2(j_neckpos_screen[i][0], j_neckpos_screen[i][1]), ImVec2(j_shoulder_lepos_screen[i][0], j_shoulder_lepos_screen[i][1]), ImColor(friendly_colors), boldness);
									draw_list->AddLine(ImVec2(j_shoulder_lepos_screen[i][0], j_shoulder_lepos_screen[i][1]), ImVec2(j_elbow_lepos_screen[i][0], j_elbow_lepos_screen[i][1]), ImColor(friendly_colors), boldness);
									draw_list->AddLine(ImVec2(j_elbow_lepos_screen[i][0], j_elbow_lepos_screen[i][1]), ImVec2(j_wrist_lepos_screen[i][0], j_wrist_lepos_screen[i][1]), ImColor(friendly_colors), boldness);

									//left bottom
									draw_list->AddLine(ImVec2(j_spinelowerpos_screen[i][0], j_spinelowerpos_screen[i][1]), ImVec2(j_knee_lepos_screen[i][0], j_knee_lepos_screen[i][1]), ImColor(friendly_colors), boldness);
									draw_list->AddLine(ImVec2(j_knee_lepos_screen[i][0], j_knee_lepos_screen[i][1]), ImVec2(j_ankle_lepos_screen[i][0], j_ankle_lepos_screen[i][1]), ImColor(friendly_colors), boldness);
								}

								if (unfilled_boxes)
								{
									draw_list->AddRect(ImVec2(screen[i][0] - (width[i] / 1.5) - 1, screen[i][1] - 1), ImVec2(screen[i][0] + (width[i] / 1.5) - 1, head_screen[i][1] - 1), ImColor(0, 0, 0));
									draw_list->AddRect(ImVec2(screen[i][0] - (width[i] / 1.5) + 1, screen[i][1] + 1), ImVec2(screen[i][0] + (width[i] / 1.5) + 1, head_screen[i][1] + 1), ImColor(0, 0, 0));
									draw_list->AddRect(ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1]), ImColor(friendly_colors), boldness);
								}

								if (corner_esp) {
									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] - (width[i] / 4), screen[i][1]), ImColor(friendly_colors), boldness); // br to middle
									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5), screen[i][1] + (width[i] / 2)), ImColor(friendly_colors), boldness); // br to tr middle

									draw_list->AddLine(ImVec2(screen[i][0] + (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] + (width[i] / 4), screen[i][1]), ImColor(friendly_colors), .8); // bl to middle
									draw_list->AddLine(ImVec2(screen[i][0] + (width[i] / 1.5), screen[i][1]), ImVec2(screen[i][0] + (width[i] / 1.5), screen[i][1] + (width[i] / 2)), ImColor(friendly_colors), boldness); // bl to tl middle

									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5), head_screen[i][1]), ImVec2(screen[i][0] - (width[i] / 4), head_screen[i][1]), ImColor(friendly_colors), boldness); // tr to middle
									draw_list->AddLine(ImVec2(screen[i][0] - (width[i] / 1.5), head_screen[i][1]), ImVec2(screen[i][0] - (width[i] / 1.5), head_screen[i][1] - (width[i] / 2)), ImColor(friendly_colors), boldness); // tr to br middle

									draw_list->AddLine(ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1]), ImVec2(screen[i][0] + (width[i] / 4), head_screen[i][1]), ImColor(friendly_colors), boldness); // tl to middle
									draw_list->AddLine(ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1]), ImVec2(screen[i][0] + (width[i] / 1.5), head_screen[i][1] - (width[i] / 2)), ImColor(friendly_colors), boldness); // tl to bl middle
								}


							}
						}
					}


				}
			}
		}
		ImGui::End();
	}
}