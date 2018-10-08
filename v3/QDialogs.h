/////////////////////////////////////////////////////////////////////
//
// QDialogs.h - definition of the dialog classes for the 
//              RogCorp QUno 3.0 user interface
//
// Copyright © 2000-2001 Roger Deetz
//

#ifndef __QDIALOGS_H_
#define __QDIALOGS_H_

#include "resource.h"

#define Q_ABOUTDLG_PRODUCTSIZE      8
#define Q_ABOUTDLG_PRODUCTFACE      _T("Tahoma")
#define Q_ABOUTDLG_VERCOLUMNS       2
#define Q_ABOUTDLG_VERCOLUMN_FILE   0
#define Q_ABOUTDLG_VERCOLUMN_BUILD  1

#define Q_QUICKHINTDLG_HINTOFFSET   2000
#define Q_QUICKHINTDLG_HINTCOUNT    10

struct LANGUAGEANDCODEPAGE {
    WORD wLanguage;
    WORD wCodePage;
};

// CAboutDlg

class CAboutDlg : 
    public CDialogImpl<CAboutDlg>
{
public:
    CAboutDlg();
    ~CAboutDlg();

    enum { IDD = IDD_ABOUT };

    BEGIN_MSG_MAP(CAboutDlg)
        MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
        COMMAND_ID_HANDLER(IDOK, OnOK)
        COMMAND_ID_HANDLER(IDCANCEL, OnOK)
    END_MSG_MAP()

    LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

private:
    bool GetFileVersionString(LPTSTR lpModule, LPTSTR lpKey, LPTSTR lpValue, UINT uMaxValue);

    HFONT m_hBoldFont;

};

// COptionsDlg

class COptionsDlg : 
    public CDialogImpl<COptionsDlg>
{
public:
    COptionsDlg();
    ~COptionsDlg();

    enum { IDD = IDD_OPTIONS };

    BEGIN_MSG_MAP(COptionsDlg)
        MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
        COMMAND_ID_HANDLER(IDOK, OnOK)
        COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
    END_MSG_MAP()

    LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

private:

};

// CWildColorDlg

class CWildColorDlg : 
    public CDialogImpl<CWildColorDlg>
{
public:
    CWildColorDlg();
    ~CWildColorDlg();

    enum { IDD = IDD_WILDCOLOR};

    BEGIN_MSG_MAP(CWildColorDlg)
        MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
        COMMAND_ID_HANDLER(IDOK, OnOK)
        COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
    END_MSG_MAP()

    LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

private:

};

// CQuickHintDlg

class CQuickHintDlg : 
    public CDialogImpl<CQuickHintDlg>
{
public:
    CQuickHintDlg();
    ~CQuickHintDlg();

    enum { IDD = IDD_QUICKHINT };

    BEGIN_MSG_MAP(CQuickHintDlg)
        MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
        COMMAND_ID_HANDLER(IDOK, OnOK)
        COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
        COMMAND_ID_HANDLER(IDC_NEXTHINT, OnNextHint)
    END_MSG_MAP()

    LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnNextHint(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

private:
    void ShowNextHint();

    UINT m_nLastHintIndex;

};

// CExceptionDlg

class CExceptionDlg : 
    public CDialogImpl<CExceptionDlg>
{
public:
    CExceptionDlg();
    ~CExceptionDlg();

    enum { IDD = IDD_EXCEPTION };

    BEGIN_MSG_MAP(CExceptionDlg)
        MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
        COMMAND_ID_HANDLER(IDOK, OnOK)
        COMMAND_ID_HANDLER(IDCANCEL, OnOK)
    END_MSG_MAP()

    LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

private:

};

#endif //__QDIALOGS_H_
