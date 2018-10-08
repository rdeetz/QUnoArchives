//////////////////////////////////////////////////////////////////////////
// QUno
// Roger Deetz, 1997
//
// quno.h - main header file for QUno and 
//          definition of the application class CQUnoApp

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main resource symbols

//////////////////////////////////////////////////////////////////////////
// CQunoApp
//   the application class

class CQunoApp : public CWinApp
{
public:
	// construction and destruction
	CQunoApp();
	
	// overrides
	virtual BOOL InitInstance();

	// message map functions
	//{{AFX_MSG(CQunoApp)
	afx_msg void OnAppAbout();
	afx_msg void OnNewGame();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
};
//////////////////////////////////////////////////////////////////////////
