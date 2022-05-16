#include "includes.h"

XSESSION_INFO get_session_info(const InfoResponseLobby& lobby)
{
	XSESSION_INFO sess_info{};
	sess_info.sessionID = lobby.secId;
	sess_info.keyExchangeKey = lobby.secKey;
	sess_info.hostAddress = lobby.serializedAdr.xnaddr;

	return sess_info;
}

bool send_oob(const netadr_t& to, const std::string& data, const netsrc_t sock)
{
	return NET_OutOfBandPrint(sock, to, data.data());
}

bool should_ignore_msg(UINT msg)
{
    switch (msg)
    {
    case WM_MOUSEACTIVATE:
    case WM_MBUTTONDOWN:
    case WM_MBUTTONUP:
    case WM_MBUTTONDBLCLK:
    case WM_MOUSEMOVE:
    case WM_NCHITTEST:
    case WM_MOUSEWHEEL:
    case WM_MOUSEHOVER:
    case WM_ACTIVATEAPP:
    case WM_RBUTTONDOWN:
    case WM_RBUTTONUP:
    case WM_RBUTTONDBLCLK:
    case WM_KEYDOWN:
    case WM_KEYUP:
    case WM_CHAR:
    case WM_LBUTTONDOWN:
    case WM_LBUTTONUP:
    case WM_LBUTTONDBLCLK:
    case WM_SETCURSOR:
        return true;
    default:
        return false;
    }
}