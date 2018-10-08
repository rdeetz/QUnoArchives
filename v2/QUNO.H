//////////////////////////////////////////////////////////////////////////
// RogCorp QUno
// version 2.0
//
//        File:  quno.h
// Description:  definition of the application class CQUnoApp
//     Revised:  08/21/97
//
// Copyright © 1997 Roger Deetz

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"			// main resource symbols


//////////////////////////////////////////////////////////////////////////
// CQunoApp
//   the application class

class CQunoApp : public CWinApp
{
public:
	// attributes
	BOOL    m_bHints;
	CString m_strHelp;

	// construction and destruction
	CQunoApp();

	// overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	// message map functions
	//{{AFX_MSG(CQunoApp)
	afx_msg void OnAppAbout();
	afx_msg void OnHelpContents();
	afx_msg void OnHelpHint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
};
//////////////////////////////////////////////////////////////////////////


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

	// message map functions
	//{{AFX_MSG(CAboutDlg)
		// no message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
};
//////////////////////////////////////////////////////////////////////////
