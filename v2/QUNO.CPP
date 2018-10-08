//////////////////////////////////////////////////////////////////////////
// RogCorp QUno
// version 2.0
//
//        File:  quno.cpp
// Description:  implementation of the application class CQUnoApp
//     Revised:  08/21/97
//
// Copyright © 1997 Roger Deetz

#include "stdafx.h"
#include "quno.h"
#include "mainfrm.h"
#include "qunocard.h"
#include "qdialogs.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


//////////////////////////////////////////////////////////////////////////
// CQunoApp 
//   the application class

BEGIN_MESSAGE_MAP(CQunoApp, CWinApp)
	//{{AFX_MSG_MAP(CQunoApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_HELP_CONTENTS, OnHelpContents)
	ON_COMMAND(ID_HELP_HINT, OnHelpHint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//------------------------------------------------------------------------
// CQUnoApp construction and destruction

CQunoApp::CQunoApp()
{
	// initialize members
	m_bHints  = TRUE;
	m_strHelp = ".\\Help\\qunohelp.htm";
}

// the one and only CQunoApp object
CQunoApp NEAR theApp;

//------------------------------------------------------------------------
// CQUnoApp initialization

BOOL CQunoApp::InitInstance()
{
	SetDialogBkColor();        // set dialog background color to gray

	// load the profile information
	SetRegistryKey("RogCorp");
	
	m_strHelp = GetProfileString("2.0\\StartUp", "HelpFile", ".\\QUno.htm");

	UINT nHints = GetProfileInt("2.0\\StartUp", "QuickHints", 1);
	if (nHints == 1)
		m_bHints = TRUE;
	else
		m_bHints = FALSE;

	// create the window for this application
	// this is required when removing the doc/view architecture from MFC
	CMainFrame* pMainFrame = new CMainFrame;
	
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME, WS_CAPTION | WS_MINIMIZEBOX | 
	                                          WS_OVERLAPPED | WS_SYSMENU | WS_VISIBLE))
		return FALSE;
		
	m_pMainWnd = pMainFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	// a new game is started when the window is created

	// show hints if needed
	if (m_bHints) 
		OnHelpHint();
		
	return TRUE;
}

int CQunoApp::ExitInstance()
{
	// save the profile information
	WriteProfileString("2.0\\StartUp", "HelpFile", m_strHelp);

	if (m_bHints)
		WriteProfileInt("2.0\\StartUp", "QuickHints", 1);
	else
		WriteProfileInt("2.0\\StartUp", "QuickHints", 0);

	return 0;
}

//------------------------------------------------------------------------
// CQunoApp commands

// display the About dialog
void CQunoApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
	
	return;
}

// display online help (via the browser)
void CQunoApp::OnHelpContents() 
{
	// try to open help file
	HINSTANCE hinst = ShellExecute(m_pMainWnd->m_hWnd, "open", m_strHelp, 
								   NULL, NULL, SW_SHOWNORMAL);

	// get error info while it's hot
	DWORD dwError = GetLastError();

	// setup the open file dialog in case of error
	CFileDialog fileDlg(TRUE, ".htm", "QUno.htm", 
		                OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_PATHMUSTEXIST, 
						"HTML Help Files (*.htm; *.html) | *.htm; *.hmtl ||", NULL);

	fileDlg.m_ofn.lpstrTitle = "Open HTML Help File";
	
	// handle errors
	int nResult;

	switch (dwError)
	{
		case ERROR_SUCCESS:
			break;

		case ERROR_FILE_NOT_FOUND: // most likely

		default:
			// prompt user to find file
			nResult = AfxMessageBox("Error executing HTML Help.\n\nWould you like to find the file QUNO.HTM yourself?", 
				                    MB_YESNO | MB_ICONEXCLAMATION);

			if (nResult == IDYES)
			{
				if (fileDlg.DoModal() == IDOK)
				{
					m_strHelp = fileDlg.GetPathName();
					OnHelpContents(); // not sure about this recursion
				}
			}

			break;
	}

	return;
}

// display the Quick Hint dialog
void CQunoApp::OnHelpHint() 
{
	CQuickHint hintDlg;

	// set the data
	hintDlg.m_bStartup = m_bHints;

	// invoke the dialog
	if (hintDlg.DoModal() == IDOK)
	{
		// get the data
		m_bHints = hintDlg.m_bStartup;
	}

	return;
}
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// CAboutDlg
//   implementation of the About dialog class

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// no message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// constructor
CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

// data mapping (none in this case) 
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}
//////////////////////////////////////////////////////////////////////////
