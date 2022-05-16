#include "includes.h"
#include "font.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;


void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	io.Fonts->AddFontFromMemoryTTF(CustomFont, 1, 15.5);
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	const auto should_ignore{ menu::is_open() && !ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam) };

	if (should_ignore && should_ignore_msg(uMsg))
	{
		return true;
	}

	return CallWindowProcA(oWndProc, hWnd, uMsg, wParam, lParam);
}

HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!initialized)
	{
		if (!pDevice || !pContext)
		{
			ImGui::CreateContext();

			if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
			{
				pSwapChain->GetDevice(__uuidof(pDevice), (void**)&pDevice);
				pDevice->GetImmediateContext(&pContext);
			}


			DXGI_SWAP_CHAIN_DESC desc;
			pSwapChain->GetDesc(&desc);
			window = desc.OutputWindow;
			oWndProc = (WNDPROC)SetWindowLongPtr(desc.OutputWindow, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			friends::refresh_friends();

		}
		else
		{
			ID3D11Texture2D* pBackBuffer = nullptr;
			if (!mainRenderTargetView)
			{
				if (SUCCEEDED(pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<LPVOID*>(&pBackBuffer))))
				{
					pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &mainRenderTargetView);
					pBackBuffer->Release();
				}
			}
		}
	}

	if (GetAsyncKeyState(VK_INSERT) & 1)
	{
		open = !open;
	}

	if (GetAsyncKeyState(VK_F2) & 1)
	{
		Cbuf_AddText(0, "disconnect");
	}

	if (GetAsyncKeyState(VK_F3) & 1)
	{
		Cbuf_AddText(0, "quit");
	}

	ImGui::GetIO().MouseDrawCursor = menu::is_open();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	//ImGui::PushFont();

	menu::draw();

	overlay::draw();

	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	return oPresent(pSwapChain, SyncInterval, Flags);
}

uintptr_t GetDiscordModuleBase() {
	return (uintptr_t)GetModuleHandleA("DiscordHook64.dll");
}

VOID StartMeHook() {
	MH_Initialize();
	if (GetDiscordModuleBase() > 0) {
		auto presentSceneAdress = Helper::PatternScan(GetDiscordModuleBase(),
			"56 57 53 48 83 EC 30 44 89 C6");
		if (presentSceneAdress > 0) {
			if (MH_CreateHook((void*)presentSceneAdress, (void*)hkPresent, (void**)&oPresent) != MH_OK)
			{
				MessageBoxA(0, "Could not create hook!", "error", MB_OK);
				exit(0);
			}
			if (MH_EnableHook((void*)presentSceneAdress) != MH_OK)
			{
				MessageBoxA(0, "Could not enable hook!", "error", MB_OK);
				exit(0);
			}

		}
		else {
			MessageBoxA(0, "Could not find Discord Present!", "", MB_OK);
		}
	}
}



BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		main::hook::initializeHook();
		StartMeHook();
		main::bones::j_neck = main::funcs::RegisterTag((char*)"j_neck");
		main::bones::j_helmet = main::funcs::RegisterTag((char*)"j_helmet");
		main::bones::j_hip_le = main::funcs::RegisterTag((char*)"j_hip_ri");
		main::bones::j_hip_ri = main::funcs::RegisterTag((char*)"j_hip_le");
		main::bones::j_ball_ri = main::funcs::RegisterTag((char*)"j_ball_ri");
		main::bones::j_ball_le = main::funcs::RegisterTag((char*)"j_ball_le");
		main::bones::j_eyeball_ri = main::funcs::RegisterTag((char*)"j_eyeball_ri");
		main::bones::j_eyeball_le = main::funcs::RegisterTag((char*)"j_eyeball_le");
		main::bones::j_ball_le = main::funcs::RegisterTag((char*)"j_ball_le");
		main::bones::j_head = main::funcs::RegisterTag((char*)"j_head");
		main::bones::j_spineupper = main::funcs::RegisterTag((char*)"j_spineupper");
		main::bones::j_spinelower = main::funcs::RegisterTag((char*)"j_spinelower");
		main::bones::j_shoulder_le = main::funcs::RegisterTag((char*)"j_shoulder_le");
		main::bones::j_shoulder_ri = main::funcs::RegisterTag((char*)"j_shoulder_ri");
		main::bones::j_elbow_le = main::funcs::RegisterTag((char*)"j_elbow_le");
		main::bones::j_elbow_ri = main::funcs::RegisterTag((char*)"j_elbow_ri");
		main::bones::j_wrist_ri = main::funcs::RegisterTag((char*)"j_wrist_ri");
		main::bones::j_wrist_le = main::funcs::RegisterTag((char*)"j_wrist_le");
		main::bones::j_knee_le = main::funcs::RegisterTag((char*)"j_knee_le");
		main::bones::j_knee_ri = main::funcs::RegisterTag((char*)"j_knee_ri");
		main::bones::j_ankle_ri = main::funcs::RegisterTag((char*)"j_ankle_ri");
		main::bones::j_ankle_le = main::funcs::RegisterTag((char*)"j_ankle_le");
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

