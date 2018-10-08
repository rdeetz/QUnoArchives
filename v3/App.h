/////////////////////////////////////////////////////////////////////
//
// App.h - definition of the application object for the 
//         RogCorp QUno 3.0 user interface
//
// Copyright © 2000-2001 Roger Deetz
//

#ifndef __APP_H_
#define __APP_H_

#include "resource.h"

#include "MainFrame.h"

// CApp

class CApp
{
public:
    CApp();
    ~CApp();

    bool Start(LPTSTR lpCmdLine = NULL);
    void End();
    void Quit();

    void GetLocalHelpFile(LPTSTR lpLocalHelpFile);
    void GetRogCorpURL(LPTSTR lpRogCorpURL);
    bool GetShowQuickHints();
    void SetShowQuickHints(bool bShowQuickHints);

    void UpdateWindowTitle();
    int PreTranslateAccelerator(LPMSG lpMsg);

private:
    void BuildWindowTitle(LPTSTR lpWindowTitle);

    void LoadWindowSettings(RECT& rc, int& nCmdShow);
    void SaveWindowSettings(LPRECT lprc, int nCmdShow = SW_SHOWNORMAL);
    void LoadHelpSettings();
    void SaveHelpSettings();

    CMainFrame m_wndMainFrame;

    TCHAR m_szLocalHelpFile[MAX_PATH];
    TCHAR m_szRogCorpURL[MAX_PATH];
    bool m_bShowQuickHints;

};

extern CApp g_App;

#endif //__APP_H_
