#include "common.h"

std::vector<std::string> vec;

//bool tr;
//bool tp;

//CORE
bool menurgb = false;

float flHue;

//ESP
bool enemy_active;
bool friendly_active;
bool rgb_enemy;
bool rgb_friendly;
bool unfilled_boxes;
bool filled_boxes;
bool skeleton_esp;
bool player_names;
bool corner_esp;
bool Healthbars;
bool Snaplines;
bool crosshair;

int speed_sel;

float rgb_speed = 1;
float boldness = 1.5f;

const char* speed_selection[] = { "Slow", "Medium", "Fast", "Hyper" };

//AIMBOT
bool aimbot_active;
bool visibility_check;
bool ads_check;
bool no_recoil;
bool selected[21];

int bone_type;
int aimbot_type;

const char* boneSel[]{

    "j_ball_le",
    "j_ball_ri",
    "j_ankle_le",
    "j_ankle_ri",
    "j_wrist_le",
    "j_wrist_ri",
    "j_elbow_le",
    "j_elbow_ri",
    "j_knee_le",
    "j_knee_ri",
    "j_hip_le",
    "j_hip_ri",
    "j_shoulder_le",
    "j_shoulder_ri",
    "j_spineupper",
    "j_spinelower",
    "j_eyeball_le",
    "j_eyeball_ri",
    "j_neck",
    "j_head",
    "j_helmet"

};

//MISC
bool div_loop;
bool inf_hatr;
bool ct;
bool start_pos_set = false;
bool session = false;
bool party = false;
bool Name = false;
bool Xuid = false;
bool ItemID = false;
bool list = false;
bool player = false;
bool Config = false;

char buf[255];
char print_bold[1012];
char clan_input[5] = { 0 };
char name_input[32] = { 0 };
char xuid_lookup_input[20] = { 0 };
char name_lookup_input[32] = { 0 };
char player_list[32] = { 0 };
char join_input[32] = { 0 };
char callvote_input[10000] = { 0 };
char crash_input[32] = { 0 };
char popup_input[32] = { 0 };
char oob_input[32] = { 0 };
char reliable_input[5000] = { 0 };
char single_input[5000] = { 0 };
char cbuf_input[5000] = { 0 };
char slot_input[50] = { 0 };
char steamid_input[50] = { 0 };
char spoofName[32]{};
char nameBuffer[32]{};

int c = 0;
int clicked = 0;
int value = 0;
int value2 = 0;
int frames = 10;
int serverID = 0;
int itemID = 0;
int crypto;
int div_amount;
int count1 = 12;
int count2 = 4;


//GAME FUNCTIONS
std::uintptr_t dwProcessBase = reinterpret_cast<std::uintptr_t>(GetModuleHandleA(nullptr));

LootT GiveLootToSelf = (LootT)(dwProcessBase + 0x1E82CE0);
BG_UnlockablesIsItemLockedFromBufferT BG_UnlockablesIsItemLockedFromBuffer = (BG_UnlockablesIsItemLockedFromBufferT)(dwProcessBase + 0x26A9C90);
BG_UnlockablesItemOptionLockedT BG_UnlockablesItemOptionLocked = (BG_UnlockablesItemOptionLockedT)(dwProcessBase + 0x26AB280);
CL_GetRankForXPT CL_GetRankForXP = (CL_GetRankForXPT)(dwProcessBase + 0x13CA880);
Com_SessionMode_IsPublicOnlineGameT Com_SessionMode_IsPublicOnlineGame = (Com_SessionMode_IsPublicOnlineGameT)(dwProcessBase + 0x20F7EE0);
LiveStorage_UploadStatsForControllerT LiveStorage_UploadStatsForController = (LiveStorage_UploadStatsForControllerT)(dwProcessBase + 0x1EC0DC0);
sub_7FF641E596F0T sub_7FF641E596F0 = (sub_7FF641E596F0T)(dwProcessBase + 0x1EA96F0);
sub_7FF641E597C0T sub_7FF641E597C0 = (sub_7FF641E597C0T)(dwProcessBase + 0x1EA97C0);
WorldPosToScreenPosT WorldPosToScreenPos = (WorldPosToScreenPosT)(dwProcessBase + 0x574140);
AimTarget_GetTagPosT AimTarget_GetTagPos = (AimTarget_GetTagPosT)(dwProcessBase + 0x7C480);
CL_GetLocalClientGlobalsT CL_GetLocalClientGlobals = (CL_GetLocalClientGlobalsT)(dwProcessBase + 0x71BD0);
AimTarget_IsTargetVisibleT AimTarget_IsTargetVisible = (AimTarget_IsTargetVisibleT)(dwProcessBase + 0x7E4A0);
CG_DObjGetWorldTagPosT CG_DObjGetWorldTagPos = (CG_DObjGetWorldTagPosT)(dwProcessBase + 0x1F0000);
RegisterTagT RegisterTag = (RegisterTagT)(dwProcessBase + 0x1A83520);
GameSendServerCommandT SV_GameSendServerCommand = (GameSendServerCommandT)(dwProcessBase + 0x224FFE0);
CG_DObjGetWorldTagPosInternalT CG_DObjGetWorldTagPosInternal = (CG_DObjGetWorldTagPosInternalT)(dwProcessBase + 0x1ABCF0);
GScr_SetDStatT GScr_SetDStat = (GScr_SetDStatT)(dwProcessBase + 0x15F21F0);
Com_GetClientDObjT Com_GetClientDObj = (Com_GetClientDObjT)(dwProcessBase + 0x214EBA0);
SV_ExecuteClientCommandT SV_ExecuteClientCommand = (SV_ExecuteClientCommandT)(dwProcessBase + 0x224ADE0);
LiveStats_GetRootDDLStateT LiveStats_GetRootDDLState = (LiveStats_GetRootDDLStateT)(dwProcessBase + 0x1EA9760);
Pub_GameT Pub_Game = (Pub_GameT)(dwProcessBase + 0x20F7EE0);

DDL_MoveToPathT DDL_MoveToPath = (DDL_MoveToPathT)(dwProcessBase + 0x2523030);
DDL_SetUIntT DDL_SetUInt = (DDL_SetUIntT)(dwProcessBase + 0x2523530);
DDL_GetUIntT DDL_GetUInt = (DDL_GetUIntT)(dwProcessBase + 0x2522AF0);


GetSessionStateT GetSessionState = (GetSessionStateT)(dwProcessBase + 0x20F7790);

tGetPersonaName oGetPersonaName;
tLiveSteam_FilterPersonaName oLiveSteam_FilterPersonaName = (tLiveSteam_FilterPersonaName)(dwProcessBase + 0x1EB0350);
DWORD_PTR pGetPersonaNameReturn = dwProcessBase + 0x1EB0E7C;
DWORD_PTR ISteamFriends = *(DWORD_PTR*)(dwProcessBase + 0x10BBEBA0);
DWORD_PTR pUserData = dwProcessBase + 0x14FB5420;
DWORD_PTR pNameBuffer = dwProcessBase + 0x15E86638;