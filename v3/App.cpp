/////////////////////////////////////////////////////////////////////
//
// App.cpp - implementation of the application object for the 
//           RogCorp QUno 3.0 user interface
//
// Copyright © 2000-2001 Roger Deetz
//

#include "stdafx.h"
#include "App.h"
#include "QGlobal.h"
#include "GameManager.h"
#include "QDialogs.h"

CApp::CApp() {

}

CApp::~CApp() {

}

bool CApp::Start(LPTSTR lpCmdLine) {
    g_GameManager.Initialize();

    // TODO: this might need to come later (like after the window is up)
    g_GameManager.Open(lpCmdLine);

    RECT rc;
    int nCmdShow;
    LoadWindowSettings(rc, nCmdShow);

    TCHAR szWindowTitle[MAX_PATH];
    BuildWindowTitle(szWindowTitle);

    m_wndMainFrame.Create(GetDesktopWindow(), rc, szWindowTitle, 0, WS_EX_CLIENTEDGE);
    m_wndMainFrame.ShowWindow(nCmdShow);

    LoadHelpSettings();

    if (m_bShowQuickHints) {
        CQuickHintDlg dlg;
        dlg.DoModal();
    }

    return true;
}

void CApp::End() {
    if (m_wndMainFrame.m_hWnd) {
        if (m_wndMainFrame.IsWindow()) {
            if (m_wndMainFrame.IsZoomed()) {
                SaveWindowSettings(NULL, SW_SHOWMAXIMIZED);
            } else if (m_wndMainFrame.IsIconic()) {
                SaveWindowSettings(NULL, SW_SHOWNORMAL);
            } else {
                RECT rc;
                m_wndMainFrame.GetWindowRect(&rc);
                SaveWindowSettings(&rc, SW_SHOWNORMAL);
            }

            m_wndMainFrame.DestroyWindow();
        }
    }

    SaveHelpSettings();

    g_GameManager.Terminate();

    return;
}

void CApp::Quit() {
    PostQuitMessage(0);

    return;
}

void CApp::GetLocalHelpFile(LPTSTR lpLocalHelpFile) {
    lstrcpy(lpLocalHelpFile, m_szLocalHelpFile);

    return;
}

void CApp::GetRogCorpURL(LPTSTR lpRogCorpURL) {
    lstrcpy(lpRogCorpURL, m_szRogCorpURL);

    return;
}

bool CApp::GetShowQuickHints() {
    return m_bShowQuickHints;
}

void CApp::SetShowQuickHints(bool bShowQuickHints) {
    m_bShowQuickHints = bShowQuickHints;

    return;
}

// this is called by GameManager when the game title has changed
void CApp::UpdateWindowTitle() {
    TCHAR szWindowTitle[MAX_PATH];
    BuildWindowTitle(szWindowTitle);

    if (m_wndMainFrame.m_hWnd) {
        m_wndMainFrame.SetWindowText(szWindowTitle);
    }

    return;
}

int CApp::PreTranslateAccelerator(LPMSG lpMsg) {
    return m_wndMainFrame.PreTranslateAccelerator(lpMsg);
}

void CApp::BuildWindowTitle(LPTSTR lpWindowTitle) {
    TCHAR szTitle[MAX_PATH];
    LoadString(_Module.m_hInstResource, IDS_MAINFRAMETITLE, szTitle, MAX_PATH);

    TCHAR szWindowTitle[MAX_PATH];
    lstrcpy(szWindowTitle, szTitle);

    TCHAR szGameTitle[MAX_PATH];
    g_GameManager.GetGameTitle(szGameTitle, false);

    if (lstrlen(szGameTitle) > 0) {
        lstrcat(szWindowTitle, Q_GAME_SEPARATOR);
        lstrcat(szWindowTitle, szGameTitle);
    }

    lstrcpy(lpWindowTitle, szWindowTitle);

    return;
}

void CApp::LoadWindowSettings(RECT& rc, int& nCmdShow) {
    if (GetSystemMetrics(SM_CXSCREEN) > Q_TARGET_HORIZRES) {
        rc.left = Q_WINDOW_HIDEFAULT_LEFT;
        rc.top = Q_WINDOW_HIDEFAULT_TOP;
        rc.right = Q_WINDOW_HIDEFAULT_RIGHT;
        rc.bottom = Q_WINDOW_HIDEFAULT_BOTTOM;
    } else {
        rc.left = Q_WINDOW_LODEFAULT_LEFT;
        rc.top = Q_WINDOW_LODEFAULT_TOP;
        rc.right = Q_WINDOW_LODEFAULT_RIGHT;
        rc.bottom = Q_WINDOW_LODEFAULT_BOTTOM;
    }

    nCmdShow = SW_SHOWNORMAL;

    TCHAR szWindowKey[MAX_PATH] = Q_REGISTRY_KEY_ROOT;
    lstrcat(szWindowKey, Q_REGISTRY_KEY_WINDOW);

    CRegKey reg;
    LONG lResult = reg.Create(HKEY_CURRENT_USER, szWindowKey);

    if (lResult == ERROR_SUCCESS) {
        DWORD dwLeft;
        lResult = reg.QueryValue(dwLeft, Q_REGISTRY_VALUE_WINDOWLEFT);

        if (lResult == ERROR_SUCCESS) {
            rc.left = dwLeft;
        }

        DWORD dwTop;
        lResult = reg.QueryValue(dwTop, Q_REGISTRY_VALUE_WINDOWTOP);

        if (lResult == ERROR_SUCCESS) {
            rc.top = dwTop;
        }

        DWORD dwRight;
        lResult = reg.QueryValue(dwRight, Q_REGISTRY_VALUE_WINDOWRIGHT);

        if (lResult == ERROR_SUCCESS) {
            rc.right = dwRight;
        }

        DWORD dwBottom;
        lResult = reg.QueryValue(dwBottom, Q_REGISTRY_VALUE_WINDOWBOTTOM);

        if (lResult == ERROR_SUCCESS) {
            rc.bottom = dwBottom;
        }

        DWORD dwCmdShow;
        lResult = reg.QueryValue(dwCmdShow, Q_REGISTRY_VALUE_WINDOWSTATE);

        if (lResult == ERROR_SUCCESS) {
            nCmdShow = dwCmdShow;
        }
    }

    return;
}

void CApp::SaveWindowSettings(LPRECT lprc, int nCmdShow) {
    TCHAR szWindowKey[MAX_PATH] = Q_REGISTRY_KEY_ROOT;
    lstrcat(szWindowKey, Q_REGISTRY_KEY_WINDOW);

    CRegKey reg;
    LONG lResult = reg.Create(HKEY_CURRENT_USER, szWindowKey);

    if (lResult == ERROR_SUCCESS) {
        if (lprc != NULL) {
            lResult = reg.SetValue(lprc->left, Q_REGISTRY_VALUE_WINDOWLEFT);
            lResult = reg.SetValue(lprc->top, Q_REGISTRY_VALUE_WINDOWTOP);
            lResult = reg.SetValue(lprc->right, Q_REGISTRY_VALUE_WINDOWRIGHT);
            lResult = reg.SetValue(lprc->bottom, Q_REGISTRY_VALUE_WINDOWBOTTOM);
        }

        lResult = reg.SetValue(nCmdShow, Q_REGISTRY_VALUE_WINDOWSTATE);
    }

    return;
}

void CApp::LoadHelpSettings() {
    lstrcpy(m_szLocalHelpFile, _T(""));
    lstrcpy(m_szRogCorpURL, _T(""));
    m_bShowQuickHints = true;

    TCHAR szHelpKey[MAX_PATH] = Q_REGISTRY_KEY_ROOT;
    lstrcat(szHelpKey, Q_REGISTRY_KEY_HELP);

    CRegKey reg;
    LONG lResult = reg.Create(HKEY_CURRENT_USER, szHelpKey);

    if (lResult == ERROR_SUCCESS) {
        TCHAR szTemp[MAX_PATH];
        DWORD dwTempLen = MAX_PATH;
        lResult = reg.QueryValue(szTemp, Q_REGISTRY_VALUE_LOCALHELPFILE, &dwTempLen);

        if (lResult == ERROR_SUCCESS) {
            lstrcpy(m_szLocalHelpFile, szTemp);
        }

        szTemp[0] = NULL;
        dwTempLen = MAX_PATH;
        lResult = reg.QueryValue(szTemp, Q_REGISTRY_VALUE_ROGCORPURL, &dwTempLen);

        if (lResult == ERROR_SUCCESS) {
            lstrcpy(m_szRogCorpURL, szTemp);
        }

        DWORD dwShowQuickHints;
        lResult = reg.QueryValue(dwShowQuickHints, Q_REGISTRY_VALUE_SHOWQUICKHINTS);

        if (lResult == ERROR_SUCCESS) {
            (dwShowQuickHints) ? m_bShowQuickHints = true : m_bShowQuickHints = false;
        }
    }

    return;
}

void CApp::SaveHelpSettings() {
    TCHAR szHelpKey[MAX_PATH] = Q_REGISTRY_KEY_ROOT;
    lstrcat(szHelpKey, Q_REGISTRY_KEY_HELP);

    CRegKey reg;
    LONG lResult = reg.Create(HKEY_CURRENT_USER, szHelpKey);

    if (lResult == ERROR_SUCCESS) {
        // NOTE: users cannot change LocalHelpFile or RogCorpURL

        DWORD dwShowQuickHints;
        (m_bShowQuickHints) ? dwShowQuickHints = 1 : dwShowQuickHints = 0;

        lResult = reg.SetValue(dwShowQuickHints, Q_REGISTRY_VALUE_SHOWQUICKHINTS);
    }

    return;
}
