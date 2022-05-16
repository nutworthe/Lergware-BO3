#include "includes.h"
__int64 centity_location = ((DWORD64)GetModuleHandleA(NULL) + 0x7C4A5);
__int64 d2d = ((DWORD64)GetModuleHandleA(NULL) + 0x60F929);
__int64 cgArray_location = ((DWORD64)GetModuleHandleA(NULL) + 0x611145);
#define PI 3.14159265358979323846264338327950288
float best[3];

int frames_past = 0;

void main::hook::initializeHook() {

	Hooks hook;

	hook.Initialize();

	THREADENTRY32 te32;
	HANDLE hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

	if (hThreadSnap)
	{
		te32.dwSize = sizeof(THREADENTRY32);

		if (!Thread32First(hThreadSnap, &te32))
		{
			CloseHandle(hThreadSnap);
		}
		else {
			do
			{
				if (te32.th32OwnerProcessID == GetCurrentProcessId() && te32.th32ThreadID != GetCurrentThreadId())
				{
					HANDLE hThread = OpenThread(THREAD_GET_CONTEXT | THREAD_SET_CONTEXT | THREAD_SUSPEND_RESUME, 0, te32.th32ThreadID);
					if (hThread)
					{
						CONTEXT context;
						context.ContextFlags = CONTEXT_DEBUG_REGISTERS;
						SuspendThread(hThread);

						if (GetThreadContext(hThread, &context))
						{
							context.Dr0 = (uintptr_t)cgArray_location;
							context.Dr1 = (uintptr_t)centity_location;
							context.Dr2 = (uintptr_t)d2d;
							context.Dr3 = dwProcessBase + 0x143A606;
							context.Dr7 = (1 << 0) | (1 << 2) | (1 << 4) | (1 << 6);

							SetThreadContext(hThread, &context);
						}

						ResumeThread(hThread);
						CloseHandle(hThread);
					}
				}
			} while (Thread32Next(hThreadSnap, &te32));
			CloseHandle(hThreadSnap);
		}
	}
	SetUnhandledExceptionFilter(main::hook::hookHandler);
}

void clear(int i) {
	screen[i][0] = 0;
	screen[i][1] = 0;
	screen[i][2] = 0;

	head_screen[i][0] = 0;
	head_screen[i][1] = 0;
	head_screen[i][2] = 0;

	healthBar[i][0] = 0;
	healthBar[i][1] = 0;
	healthBar[i][2] = 0;
}

LONG CALLBACK main::hook::hookHandler(LPEXCEPTION_POINTERS ex)
{
	if (ex->ExceptionRecord->ExceptionCode == STATUS_SINGLE_STEP)
	{
		if (ex->ContextRecord->Rip == (uintptr_t)centity_location)
		{
			ex->ContextRecord->Rdi = ex->ContextRecord->Rcx;
			ex->ContextRecord->Rip = (uintptr_t)centity_location + 0x3;
			cg_EntitiesArray = (ex->ContextRecord->Rcx - (0x900 * 500));
		}
		else if (ex->ContextRecord->Rip == (uintptr_t)cgArray_location)
		{
			ex->ContextRecord->Rbx = ex->ContextRecord->Rbx + ex->ContextRecord->Rax;
			ex->ContextRecord->Rip = (uintptr_t)cgArray_location + 0x3;
			cgArray = ex->ContextRecord->Rbx;
			playerState = cgArray + 1157296;
		}
		else if (ex->ContextRecord->Rip == (uintptr_t)d2d)
		{
			ex->ContextRecord->Rbp = ex->ContextRecord->Rsp;

			if (cgArray > 0) {
				__int64 cgsArray = cgArray + 0x684E40;
				if (*(int*)(cgsArray + 444)) { //vote active
					char* voteString = (char*)(cgsArray + 456); //vote string
					int voteStringLength = strlen(voteString);
					for (int i = 0; i < voteStringLength; i++) {
						if ((i + 1) < voteStringLength) {
							if (voteString[i] == '^' && (voteString[i + 1] == 'H' || voteString[i + 1] == 'B' || voteString[i + 1] == 'I')) {
								voteString[i] = '&';
								ZeroMemory(voteString, strlen(voteString));
							}
						}
					}
				}
			}

			if (div_loop)
			{
				char buf_cmd[255];
				sprintf_s(buf_cmd, "%c %u %u", 120, 3, 120);
				SV_GameSendServerCommand(0, 1, buf_cmd);
			}

			if (ct)
			{
				GiveLootToSelf(0, 1, 1500);
			}

			if (inf_hatr)
			{
				*(DWORD*)(cgArray + 1159132) = 1;
			}

			if (no_recoil == true && cgArray > 0)
			{
				float* recoilarray = (float*)(cgArray + 2986256);
				recoilarray[0] = 0;
				recoilarray[1] = 0;
				float* kickAVel = (float*)(cgArray + 3044556);
				kickAVel[0] = 0;
				kickAVel[1] = 0;
				kickAVel[2] = 0;
			}

			clientactive_t = (__int64)(cgArray + 0x15CE0B0);

			clientinfo = (__int64)(cgArray + 0x2E7A40);

			RECT desktop;
			const HWND hDesktop = GetDesktopWindow();
			GetWindowRect(hDesktop, &desktop);
			vec2_t res = { desktop.right, desktop.bottom };

			int min = INT_MAX;
			int bestTarget = 0;
			best[0] = 0;
			best[1] = 0;
			best[2] = 0;

			if (cg_EntitiesArray > 0) {
				float ViewOrigin[3];
				CG_GetPlayerViewOrigin(0, playerState, ViewOrigin);
				for (int i = 0; i < 1024; i++) {
					centity[i] = cg_EntitiesArray + (0x900 * i);
					type[i] = *(__int16*)(centity[i] + 0x598);
					if (type[i] == 1 || type[i] == 18)
					{
						if (*(int*)(centity[i] + 0x8F4) > 1 && (*(DWORD*)(centity[i] + 0x3F8) != *(DWORD*)cgArray) && *(int*)((clientinfo + (0xED0 * *(DWORD*)(centity[i] + 0x3F8)) + 0xF4)) > -1) {

							clear(i);
							targeted[i] = false;
							valid[i] = true;

							__int64 DObj = main::funcs::Com_GetClientDObj(*(DWORD*)(centity[i] + 0x3F8), *(unsigned __int8*)(centity[i] + 2));
							float whatever1[255];
							if (DObj > 0) {
								main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_head, whatever1, players_head_pos[i], 0xFFFF);
								w2s(0, players_head_pos[i], head_screen[i]);

								main::funcs::CG_DObjGetWorldTagPosInternal(centity[i], DObj, main::bones::j_hip_ri, whatever1, bodyPos[i], 0xFFFF);
							}

							updateBones(i);

							if (CG_IsEntityFriendlyNotEnemy(0, centity[i]))
							{
								team[i] = true;
							}
							else {
								team[i] = false;
							}

							float x = *(float*)(centity[i] + 0x40);
							float y = *(float*)(centity[i] + 0x44);
							float z = *(float*)(centity[i] + 0x48);
							float world[3];
							world[0] = x;
							world[1] = y;
							world[2] = z;
							vec3_t tpos1;
							tpos1.x = world[0];
							tpos1.y = world[1];
							tpos1.z = world[2];
							WorldToScreen(tpos1, &screen[i][0], &screen[i][1]);

							world[2] = z + 65.f;

							vec3_t tpos11;
							tpos11.x = world[0];
							tpos11.y = world[1];
							tpos11.z = world[2];
							WorldToScreen(tpos11, &head_screen[i][0], &head_screen[i][1]);

							float w = (players_head_pos[i][1] - world[1]) / 2;

							world[2] = z - 2;

							vec3_t tpos12;
							tpos12.x = world[0];
							tpos12.y = world[1];
							tpos12.z = world[2];
							WorldToScreen(tpos12, &healthBar[i][0], &healthBar[i][1]);


							world[2] = z - 5;

							vec3_t tpos13;
							tpos13.x = world[0];
							tpos13.y = world[1];
							tpos13.z = world[2];
							WorldToScreen(tpos13, &healthBar2[i][0], &healthBar2[i][1]);

							height[i] = head_screen[i][1] - screen[i][1];
							width[i] = height[i] / 2;

							if (bone_type == 0)
							{
								bonescan(i, centity[i], bestBonePos[i]);
							}
							else if (bone_type == 1) {
								bestBonePos[i][0] = players_head_pos[i][0];
								bestBonePos[i][1] = players_head_pos[i][1];
								bestBonePos[i][2] = players_head_pos[i][2];
							}
							else if (bone_type == 2) {
								bestBonePos[i][0] = bodyPos[i][0];
								bestBonePos[i][1] = bodyPos[i][1];
								bestBonePos[i][2] = bodyPos[i][2];
							}
							else if (bone_type == 3) {
								customScan(i, centity[i], bestBonePos[i]);
							}

							if (visibility_check)
							{
								if (IsTargetVisible(0, centity[i], ViewOrigin, bestBonePos[i]) && !CG_IsEntityFriendlyNotEnemy(0, centity[i])) {
									if (aimbot_type == 0) {
										float distance = sqrtf((bestBonePos[i][0] - ViewOrigin[0]) * (bestBonePos[i][0] - ViewOrigin[0]) + (bestBonePos[i][1] - ViewOrigin[1]) * (bestBonePos[i][1] - ViewOrigin[1]) + (bestBonePos[i][2] - ViewOrigin[2]) * (bestBonePos[i][2] - ViewOrigin[2]));
										if (distance < min)
										{
											best[0] = bestBonePos[i][0];
											best[1] = bestBonePos[i][1];
											best[2] = bestBonePos[i][2];
											targeted[i] = true;
											bestTarget = i;
											min = distance;
										}
									}
									else if (aimbot_type == 1) {
										float dist1 = sqrt(pow(desktop.right / 2 - bestBonePos[i][0], 2) + pow(desktop.bottom / 2 - bestBonePos[i][1], 2));
										if (dist1 < min)
										{
											best[0] = bestBonePos[i][0];
											best[1] = bestBonePos[i][1];
											best[2] = bestBonePos[i][2];
											targeted[i] = true;
											bestTarget = i;
											min = dist1;
										}
									}
								}
							}
							else {
								if (!CG_IsEntityFriendlyNotEnemy(0, centity[i])) {
									if (aimbot_type == 0) {
										float distance = sqrtf((bestBonePos[i][0] - ViewOrigin[0]) * (bestBonePos[i][0] - ViewOrigin[0]) + (bestBonePos[i][1] - ViewOrigin[1]) * (bestBonePos[i][1] - ViewOrigin[1]) + (bestBonePos[i][2] - ViewOrigin[2]) * (bestBonePos[i][2] - ViewOrigin[2]));
										if (distance < min)
										{
											best[0] = bestBonePos[i][0];
											best[1] = bestBonePos[i][1];
											best[2] = bestBonePos[i][2];
											targeted[i] = true;
											bestTarget = i;
											min = distance;
										}
									}
									else if (aimbot_type == 1) {
										float dist1 = sqrt(pow(desktop.right / 2 - bestBonePos[i][0], 2) + pow(desktop.bottom / 2 - bestBonePos[i][1], 2));
										if (dist1 < min)
										{
											best[0] = bestBonePos[i][0];
											best[1] = bestBonePos[i][1];
											best[2] = bestBonePos[i][2];
											targeted[i] = true;
											bestTarget = i;
											min = dist1;
										}
									}
								}
							}

							for (int j = 0; j < 64; j++) {
								playername[i][j] = *(char*)((clientinfo + (0xED0 * *(DWORD*)(centity[i] + 0x3F8))) + (0xC + (0x1 * j)));
							}

							health[i] = *(int*)((clientinfo + (0xED0 * *(DWORD*)(centity[i] + 0x3F8)) + 0xF4));
							
						}
						else {
							valid[i] = false;
						}
					}
					else {
						valid[i] = false;
					}
				}
			}

			aimbot::aimbot(bestTarget, best);

			ex->ContextRecord->Rip = (uintptr_t)d2d + 0x3;
		}
		else if (ex->ContextRecord->Rip == dwProcessBase + 0x143A606)
		{
			ex->ContextRecord->Rsp -= 0x60;
			ex->ContextRecord->Rip += 4;

			const auto message{ reinterpret_cast<const char*>(ex->ContextRecord->R8) };
			const auto message_size{ ex->ContextRecord->R9 };
			instant_message::dispatch::handle_message(message, message_size);
		}

		return EXCEPTION_CONTINUE_EXECUTION;
	}

	std::ofstream myfile;
	myfile.open("D:\Program Files (x86)\Steam\steamapps\common\Call of Duty Black Ops III\lergware\logs\\UnhandledExceptions.txt", std::ios_base::app);
	myfile << "Exception at: " << ex->ContextRecord->Rip << "\n";
	myfile.close();

	return EXCEPTION_CONTINUE_SEARCH;
}