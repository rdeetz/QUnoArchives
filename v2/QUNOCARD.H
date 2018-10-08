//////////////////////////////////////////////////////////////////////////
// RogCorp QUno
// version 2.0
//
//        File:  qunocard.h
// Description:  definition of the data classes - 
//               CCard, the individual cards
//               CDeck, the deck of cards
//               CHand, the hands of the players
//     Revised:  08/21/97
//
// Copyright © 1997 Roger Deetz

// constants for the value of the cards
enum value { UNO_WILD_DRAWFOUR = -2, UNO_WILD = -1, UNO_ZERO = 0, 
			 UNO_ONE   =  1, UNO_TWO     =  2, UNO_THREE   = 3, 
             UNO_FOUR  =  4, UNO_FIVE    =  5, UNO_SIX     = 6, 
             UNO_SEVEN =  7, UNO_EIGHT   =  8, UNO_NINE    = 9, 
			 UNO_SKIP  = 10, UNO_DRAWTWO = 11, UNO_REVERSE = 12 }; 

// constants for the color of the cards
enum color { UNO_NOCOLOR = 0, 
             UNO_RED = 1, UNO_BLUE = 2, UNO_YELLOW = 3, UNO_GREEN = 4 };

// constants for various things
const UNO_HAND_INITSIZE = 5;
const UNO_HAND_MAXSIZE  = 10;
const UNO_NOPLAY        = -1;
const UNO_DRAW          = -2;

// forward declaration (so CHand can see CDeck coming)
class CDeck;


//////////////////////////////////////////////////////////////////////////
// CCard
//   the card class

class CCard : public CObject 
{
public:
	// construction and destruction
	CCard(); 
	CCard(value v, color c, UINT bmp); 		// initialized constructor
	~CCard();
	
	// accessors
	value GetValue();
	color GetColor();
	UINT  GetBitmap();

private:
	value m_Value;			// value of the card
	color m_Color;			// color of the card
	UINT  m_Bitmap; 		// resource ID for the bitmap of the card
	
};
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// CHand
//   the cosmic hand class

class CHand : public CObject
{
friend class CDeck;

public:
	// construction and destruction
	CHand(); 
	CHand(BOOL bHuman, CString strName);	// initialized constuctor
	~CHand();

	// attributes
	CString m_strName;

	// accessors
	BOOL   IsSmart();
	UINT   GetPicture();
	int    GetSize();

	// mutators
	void   SetSmart(BOOL bSmart);
	void   SetPicture(UINT img);

	// operations
	void   Play(CDeck* pDeck, int idx, CHand* pNextHand);
	void   Draw(CDeck* pDeck, int num);
	void   TakeTurn(CDeck* pDeck, CHand* nextHand);

	color  AskWildColor();

	CCard* PeekCard(int idx);
	BOOL   Playable(int idx, CDeck* pDeck);

protected:
	// operations
	void   AddCard(CCard* pCard);
	CCard* RemoveCard(int idx);
	
private:
	// operations
	int    CanPlay(CDeck* pDeck);
	BOOL   CanThisCardPlayAgainst(int idxSource, int idxTarget); // helper
	color  FindColor(CObArray* hand);	// helper function to get most common color
	void   IsUno();
	BOOL   IsEmpty();

private:
	BOOL     m_bHuman;			// whether or not this is a user 
	BOOL     m_bSmart;          // if computer, use intelligence?
	UINT     m_imgPicture;		// if computer, what picture?
	CObArray m_Hand;			// the cards in the hand
	
};
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// CDeck
//   the deck class

class CDeck : public CObject
{
public:
	// construction and destruction
	CDeck(); 
	~CDeck();
    
    // accessors
	BOOL   UserTurn();
	
	color  GetWildColor();
	UINT   GetDeckImage();
	CCard* GetCurrentCard();
	
	// operations
	void   ChangePlayer();
	void   NewGame(CHand* hand1, CHand* hand2);
	CCard* PopCard();
	void   PushCard(CCard* pNewCard, CHand* thisHand = NULL, CHand* nextHand = NULL);

private:
	// operations
	void   SetWildColor(color c);
	void   SetDeckImage(/*UINT img*/);
	void   SetCurrentCard(CCard* pCard);

	void   ShuffleDeck(CObList& deck);
		
private:
	BOOL    m_bGameInProg;		// whether a game is in going on
	BOOL    m_bUserTurn;		// whether or not it is the user's turn
	
	color   m_colorWild;		// color of the Wild card (if active)
	UINT    m_imgDeck;			// the deck image
	CCard*  m_pCurrent;			// the currently active card
	
	CObList m_Deck;				// the cards left in the deck
	CObList m_Stack; 			// the cards on the stack (played)
	
};
//////////////////////////////////////////////////////////////////////////

