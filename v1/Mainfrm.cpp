//////////////////////////////////////////////////////////////////////////
// QUno
// Roger Deetz, 1997
//
// mainfrm.h - implementation of the main window class CMainFrame

#include "stdafx.h"
#include "quno.h"
#include "mainfrm.h"
#include "qunocard.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

// the one and only deck and the hands
CDeck theDeck;
CHand livyHand("Livy");
CHand rogerHand("Roger");

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
	ON_COMMAND(ID_NEWGAME, OnNewGame)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//------------------------------------------------------------------------
// CMainFrame construction and destruction

CMainFrame::CMainFrame()
{
	
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

	// start a new game for the first time
	theDeck.NewGame(&livyHand, &rogerHand);

	return 0;
}

// draw the surface of the window
void CMainFrame::OnPaint()
{
	// draw the upper region of the game board
	
	CPaintDC dc(this);				// painting device context
	
	CDC dcMem;						// memory device context
	dcMem.CreateCompatibleDC(&dc);
	
	// the deck image
	CBitmap bmpDeck;
	bmpDeck.LoadBitmap(IDB_DECK);
	
	CBitmap* pOldDeckBmp = dcMem.SelectObject(&bmpDeck);
	dc.BitBlt(14, 14, 71, 101, &dcMem, 0, 0, SRCCOPY);
	bmpDeck.DeleteObject();
		
	// the stack container
	m_rectStack.SetRect(105, 20, 170, 115);
	dc.Rectangle(m_rectStack);

	CBitmap bmpStack;
	bmpStack.LoadBitmap(theDeck.GetCurrentCard()->GetBitmap());
	
	CBitmap* pOldStackBmp = dcMem.SelectObject(&bmpStack);
	dc.BitBlt(105, 20, 65, 95, &dcMem, 0, 0, SRCCOPY);
	bmpStack.DeleteObject();
	
	// the status indicators
	
	// get the current player
	if (theDeck.UserTurn())
	{
		dc.TextOut(195, 25, livyHand.m_strName + "'s Turn");
	}
	else
	{
		dc.TextOut(195, 25, rogerHand.m_strName + "'s Turn");
	}

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

	// get the number of cards in the Roger's hand and display it
	int size = rogerHand.GetSize();
	
	CString str;
	str.Format("Roger has %d cards left ", size);
	
	dc.TextOut(195, 91, str);
	                                
	// draw the lower region of the game board 
	
	CPoint pt(20, 140);				// starting point for the first card
	CBitmap bmp;					// temp bitmap to be used when drawing pictures
	CBitmap* pOldBmp;				// temp pointer for dcMem swapping
	
	// draw the rectangles to hold the array of cards
	for (int i = 0; i < UNO_HAND_MAXSIZE; i++)
	{
		m_rectCards[i].SetRect(pt.x, pt.y, pt.x + 65, pt.y + 95);
		dc.Rectangle(m_rectCards[i]);
		
		// after you've drawn the rect, check if Livy's hand
		// has a card for the i position; if so, load the bitmap of that card
		if (i < livyHand.GetSize()) 
		{
		 	bmp.LoadBitmap(livyHand.PeekCard(i)->GetBitmap());
		 	pOldBmp = dcMem.SelectObject(&bmp);
		 	dc.BitBlt(pt.x, pt.y, 65, 95, &dcMem, 0, 0, SRCCOPY);
		 	bmp.DeleteObject();
		}

		pt.x += 85;					// move to the position of the next card
		
		// check if it is time to start a new row
		if (i == (UNO_HAND_INITSIZE - 1))
		{
			pt.x = 20;
			pt.y = 255;
		}
	}
    
	// hose the memory device context
	dcMem.DeleteDC();

	// do not call CFrameWnd::OnPaint() for painting messages!
	return;
}

// exit the application
void CMainFrame::OnClose()
{
	// prompt the user to exit
	int nResult = MessageBox("Are you sure you want to quit?", "Exit", MB_YESNO | MB_ICONQUESTION);
	
	if (nResult == IDYES)
		CFrameWnd::OnClose();
	
	return;	
}

// here is what happends when the user moves over the window
void CMainFrame::OnMouseMove(UINT nFlags, CPoint point) 
{
	// if not Livy's turn, get out
	if (!theDeck.UserTurn())
		return;
	
	// device context for drawing
	CClientDC dc(this);
	CGdiObject* pOldBrush = dc.SelectStockObject(NULL_BRUSH);
	
	// check if they are over a card
	for (int i = 0; i < 10; i++)
	{
		if (m_rectCards[i].PtInRect(point))
		{
			CCard* pCard = livyHand.PeekCard(i);

			if (pCard != NULL)
			{
				// check if that card will play and change color
				COLORREF c;

				if (livyHand.Playable(pCard, theDeck.GetCurrentCard(), theDeck.GetWildColor()))
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
	// whose turn is it?
	if (!theDeck.UserTurn()) 
	{
		// do the stuff for Roger's turn
		int index = rogerHand.CanPlay(theDeck.GetCurrentCard(), theDeck.GetWildColor());
		
		if (index != -1)
		{
			// play a card 
			rogerHand.Play(&theDeck, index, &livyHand);
			
			// check for game over
			if (rogerHand.IsEmpty()) 
			{
		 		theDeck.NewGame(&livyHand, &rogerHand);
		 	}
		}
		else 
		{
			// draw a card
			rogerHand.Draw(&theDeck, 1);
			theDeck.ChangePlayer();
		}
	}
	else 
	{
		// do the stuff for Livy's turn
		int index = livyHand.CanPlay(theDeck.GetCurrentCard(), theDeck.GetWildColor());
		
		if (index == -1)
		{
			// draw a card
			livyHand.Draw(&theDeck, 1);
			theDeck.ChangePlayer();
		}
		else 
		{
			// check if she clicked a square
			for (int i = 0; i < 10; i++)
			{
				if (m_rectCards[i].PtInRect(point))
				{
					// check if there is a card there  
					CCard* pCard = livyHand.PeekCard(i);
					
					if (pCard != NULL)
					{	
						// check if that card will play
						if (livyHand.Playable(pCard, theDeck.GetCurrentCard(), theDeck.GetWildColor()))
						{
							// play the card
							livyHand.Play(&theDeck, i, &rogerHand);
							
							// check for game over
							if (livyHand.IsEmpty()) 
							{
								theDeck.NewGame(&livyHand, &rogerHand);
							}
						}
					} 
				}			
	  		}
		}
	}
	
	// update the display
	Invalidate();
	UpdateWindow();
	
	CFrameWnd::OnLButtonDown(nFlags, point);
}

//------------------------------------------------------------------------
// CMainFrame virtual overrides

// adjust the size of the new window
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// set the new size
	cs.cx = 440;
	cs.cy = 410;
	
	return CFrameWnd::PreCreateWindow(cs);
}

//------------------------------------------------------------------------
// CMainFrame commands

void CMainFrame::OnNewGame()
{
	// ask if they want a new game
	int nResult = MessageBox("Do you want to start a new game?", 
	                         "New Game", MB_YESNO | MB_ICONQUESTION);
	                                     
	if (nResult == IDYES) 
		theDeck.NewGame(&livyHand, &rogerHand);
			                                     
	// refresh the frame's display
	Invalidate();
	UpdateWindow();

	return;	
}

// display the new card on the stack
void CMainFrame::UpdateStack()
{

	return;	
}
