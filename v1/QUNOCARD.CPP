//////////////////////////////////////////////////////////////////////////
// QUno
// Roger Deetz, 1997
//
// qunocard.cpp - implementation of the data classes
//                CCard, the individual cards
//                CHand, the hands of the players
//                CDeck, the deck of cards
//                CPickColor, the dialog support for Wild cards

#include <stdlib.h>
#include "stdafx.h"
#include "qunocard.h"

//////////////////////////////////////////////////////////////////////////
// CPickColor
//   the Wild color dialog support class

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
	//DDX_Control(pDX, IDC_COLOR, m_ctlColor);
	DDX_Radio(pDX, IDC_RED, m_bRed);
	//}}AFX_DATA_MAP
}

void CPickColor::OnRed() 
{
	// when clicked, change the color box to red
	//m_hbmpColor = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_RED));
	//m_ctlColor.SetBitmap(m_hbmpColor);

	return;
}

void CPickColor::OnBlue() 
{
	// when clicked, change the color box to blue
	//m_hbmpColor = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BLUE));
	//m_ctlColor.SetBitmap(m_hbmpColor);

	return;
}

void CPickColor::OnYellow() 
{
	// when clicked, change the color box to yellow
	//m_hbmpColor = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_YELLOW));
	//m_ctlColor.SetBitmap(m_hbmpColor);

	return;
}

void CPickColor::OnGreen() 
{
	// when clicked, change the color box to green
	//m_hbmpColor = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_GREEN));
	//m_ctlColor.SetBitmap(m_hbmpColor);

	return;
}

void CPickColor::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// clean up the bitmaps
	::DeleteObject(m_hbmpColor);

	return;
}

BEGIN_MESSAGE_MAP(CPickColor, CDialog)
	//{{AFX_MSG_MAP(CPickColor)
	ON_BN_CLICKED(IDC_RED, OnRed)
	ON_BN_CLICKED(IDC_BLUE, OnBlue)
	ON_BN_CLICKED(IDC_YELLOW, OnYellow)
	ON_BN_CLICKED(IDC_GREEN, OnGreen)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// CCard 
//   the card class

//------------------------------------------------------------------------
// CCard construction and destruction

CCard::CCard()
{
	// uninitialize members
	m_Value  = UNO_ZERO;
	m_Color  = UNO_NOCOLOR;
	m_Bitmap = 0;
}

CCard::CCard(value v, color c, UINT bmp)
{
	// initialize members
	m_Value  = v;
	m_Color  = c;
	m_Bitmap = bmp;
}

CCard::~CCard()
{

}

//------------------------------------------------------------------------
// CCard accessors

value CCard::GetValue()
{
	return m_Value;
}

color CCard::GetColor()
{
	return m_Color;
}

UINT CCard::GetBitmap()
{
	return m_Bitmap;
}
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// CHand 
//   the cosmic hand class

//------------------------------------------------------------------------
// CHand construction and destruction

CHand::CHand()
{

}

CHand::CHand(CString strName)
{
	m_strName = strName;
}

CHand::~CHand()
{
	// hose all the cards left in this hand
	CCard* pCard;
	
	for (int i = 0; i < (GetSize() - 1); i++)
	{
		pCard = (CCard*)m_Hand.GetAt(i);
		delete pCard;
	}
	
	m_Hand.RemoveAll();
}

//------------------------------------------------------------------------
// CHand accessors

int CHand::GetSize()
{
	return m_Hand.GetSize();
}

//------------------------------------------------------------------------
// CHand operations

BOOL CHand::AddCard(CCard* pCard)
{
	// if the max number of cards has been reached, don't add one
	if (m_Hand.GetSize() >= UNO_HAND_MAXSIZE)
	{
		CString msg;
		msg = "You can't add any more cards to your hand, " + m_strName;
		AfxMessageBox(msg, MB_OK | MB_ICONINFORMATION);
		return FALSE;
	}
			
	// otherwise add a card to the hand
	m_Hand.Add(pCard);
		
	return TRUE;		
}

CCard* CHand::RemoveCard(int idx)
{
	// check if out of bounds
	if (idx > m_Hand.GetUpperBound()) return NULL;
	
	// otherwise get rid of the requested card
	CCard* pCard;
	
	pCard = (CCard*)m_Hand.GetAt(idx);
	m_Hand.RemoveAt(idx);
	
	return pCard;
}

CCard* CHand::PeekCard(int idx)
{
	// check if out of bounds
	if (idx > m_Hand.GetUpperBound()) return NULL;

	// otherwise return the requested card	
	return (CCard*)m_Hand.GetAt(idx);		
}

BOOL CHand::Playable(CCard* pSource, CCard* pTarget, color wild)
{
	// if their card is Wild, they can definitely play
	if (pSource->GetValue() == UNO_WILD)
		return TRUE;
    
    // get the other options    
 	color c;
	value v;
	
	if (pTarget->GetValue() == UNO_WILD)
	{
		c = wild;
	}
	else 
	{
		c = pTarget->GetColor();
	}
		
	v = pTarget->GetValue();
	
	if ( (pSource->GetValue() == v) || 
	     (pSource->GetColor() == c) )
		return TRUE;
	
	return FALSE;		
}

int CHand::CanPlay(CCard* pTarget, color c)
{
	// check all the cards in their hand
	CCard* pCard;
	
	for (int i = 0; i <= m_Hand.GetUpperBound(); i++) 
	{
		pCard = PeekCard(i); 
		if (Playable(pCard, pTarget, c)) return i;
	}
	
	return -1;
}

void CHand::Play(CDeck* pDeck, int idx, CHand* pNextHand)
{
	CCard* pCard = RemoveCard(idx);
	pDeck->PushCard(pCard, pNextHand);
	IsUno();
	
	return;
}

void CHand::Draw(CDeck* pDeck, int num)
{
	CCard* pCard;
	
	// loop through however many cards they're supposed to draw
	for (int i = num; i > 0; i--)
	{
		pCard = pDeck->PopCard();
		AddCard(pCard);
	}
	
	return;
}
	
void CHand::IsUno()
{
	// check for Uno
	if (m_Hand.GetSize() == 1)
	{
		CString msg;
		msg = m_strName + " has Uno!";
		AfxMessageBox(msg, MB_OK | MB_ICONINFORMATION);
	}

	return;		
}

BOOL CHand::IsEmpty()
{
	// check for a winner
	if (m_Hand.GetSize() == 0)
	{
		CString msg;
		msg = "Congratulations! " + m_strName + " wins!";
		AfxMessageBox(msg, MB_OK | MB_ICONEXCLAMATION);
		return TRUE;
	}

	return FALSE;
}
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// CDeck 
//   the deck class

//------------------------------------------------------------------------
// CDeck construction and destruction

CDeck::CDeck()
{
	// initialize the regular members
	m_bUserTurn   = TRUE;
	m_colorWild   = UNO_NOCOLOR;
	m_bGameInProg = FALSE;
	m_pCurrent    = NULL;
	
	// add the cards to the deck
	m_Deck.AddHead(new CCard(UNO_ZERO, UNO_RED, ID_RED_ZERO));
	m_Deck.AddHead(new CCard(UNO_ONE, UNO_RED, ID_RED_ONE));
	m_Deck.AddHead(new CCard(UNO_TWO, UNO_RED, ID_RED_TWO));
	m_Deck.AddHead(new CCard(UNO_THREE, UNO_RED, ID_RED_THREE));
	m_Deck.AddHead(new CCard(UNO_FOUR, UNO_RED, ID_RED_FOUR));
	m_Deck.AddHead(new CCard(UNO_FIVE, UNO_RED, ID_RED_FIVE));
	m_Deck.AddHead(new CCard(UNO_SIX, UNO_RED, ID_RED_SIX));
	m_Deck.AddHead(new CCard(UNO_SEVEN, UNO_RED, ID_RED_SEVEN));
	m_Deck.AddHead(new CCard(UNO_EIGHT, UNO_RED, ID_RED_EIGHT));
	m_Deck.AddHead(new CCard(UNO_NINE, UNO_RED, ID_RED_NINE));
	m_Deck.AddHead(new CCard(UNO_SKIP, UNO_RED, ID_RED_SKIP));
	m_Deck.AddHead(new CCard(UNO_DRAWTWO, UNO_RED, ID_RED_DRAWTWO));
	
	m_Deck.AddHead(new CCard(UNO_ZERO, UNO_BLUE, ID_BLUE_ZERO));
	m_Deck.AddHead(new CCard(UNO_ONE, UNO_BLUE, ID_BLUE_ONE));
	m_Deck.AddHead(new CCard(UNO_TWO, UNO_BLUE, ID_BLUE_TWO));
	m_Deck.AddHead(new CCard(UNO_THREE, UNO_BLUE, ID_BLUE_THREE));
	m_Deck.AddHead(new CCard(UNO_FOUR, UNO_BLUE, ID_BLUE_FOUR));
	m_Deck.AddHead(new CCard(UNO_FIVE, UNO_BLUE, ID_BLUE_FIVE));
	m_Deck.AddHead(new CCard(UNO_SIX, UNO_BLUE, ID_BLUE_SIX));
	m_Deck.AddHead(new CCard(UNO_SEVEN, UNO_BLUE, ID_BLUE_SEVEN));
	m_Deck.AddHead(new CCard(UNO_EIGHT, UNO_BLUE, ID_BLUE_EIGHT));
	m_Deck.AddHead(new CCard(UNO_NINE, UNO_BLUE, ID_BLUE_NINE));
	m_Deck.AddHead(new CCard(UNO_SKIP, UNO_BLUE, ID_BLUE_SKIP));
	m_Deck.AddHead(new CCard(UNO_DRAWTWO, UNO_BLUE, ID_BLUE_DRAWTWO));

	m_Deck.AddHead(new CCard(UNO_ZERO, UNO_YELLOW, ID_YELLOW_ZERO));
	m_Deck.AddHead(new CCard(UNO_ONE, UNO_YELLOW, ID_YELLOW_ONE));
	m_Deck.AddHead(new CCard(UNO_TWO, UNO_YELLOW, ID_YELLOW_TWO));
	m_Deck.AddHead(new CCard(UNO_THREE, UNO_YELLOW, ID_YELLOW_THREE));
	m_Deck.AddHead(new CCard(UNO_FOUR, UNO_YELLOW, ID_YELLOW_FOUR));
	m_Deck.AddHead(new CCard(UNO_FIVE, UNO_YELLOW, ID_YELLOW_FIVE));
	m_Deck.AddHead(new CCard(UNO_SIX, UNO_YELLOW, ID_YELLOW_SIX));
	m_Deck.AddHead(new CCard(UNO_SEVEN, UNO_YELLOW, ID_YELLOW_SEVEN));
	m_Deck.AddHead(new CCard(UNO_EIGHT, UNO_YELLOW, ID_YELLOW_EIGHT));
	m_Deck.AddHead(new CCard(UNO_NINE, UNO_YELLOW, ID_YELLOW_NINE));
	m_Deck.AddHead(new CCard(UNO_SKIP, UNO_YELLOW, ID_YELLOW_SKIP));
	m_Deck.AddHead(new CCard(UNO_DRAWTWO, UNO_YELLOW, ID_YELLOW_DRAWTWO));

	m_Deck.AddHead(new CCard(UNO_ZERO, UNO_GREEN, ID_GREEN_ZERO));
	m_Deck.AddHead(new CCard(UNO_ONE, UNO_GREEN, ID_GREEN_ONE));
	m_Deck.AddHead(new CCard(UNO_TWO, UNO_GREEN, ID_GREEN_TWO));
	m_Deck.AddHead(new CCard(UNO_THREE, UNO_GREEN, ID_GREEN_THREE));
	m_Deck.AddHead(new CCard(UNO_FOUR, UNO_GREEN, ID_GREEN_FOUR));
	m_Deck.AddHead(new CCard(UNO_FIVE, UNO_GREEN, ID_GREEN_FIVE));
	m_Deck.AddHead(new CCard(UNO_SIX, UNO_GREEN, ID_GREEN_SIX));
	m_Deck.AddHead(new CCard(UNO_SEVEN, UNO_GREEN, ID_GREEN_SEVEN));
	m_Deck.AddHead(new CCard(UNO_EIGHT, UNO_GREEN, ID_GREEN_EIGHT));
	m_Deck.AddHead(new CCard(UNO_NINE, UNO_GREEN, ID_GREEN_NINE));
	m_Deck.AddHead(new CCard(UNO_SKIP, UNO_GREEN, ID_GREEN_SKIP));
	m_Deck.AddHead(new CCard(UNO_DRAWTWO, UNO_GREEN, ID_GREEN_DRAWTWO));

	// add the Wilds to the deck	
	for (int i = 0; i < 4; i++)
	{
		m_Deck.AddHead(new CCard(UNO_WILD, UNO_NOCOLOR, ID_WILD));
	}
}

CDeck::~CDeck()
{
	// delete all the stuff in the deck and the stack
	POSITION pos;
	CCard* pCard;

	// first the deck	
	pos = m_Deck.GetHeadPosition();
	
	while (pos != NULL)
	{
		pCard = (CCard*)m_Deck.GetAt(pos);
		delete pCard;
		m_Deck.GetNext(pos);
	}
	
	m_Deck.RemoveAll();

	// now the stack
	pos = m_Stack.GetHeadPosition();
	
	while (pos != NULL)
	{
		pCard = (CCard*)m_Stack.GetAt(pos);
		delete pCard;
		m_Stack.GetNext(pos);
	}
	
	m_Stack.RemoveAll();
}

//------------------------------------------------------------------------
// CDeck accessors

BOOL CDeck::UserTurn()
{
	return m_bUserTurn;
}

color CDeck::GetWildColor()
{
	return m_colorWild;
}

CCard* CDeck::GetCurrentCard()
{
	return m_pCurrent;
}

//------------------------------------------------------------------------
// CDeck operations

void CDeck::ChangePlayer()
{
	m_bUserTurn = !m_bUserTurn;

	return;
}

void CDeck::SetWildColor(color c)
{
	m_colorWild = c;
	
	return;
}

void CDeck::ShuffleDeck(CObList& deck)
{
	// initialize the randomness
	srand((unsigned)time(NULL));
    
    int ct = deck.GetCount();
    POSITION pos;
    
	for (int i = 0; i < ct; i++)
	{
		int j = rand() % ct;
		
		pos = deck.FindIndex(j);
		CCard* temp = (CCard*)deck.GetAt(pos);
		deck.RemoveAt(pos);
		deck.AddHead(temp);
	}
		
	return;		
}

void CDeck::NewGame(CHand* hand1, CHand* hand2)
{
	// if we're in the middle of a game, we need to collect the cards
	if (m_bGameInProg)
	{
		// get the cards from the players
		while (hand1->GetSize() != 0) 
		{
			m_Deck.AddHead(hand1->RemoveCard(0));
		}
		
		while (hand2->GetSize() != 0) 
		{
			m_Deck.AddHead(hand2->RemoveCard(0));
		}
        
        // get the cards from the stack
	    CCard* pCard;
	    
		while (!m_Stack.IsEmpty())
		{
			pCard = (CCard*)m_Stack.RemoveHead();
			m_Deck.AddHead(pCard);
		}
	}	
    
    // reset the flag
    m_bGameInProg = FALSE;
    
	// shuffle the deck
	ShuffleDeck(m_Deck);
	
	// deal the cards
	CCard* pCard1; 
	CCard* pCard2; 
	
	for (int j = 0; j < UNO_HAND_INITSIZE; j++)
	{
		pCard1 = (CCard*)m_Deck.RemoveHead();
		hand1->AddCard(pCard1);
		pCard2 = (CCard*)m_Deck.RemoveHead();
		hand2->AddCard(pCard2);
	}
	
	// get the top non-Wild card and set it as the current card
	CCard* pCard = PopCard();

	while (pCard->GetValue() == UNO_WILD) 
	{
		PushCard(pCard);
		pCard = PopCard();
	}
	
	SetWildColor(UNO_NOCOLOR);
	PushCard(pCard); 

	// now a game is in progress
	m_bUserTurn = TRUE;
	m_bGameInProg = TRUE;
	
	return;		
}

CCard* CDeck::PopCard()
{
	// get the top card off the deck
	CCard* pCard;
	pCard = (CCard*)m_Deck.RemoveHead();
	
	// check if we need to need to reshuffle
	if (m_Deck.IsEmpty())
	{
		// save the top card on the stack
		CCard* current;
		current = (CCard*)m_Stack.RemoveHead();
		
		// shuffle the stack and put them back in the deck
		ShuffleDeck(m_Stack);
		m_Deck.AddHead(&m_Stack);
		m_Stack.RemoveAll();
		
		// reset the current card
		PushCard(current);
	}
		
	return pCard;		
}

void CDeck::PushCard(CCard* pNewCard, CHand* nextHand)
{
	// put the card on the top of the stack
	m_Stack.AddHead(pNewCard);
	m_pCurrent = pNewCard;
    
    // if we are dealing for the first time, get out
    if (!m_bGameInProg) return;
    
	// otherwise do something special if needed
	CPickColor colorDlg;

	switch (pNewCard->GetValue()) 
	{
		case UNO_WILD:
			// get and set the Wild color
			colorDlg.DoModal();
			
			switch (colorDlg.m_bRed) 
			{
				case 0:
					SetWildColor(UNO_RED);
					break;
				case 1:
					SetWildColor(UNO_BLUE);
					break;
				case 2:
					SetWildColor(UNO_YELLOW);
					break;
				case 3:
					SetWildColor(UNO_GREEN);
					break;
				default:
					SetWildColor(UNO_NOCOLOR);
					break;
			}
						
			ChangePlayer();
			break;
		
		case UNO_SKIP:
			m_colorWild = UNO_NOCOLOR;
			break;
			
		case UNO_DRAWTWO:
			m_colorWild = UNO_NOCOLOR;
			nextHand->Draw(this, 2);
			break;
			
		default:
			m_colorWild = UNO_NOCOLOR;
			ChangePlayer();
			break;
	}
	
	return;		
}
//////////////////////////////////////////////////////////////////////////

