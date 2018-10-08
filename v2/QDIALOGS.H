//////////////////////////////////////////////////////////////////////////
// RogCorp QUno
// version 2.0
//
//        File:  qdialogs.h
// Description:  definition of the dialog classes - 
//               CPickColor, the dialog support for Wild cards
//               CGameOptions, the options dialog
//               CQuickHint, the strategy hint dialog
//     Revised:  08/21/97
//
// Copyright © 1997 Roger Deetz

#include "resource.h"			// main resource symbols


//////////////////////////////////////////////////////////////////////////
// CPickColor
//   the Wild card dialog class

class CPickColor : public CDialog
{
public:
	// construction and destruction
	CPickColor(CWnd* pParent = NULL);

	// data
	//{{AFX_DATA(CPickColor)
	enum { IDD = IDD_PICKCOLOR };
	CStatic	m_ctlColor;
	int		m_bRed;
	//}}AFX_DATA

protected:
	// implementation
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// message map functions
	//{{AFX_MSG(CPickColor)
	afx_msg void OnRed();
	afx_msg void OnBlue();
	afx_msg void OnYellow();
	afx_msg void OnGreen();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
private:
	HBITMAP m_hbmpColor;

};
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// CGameOptions
//   the game options dialog class

class CGameOptions : public CDialog
{
public:
	// construction and destructions
	CGameOptions(CWnd* pParent = NULL);

	// data
	//{{AFX_DATA(CGameOptions)
	enum { IDD = IDD_OPTIONS };
	CStatic	m_ctlPicture;
	int		m_nWizard;
	BOOL	m_bSmart;
	CString	m_strComputer;
	CString	m_strUser;
	//}}AFX_DATA

	// overrides
	//{{AFX_VIRTUAL(CGameOptions)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	// message map functions
	//{{AFX_MSG(CGameOptions)
	afx_msg void OnDestroy();
	afx_msg void OnCompute();
	afx_msg void OnCowboy();
	afx_msg void OnNerd();
	afx_msg void OnWizard();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	HBITMAP m_hbmpPicture;

};
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// CQuickHint
//   the Quick Hint help dialog class

class CQuickHint : public CDialog
{
public:
	// construction and destruction
	CQuickHint(CWnd* pParent = NULL);

	// data
	//{{AFX_DATA(CQuickHint)
	enum { IDD = IDD_HINT };
	CStatic	m_ctlHint;
	BOOL	m_bStartup;
	//}}AFX_DATA

	// overrides
	//{{AFX_VIRTUAL(CQuickHint)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	// message map functions
	//{{AFX_MSG(CQuickHint)
	afx_msg void OnNext();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	UINT GetHint();			// function to grab random string entries

};
//////////////////////////////////////////////////////////////////////////
