#pragma once
#include "includes.h"
#include "common.h"

extern bool initialized;
extern bool open;

extern DWORD64 exc;

struct Vector3D
{
	float x, y, z;
};
struct Vector2D
{
	float x, y;
};

#include <cstdint>
extern __int64 cg_EntitiesArray;
extern __int64 cgArray;
extern __int64 playerState;
extern __int64 clientactive_t;
extern __int64 clientinfo;
extern __int64 centity[1024];
extern __int16 type[1024];
extern float position[1024][3];
extern float players_head_pos[1024][3];
extern float bestBonePos[1024][3];
extern float bestBoneScreen[1024][2];
extern float screen[1024][2];
extern float head_screen[1024][2];
extern char playername[1024][255];
extern bool valid[1024];
extern int health[1024];
extern int healthHeight[1024];
extern bool team[1024];
extern float height[1024];
extern float width[1024];
extern float healthBar[1024][2];
extern float healthBar2[1024][2];
extern float bodyPos[1024][3];
extern bool targeted[1024];

extern float j_neckpos[1024][3];
extern float j_headpos[1024][3];
extern float j_eyeball_le[1024][3];
extern float j_eyeball_ri[1024][3];
extern float j_spineupper[1024][3];
extern float j_spinelower[1024][3];
extern float j_shoulder_le[1024][3];
extern float j_shoulder_ri[1024][3];
extern float j_headpos[1024][3];
extern float j_spineupperpos[1024][3];
extern float j_spinelowerpos[1024][3];
extern float j_shoulder_lepos[1024][3];
extern float j_shoulder_ripos[1024][3];
extern float j_elbow_lepos[1024][3];
extern float j_elbow_ripos[1024][3];
extern float j_wrist_ripos[1024][3];
extern float j_wrist_lepos[1024][3];
extern float j_knee_lepos[1024][3];
extern float j_knee_ripos[1024][3];
extern float j_kneebuldge_le[1024][3];
extern float j_kneebuldge_ri[1024][3];
extern float j_ankle_ripos[1024][3];
extern float j_ankle_lepos[1024][3];
extern float j_hip_le[1024][3];
extern float j_hip_ri[1024][3];
extern float j_ball_le[1024][3];
extern float j_ball_ri[1024][3];
extern float helmet_pos[1024][3];

extern float j_neckpos_screen[1024][3];
extern float j_headpos_screen[1024][3];
extern float j_spineupperpos_screen[1024][3];
extern float j_spinelowerpos_screen[1024][3];
extern float j_shoulder_lepos_screen[1024][3];
extern float j_shoulder_ripos_screen[1024][3];
extern float j_elbow_lepos_screen[1024][3];
extern float j_elbow_ripos_screen[1024][3];
extern float j_wrist_ripos_screen[1024][3];
extern float j_wrist_lepos_screen[1024][3];
extern float j_knee_lepos_screen[1024][3];
extern float j_knee_ripos_screen[1024][3];
extern float j_ankle_ripos_screen[1024][3];
extern float j_ankle_lepos_screen[1024][3];
extern float j_bodypos_screen[1024][3];
extern float helmet_pos_screen[1024][3];

struct vec3_t
{
	float x, y, z;
};

struct vec2_t
{
	float x, y;
};

namespace aim_type 
{
	extern int min;
}

namespace aimbot
{
	void aimbot(int i, float* best);
}

namespace main {
	extern const void* spoof_t;

	namespace main_menu 
	{
		void draw();
	}

	namespace hook {
		LONG CALLBACK hookHandler(EXCEPTION_POINTERS* ex);
		void initializeHook();
	}

	namespace funcs {
		extern bool WorldToScreen(vec3_t vWorldLocation, float* fScreenX, float* fScreenY);
		extern void mainLoop();

		const static auto UI_FillRectPhysical = reinterpret_cast<std::uintptr_t(__fastcall*)(float x, float y, float width, float height, float* color)>((DWORD64)GetModuleHandleA(NULL) + 0x2289650);
		const static auto WorldPosToScreenPos = reinterpret_cast<std::uintptr_t(__fastcall*)(int localClientNum, float* worldPos, float* out)>((DWORD64)GetModuleHandleA(NULL) + 0x574140);
		const static auto LiveStats_SetClanTagText = reinterpret_cast<std::uintptr_t(__fastcall*)(int localClientNum, const char* clanName)>((DWORD64)GetModuleHandleA(NULL) + 0x1EA5510);
		const static auto Cbuf_AddText = reinterpret_cast<std::uintptr_t(__fastcall*)(unsigned int clientNum, const char* command)>((DWORD64)GetModuleHandleA(NULL) + 0x135D4C0);
		const static auto Com_GetClientDObj = reinterpret_cast<std::uintptr_t(__fastcall*)(int a1, int a2)>((DWORD64)GetModuleHandleA(NULL) + 0x214EBA0);
		const static auto CG_DObjGetWorldTagPosInternal = reinterpret_cast<std::uintptr_t(__fastcall*)(__int64 centity, __int64 DObj, int tag, float* whatever, float* pos, int something)>((DWORD64)GetModuleHandleA(NULL) + 0x1ABCF0);
		const static auto AimTarget_GetTagPos = reinterpret_cast<std::uintptr_t(__fastcall*)(__int64 centity, unsigned int tagName, float* out)>((DWORD64)GetModuleHandleA(NULL) + 0x7C480);
		const static auto CL_GetLocalClientGlobals = reinterpret_cast<std::uintptr_t(__fastcall*)(int localClientNum)>((DWORD64)GetModuleHandleA(NULL) + 0x71BD0);
		const static auto AimTarget_IsTargetVisible = reinterpret_cast<std::uintptr_t(__fastcall*)(int localClientNum, __int64 centity)>((DWORD64)GetModuleHandleA(NULL) + 0x7E4A0);
		const static auto CG_DObjGetWorldTagPos = reinterpret_cast<std::uintptr_t(__fastcall*)(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5, int a6)>((DWORD64)GetModuleHandleA(NULL) + 0x1F0000);
		const static auto RegisterTag = reinterpret_cast<std::uintptr_t(__fastcall*)(char* tag)>((DWORD64)GetModuleHandleA(NULL) + 0x1A83520);
	}

	namespace bones 
	{
		extern __int16 j_neck;
		extern __int16 j_head;
		extern __int16 j_spineupper;
		extern __int16 j_spinelower;
		extern __int16 j_shoulder_le;
		extern __int16 j_shoulder_ri;
		extern __int16 j_elbow_le;
		extern __int16 j_elbow_ri;
		extern __int16 j_wrist_ri;
		extern __int16 j_wrist_le;
		extern __int16 j_knee_le;
		extern __int16 j_knee_ri;
		extern __int16 j_ankle_ri;
		extern __int16 j_ankle_le;
		extern __int16 j_helmet;
		extern __int16 j_hip_ri;
		extern __int16 j_hip_le;
		extern __int16 j_ball_ri;
		extern __int16 j_ball_le;
		extern __int16 j_eyeball_ri;
		extern __int16 j_eyeball_le;
	}
}

bool IsTargetVisible(int localClientNum, __int64 centity, float* start, float* end);
bool CG_GetPlayerViewOrigin(unsigned int localClientNum, __int64 playerstate, float* origin);
bool w2s(int localClientNum, float* worldPos, float* out);
bool CG_IsEntityFriendlyNotEnemy(int localClientNum, __int64 centity);
Vector2D CalcAngles(Vector3D src, Vector3D dest, Vector3D ViewAxis[3]);
void bonescan(int i, __int64 centity_t, float bestpos[3]);
void customScan(int i, __int64 centity_t, float bestpos[3]);
void updateBones(int i);
bool send_oob(const netadr_t& to, const std::string& data, const netsrc_t sock = NS_SERVER);
XSESSION_INFO get_session_info(const InfoResponseLobby& lobby);
bool should_ignore_msg(UINT msg);

template <typename T>
static void set(void* place, T value)
{
	DWORD old_protect;
	VirtualProtect(place, sizeof(T), PAGE_EXECUTE_READWRITE, &old_protect);

	*static_cast<T*>(place) = value;

	VirtualProtect(place, sizeof(T), old_protect, &old_protect);
	FlushInstructionCache(GetCurrentProcess(), place, sizeof(T));
}

template <typename T>
static void set(const size_t place, T value)
{
	return set<T>(reinterpret_cast<void*>(place), value);
}
