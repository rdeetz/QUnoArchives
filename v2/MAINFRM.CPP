//////////////////////////////////////////////////////////////////////////
// RogCorp QUno
// version 2.0
//
//        File:  mainfrm.cpp
// Description:  implementation of the main window class CMainFrame
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

// the one and only deck
CDeck theDeck;

// initialize the players with default identities
CHand livyHand(TRUE, "Player");
CHand rogerHand(FALSE, "Computer");


//////////////////////////////////////////////////////////////////////////
// CMainFrame 
//   the main window class

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_GAME_DRAW, OnGameDraw)
	ON_COMMAND(ID_GAME_FORCE, OnGameForce)
	ON_UPDATE_COMMAND_UI(ID_GAME_DRAW, OnUpdateGameDraw)
	ON_UPDATE_COMMAND_UI(ID_GAME_FORCE, OnUpdateGameForce)
	ON_COMMAND(ID_GAME_NEW, OnGameNew)
	ON_COMMAND(ID_GAME_OPTIONS, OnGameOptions)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//------------------------------------------------------------------------
// CMainFrame construction and destruction

CMainFrame::CMainFrame()
{
	// initialize the screen rectangles
	m_rectDeck.SetRect(14, 14, 85, 115);
	m_rectStack.SetRect(105, 20, 170, 115);
	m_rectRoger.SetRect(365, 35, 413, 83);

	// starting point for the first user card
	CPoint pt(20, 140);

	for (int i = 0; i < UNO_HAND_MAXSIZE; i++)
	{
		m_rectCards[i].SetRect(pt.x, pt.y, pt.x + 65, pt.y + 95);
		
		// move to the position of the next card
		pt.x += 85;
		
		// check if it is time to start a new row
		if (i == (UNO_HAND_INITSIZE - 1))
		{
			pt.x = 20;
			pt.y = 255;
		}
	}
}

CMainFrame::~CMainFrame()
{

}

//------------------------------------------------------------------------
// CMainFrame diagnostics

#ifdef _DEBUG

void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

//------------------------------------------------------------------------
// CMainFrame message handlers

// start the game
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// load the persistent settings
	CString strPlayer = AfxGetApp()->GetProfileString("2.0\\UserData", "PlayerName", "Player");
	CString strComputer = AfxGetApp()->GetProfileString("2.0\\UserData", "ComputerName", "Computer");
	UINT imgComputer = AfxGetApp()->GetProfileInt("2.0\\UserData", "ComputerImage", IDB_WIZARD);
	UINT nIntelligence = AfxGetApp()->GetProfileInt("2.0\\UserData", "Intelligence", 1);

	livyHand.m_strName = strPlayer;
	rogerHand.m_strName = strComputer;
	rogerHand.SetPicture(imgComputer);
	
	if (nIntelligence == 1)
		rogerHand.SetSmart(TRUE);
	else
		rogerHand.SetSmart(FALSE);

	// start a new game for the first time (this isn't real good)
	theDeck.NewGame(&livyHand, &rogerHand);

	return 0;
}

// draw the surface of the window
void CMainFrame::OnPaint()
{
	CPaintDC dc(this);				// painting device context

	//// draw the upper region of the game board

	// the deck image
	BlastBitmap(m_rectDeck, theDeck.GetDeckImage());
		
	// the stack container
	dc.Rectangle(m_rectStack);
	BlastBitmap(m_rectStack, theDeck.GetCurrentCard()->GetBitmap());
	
	// the computer opponent container
	dc.Rectangle(m_rectRoger);
	BlastBitmap(m_rectRoger, rogerHand.GetPicture());

	//// draw the status indicators

	// get the current player
	if (theDeck.UserTurn())
		dc.TextOut(195, 25, livyHand.m_strName + "'s Turn");
	else
		dc.TextOut(195, 25, rogerHand.m_strName + "'s Turn");

	// get the Wild color and display the word
	switch (theDeck.GetWildColor())
	{
		case UNO_NOCOLOR :
			dc.TextOut(195, 58, "No Wild Card");
			break;
		
		case UNO_RED :
			dc.TextOut(195, 58, "Wild Card -> Red");
			break;
		
		case UNO_BLUE :
			dc.TextOut(195, 58, "Wild Card -> Blue");
			break;
		
		case UNO_YELLOW :
			dc.TextOut(195, 58, "Wild Card -> Yellow");
			break;
		
		case UNO_GREEN :
			dc.TextOut(195, 58, "Wild Card -> Green");
			break;
		
		default:
			break;
	}

	// get the number of cards in the computer's hand and display it
	int size = rogerHand.GetSize();
	
	CString str;
	str.Format(rogerHand.m_strName + " has %d cards left ", size);
	
	dc.TextOut(195, 91, str);
		                                
	//// draw the lower region of the game board 

	// draw the rectangles to hold the array of cards
	for (int i = 0; i < UNO_HAND_MAXSIZE; i++)
	{
		dc.Rectangle(m_rectCards[i]);
		
		// draw the bitmaps for the cards in the hand
		if (i < livyHand.GetSize()) 
		{
		 	BlastBitmap(m_rectCards[i], livyHand.PeekCard(i)->GetBitmap());
		}
	}
    
	// do not call CFrameWnd::OnPaint() for painting messages!
	return;
}

// exit the application
void CMainFrame::OnClose()
{
	// prompt the user to exit
	int nResult = MessageBox("Are you sure you want to quit?", 
		                     "Exit", 
							 MB_YESNO | MB_ICONQUESTION);
	
	if (nResult == IDYES)
	{
		// save the persistent settings
		AfxGetApp()->WriteProfileString("2.0\\UserData", "PlayerName", livyHand.m_strName);
		AfxGetApp()->WriteProfileString("2.0\\UserData", "ComputerName", rogerHand.m_strName);
		AfxGetApp()->WriteProfileInt("2.0\\UserData", "ComputerImage", rogerHand.GetPicture());

		UINT nSmart;
		if (rogerHand.IsSmart())
			nSmart = 1;
		else
			nSmart = 0;

		AfxGetApp()->WriteProfileInt("2.0\\UserData", "Intelligence", nSmart);

		CFrameWnd::OnClose();
	}
	
	return;	
}

// here is what happends when the user moves over the window
void CMainFrame::OnMouseMove(UINT nFlags, CPoint point) 
{
	// device context for drawing
	CClientDC dc(this);
	CGdiObject* pOldBrush = dc.SelectStockObject(NULL_BRUSH);

	// if not user's turn, check for being over the computer
	if (!theDeck.UserTurn())
	{
		if (m_rectRoger.PtInRect(point))
		{
			CPen* pNewPen = new CPen(PS_SOLID, 1, RGB(0, 255, 0));
			CPen* pOldPen = dc.SelectObject(pNewPen);

			dc.Rectangle(m_rectRoger);

			dc.SelectObject(pOldPen);
			delete pNewPen;
		}
		else
		{
			dc.Rectangle(m_rectRoger);
		}

		// reset the brush
		dc.SelectObject(pOldBrush);

		return;
	}

	// check if they are over a card
	for (int i = 0; i < UNO_HAND_MAXSIZE; i++)
	{
		if (m_rectCards[i].PtInRect(point))
		{
			// check if that card will play and change color
			COLORREF c;

			if (livyHand.Playable(i, &theDeck))
				c = RGB(0, 255, 0);
			else
				c = RGB(255, 0, 0);

			// make a new pen
			CPen* pNewPen = new CPen(PS_SOLID, 1, c);
			CPen* pOldPen = dc.SelectObject(pNewPen);

			dc.Rectangle(m_rectCards[i]);

			dc.SelectObject(pOldPen);
			delete pNewPen;
		}
		else 
		{
			dc.Rectangle(m_rectCards[i]);
		}
	}

	// reset the brush
	dc.SelectObject(pOldBrush);

	CFrameWnd::OnMouseMove(nFlags, point);
}

// here is what happens when the user clicks in the window
void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	// check if it's the computer turn
	if (!theDeck.UserTurn())
	{
		// check if they clicked the computer image
		if (m_rectRoger.PtInRect(point))
		{
			OnGameForce();
		}
		
		return;
	}

	// check if they clicked the deck
	if (m_rectDeck.PtInRect(point))
	{
		// draw a card
		OnGameDraw();
		return;
	}
	
	// check if they clicked a square
	for (int i = 0; i < UNO_HAND_MAXSIZE; i++)
	{
		if (m_rectCards[i].PtInRect(point))
		{
			// try to play
			if (livyHand.Playable(i, &theDeck))
			{
				livyHand.Play(&theDeck, i, &rogerHand);

				Invalidate();
			}
		}			
	}
		
	CFrameWnd::OnLButtonDown(nFlags, point);
}

//------------------------------------------------------------------------
// CMainFrame virtual overrides

// adjust the size of the new window
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// set the new size
	cs.cx = 455;
	cs.cy = 420;
	
	return CFrameWnd::PreCreateWindow(cs);
}

//------------------------------------------------------------------------
// CMainFrame commands

// draw a card for the human player
void CMainFrame::OnGameDraw() 
{
	livyHand.Draw(&theDeck, 1);
	
	Invalidate();

	return;
}

// update the ui for the Draw command
void CMainFrame::OnUpdateGameDraw(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(theDeck.UserTurn());
	return;
}

// force the computer player to take turn
void CMainFrame::OnGameForce() 
{
	rogerHand.TakeTurn(&theDeck, &livyHand);

	Invalidate();

	return;
}

// update the ui for the Force command
void CMainFrame::OnUpdateGameForce(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(!theDeck.UserTurn());
	return;
}

// start a new game
void CMainFrame::OnGameNew() 
{
	// ask if they want a new game
	int nResult = MessageBox("Do you want to start a new game?", 
	                         "New Game", MB_YESNO | MB_ICONQUESTION);
	                                     
	if (nResult == IDYES) 
	{
		// fire up a new one
		theDeck.NewGame(&livyHand, &rogerHand);
		Invalidate();
	}

	return;
}

// set the game options
void CMainFrame::OnGameOptions() 
{
	CGameOptions dlg;

	// set the data
	dlg.m_strUser = livyHand.m_strName;
	dlg.m_strComputer = rogerHand.m_strName;
	dlg.m_bSmart = rogerHand.IsSmart();
	dlg.m_nWizard = 0; // this isn't real good

	// invoke the dialog
	if (dlg.DoModal() == IDOK)
	{
		// get the data
		livyHand.m_strName = dlg.m_strUser;
		rogerHand.m_strName = dlg.m_strComputer;
		rogerHand.SetSmart(dlg.m_bSmart);
		
		switch (dlg.m_nWizard)
		{
			case 0:
				rogerHand.SetPicture(IDB_WIZARD);
				break;
			case 1:
				rogerHand.SetPicture(IDB_NERD);
				break;
			case 2:
				rogerHand.SetPicture(IDB_COMPUTE);
				break;
			case 3:
				rogerHand.SetPicture(IDB_COWBOY);
				break;
			default:
				rogerHand.SetPicture(IDB_WIZARD);
				break;
		}

		// need to repaint
		Invalidate();
	}

	return;
}

//------------------------------------------------------------------------
// CMainFrame private member functions

// draw a bitmap on the screen
void CMainFrame::BlastBitmap(CRect rect, UINT img)
{
	CClientDC dc(this);				// painting device context
	CDC dcMem;						// memory device context
	dcMem.CreateCompatibleDC(&dc);

	// get the coordinates for drawing
	int x      = (rect.TopLeft()).x;
	int y      = (rect.TopLeft()).y;
	int width  = rect.Width();
	int height = rect.Height();
	
	// draw the image
	CBitmap bmp;
	bmp.LoadBitmap(img);
	
	CBitmap* pOldBmp = dcMem.SelectObject(&bmp);
	dc.BitBlt(x, y, width, height, &dcMem, 0, 0, SRCCOPY);
	
	bmp.DeleteObject();

	// hose the memory device context
	dcMem.DeleteDC();

	return;
}
//////////////////////////////////////////////////////////////////////////

