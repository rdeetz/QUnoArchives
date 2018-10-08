/////////////////////////////////////////////////////////////////////
//
// QUno.cpp - main source file for the 
//            RogCorp QUno 3.0 user interface
//
// Copyright © 2000-2001 Roger Deetz
//

// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f QUnops.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>

#include "QUno.h"
#include "QUno_i.c"

#include "App.h"
#include "GameManager.h"
#include "QDialogs.h"

// these need to be here for the linker
#include "QEngine\QEngine_i.c"
#include "QControl\QControl_i.c"

const DWORD dwTimeOut = 5000; // time for EXE to be idle before shutting down
const DWORD dwPause = 1000; // time to wait for threads to finish up

static DWORD WINAPI MonitorProc(void* pv) {
    CExeModule* p = (CExeModule*)pv;
    p->MonitorShutdown();

    return 0;
}

bool CExeModule::StartMonitor() {
    m_hEventShutdown = CreateEvent(NULL, false, false, NULL);

    if (m_hEventShutdown == NULL) {
        return false;
    }

    DWORD dwID;
    HANDLE h = CreateThread(NULL, 0, MonitorProc, this, 0, &dwID);

    return (h != NULL);
}

void CExeModule::MonitorShutdown() {
    while (true) {
        WaitForSingleObject(m_hEventShutdown, INFINITE);

        DWORD dwWait = 0;

        do {
            m_bActivity = false;
            dwWait = WaitForSingleObject(m_hEventShutdown, dwTimeOut);
        } while (dwWait == WAIT_OBJECT_0);

        // timed out... if no activity let's really bail
        if (!m_bActivity && (m_nLockCnt == 0)) {
#if _WIN32_WINNT >= 0x0400 & defined(_ATL_FREE_THREADED)
            CoSuspendClassObjects();

            if (!m_bActivity && (m_nLockCnt == 0))
#endif
                break;
        }
    }

    CloseHandle(m_hEventShutdown);

    PostThreadMessage(m_dwThreadID, WM_QUIT, 0, 0);

    return;
}

LONG CExeModule::Unlock() {
    LONG l = CComModule::Unlock();

    if (l == 0) {
        m_bActivity = true;
        SetEvent(m_hEventShutdown); // tell monitor that we transitioned to zero
    }

    return l;
}

CExeModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
END_OBJECT_MAP()

// helper function to parse command line
LPCTSTR FindOneOf(LPCTSTR p1, LPCTSTR p2) {
    while ((p1 != NULL) && (*p1 != NULL)) {
        LPCTSTR p = p2;

        while ((p != NULL) && (*p != NULL)) {
            if (*p1 == *p) {
                return CharNext(p1);
            }

            p = CharNext(p);
        }

        p1 = CharNext(p1);
    }

    return NULL;
}

// handles GPFs gracefully
LONG ProcessException(_EXCEPTION_POINTERS* lpExceptionInfo)
{
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);

    CExceptionDlg dlg;
    dlg.DoModal(GetDesktopWindow());

    SetUnhandledExceptionFilter(NULL);

    g_App.End();

    return EXCEPTION_EXECUTE_HANDLER;
}

// the one and only Application object and Game Manager object
CApp g_App;
CGameManager g_GameManager;


/////////////////////////////////////////////////////////////////////
//
// WinMain - It All Starts Here
//

extern "C" int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpCmdLine, int nCmdShow) {
    //lpCmdLine = GetCommandLine(); // this line is required for _ATL_MIN_CRT (i'm not using that)

#if _WIN32_WINNT >= 0x0400 & defined(_ATL_FREE_THREADED)
    HRESULT hRes = CoInitializeEx(NULL, COINIT_MULTITHREADED);
#else
    HRESULT hRes = CoInitialize(NULL);
#endif

    _ASSERTE(SUCCEEDED(hRes));

    _Module.Init(ObjectMap, hInstance, &LIBID_QUnoLib);
    _Module.m_dwThreadID = GetCurrentThreadId();

    TCHAR szTokens[] = _T("-/");

    int nRet = 0;
    bool bRun = true;

    LPCTSTR lpszToken = FindOneOf(lpCmdLine, szTokens);

    while (lpszToken != NULL) {
        if (lstrcmpi(lpszToken, _T("UnregServer")) == 0) {
            _Module.UpdateRegistryFromResource(IDR_QUno, FALSE);
            nRet = _Module.UnregisterServer(TRUE);
            bRun = false;

            break;
        }

        if (lstrcmpi(lpszToken, _T("RegServer")) == 0) {
            _Module.UpdateRegistryFromResource(IDR_QUno, TRUE);
            nRet = _Module.RegisterServer(TRUE);
            bRun = false;

            break;
        }

        lpszToken = FindOneOf(lpszToken, szTokens);
    }

#ifndef _DEBUG
    // set up the custom top-level exception handler
    SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ProcessException);
#endif

    if (bRun) {
        _Module.StartMonitor();

#if _WIN32_WINNT >= 0x0400 & defined(_ATL_FREE_THREADED)
        hRes = _Module.RegisterClassObjects(CLSCTX_LOCAL_SERVER, REGCLS_MULTIPLEUSE | REGCLS_SUSPENDED);

        _ASSERTE(SUCCEEDED(hRes));

        hRes = CoResumeClassObjects();
#else
        hRes = _Module.RegisterClassObjects(CLSCTX_LOCAL_SERVER, REGCLS_MULTIPLEUSE);
#endif
        _ASSERTE(SUCCEEDED(hRes));

        bool bStart = g_App.Start(lpCmdLine);

        if (bStart) {
            MSG msg;

            while (GetMessage(&msg, 0, 0, 0)) {
                if (!g_App.PreTranslateAccelerator(&msg)) {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
            }
        }

        g_App.End();

        _Module.RevokeClassObjects();

        Sleep(dwPause); // wait (poorly) for any threads to finish
    }

#ifndef _DEBUG
    // revoke the custom top-level exception handler
    SetUnhandledExceptionFilter(NULL);
#endif

    _Module.Term();

    CoUninitialize();

    return nRet;
}
