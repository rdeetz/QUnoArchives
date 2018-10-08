//////////////////////////////////////////////////////////////////////////
// QUno
// Roger Deetz, 1997
//
// qunocard.h - definition of the data classes
//              CCard, the individual cards
//              CDeck, the deck of cards
//              CHand, the hands of the players
//              CPickColor, the dialog support for Wild cards

#include "resource.h"

// constants for the value of the cards
enum value { UNO_WILD = -1, UNO_ZERO  = 0, UNO_ONE   = 1, UNO_TWO   = 2,
             UNO_THREE = 3, UNO_FOUR  = 4, UNO_FIVE  = 5, UNO_SIX   = 6, 
             UNO_SEVEN = 7, UNO_EIGHT = 8, UNO_NINE  = 9, UNO_SKIP  = 10,
             UNO_DRAWTWO = 11 }; 

// constants for the color of the cards
enum color { UNO_NOCOLOR = 0, UNO_RED = 1, UNO_BLUE = 2, UNO_YELLOW = 3, 
             UNO_GREEN = 4 };

// constants for various things
const UNO_HAND_INITSIZE = 5;
const UNO_HAND_MAXSIZE  = 10;

// forward declaration (so CHand can see CDeck coming)
class CDeck;

//////////////////////////////////////////////////////////////////////////
// CPickColor
//   the Wild card dialog class

class CPickColor : public CDialog
{
public:
	// construction and destruction
	CPickColor(CWnd* pParent = NULL);	// standard constructor

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
	CHand(CString strName);
	~CHand();

	// accessors
	int GetSize();
		
	// operations
	CCard* PeekCard(int idx);
	BOOL   Playable(CCard* pSource, CCard* pTarget, color c = UNO_NOCOLOR);
	int    CanPlay(CCard* pTarget, color c = UNO_NOCOLOR);
	void   Play(CDeck* pDeck, int idx, CHand* pNextHand);
	void   Draw(CDeck* pDeck, int num);
	void   IsUno();
	BOOL   IsEmpty();

	// member variables
	CString m_strName;

protected:
	// operations
	BOOL   AddCard(CCard* pCard);
	
private:
	// operations
	CCard* RemoveCard(int idx);

private:
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
	CCard* GetCurrentCard();
	
	// operations
	void   ChangePlayer();
	void   NewGame(CHand* hand1, CHand* hand2);
	CCard* PopCard();
	void   PushCard(CCard* pNewCard, CHand* nextHand = NULL);

private:
	// operations
	void   SetWildColor(color c);
	void   ShuffleDeck(CObList& deck);
		
private:
	BOOL    m_bGameInProg;		// whether a game is in going on
	BOOL    m_bUserTurn;		// whether or not it is Livy's turn
	color   m_colorWild;		// color of the Wild card (if active)
	CCard*  m_pCurrent;			// the currently active card
	CObList m_Deck;				// the cards left in the deck
	CObList m_Stack; 			// the cards on the stack (played)
	
};
//////////////////////////////////////////////////////////////////////////

