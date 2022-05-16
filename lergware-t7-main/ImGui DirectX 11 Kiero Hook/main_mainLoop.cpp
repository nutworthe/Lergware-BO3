#include "includes.h"
void updateBones(int i)
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
		w2s(0, j_headpos[i], head_screen[i]);
		w2s(0, j_neckpos[i], j_neckpos_screen[i]);
		w2s(0, j_shoulder_lepos[i], j_shoulder_lepos_screen[i]);
		w2s(0, j_shoulder_ripos[i], j_shoulder_ripos_screen[i]);
		w2s(0, j_spineupperpos[i], j_spineupperpos_screen[i]);
		w2s(0, j_spinelowerpos[i], j_spinelowerpos_screen[i]);
		w2s(0, j_elbow_lepos[i], j_elbow_lepos_screen[i]);
		w2s(0, j_elbow_ripos[i], j_elbow_ripos_screen[i]);
		w2s(0, j_wrist_ripos[i], j_wrist_ripos_screen[i]);
		w2s(0, j_wrist_lepos[i], j_wrist_lepos_screen[i]);
		w2s(0, j_knee_lepos[i], j_knee_lepos_screen[i]);
		w2s(0, j_knee_ripos[i], j_knee_ripos_screen[i]);
		w2s(0, j_ankle_lepos[i], j_ankle_lepos_screen[i]);
		w2s(0, j_ankle_ripos[i], j_ankle_ripos_screen[i]);
	}
}