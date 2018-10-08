/////////////////////////////////////////////////////////////////////
//
// MainFrame.cpp - implementation of main window for the 
//                 RogCorp QUno 3.0 user interface
//
// Copyright © 2000-2001 Roger Deetz
//

#include "stdafx.h"
#include "MainFrame.h"
#include "QGlobal.h"
#include "App.h"
#include "GameManager.h"
#include "QDialogs.h"

CMainFrame::CMainFrame() {

}

CMainFrame::~CMainFrame() {

}

LRESULT CMainFrame::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    // TODO: initialize ATL ActiveX windowing, if needed
    //AtlAxWinInit();

    // initialize the Windows common controls library
    INITCOMMONCONTROLSEX iccex;
    iccex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    iccex.dwICC = ICC_LISTVIEW_CLASSES;
    InitCommonControlsEx(&iccex);

    SetIcon((HICON)LoadImage(_Module.m_hInstResource, MAKEINTRESOURCE(IDI_QUNO), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR), TRUE);
    SetIcon((HICON)LoadImage(_Module.m_hInstResource, MAKEINTRESOURCE(IDI_QUNO), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR), FALSE);

    SetMenu(LoadMenu(_Module.m_hInstResource, MAKEINTRESOURCE(IDR_MAINFRAME)));

    m_hAccel = LoadAccelerators(_Module.m_hInstResource, MAKEINTRESOURCE(IDA_QUNO));

    return 0;
}

LRESULT CMainFrame::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    return 0;
}

LRESULT CMainFrame::OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    return 0;
}

LRESULT CMainFrame::OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    if (wParam == SC_CLOSE) {
        g_App.Quit();

        return 0;
    }

    return DefWindowProc(uMsg, wParam, lParam);
}

LRESULT CMainFrame::OnQueryEndSession(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    g_App.Quit();

    return 0;
}

LRESULT CMainFrame::OnInitMenu(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    /*
    RemoveMenu((HMENU)wParam, IDM_GAME_OPEN, MF_BYCOMMAND);
    RemoveMenu((HMENU)wParam, IDM_GAME_SAVE, MF_BYCOMMAND);
    RemoveMenu((HMENU)wParam, IDM_GAME_SAVEAS, MF_BYCOMMAND);
    */

    return 0;
}

LRESULT CMainFrame::OnGameNew(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    g_GameManager.Open();

    return 0;
}

LRESULT CMainFrame::OnGameOpen(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    TCHAR szFile[MAX_PATH];
    BOOL bResult = OpenOrSaveFile(szFile, true);

    if (bResult) {
        g_GameManager.Open(szFile);
    }

    return 0;
}

LRESULT CMainFrame::OnGameSave(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    // TODO: check if the game has been saved before

    if (true) {
        g_GameManager.Save();
    } else {
        return OnGameSaveAs(wNotifyCode, wID, hWndCtl, bHandled);
    }

    return 0;
}

LRESULT CMainFrame::OnGameSaveAs(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    TCHAR szFile[MAX_PATH];
    g_GameManager.GetGameTitle(szFile, true);

    BOOL bResult = OpenOrSaveFile(szFile, false);

    if (bResult) {
        g_GameManager.Save(szFile);
    }

    return 0;
}

LRESULT CMainFrame::OnGameExit(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    g_App.Quit();

    return 0;
}

LRESULT CMainFrame::OnPlayPlay(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    return 0;
}

LRESULT CMainFrame::OnPlayDraw(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    return 0;
}

LRESULT CMainFrame::OnPlayPass(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    return 0;
}

LRESULT CMainFrame::OnPlayForce(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    return 0;
}

LRESULT CMainFrame::OnToolsOptions(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    COptionsDlg dlgOptions;
    int nResult = dlgOptions.DoModal();

    if (nResult == IDOK) {
        // TODO: refresh the view (the options were saved by the dialog)
    }

    return 0;
}

LRESULT CMainFrame::OnHelpContents(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    TCHAR szLocalHelpFile[MAX_PATH];
    g_App.GetLocalHelpFile(szLocalHelpFile);

    if (lstrlen(szLocalHelpFile) > 0) {
        BOOL bResult = LaunchWebBrowser(szLocalHelpFile);

        if (bResult) {
            return 0;
        }
    }

    SimpleMessageBox(IDS_ERROR_NOHELP, MB_OK | MB_ICONEXCLAMATION);

    return 0;
}

LRESULT CMainFrame::OnHelpQuickHint(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    CQuickHintDlg dlg;
    dlg.DoModal();

    return 0;
}

LRESULT CMainFrame::OnHelpWeb(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    TCHAR szRogCorpURL[MAX_PATH];
    g_App.GetRogCorpURL(szRogCorpURL);

    if (lstrlen(szRogCorpURL) > 0) {
        BOOL bResult = LaunchWebBrowser(szRogCorpURL);

        if (bResult) {
            return 0;
        }
    }

    SimpleMessageBox(IDS_ERROR_NOWEB, MB_OK | MB_ICONEXCLAMATION);

    return 0;
}

LRESULT CMainFrame::OnHelpAbout(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    CAboutDlg dlgAbout;
    dlgAbout.DoModal();

    return 0;
}

int CMainFrame::PreTranslateAccelerator(LPMSG lpMsg) {
    return TranslateAccelerator(m_hWnd, m_hAccel, lpMsg);
}

void CMainFrame::OnFinalMessage(HWND hWnd) {
    return;
}

BOOL CMainFrame::OpenOrSaveFile(LPTSTR lpFile, bool bOpen) {
    // find the 'My Documents' folder
    TCHAR szInitialDir[MAX_PATH];

    CComPtr<IMalloc> pMalloc;
    SHGetMalloc(&pMalloc);

    ITEMIDLIST* pidl;
    SHGetSpecialFolderLocation(m_hWnd, CSIDL_PERSONAL, &pidl);
    SHGetPathFromIDList(pidl, szInitialDir);

    pMalloc->Free((LPVOID)pidl);

    // set up the Open/Save As commong dialog
    OPENFILENAME ofn;

    LPTSTR lpstrFilter = Q_FILTER_GAME; // TODO: use a string resource!
    LPTSTR lpstrDefExt = Q_GAME_EXTENSION;

    TCHAR szFile[MAX_PATH];

    if (bOpen) {
        szFile[0] = NULL;
    } else {
        lstrcpy(szFile, lpFile);
    }

    ofn.lStructSize = 76; // why is this the right number?
    ofn.hwndOwner = m_hWnd;
    ofn.lpstrFilter = lpstrFilter;
    ofn.lpstrCustomFilter = NULL;
    ofn.nFilterIndex = 1;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFileTitle = NULL;
    ofn.lpstrInitialDir = szInitialDir;
    ofn.lpstrTitle = NULL;
    ofn.lpstrDefExt = lpstrDefExt;
    ofn.Flags = (OFN_ENABLESIZING | OFN_EXPLORER | OFN_HIDEREADONLY);

    BOOL bResult;

    if (bOpen) {
        ofn.Flags = (ofn.Flags | OFN_FILEMUSTEXIST);
        bResult = GetOpenFileName(&ofn);
    } else {
        ofn.Flags = (ofn.Flags | OFN_OVERWRITEPROMPT);
        bResult = GetSaveFileName(&ofn);
    }

    if (bResult) {
        lstrcpy(lpFile, ofn.lpstrFile);
    }

    return bResult;
}

BOOL CMainFrame::LaunchWebBrowser(LPTSTR lpURL) {
    TCHAR szTemp[MAX_PATH];
    lstrcpy(szTemp, lpURL);

    /* NOTE: could also use this to wait on the process 
    SHELLEXECUTEINFO sei;
    sei.cbSize = sizeof(SHELLEXECUTEINFO);
    sei.hwnd = m_hWnd;
    sei.lpVerb = NULL;
    sei.lpFile = szTemp;
    sei.lpParameters = NULL;
    sei.lpDirectory = NULL;
    sei.nShow = SW_SHOWNORMAL;

    BOOL bResult = ShellExecuteEx(&sei);

    return bResult;
    */

    int nResult = (int)ShellExecute(m_hWnd, _T("open"), szTemp, NULL, NULL, SW_SHOWNORMAL);

    return (nResult > 32) ? TRUE : FALSE;
}

int CMainFrame::SimpleMessageBox(UINT nID, UINT nFlags) {
    TCHAR szMessage[Q_BUFFER_LARGETEXT];
    LoadString(_Module.m_hInstResource, nID, szMessage, Q_BUFFER_LARGETEXT);

    TCHAR szTitle[MAX_PATH];
    LoadString(_Module.m_hInstResource, IDS_MAINFRAMETITLE, szTitle, Q_BUFFER_LARGETEXT);

    return MessageBox(szMessage, szTitle, nFlags);
}
