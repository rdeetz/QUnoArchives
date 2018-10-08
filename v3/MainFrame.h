/////////////////////////////////////////////////////////////////////
//
// MainFrame.h - definition of the main window for the 
//               RogCorp QUno 3.0 user interface
//
// Copyright © 2000-2001 Roger Deetz
//

#if !defined(AFX_MAINFRAME_H__DC62D1D0_9B08_464A_ADA7_F6DA1779F1D3__INCLUDED_)
#define AFX_MAINFRAME_H__DC62D1D0_9B08_464A_ADA7_F6DA1779F1D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"

// CMainFrame

class CMainFrame :
    public CWindowImpl<CMainFrame, CWindow, CFrameWinTraits>
{
public:
    CMainFrame();
    virtual ~CMainFrame();

    DECLARE_WND_CLASS("RogCorpQUnoUI")

    BEGIN_MSG_MAP(CMainFrame)
        MESSAGE_HANDLER(WM_CREATE, OnCreate)
        MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
        MESSAGE_HANDLER(WM_SIZE, OnSize)
        MESSAGE_HANDLER(WM_SYSCOMMAND, OnSysCommand)
        MESSAGE_HANDLER(WM_QUERYENDSESSION, OnQueryEndSession)
        MESSAGE_HANDLER(WM_INITMENU, OnInitMenu)
        COMMAND_ID_HANDLER(IDM_GAME_NEW, OnGameNew)
        COMMAND_ID_HANDLER(IDM_GAME_OPEN, OnGameOpen)
        COMMAND_ID_HANDLER(IDM_GAME_SAVE, OnGameSave)
        COMMAND_ID_HANDLER(IDM_GAME_SAVEAS, OnGameSaveAs)
        COMMAND_ID_HANDLER(IDM_GAME_EXIT, OnGameExit)
        COMMAND_ID_HANDLER(IDM_PLAY_PLAY, OnPlayPlay)
        COMMAND_ID_HANDLER(IDM_PLAY_DRAW, OnPlayDraw)
        COMMAND_ID_HANDLER(IDM_PLAY_PASS, OnPlayPass)
        COMMAND_ID_HANDLER(IDM_PLAY_FORCE, OnPlayForce)
        COMMAND_ID_HANDLER(IDM_TOOLS_OPTIONS, OnToolsOptions)
        COMMAND_ID_HANDLER(IDM_HELP_CONTENTS, OnHelpContents)
        COMMAND_ID_HANDLER(IDM_HELP_QUICKHINT, OnHelpQuickHint)
        COMMAND_ID_HANDLER(IDM_HELP_WEB, OnHelpWeb)
        COMMAND_ID_HANDLER(IDM_HELP_ABOUT, OnHelpAbout)
    END_MSG_MAP()

    LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnQueryEndSession(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnInitMenu(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

    LRESULT OnGameNew(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnGameOpen(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnGameSave(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnGameSaveAs(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnGameExit(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnPlayPlay(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnPlayDraw(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnPlayPass(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnPlayForce(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnToolsOptions(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnHelpContents(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnHelpQuickHint(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnHelpWeb(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnHelpAbout(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

    int PreTranslateAccelerator(LPMSG lpMsg);

    void OnFinalMessage(HWND hWnd);

private:
    BOOL OpenOrSaveFile(LPTSTR lpFile, bool bOpen = true);
    BOOL LaunchWebBrowser(LPTSTR lpURL);
    int SimpleMessageBox(UINT nID, UINT nFlags = (MB_OK | MB_ICONINFORMATION));

    HACCEL m_hAccel;

};

#endif // !defined(AFX_MAINFRAME_H__DC62D1D0_9B08_464A_ADA7_F6DA1779F1D3__INCLUDED_)
