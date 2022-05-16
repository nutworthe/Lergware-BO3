#include "includes.h"
#define PI 3.14159265358979323846264338327950288

void customScan(int d, __int64 centity_t, float bestpos[3]) {
	for (size_t i = 0; i < IM_ARRAYSIZE(boneSel); i++) {
		if (selected[i]) {
			float ViewOrigin[3];
			CG_GetPlayerViewOrigin(0, playerState, ViewOrigin);

			__int64 DObj = main::funcs::Com_GetClientDObj(*(DWORD*)(centity[d] + 0x3F8), *(unsigned __int8*)(centity[d] + 2));
			float whatever1[255];
			if (DObj > 0) {
				main::funcs::CG_DObjGetWorldTagPosInternal(centity[d], DObj, main::bones::j_eyeball_le, whatever1, j_eyeball_le[d], 0xFFFF);
				main::funcs::CG_DObjGetWorldTagPosInternal(centity[d], DObj, main::bones::j_eyeball_ri, whatever1, j_eyeball_ri[d], 0xFFFF);
				main::funcs::CG_DObjGetWorldTagPosInternal(centity[d], DObj, main::bones::j_ball_le, whatever1, j_ball_le[d], 0xFFFF);
				main::funcs::CG_DObjGetWorldTagPosInternal(centity[d], DObj, main::bones::j_ball_ri, whatever1, j_ball_ri[d], 0xFFFF);
			}

			if (boneSel[i] == "j_helmet") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, helmet_pos[d])) {
					bestpos[0] = helmet_pos[d][0];
					bestpos[1] = helmet_pos[d][1];
					bestpos[2] = helmet_pos[d][2];
				}
			}
			else if (boneSel[i] == "j_head") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, players_head_pos[d])) {
					bestpos[0] = players_head_pos[d][0];
					bestpos[1] = players_head_pos[d][1];
					bestpos[2] = players_head_pos[d][2];
				}
			}
			else if (boneSel[i] == "j_neck") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_neckpos[d])) {
					bestpos[0] = j_neckpos[d][0];
					bestpos[1] = j_neckpos[d][1];
					bestpos[2] = j_neckpos[d][2];
				}
			}
			else if (boneSel[i] == "j_eyeball_le") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_eyeball_le[d])) {
					bestpos[0] = j_eyeball_le[d][0];
					bestpos[1] = j_eyeball_le[d][1];
					bestpos[2] = j_eyeball_le[d][2];
				}
			}
			else if (boneSel[i] == "j_eyeball_ri") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_eyeball_ri[d])) {
					bestpos[0] = j_eyeball_ri[d][0];
					bestpos[1] = j_eyeball_ri[d][1];
					bestpos[2] = j_eyeball_ri[d][2];
				}
			}
			else if (boneSel[i] == "j_spineupper") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_spineupperpos[d])) {
					bestpos[0] = j_spineupperpos[d][0];
					bestpos[1] = j_spineupperpos[d][1];
					bestpos[2] = j_spineupperpos[d][2];
				}
			}
			else if (boneSel[i] == "j_spinelower") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_spinelowerpos[d])) {
					bestpos[0] = j_spinelowerpos[d][0];
					bestpos[1] = j_spinelowerpos[d][1];
					bestpos[2] = j_spinelowerpos[d][2];
				}
			}
			else if (boneSel[i] == "j_shoulder_le") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_shoulder_lepos[d])) {
					bestpos[0] = j_shoulder_lepos[d][0];
					bestpos[1] = j_shoulder_lepos[d][1];
					bestpos[2] = j_shoulder_lepos[d][2];
				}
			}
			else if (boneSel[i] == "j_shoulder_ri") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_shoulder_ripos[d])) {
					bestpos[0] = j_shoulder_ripos[d][0];
					bestpos[1] = j_shoulder_ripos[d][1];
					bestpos[2] = j_shoulder_ripos[d][2];
				}
			}
			else if (boneSel[i] == "j_hip_le") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_hip_le[d])) {
					bestpos[0] = j_hip_le[d][0];
					bestpos[1] = j_hip_le[d][1];
					bestpos[2] = j_hip_le[d][2];
				}
			}
			else if (boneSel[i] == "j_hip_ri") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_hip_ri[d])) {
					bestpos[0] = j_hip_ri[d][0];
					bestpos[1] = j_hip_ri[d][1];
					bestpos[2] = j_hip_ri[d][2];
				}
			}
			else if (boneSel[i] == "j_knee_le") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_knee_lepos[d])) {
					bestpos[0] = j_knee_lepos[d][0];
					bestpos[1] = j_knee_lepos[d][1];
					bestpos[2] = j_knee_lepos[d][2];
				}
			}
			else if (boneSel[i] == "j_knee_ri") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_knee_ripos[d])) {
					bestpos[0] = j_knee_ripos[d][0];
					bestpos[1] = j_knee_ripos[d][1];
					bestpos[2] = j_knee_ripos[d][2];
				}
			}
			else if (boneSel[i] == "j_kneebuldge_le") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_kneebuldge_le[d])) {
					bestpos[0] = j_kneebuldge_le[d][0];
					bestpos[1] = j_kneebuldge_le[d][1];
					bestpos[2] = j_kneebuldge_le[d][2];
				}
			}
			else if (boneSel[i] == "j_kneebuldge_ri") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_kneebuldge_ri[d])) {
					bestpos[0] = j_kneebuldge_ri[d][0];
					bestpos[1] = j_kneebuldge_ri[d][1];
					bestpos[2] = j_kneebuldge_ri[d][2];
				}
			}
			else if (boneSel[i] == "j_elbow_le") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_elbow_lepos[d])) {
					bestpos[0] = j_elbow_lepos[d][0];
					bestpos[1] = j_elbow_lepos[d][1];
					bestpos[2] = j_elbow_lepos[d][2];
				}
			}
			else if (boneSel[i] == "j_elbow_ri") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_elbow_ripos[d])) {
					bestpos[0] = j_elbow_ripos[d][0];
					bestpos[1] = j_elbow_ripos[d][1];
					bestpos[2] = j_elbow_ripos[d][2];
				}
			}
			else if (boneSel[i] == "j_wrist_le") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_wrist_lepos[d])) {
					bestpos[0] = j_wrist_lepos[d][0];
					bestpos[1] = j_wrist_lepos[d][1];
					bestpos[2] = j_wrist_lepos[d][2];
				}
			}
			else if (boneSel[i] == "j_wrist_ri") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_wrist_ripos[d])) {
					bestpos[0] = j_wrist_ripos[d][0];
					bestpos[1] = j_wrist_ripos[d][1];
					bestpos[2] = j_wrist_ripos[d][2];
				}
			}
			else if (boneSel[i] == "j_ankle_le") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_ankle_lepos[d])) {
					bestpos[0] = j_ankle_lepos[d][0];
					bestpos[1] = j_ankle_lepos[d][1];
					bestpos[2] = j_ankle_lepos[d][2];
				}
			}
			else if (boneSel[i] == "j_ankle_ri") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_ankle_ripos[d])) {
					bestpos[0] = j_ankle_ripos[d][0];
					bestpos[1] = j_ankle_ripos[d][1];
					bestpos[2] = j_ankle_ripos[d][2];
				}
			}
			else if (boneSel[i] == "j_ball_le") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_ball_le[d])) {
					bestpos[0] = j_ball_le[d][0];
					bestpos[1] = j_ball_le[d][1];
					bestpos[2] = j_ball_le[d][2];
				}
			}
			else if (boneSel[i] == "j_ball_le") {
				if (IsTargetVisible(0, centity[d], ViewOrigin, j_ball_ri[d])) {
					bestpos[0] = j_ball_ri[d][0];
					bestpos[1] = j_ball_ri[d][1];
					bestpos[2] = j_ball_ri[d][2];
				}
			}
		}
	}
}

void bonescan(int i, __int64 centity_t, float bestpos[3])
{

	__int64 DObj = main::funcs::Com_GetClientDObj(*(DWORD*)(centity[i] + 0x3F8), *(unsigned __int8*)(centity[i] + 2));
	float whatever1[255];
	if (DObj > 0) {
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_neck, whatever1, j_neckpos[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_helmet, whatever1, helmet_pos[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_head, whatever1, players_head_pos[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_hip_le, whatever1, j_hip_le[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_hip_ri, whatever1, j_hip_ri[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_eyeball_le, whatever1, j_eyeball_le[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_eyeball_ri, whatever1, j_eyeball_ri[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_shoulder_le, whatever1, j_shoulder_lepos[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_shoulder_ri, whatever1, j_shoulder_ripos[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_spineupper, whatever1, j_spineupperpos[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_spinelower, whatever1, j_spinelowerpos[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_elbow_le, whatever1, j_elbow_lepos[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_elbow_ri, whatever1, j_elbow_ripos[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_wrist_ri, whatever1, j_wrist_ripos[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_wrist_le, whatever1, j_wrist_lepos[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_knee_le, whatever1, j_knee_lepos[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_knee_ri, whatever1, j_knee_ripos[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_ankle_ri, whatever1, j_ankle_ripos[i], 0xFFFF);
		main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_ankle_le, whatever1, j_ankle_lepos[i], 0xFFFF);
		float origin[3];
		CG_GetPlayerViewOrigin(0, playerState, origin);
		if (IsTargetVisible(0, centity_t, origin, players_head_pos[i]))
		{
			bestpos[0] = players_head_pos[i][0];
			bestpos[1] = players_head_pos[i][1];
			bestpos[2] = players_head_pos[i][2];
		}
		else
		{
			if (IsTargetVisible(0, centity_t, origin, j_neckpos[i]))
			{
				bestpos[0] = j_neckpos[i][0];
				bestpos[1] = j_neckpos[i][1];
				bestpos[2] = j_neckpos[i][2];
			}
			else
			{
				if (IsTargetVisible(0, centity_t, origin, j_spineupperpos[i]))
				{
					bestpos[0] = j_spineupperpos[i][0];
					bestpos[1] = j_spineupperpos[i][1];
					bestpos[2] = j_spineupperpos[i][2];
				}
				else
				{
					if (IsTargetVisible(0, centity_t, origin, j_spinelowerpos[i]))
					{
						bestpos[0] = j_spinelowerpos[i][0];
						bestpos[1] = j_spinelowerpos[i][1];
						bestpos[2] = j_spinelowerpos[i][2];
					}
					else
					{
						if (IsTargetVisible(0, centity_t, origin, j_shoulder_lepos[i]))
						{
							bestpos[0] = j_shoulder_lepos[i][0];
							bestpos[1] = j_shoulder_lepos[i][1];
							bestpos[2] = j_shoulder_lepos[i][2];
						}
						else
						{
							if (IsTargetVisible(0, centity_t, origin, j_shoulder_ripos[i]))
							{
								bestpos[0] = j_shoulder_ripos[i][0];
								bestpos[1] = j_shoulder_ripos[i][1];
								bestpos[2] = j_shoulder_ripos[i][2];
							}
							else
							{
								if (IsTargetVisible(0, centity_t, origin, j_elbow_lepos[i]))
								{
									bestpos[0] = j_elbow_lepos[i][0];
									bestpos[1] = j_elbow_lepos[i][1];
									bestpos[2] = j_elbow_lepos[i][2];
								}
								else
								{
									if (IsTargetVisible(0, centity_t, origin, j_elbow_ripos[i]))
									{
										bestpos[0] = j_elbow_ripos[i][0];
										bestpos[1] = j_elbow_ripos[i][1];
										bestpos[2] = j_elbow_ripos[i][2];
									}
									else
									{
										if (IsTargetVisible(0, centity_t, origin, j_knee_lepos[i]))
										{
											bestpos[0] = j_knee_lepos[i][0];
											bestpos[1] = j_knee_lepos[i][1];
											bestpos[2] = j_knee_lepos[i][2];
										}
										else
										{
											if (IsTargetVisible(0, centity_t, origin, j_knee_ripos[i]))
											{
												bestpos[0] = j_knee_ripos[i][0];
												bestpos[1] = j_knee_ripos[i][1];
												bestpos[2] = j_knee_ripos[i][2];
											}
											else
											{
												if (IsTargetVisible(0, centity_t, origin, j_ankle_ripos[i]))
												{
													bestpos[0] = j_ankle_ripos[i][0];
													bestpos[1] = j_ankle_ripos[i][1];
													bestpos[2] = j_ankle_ripos[i][2];
												}
												else
												{
													if (IsTargetVisible(0, centity_t, origin, j_ankle_lepos[i]))
													{
														bestpos[0] = j_ankle_lepos[i][0];
														bestpos[1] = j_ankle_lepos[i][1];
														bestpos[2] = j_ankle_lepos[i][2];
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

float GetMagnitude(Vector3D vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
}

Vector3D SubtractVec(Vector3D src, Vector3D dest)
{
	Vector3D vec;
	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	vec.x = dest.x - src.x;
	vec.y = dest.y - src.y;
	vec.z = dest.z - src.z;

	return vec;
}

Vector3D NormalizeVec(Vector3D vec)
{
	float Length = GetMagnitude(vec);

	vec.x /= Length;
	vec.y /= Length;
	vec.z /= Length;

	return vec;
}

Vector3D MultiplyVec(Vector3D src, Vector3D dest)
{
	src.x *= dest.x;
	src.y *= dest.y;
	src.z *= dest.z;

	return src;
}
float distanceBetweenTwoPoints(float x, float y, float a, float b) {
	return sqrt(pow(x - a, 2) + pow(y - b, 2));
}
Vector2D CalcAngles(Vector3D src, Vector3D dest, Vector3D ViewAxis[3])
{
	Vector3D aimAt = SubtractVec(src, dest);
	Vector3D normalized = NormalizeVec(aimAt);

	aimAt = MultiplyVec(ViewAxis[1], normalized);
	float yaw = (float)(asin(aimAt.x + aimAt.y + aimAt.z) * (180 / PI));
	aimAt = MultiplyVec(ViewAxis[2], normalized);
	float pitch = (float)(-asin(aimAt.x + aimAt.y + aimAt.z) * (180 / PI));

	Vector2D angles;
	angles.x = 0;
	angles.y = 0;
	angles.x = yaw;
	angles.y = pitch;

	return angles;
}

void aimbot::aimbot(int i, float* best) {
	if (aimbot_active && CL_IsLocalClientInGame(0) > 0 && valid[i])
	{
		float ViewOrigin[3];
		CG_GetPlayerViewOrigin(0, playerState, ViewOrigin);
		Vector3D view;
		view.x = ViewOrigin[0];
		view.y = ViewOrigin[1];
		view.z = ViewOrigin[2];
		Vector3D dest;
		dest.x = best[0];
		dest.y = best[1];
		dest.z = best[2];

		Vector3D ViewAxis[3];
		ViewAxis[0].x = *(float*)(cgArray + 0x131D94);
		ViewAxis[0].y = *(float*)(cgArray + 0x131D98);
		ViewAxis[0].z = *(float*)(cgArray + 0x131D9C);
		ViewAxis[1].x = *(float*)(cgArray + 0x131DA0);
		ViewAxis[1].y = *(float*)(cgArray + 0x131DA4);
		ViewAxis[1].z = *(float*)(cgArray + 0x131DA8);
		ViewAxis[2].x = *(float*)(cgArray + 0x131DAC);
		ViewAxis[2].y = *(float*)(cgArray + 0x131DB0);
		ViewAxis[2].z = *(float*)(cgArray + 0x131DB4);
		Vector2D desiredAngles = CalcAngles(view, dest, ViewAxis);
		float* currentViewAngles = (float*)clientactive_t;
		if (ads_check && GetAsyncKeyState(0x02)) {
			currentViewAngles[11827] += desiredAngles.x;
			currentViewAngles[11826] += desiredAngles.y;
		}
		else if (!ads_check) {
			currentViewAngles[11827] += desiredAngles.x;
			currentViewAngles[11826] += desiredAngles.y;
		}
	}
}