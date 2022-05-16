#pragma once
namespace Helper {
	uintptr_t PatternScan(uintptr_t moduleAdress, const char* signature);
}

bool should_ignore_msg(UINT msg);