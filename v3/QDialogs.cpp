/////////////////////////////////////////////////////////////////////
//
// QDialogs.cpp - implementation of dialog classes for the 
//                RogCorp QUno 3.0 user interface
//
// Copyright © 2000-2001 Roger Deetz
//

#include "stdafx.h"
#include "QDialogs.h"
#include "QGlobal.h"
#include "App.h"
#include "GameManager.h"

CAboutDlg::CAboutDlg() {

}

CAboutDlg::~CAboutDlg() {

}

LRESULT CAboutDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    CenterWindow();

    // load copyright warning text
    TCHAR szWarning[Q_BUFFER_LARGETEXT];
    LoadString(_Module.m_hInstResource, IDS_WARNING, szWarning, Q_BUFFER_LARGETEXT);

    SetDlgItemText(IDC_WARNING, szWarning);

    // set product name to bold
    HWND hwndProductName = GetDlgItem(IDC_PRODUCTNAME);
    HDC hdcProductName = ::GetDC(hwndProductName);
    HFONT hOldFont = (HFONT)::SendMessage(hwndProductName, WM_GETFONT, 0, 0);

    LOGFONT lf;
    GetObject(hOldFont, sizeof(LOGFONT), (LPVOID)&lf);
    lf.lfWeight = FW_BOLD;
    lf.lfHeight = -MulDiv(Q_ABOUTDLG_PRODUCTSIZE, GetDeviceCaps(hdcProductName, LOGPIXELSY), 72);
    lstrcpy(lf.lfFaceName, Q_ABOUTDLG_PRODUCTFACE);

    m_hBoldFont = CreateFontIndirect(&lf);
    ::SendMessage(hwndProductName, WM_SETFONT, (WPARAM)m_hBoldFont, 0);

    // load product build number
    TCHAR szProductVersion1[MAX_PATH];
    GetDlgItemText(IDC_PRODUCTVERSION, szProductVersion1, MAX_PATH);

    TCHAR szModule[MAX_PATH];
    GetModuleFileName(NULL, szModule, MAX_PATH);

    TCHAR szVersion[MAX_PATH];
    bool bResult = GetFileVersionString(szModule, Q_VERSION_FILEVERSION, szVersion, MAX_PATH);

    if (bResult) {
        TCHAR szProductVersion2[MAX_PATH];
        wsprintf(szProductVersion2, szProductVersion1, szVersion);
        SetDlgItemText(IDC_PRODUCTVERSION, szProductVersion2);
    }

    // display component build numbers
    HWND hwndComponents = GetDlgItem(IDC_COMPONENTS);

    RECT rc;
    ::GetClientRect(hwndComponents, &rc);
    int nColumnWidth = (((rc.right - rc.left) - GetSystemMetrics(SM_CXVSCROLL)) / Q_ABOUTDLG_VERCOLUMNS);

    LVCOLUMN lvcol;
    lvcol.mask = (LVCF_FMT | LVCF_ORDER | LVCF_WIDTH);
    lvcol.fmt = LVCFMT_LEFT;
    lvcol.cx = nColumnWidth;

    lvcol.iOrder = Q_ABOUTDLG_VERCOLUMN_FILE;
    ListView_InsertColumn(hwndComponents, lvcol.iOrder, &lvcol);

    lvcol.iOrder = Q_ABOUTDLG_VERCOLUMN_BUILD;
    ListView_InsertColumn(hwndComponents, lvcol.iOrder, &lvcol);

    LVITEM lvitem;
    lvitem.mask = LVIF_TEXT;
    lvitem.iSubItem = 0;

    int nIndex = 0;

    // QUno Engine
    TCHAR szEngineDescription[MAX_PATH];
    bResult = GetFileVersionString(Q_MODULE_QENGINE, Q_VERSION_FILEDESCRIPTION, szEngineDescription, MAX_PATH);

    if (bResult) {
        lvitem.iItem = nIndex;
        lvitem.pszText = szEngineDescription;
        ListView_InsertItem(hwndComponents, &lvitem);

        nIndex++;

        TCHAR szEngineVersion[MAX_PATH];
        bResult = GetFileVersionString(Q_MODULE_QENGINE, Q_VERSION_FILEVERSION, szEngineVersion, MAX_PATH);

        if (bResult) {
            ListView_SetItemText(hwndComponents, lvitem.iItem, Q_ABOUTDLG_VERCOLUMN_BUILD, szEngineVersion);
        }
    }

    // QControls Library
    TCHAR szControlDescription[MAX_PATH];
    bResult = GetFileVersionString(Q_MODULE_QCONTROL, Q_VERSION_FILEDESCRIPTION, szControlDescription, MAX_PATH);

    if (bResult) {
        lvitem.iItem = nIndex;
        lvitem.pszText = szControlDescription;
        ListView_InsertItem(hwndComponents, &lvitem);

        nIndex++;

        TCHAR szControlVersion[MAX_PATH];
        bResult = GetFileVersionString(Q_MODULE_QCONTROL, Q_VERSION_FILEVERSION, szControlVersion, MAX_PATH);

        if (bResult) {
            ListView_SetItemText(hwndComponents, lvitem.iItem, Q_ABOUTDLG_VERCOLUMN_BUILD, szControlVersion);
        }
    }

    return 1;
}

LRESULT CAboutDlg::OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    DeleteObject(m_hBoldFont);

    EndDialog(wID);

    return 0;
}

bool CAboutDlg::GetFileVersionString(LPTSTR lpModule, LPTSTR lpKey, LPTSTR lpValue, UINT uMaxValue) {
    bool bReturn = false;

    DWORD dwSize = GetFileVersionInfoSize(lpModule, 0);

    if (dwSize > 0) {
        LPVOID pBlock = GlobalAlloc(GMEM_FIXED | GMEM_ZEROINIT, dwSize);

        if (pBlock) {
            BOOL bResult = GetFileVersionInfo(lpModule, 0, dwSize, pBlock);

            if (bResult) {
                LANGUAGEANDCODEPAGE* pLanguage;
                UINT uLanguageLen = sizeof(LANGUAGEANDCODEPAGE);
                bResult = VerQueryValue(pBlock, _T("\\VarFileInfo\\Translation"), (LPVOID*)&pLanguage, &uLanguageLen);

                if (bResult && (uLanguageLen > 0)) {
                    TCHAR szSubBlock[MAX_PATH];
                    wsprintf(szSubBlock, _T("\\StringFileInfo\\%04x%04x\\"), pLanguage[0].wLanguage, pLanguage[0].wCodePage);
                    lstrcat(szSubBlock, lpKey);

                    LPTSTR lpBuffer;
                    bResult = VerQueryValue(pBlock, szSubBlock, (LPVOID*)&lpBuffer, &uMaxValue);

                    if (bResult && (uMaxValue > 0)) {
                        lstrcpy(lpValue, lpBuffer);

                        bReturn = true;
                    }
                }
            }

            GlobalFree(GlobalHandle(pBlock));
        }
    }

    return bReturn;
}

COptionsDlg::COptionsDlg() {

}

COptionsDlg::~COptionsDlg() {

}

LRESULT COptionsDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    CenterWindow();

    // hand size
    long lHandSize = g_GameManager.GetHandSize();

    HWND hwndHandSizeSpin = GetDlgItem(IDC_HANDSIZESPIN);
    ::SendMessage(hwndHandSizeSpin, UDM_SETRANGE32, Q_HANDSIZE_MIN, Q_HANDSIZE_MAX);

    TCHAR szHandSize[MAX_PATH];
    wsprintf(szHandSize, _T("%d"), lHandSize);
    SetDlgItemText(IDC_HANDSIZEEDIT, szHandSize);

    // play after draw
    bool bPlayAfterDraw = g_GameManager.GetPlayAfterDraw();

    if (bPlayAfterDraw) {
        CheckDlgButton(IDC_PLAYAFTERDRAW, BST_CHECKED);
    }

    // players


    return 1;
}

LRESULT COptionsDlg::OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    USES_CONVERSION;

    // hand size
    TCHAR szHandSize[MAX_PATH];
    GetDlgItemText(IDC_HANDSIZEEDIT, szHandSize, MAX_PATH);

    long lHandSize;
    VarI4FromStr(T2OLE(szHandSize), GetSystemDefaultLCID(), LOCALE_NOUSEROVERRIDE, &lHandSize);

    if ((lHandSize < Q_HANDSIZE_MIN) || (lHandSize > Q_HANDSIZE_MAX)) {
        lHandSize = Q_HANDSIZE_DEFAULT;
    }

    g_GameManager.SetHandSize(lHandSize);

    // play after draw
    bool bPlayAfterDraw = false;

    if (IsDlgButtonChecked(IDC_PLAYAFTERDRAW) == BST_CHECKED) {
        bPlayAfterDraw = true;
    }

    g_GameManager.SetPlayAfterDraw(bPlayAfterDraw);

    // players


    EndDialog(wID);

    return 0;
}

LRESULT COptionsDlg::OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    EndDialog(wID);

    return 0;
}

CWildColorDlg::CWildColorDlg() {

}

CWildColorDlg::~CWildColorDlg() {

}

LRESULT CWildColorDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    CenterWindow();

    return 1;
}

LRESULT CWildColorDlg::OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    EndDialog(wID);

    return 0;
}

LRESULT CWildColorDlg::OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    EndDialog(wID);

    return 0;
}

CQuickHintDlg::CQuickHintDlg() {
    m_nLastHintIndex = 0;
}

CQuickHintDlg::~CQuickHintDlg() {

}

LRESULT CQuickHintDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    CenterWindow();

    if (g_App.GetShowQuickHints()) {
        CheckDlgButton(IDC_SHOWQUICKHINTS, BST_CHECKED);
    }

    ShowNextHint();

    return 1;
}

LRESULT CQuickHintDlg::OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    bool bShowQuickHints = false;

    if (IsDlgButtonChecked(IDC_SHOWQUICKHINTS) == BST_CHECKED) {
        bShowQuickHints = true;
    }

    g_App.SetShowQuickHints(bShowQuickHints);

    EndDialog(wID);

    return 0;
}

LRESULT CQuickHintDlg::OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    EndDialog(wID);

    return 0;
}

LRESULT CQuickHintDlg::OnNextHint(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    ShowNextHint();

    return 0;
}

void CQuickHintDlg::ShowNextHint() {
    srand((unsigned)GetTickCount());

    UINT nHintIndex;

    do {
        nHintIndex = ((rand() % Q_QUICKHINTDLG_HINTCOUNT) + 1);
    } while (nHintIndex == m_nLastHintIndex);

    m_nLastHintIndex = nHintIndex;

    ATLTRACE(_T("Quick Hint Index: %d\n"), nHintIndex);

    UINT nHintID;
    nHintID = (Q_QUICKHINTDLG_HINTOFFSET + nHintIndex);

    TCHAR szHintText[Q_BUFFER_LARGETEXT];
    LoadString(_Module.m_hInstResource, nHintID, szHintText, Q_BUFFER_LARGETEXT);

    SetDlgItemText(IDC_HINTTEXT, szHintText);

    return;
}

CExceptionDlg::CExceptionDlg() {

}

CExceptionDlg::~CExceptionDlg() {

}

LRESULT CExceptionDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    CenterWindow(GetDesktopWindow());

    return 1;
}

LRESULT CExceptionDlg::OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
    EndDialog(wID);

    return 0;
}
