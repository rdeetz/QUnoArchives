/////////////////////////////////////////////////////////////////////
//
// QControl.cpp - main source file for the 
//                RogCorp QControls Library 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f QControlps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>

#include "QControl.h"
#include "QControl_i.c"
#include "UnoCardView.h"

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
    OBJECT_ENTRY(CLSID_UnoCardView, CUnoCardView)
END_OBJECT_MAP()


/////////////////////////////////////////////////////////////////////
//
// DllMain - It All Starts Here
//

extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/) {
    if (dwReason == DLL_PROCESS_ATTACH) {
        _Module.Init(ObjectMap, hInstance, &LIBID_QControlLib);
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
