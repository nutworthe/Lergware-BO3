#include "includes.h"
Hooks hooks;

__int64 hLiveSteam_FilterPersonaName(char* buffer, int size, char asciionly)
{
    Unhook(oLiveSteam_FilterPersonaName, hLiveSteam_FilterPersonaName);
    return 0;
}

char* hGetPersonaName(DWORD_PTR _this)
{
    if (spoofName[0] != 0)
    {
        if ((DWORD_PTR)_ReturnAddress() == pGetPersonaNameReturn)
        {
            Hook(oLiveSteam_FilterPersonaName, hLiveSteam_FilterPersonaName);
        }

        return spoofName;
    }

    return oGetPersonaName(_this);
}

void Hooks::Initialize()
{
    oGetPersonaName = (tGetPersonaName)HookVMT(ISteamFriends, (DWORD_PTR)&hGetPersonaName, 0);
}

