#include "includes.h"

DWORD64 exc;

bool initialized = false;
bool open = true;

const void* main::spoof_t = (const void*)((DWORD64)GetModuleHandleA(NULL) + 0x2A96FFB);
typedef bool(__fastcall* CG_GetPlayerViewOriginT)(unsigned int localClientNum, __int64 playerstate, float* origin);
CG_GetPlayerViewOriginT CG_GetPlayerViewOrigin1 = (CG_GetPlayerViewOriginT)((DWORD64)GetModuleHandleA(NULL) + 0x11F04C0);
typedef bool(__fastcall* tCG_CanSeeFriendlyHeadTrace)(int localClientNum, __int64 centity_t, __int64 start, __int64 end);
tCG_CanSeeFriendlyHeadTrace CG_CanSeeFriendlyHeadTrace = (tCG_CanSeeFriendlyHeadTrace)((DWORD64)GetModuleHandleA(NULL) + 0x676140);
typedef bool(__fastcall* CG_IsEntityFriendlyNotEnemyT)(int localClientNum, __int64 centity_t);
CG_IsEntityFriendlyNotEnemyT CG_IsEntityFriendlyNotEnemy12 = (CG_IsEntityFriendlyNotEnemyT)((DWORD64)GetModuleHandleA(NULL) + 0x1D6180);

void VectorSubtract(const vec3_t& a, const vec3_t& b, vec3_t& c)
{
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
}

float DotProduct(const vec3_t& v1, const vec3_t& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}


bool IsTargetVisible(int localClientNum, __int64 centity_t, float* start, float* end) {
	return spoof_call(main::spoof_t, CG_CanSeeFriendlyHeadTrace, localClientNum, centity_t, (__int64)start, (__int64)end);
}

bool CG_GetPlayerViewOrigin(unsigned int localClientNum, __int64 playerstate, float* origin) {
	return spoof_call(main::spoof_t, CG_GetPlayerViewOrigin1, localClientNum, playerstate, origin);
}

bool w2s(int localClientNum, float* worldPos, float* out) {
	return spoof_call(main::spoof_t, main::funcs::WorldPosToScreenPos, localClientNum, worldPos, out);
}

bool CG_IsEntityFriendlyNotEnemy(int localClientNum, __int64 centity_t) {
	return spoof_call(main::spoof_t, CG_IsEntityFriendlyNotEnemy12, localClientNum, centity_t);
}

bool WorldToScreen(vec3_t vWorldLocation, float* fScreenX, float* fScreenY)
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	vec2_t res = { desktop.right, desktop.bottom };

	int width = res.x / 2;
	int height = res.y / 2;

	vec3_t vLocal, vTransForm;

	vec3_t vfwd;
	float* viewaxis = (float*)(cgArray + 0x131D94);
	vfwd.x = viewaxis[0];
	vfwd.y = viewaxis[1];
	vfwd.z = viewaxis[2];

	vec3_t vright;
	vright.x = viewaxis[3];
	vright.y = viewaxis[4];
	vright.z = viewaxis[5];

	vec3_t vup;
	vup.x = viewaxis[6];
	vup.y = viewaxis[7];
	vup.z = viewaxis[8];

	vec3_t viewOrg;
	float* vieworigin = (float*)(cgArray + 0x131D78);
	viewOrg.x = vieworigin[0];
	viewOrg.y = vieworigin[1];
	viewOrg.z = vieworigin[2];
	VectorSubtract(vWorldLocation, viewOrg, vLocal);

	vTransForm.x = DotProduct(vLocal, vright);
	vTransForm.y = DotProduct(vLocal, vup);
	vTransForm.z = DotProduct(vLocal, vfwd);

	if (vTransForm.z < 0.01)
		return 0;

	if (fScreenX && fScreenY)
	{
		float fovX = *(float*)(cgArray + 0x131D68);
		float fovY = *(float*)(cgArray + 0x131D6C);

		*fScreenX = width * (1 - (vTransForm.x / fovX / vTransForm.z));
		*fScreenY = height * (1 - (vTransForm.y / fovY / vTransForm.z));
	}

	return vTransForm.z > 0;
}

ImColor text_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0);
ImColor enemy_colors = ImVec4(1.0f, 0.784f, 0.0f, 0.9);
ImColor friendly_colors = ImVec4(1.0f, 1.0f, 1.0f, 0.9);

int aim_type::min;

__int16 main::bones::j_neck;
__int16 main::bones::j_head;
__int16 main::bones::j_spineupper;
__int16 main::bones::j_spinelower;
__int16 main::bones::j_shoulder_le;
__int16 main::bones::j_shoulder_ri;
__int16 main::bones::j_elbow_ri;
__int16 main::bones::j_elbow_le;
__int16 main::bones::j_wrist_ri;
__int16 main::bones::j_wrist_le;
__int16 main::bones::j_knee_le;
__int16 main::bones::j_knee_ri;
__int16 main::bones::j_ankle_ri;
__int16 main::bones::j_ankle_le;
__int16 main::bones::j_hip_ri;
__int16 main::bones::j_hip_le;
__int16 main::bones::j_helmet;
__int16 main::bones::j_ball_ri;
__int16 main::bones::j_ball_le;
__int16 main::bones::j_eyeball_ri;
__int16 main::bones::j_eyeball_le;

float j_neckpos[1024][3];
float helmet_pos[1024][3];
float j_headpos[1024][3];
float j_spineupperpos[1024][3];
float j_spinelowerpos[1024][3];
float j_shoulder_lepos[1024][3];
float j_shoulder_ripos[1024][3];
float j_elbow_lepos[1024][3];
float j_elbow_ripos[1024][3];
float j_wrist_ripos[1024][3];
float j_wrist_lepos[1024][3];
float j_knee_lepos[1024][3];
float j_knee_ripos[1024][3];
float j_ankle_ripos[1024][3];
float j_ankle_lepos[1024][3];
float j_kneebuldge_le[1024][3];
float j_kneebuldge_ri[1024][3];
float j_hip_ri[1024][3];
float j_hip_le[1024][3];
float j_eyeball_ri[1024][3];
float j_eyeball_le[1024][3];
float j_ball_ri[1024][3];
float j_ball_le[1024][3];

float j_neckpos_screen[1024][3];
float j_headpos_screen[1024][3];
float j_spineupperpos_screen[1024][3];
float j_spinelowerpos_screen[1024][3];
float j_shoulder_lepos_screen[1024][3];
float j_shoulder_ripos_screen[1024][3];
float j_elbow_lepos_screen[1024][3];
float j_elbow_ripos_screen[1024][3];
float j_wrist_ripos_screen[1024][3];
float j_wrist_lepos_screen[1024][3];
float j_knee_lepos_screen[1024][3];
float j_knee_ripos_screen[1024][3];
float j_ankle_ripos_screen[1024][3];
float j_ankle_lepos_screen[1024][3];
float j_bodypos_screen[1024][3];
bool targeted[1024];

__int64 centity[1024];
__int16 type[1024];
float position[1024][3];
float players_head_pos[1024][3];
float bodyPos[1024][3];
float bestBonePos[1024][3] = { 10,10, 10 };
float bestBoneScreen[1024][2] = { 10, 10 };
float screen[1024][2] = { 10,10 };
float head_screen[1024][2] = { 10,10 };
char playername[1024][255];
bool valid[1024];
int health[1024];
bool team[1024];
float height[1024];
float width[1024];
float healthBar[1024][2];
float healthBar2[1024][2];

__int64 cg_EntitiesArray = 0;
__int64 cgArray = 0;
__int64 playerState = 0;
__int64 clientactive_t = 0;
__int64 clientinfo = 0;

bool main::funcs::WorldToScreen(vec3_t vWorldLocation, float* fScreenX, float* fScreenY);

void main::funcs::mainLoop();
