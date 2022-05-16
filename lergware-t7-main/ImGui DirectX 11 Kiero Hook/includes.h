#pragma once
#include <d3d11.h>
#include <d3d9.h>
#include <dxgi.h>
#include <windows.h>
#include <stdio.h>
#include <type_traits>
#include <string>
#include <tchar.h>
#include <iostream>
#include <vector>
#include <memory>
#include <intrin.h>
#include <algorithm>
#include <time.h>
#include <cmath>
#include <random>
#include <numeric>
#include <TlHelp32.h>
#include <future>
#include <mutex>
#include <regex>
#include <cmath>
#include <conio.h>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <tchar.h>
#include <type_traits>
#include <array>
#include <codecvt>
#include <filesystem>
#include <shellapi.h>
#include <cctype>
#include <csetjmp>
#include <sstream>
#include <filesystem>
#include "utils/json/nlohmann/json.hpp"
#include "Helper.h"

using namespace std::chrono_literals;
using namespace std::literals;

#include "libraries/minhook/include/MinHook.h"
#pragma comment(lib, "libraries/minhook/lib/libMinHook.x64.lib")

#include "libraries/detours/detours.h"
#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"

#include "utils/utils.hpp"
#include "utils/io.hpp"
#include "utils/nt.hpp"

#include "structs.h"

#include "friends/friends.hpp"
#include "exploit/exploit.hpp"
#include "instant_message/instant_message.hpp"
#include "hooks.h"
#include "defs.h"
#include "main.h"
#include "menu.h"
#include "overlay.h"

extern ImColor text_color;
extern ImColor enemy_colors;
extern ImColor friendly_colors;


typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;

bool WorldToScreen(vec3_t vWorldLocation, float* fScreenX, float* fScreenY);

namespace detail
{
	extern "C" void* _spoofer_stub();

	template <typename Ret, typename... Args>
	static inline auto shellcode_stub_helper(
		const void* shell,
		Args... args
	) -> Ret
	{
		auto fn = (Ret(*)(Args...))(shell);
		return fn(args...);
	}

	template <std::size_t Argc, typename>
	struct argument_remapper
	{
		// At least 5 params
		template<
			typename Ret,
			typename First,
			typename Second,
			typename Third,
			typename Fourth,
			typename... Pack
		>
			static auto do_call(
				const void* shell,
				void* shell_param,
				First first,
				Second second,
				Third third,
				Fourth fourth,
				Pack... pack
			) -> Ret
		{
			return shellcode_stub_helper<
				Ret,
				First,
				Second,
				Third,
				Fourth,
				void*,
				void*,
				Pack...
			>(
				shell,
				first,
				second,
				third,
				fourth,
				shell_param,
				nullptr,
				pack...
				);
		}
	};

	template <std::size_t Argc>
	struct argument_remapper<Argc, std::enable_if_t<Argc <= 4>>
	{
		// 4 or less params
		template<
			typename Ret,
			typename First = void*,
			typename Second = void*,
			typename Third = void*,
			typename Fourth = void*
		>
			static auto do_call(
				const void* shell,
				void* shell_param,
				First first = First{},
				Second second = Second{},
				Third third = Third{},
				Fourth fourth = Fourth{}
			) -> Ret
		{
			return shellcode_stub_helper<
				Ret,
				First,
				Second,
				Third,
				Fourth,
				void*,
				void*
			>(
				shell,
				first,
				second,
				third,
				fourth,
				shell_param,
				nullptr
				);
		}
	};
}
template <typename Ret, typename... Args>
static inline auto spoof_call(
	const void* trampoline,
	Ret(*fn)(Args...),
	Args... args
) -> Ret
{
	struct shell_params
	{
		const void* trampoline;
		void* function;
		void* rbx;
	};

	shell_params p{ trampoline, reinterpret_cast<void*>(fn) };
	using mapper = detail::argument_remapper<sizeof...(Args), void>;
	return mapper::template do_call<Ret, Args...>((const void*)&detail::_spoofer_stub, &p, args...);
}