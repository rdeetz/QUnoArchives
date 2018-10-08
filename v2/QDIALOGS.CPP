//////////////////////////////////////////////////////////////////////////
// RogCorp QUno
// version 2.0
//
//        File:  qdialogs.cpp
// Description:  implementation of the dialog classes - 
//               CPickColor, the dialog support for Wild cards
//               CGameOptions, the options dialog
//               CQuickHint, the strategy hint dialog
//     Revised:  08/21/97
//
// Copyright © 1997 Roger Deetz

#include <stdlib.h>
#include "stdafx.h"
#include "qdialogs.h"

//////////////////////////////////////////////////////////////////////////
// CPickColor
//   the Wild color dialog class

BEGIN_MESSAGE_MAP(CPickColor, CDialog)
	//{{AFX_MSG_MAP(CPickColor)
	ON_BN_CLICKED(IDC_RED, OnRed)
	ON_BN_CLICKED(IDC_BLUE, OnBlue)
	ON_BN_CLICKED(IDC_YELLOW, OnYellow)
	ON_BN_CLICKED(IDC_GREEN, OnGreen)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//------------------------------------------------------------------------
// CPickColor construction and commands

CPickColor::CPickColor(CWnd* pParent /*=NULL*/) : CDialog(CPickColor::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPickColor)
	m_bRed = 0;
	//}}AFX_DATA_INIT
}

void CPickColor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPickColor)
	DDX_Control(pDX, IDC_COLOR, m_ctlColor);
	DDX_Radio(pDX, IDC_RED, m_bRed);
	//}}AFX_DATA_MAP
}

void CPickColor::OnRed() 
{
	// when clicked, change the color box to red
	m_hbmpColor = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_RED));
	m_ctlColor.SetBitmap(m_hbmpColor);

	return;
}

void CPickColor::OnBlue() 
{
	// when clicked, change the color box to blue
	m_hbmpColor = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BLUE));
	m_ctlColor.SetBitmap(m_hbmpColor);

	return;
}

void CPickColor::OnYellow() 
{
	// when clicked, change the color box to yellow
	m_hbmpColor = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_YELLOW));
	m_ctlColor.SetBitmap(m_hbmpColor);

	return;
}

void CPickColor::OnGreen() 
{
	// when clicked, change the color box to green
	m_hbmpColor = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_GREEN));
	m_ctlColor.SetBitmap(m_hbmpColor);

	return;
}

void CPickColor::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// clean up the bitmaps
	::DeleteObject(m_hbmpColor);

	return;
}
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// CGameOptions dialog
//   the game options dialog class

BEGIN_MESSAGE_MAP(CGameOptions, CDialog)
	//{{AFX_MSG_MAP(CGameOptions)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_COMPUTE, OnCompute)
	ON_BN_CLICKED(IDC_COWBOY, OnCowboy)
	ON_BN_CLICKED(IDC_NERD, OnNerd)
	ON_BN_CLICKED(IDC_WIZARD, OnWizard)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//------------------------------------------------------------------------
// CGameOptions construction and commands

CGameOptions::CGameOptions(CWnd* pParent /*=NULL*/) : CDialog(CGameOptions::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGameOptions)
	m_nWizard = 0;
	m_bSmart = TRUE;
	m_strComputer = _T("");
	m_strUser = _T("");
	//}}AFX_DATA_INIT
}

void CGameOptions::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGameOptions)
	DDX_Control(pDX, IDC_PICTURE, m_ctlPicture);
	DDX_Radio(pDX, IDC_WIZARD, m_nWizard);
	DDX_Check(pDX, IDC_SMART, m_bSmart);
	DDX_Text(pDX, IDC_COMPUTERNAME, m_strComputer);
	DDV_MaxChars(pDX, m_strComputer, 10);
	DDX_Text(pDX, IDC_USERNAME, m_strUser);
	DDV_MaxChars(pDX, m_strUser, 10);
	//}}AFX_DATA_MAP
}

void CGameOptions::OnWizard() 
{
	// when clicked, change the picture to Wizard
	m_hbmpPicture = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_WIZARD));
	m_ctlPicture.SetBitmap(m_hbmpPicture);

	return;
}

void CGameOptions::OnNerd() 
{
	// when clicked, change the picture to Nerd
	m_hbmpPicture = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_NERD));
	m_ctlPicture.SetBitmap(m_hbmpPicture);

	return;
}

void CGameOptions::OnCompute() 
{
	// when clicked, change the picture to Computer
	m_hbmpPicture = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_COMPUTE));
	m_ctlPicture.SetBitmap(m_hbmpPicture);

	return;
}

void CGameOptions::OnCowboy() 
{
	// when clicked, change the picture to Cowboy
	m_hbmpPicture = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_COWBOY));
	m_ctlPicture.SetBitmap(m_hbmpPicture);

	return;
}

void CGameOptions::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// clean up the bitmaps
	::DeleteObject(m_hbmpPicture);

	return;
}
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// CQuickHint
//  the Quick Hint help dialog class

BEGIN_MESSAGE_MAP(CQuickHint, CDialog)
	//{{AFX_MSG_MAP(CQuickHint)
	ON_BN_CLICKED(IDNEXT, OnNext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//------------------------------------------------------------------------
// CGameOptions construction and commands

CQuickHint::CQuickHint(CWnd* pParent /*=NULL*/) : CDialog(CQuickHint::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQuickHint)
	m_bStartup = TRUE;
	//}}AFX_DATA_INIT
}

BOOL CQuickHint::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// pick a new tip for the static text control
	UINT uHint = GetHint();
	CString strHint((LPCSTR)uHint);
	m_ctlHint.SetWindowText(strHint);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CQuickHint::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQuickHint)
	DDX_Control(pDX, IDC_HINT, m_ctlHint);
	DDX_Check(pDX, IDC_STARTUP, m_bStartup);
	//}}AFX_DATA_MAP
}

void CQuickHint::OnNext() 
{
	// when clicked, fire up the next tip
	UINT uHint = GetHint();
	CString strHint((LPCSTR)uHint);
	m_ctlHint.SetWindowText(strHint);

	return;
}

UINT CQuickHint::GetHint()
{
	// initialize the randomness
	srand((unsigned)time(NULL));
	
	UINT hint;							// ID to send back
    int  count = 12;					// total number of tips
	int  r = rand() % count;			// random boy

	// return a random resource ID of a string
	switch (r)
	{
		case 0:
			hint = IDS_HELP_HINT_1;
			break;
		case 1:
			hint = IDS_HELP_HINT_2;
			break;
		case 2:
			hint = IDS_HELP_HINT_3;
			break;
		case 3:
			hint = IDS_HELP_HINT_4;
			break;
		case 4:
			hint = IDS_HELP_HINT_5;
			break;
		case 5:
			hint = IDS_HELP_HINT_6;
			break;
		case 6:
			hint = IDS_HELP_HINT_7;
			break;
		case 7:
			hint = IDS_HELP_HINT_8;
			break;
		case 8:
			hint = IDS_HELP_HINT_9;
			break;
		case 9:
			hint = IDS_HELP_HINT_10;
			break;
		case 10:
			hint = IDS_HELP_HINT_11;
			break;
		case 11:
			hint = IDS_HELP_HINT_12;
			break;
		default:
			hint = IDS_HELP_HINT_1;
			break;
	}

	return hint;
}
//////////////////////////////////////////////////////////////////////////
