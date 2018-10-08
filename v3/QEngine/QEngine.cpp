/////////////////////////////////////////////////////////////////////
//
// QEngine.cpp - main source file for the 
//               RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f QEngineps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>

#include "QEngine.h"
#include "QEngine_i.c"
#include "UnoCard.h"
#include "UnoHand.h"
#include "UnoPlayer.h"
#include "UnoPlayers.h"
#include "UnoDeck.h"
#include "UnoGame.h"
#include "UnoEngine.h"

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
    OBJECT_ENTRY(CLSID_UnoCard, CUnoCard)
    OBJECT_ENTRY(CLSID_UnoHand, CUnoHand)
    OBJECT_ENTRY(CLSID_UnoPlayer, CUnoPlayer)
    OBJECT_ENTRY(CLSID_UnoPlayers, CUnoPlayers)
    OBJECT_ENTRY(CLSID_UnoDeck, CUnoDeck)
    OBJECT_ENTRY(CLSID_UnoGame, CUnoGame)
    OBJECT_ENTRY(CLSID_UnoEngine, CUnoEngine)
END_OBJECT_MAP()


/////////////////////////////////////////////////////////////////////
//
// DllMain - It All Starts Here
//

extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/) {
    if (dwReason == DLL_PROCESS_ATTACH) {
        _Module.Init(ObjectMap, hInstance, &LIBID_QEngineLib);
        DisableThreadLibraryCalls(hInstance);
    } else if (dwReason == DLL_PROCESS_DETACH) {
        _Module.Term();
    }

    return TRUE;
}

STDAPI DllCanUnloadNow() {
    return (_Module.GetLockCount() == 0) ? S_OK : S_FALSE;
}

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv) {
    return _Module.GetClassObject(rclsid, riid, ppv);
}

STDAPI DllRegisterServer() {
    return _Module.RegisterServer(TRUE);
}

STDAPI DllUnregisterServer() {
    return _Module.UnregisterServer(TRUE);
}
