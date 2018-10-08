//////////////////////////////////////////////////////////////////////////
// RogCorp QUno
// version 2.0
//
//        File:  qunocard.cpp
// Description:  implementation of the data classes - 
//               CCard, the individual cards
//               CHand, the hands of the players
//               CDeck, the deck of cards
//     Revised:  08/21/97
//
// Copyright © 1997 Roger Deetz

#include <stdlib.h>
#include "stdafx.h"
#include "qunocard.h"
#include "qdialogs.h"


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
	// uninitialize members
	m_bHuman     = TRUE;
	m_bSmart     = FALSE;
	m_imgPicture = 0;
	m_strName    = "Player";
}

CHand::CHand(BOOL bHuman, CString strName)
{
	// initialize members
	m_bHuman = bHuman;
	m_bHuman ? m_bSmart = FALSE : m_bSmart = TRUE;
	m_bHuman ? m_imgPicture = 0 : m_imgPicture = IDB_WIZARD;
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

BOOL CHand::IsSmart()
{
	return m_bSmart;
}

UINT CHand::GetPicture()
{
	return m_imgPicture;
}

int CHand::GetSize()
{
	return m_Hand.GetSize();
}

//------------------------------------------------------------------------
// CHand mutators

void CHand::SetSmart(BOOL bSmart)
{
	// if not a computer, get out
	if (m_bHuman) return;

	m_bSmart = bSmart;

	return;
}

void CHand::SetPicture(UINT img)
{
	// if not a computer, get out
	if (m_bHuman) return;

	m_imgPicture = img;

	return;
}

//------------------------------------------------------------------------
// CHand operations

void CHand::Play(CDeck* pDeck, int idx, CHand* pNextHand)
{
	// play the valid card and check for Uno
	CCard* pCard = RemoveCard(idx);
	
	if (pCard != NULL)
	{
		pDeck->PushCard(pCard, this, pNextHand);
		IsUno();

		// check for game over
		if (IsEmpty())
		{
			// establish the order for next game (this isn't real good)
			if (m_bHuman)
				pDeck->NewGame(this, pNextHand);
			else
				pDeck->NewGame(pNextHand, this);
		}
	}

	return;
}

void CHand::Draw(CDeck* pDeck, int num)
{
	// if the max number of cards has been reached, don't add any
	if (GetSize() >= UNO_HAND_MAXSIZE)
	{
		CString msg;
		msg = "You can't add any more cards to your hand, " + m_strName;
		AfxMessageBox(msg, MB_OK | MB_ICONINFORMATION);

		// may not need this depending on rules of game
		pDeck->ChangePlayer();

		return;
	}
	
	// otherwise loop through however many cards they're supposed to draw
	for (int i = num; i > 0; i--)
	{
		AddCard(pDeck->PopCard());
	}
	
	// may not need this depending on rules of game
	pDeck->ChangePlayer();

	return;
}

void CHand::TakeTurn(CDeck* pDeck, CHand* nextHand)
{
	// see if they can play at all
	int index = CanPlay(pDeck);

	if (index != UNO_NOPLAY)
	{
		// play a card 
		Play(pDeck, index, nextHand);
	}
	else 
	{
		// draw a card
		Draw(pDeck, 1);
	}

	return;
}

color CHand::AskWildColor()
{
	// get the player's or computer's color choice

	// check for and do if computer
	if (!m_bHuman)
	{
		return FindColor(&m_Hand);
	}

	// must be  a human, so let 'em pick via dialog
	color choice;

	CPickColor colorDlg;
	colorDlg.DoModal();
			
	switch (colorDlg.m_bRed) 
	{
		case 0:
			choice = UNO_RED;
			break;
		case 1:
			choice = UNO_BLUE;
			break;
		case 2:
			choice = UNO_YELLOW;
			break;
		case 3:
			choice = UNO_GREEN;
			break;
		default:
			choice = UNO_NOCOLOR;
			break;
	}

	return choice;
}

CCard* CHand::PeekCard(int idx)
{
	// check if out of bounds
	if (idx > m_Hand.GetUpperBound()) return NULL;

	// otherwise return the requested card	
	return (CCard*)m_Hand.GetAt(idx);		
}

BOOL CHand::Playable(int idx, CDeck* pDeck)
{
	// get the requested card
	CCard* pSource = PeekCard(idx);

	// if no card, get out
	if (pSource == NULL) 
		return FALSE;

	// if their card is Wild, they can definitely play
	if (pSource->GetValue() < UNO_ZERO)
		return TRUE;
    
    // get the other options    
	CCard* pTarget = pDeck->GetCurrentCard();
	value  v = pTarget->GetValue();
	color  c;
	
	if (v < UNO_ZERO)
		c = pDeck->GetWildColor();
	else 
		c = pTarget->GetColor();
		
	if ( (pSource->GetValue() == v) || 
	     (pSource->GetColor() == c) )
		return TRUE;
	
	return FALSE;		
}

void CHand::AddCard(CCard* pCard)
{
	// add a card to the hand
	m_Hand.Add(pCard);
		
	return;		
}

CCard* CHand::RemoveCard(int idx)
{
	// check if out of bounds
	if (idx > m_Hand.GetUpperBound()) return NULL;
	
	// otherwise remove and return the requested card
	CCard* pCard;
	
	pCard = (CCard*)m_Hand.GetAt(idx);
	m_Hand.RemoveAt(idx);
	
	return pCard;
}

int CHand::CanPlay(CDeck* pDeck)
{
	int i, j;

	CUIntArray playset;		// this is an array of indices, not cards
	CUIntArray playables;	// array of totals per playable card

	playset.SetSize(0);

	// determine which card, if any, the computer should play
	if (IsSmart())
	{
		// this is the smart method
		for (i = 0; i <= m_Hand.GetUpperBound(); i++)
		{
			if (Playable(i, pDeck))
			{
				// add the 'playable' index to the array
				playset.Add(i) ;
			}
		}

		// check for no playable cards
		if (playset.GetSize() == 0)
			return UNO_NOPLAY;

		// set up array of totals
		playables.SetSize(playset.GetSize());

		UINT current, total = 0;

		// loop thru each playable card
		for (i = 0; i <= playset.GetUpperBound(); i++)
		{
			current = playset[i];

			// compare each card in their hand against current playable card
			for (j = 0; j <= m_Hand.GetUpperBound(); j++)
			{
				if (CanThisCardPlayAgainst(j, current))
				{
					total++;
				}
			}

			// set the total for the current playable card
			playables[i] = total;
			total = 0;
		}

		// sort totals
		UINT nswap, cswap;

		for (i = 0; i < playset.GetUpperBound(); i++)
		{
			if (playables[i] > playables[i+1])
			{
				// trade the values
				nswap          = playables[i];
				playables[i]   = playables[i+1];
				playables[i+1] = nswap;
				
				// trade the original indices
				cswap        = playset[i];
				playset[i]   = playset[i+1];
				playset[i+1] = cswap;
			}
		}

		return playset[0];
	}
	else
	{
		// this is the dumb method
		for (i = 0; i <= m_Hand.GetUpperBound(); i++) 
		{
			if (Playable(i, pDeck)) return i;
		}
	}

	return UNO_NOPLAY;
}

BOOL CHand::CanThisCardPlayAgainst(int idxSource, int idxTarget)
{
	// get the requested card
	CCard* pSource = PeekCard(idxSource);

	// if no card, get out
	if (pSource == NULL) 
		return FALSE;

	// if their card is Wild, they can definitely play
	if (pSource->GetValue() < UNO_ZERO)
		return TRUE;
    
    // get the other options    
	CCard* pTarget = PeekCard(idxTarget);
	value  v = pTarget->GetValue();
	color  c;
	
	if (v < UNO_ZERO)
		return TRUE;
	else 
		c = pTarget->GetColor();
		
	if ( (pSource->GetValue() == v) || 
	     (pSource->GetColor() == c) )
		return TRUE;
	
	return FALSE;		
}

color CHand::FindColor(CObArray* hand)
{
	// find most common color
	CCard* pCard;
	int    counts[4] = {0, 0, 0, 0};
	int    nswap;
	color  colors[4] = {UNO_RED, UNO_BLUE, UNO_YELLOW, UNO_GREEN};
	color  cswap;
		
	// loop through cards to tally colors
	for (int i = 0; i <= hand->GetUpperBound(); i++)
	{
		pCard = (CCard*)hand->GetAt(i);

		switch (pCard->GetColor())
		{
			case UNO_RED:
				counts[0] += 1;
				break;

			case UNO_BLUE:
				counts[1] += 1;
				break;

			case UNO_YELLOW:
				counts[2] += 1;
				break;

			case UNO_GREEN:
				counts[3] += 1;
				break;

			default:
				break;
		}
	}

	// find the color that has the most
	for (int j = 0; j < 3; j++)
	{
		if (counts[j] > counts[j+1])
		{
			// trade the values
			nswap       = counts[j];
			counts[j]   = counts[j+1];
			counts[j+1] = nswap;
			
			// trade the names
			cswap       = colors[j];
			colors[j]   = colors[j+1];
			colors[j+1] = cswap;
		}
	}

	// the highest number will be in the last element
	return colors[3];
}

void CHand::IsUno()
{
	// check for Uno
	if (GetSize() == 1)
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
	if (GetSize() == 0)
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
	m_bGameInProg = FALSE;
	m_bUserTurn   = TRUE;

	m_colorWild   = UNO_NOCOLOR;
	m_imgDeck     = IDB_DECKHI;
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
	m_Deck.AddHead(new CCard(UNO_REVERSE, UNO_RED, ID_RED_REVERSE));
	
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
	m_Deck.AddHead(new CCard(UNO_REVERSE, UNO_BLUE, ID_BLUE_REVERSE));

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
	m_Deck.AddHead(new CCard(UNO_REVERSE, UNO_YELLOW, ID_YELLOW_REVERSE));

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
	m_Deck.AddHead(new CCard(UNO_REVERSE, UNO_GREEN, ID_GREEN_REVERSE));

	// add the Wilds to the deck	
	for (int i = 0; i < 4; i++)
	{
		m_Deck.AddHead(new CCard(UNO_WILD, UNO_NOCOLOR, ID_WILD));
		m_Deck.AddHead(new CCard(UNO_WILD_DRAWFOUR, UNO_NOCOLOR, ID_WILD_DRAWFOUR));
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

UINT CDeck::GetDeckImage()
{
	return m_imgDeck;
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

void CDeck::SetDeckImage(/*UINT img*/)
{
	int size = m_Deck.GetCount();

	if (size > 45) 
		m_imgDeck = IDB_DECKHI;

	else if (size > 30) 
		m_imgDeck = IDB_DECKHIMID;

	else if (size > 15) 
		m_imgDeck = IDB_DECKMID;

	else 
		m_imgDeck = IDB_DECKLO;

	return;
}

void CDeck::SetCurrentCard(CCard* pCard)
{
	m_Stack.AddHead(pCard);
	m_pCurrent = (CCard*)m_Stack.GetHead();

	return;
}

void CDeck::ShuffleDeck(CObList& deck)
{
	// initialize the randomness
	srand((unsigned)time(NULL));
    
    int count = deck.GetCount();
    POSITION pos;
    
	// shuffle the cards
	for (int i = 0; i < count; i++)
	{
		int j = rand() % count;
		
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

	while (pCard->GetValue() < UNO_ZERO) 
	{
		PushCard(pCard);
		pCard = PopCard();
	}
	
	PushCard(pCard); 

	SetWildColor(UNO_NOCOLOR);
	m_bUserTurn = TRUE; // this isn't real good
	
	// now a game is in progress
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
		SetCurrentCard(current);
	}
	
	// update the deck image
	SetDeckImage();

	return pCard;		
}

void CDeck::PushCard(CCard* pNewCard, CHand* thisHand, CHand* nextHand)
{
	// put the card on the top of the stack
	SetCurrentCard(pNewCard);
    
    // if we are dealing for the first time, get out
    if (!m_bGameInProg) return;
    
	// otherwise do something special if needed
	switch (pNewCard->GetValue()) 
	{
		case UNO_WILD_DRAWFOUR:
			// get and set the Wild color
			SetWildColor(thisHand->AskWildColor());
			nextHand->Draw(this, 4);
			break;
		
		case UNO_WILD:
			// get and set the Wild color
			SetWildColor(thisHand->AskWildColor());
			ChangePlayer();
			break;
		
		case UNO_SKIP:
			SetWildColor(UNO_NOCOLOR);
			break;
			
		case UNO_DRAWTWO:
			SetWildColor(UNO_NOCOLOR);
			nextHand->Draw(this, 2);
			break;

		case UNO_REVERSE:
			SetWildColor(UNO_NOCOLOR);
			break;
			
		default:
			SetWildColor(UNO_NOCOLOR);
			ChangePlayer();
			break;
	}
	
	return;		
}
//////////////////////////////////////////////////////////////////////////

