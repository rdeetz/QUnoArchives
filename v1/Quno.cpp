//////////////////////////////////////////////////////////////////////////
// QUno
// Roger Deetz, 1997
//
// quno.cpp - implementation of the application class CQUnoApp

#include "stdafx.h"
#include "quno.h"
#include "mainfrm.h"
#include "qunocard.h"

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
	ON_COMMAND(ID_NEWGAME, OnNewGame)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//------------------------------------------------------------------------
// CQUnoApp construction and destruction
CQunoApp::CQunoApp()
{

}

// the one and only CQunoApp object
CQunoApp NEAR theApp;

//------------------------------------------------------------------------
// CQUnoApp initialization

BOOL CQunoApp::InitInstance()
{
	SetDialogBkColor();        // set dialog background color to gray

	// create the window for this application
	// this is required when removing the doc/view architecture from MFC
	CMainFrame* pMainFrame = new CMainFrame;
	
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME, WS_CAPTION | WS_MINIMIZEBOX | 
	                                          WS_OVERLAPPED | WS_SYSMENU | WS_VISIBLE))
		return FALSE;
		
	m_pMainWnd = pMainFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	// start the game? or maybe before the window is painted?

	return TRUE;
}


//////////////////////////////////////////////////////////////////////////
// CAboutDlg 
//   definition of the About dialog class

class CAboutDlg : public CDialog
{
public:
	// construction and destruction
	CAboutDlg();

	// data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

protected:
	// implementation
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//{{AFX_MSG(CAboutDlg)
		// no message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
};
//////////////////////////////////////////////////////////////////////////
         
//////////////////////////////////////////////////////////////////////////
// CAboutDlg
//   implementation of the About dialog class
         
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

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// no message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
//////////////////////////////////////////////////////////////////////////


//------------------------------------------------------------------------
// CQunoApp commands

// display the About dialog
void CQunoApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
	
	return;
}

// fire up a new game
void CQunoApp::OnNewGame() 
{
	// TODO: Add your command handler code here
	// not sure if this will work
	
}
