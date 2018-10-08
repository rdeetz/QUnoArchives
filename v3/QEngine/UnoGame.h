/////////////////////////////////////////////////////////////////////
//
// UnoGame.h - definition of the UnoGame object for the 
//             RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#ifndef __UNOGAME_H_
#define __UNOGAME_H_

#include "resource.h"

#include "UnoGameCP.h"
#include "UnoPlayersIter.h"

#define Q_DEFAULT_HANDSIZE  5

#define Q_MIN_PLAYERSSIZE   2
#define Q_MIN_HANDSIZE      1

#define Q_DRAWCOUNT_FOUR    4
#define Q_DRAWCOUNT_TWO     2

#define Q_UNO               1

// CUnoGame

class ATL_NO_VTABLE CUnoGame : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CUnoGame, &CLSID_UnoGame>,
    public IDispatchImpl<IUnoGame, &IID_IUnoGame, &LIBID_QEngineLib>,
    public IUnoGameCmd,
    public CProxyIUnoGameEvents<CUnoGame>,
    public IConnectionPointContainerImpl<CUnoGame>, 
    public IProvideClassInfo2Impl<&CLSID_UnoGame, &DIID_IUnoGameEvents, &LIBID_QEngineLib>, 
    public IPersistPropertyBagImpl<CUnoGame>,
    public IObjectSafetyImpl<CUnoGame, (INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA)>
{
public:
    CUnoGame();
    ~CUnoGame();

    DECLARE_REGISTRY_RESOURCEID(IDR_UNOGAME)
    DECLARE_NOT_AGGREGATABLE(CUnoGame)

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP(CUnoGame)
        COM_INTERFACE_ENTRY(IUnoGame)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IUnoGameCmd)
        COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
        COM_INTERFACE_ENTRY(IProvideClassInfo)
        COM_INTERFACE_ENTRY_IMPL(IPersistPropertyBag)
        COM_INTERFACE_ENTRY(IObjectSafety)
    END_COM_MAP()

    BEGIN_CONNECTION_POINT_MAP(CUnoGame)
        CONNECTION_POINT_ENTRY(DIID_IUnoGameEvents)
    END_CONNECTION_POINT_MAP()

    BEGIN_PROP_MAP(CUnoGame)
        PROP_ENTRY("HandSize", DISPID_UNOGAME_HANDSIZE, CLSID_NULL)
        PROP_ENTRY("PlayAfterDraw", DISPID_UNOGAME_PLAYAFTERDRAW, CLSID_NULL)
    END_PROP_MAP()

    // IPersistPropertyBagImpl relies on your class deriving from 
    // CComControl...  this mimmicks the portion of CComControl
    // that IPersistPropertyBagImpl uses
    BOOL GetDirty() { return m_bRequiresSave; }
    void SetDirty(BOOL bDirty) { m_bRequiresSave = bDirty; }
    BOOL m_bRequiresSave;

// IUnoGame
public:
    STDMETHOD(get_Title)(BSTR* pbstrTitle);
    STDMETHOD(put_Title)(BSTR bstrTitle);
    STDMETHOD(get_Players)(IUnoPlayers** ppPlayers);
    STDMETHOD(get_Deck)(IUnoDeck** ppDeck);
    STDMETHOD(get_WildColor)(UnoColor* peWildColor);
    STDMETHOD(put_WildColor)(UnoColor eWildColor);
    STDMETHOD(CreatePlayer)(BSTR bstrName, UnoPlayerType eType, IUnoPlayer** ppPlayer);
    STDMETHOD(Start)();
    STDMETHOD(Stop)();
    STDMETHOD(IsCardPlayable)(IUnoCard* pCard, VARIANT_BOOL* pbIsCardPlayable);
    STDMETHOD(get_HandSize)(long* plHandSize);
    STDMETHOD(put_HandSize)(long lHandSize);
    STDMETHOD(get_PlayAfterDraw)(VARIANT_BOOL* pbPlayAfterDraw);
    STDMETHOD(put_PlayAfterDraw)(VARIANT_BOOL bPlayAfterDraw);

// IUnoGameCmd
public:
    STDMETHOD(Draw)(IUnoCard** ppCard);
    STDMETHOD(Play)(IUnoCard* pCard, VARIANT_BOOL* pbPlayed);
    STDMETHOD(Pass)(VARIANT_BOOL* pbPassed);
    STDMETHOD(TurnCompleted)();

private:
    void DealCards(long lPlayerCount);
    void InitializePlayersIter(long lPlayerCount);
    void TerminatePlayersIter();
    void PlayFirstCard();
    void MakePlayerChooseWildColor(UnoPlayersIterType eIterType);
    void MakePlayerDraw(UnoPlayersIterType eIterType, long lHowMany);
    bool CanPlayerPass(UnoPlayersIterType eIterType);
    bool IsCardWild(IUnoCard* pCard);
    bool CheckPlayers();
    void DoNextPlayer();

    CComBSTR m_bstrTitle;
    CComPtr<IUnoPlayers> m_spPlayers;
    CComPtr<IUnoDeck> m_spDeck;
    UnoColor m_eWildColor;
    long m_lHandSize;
    VARIANT_BOOL m_bPlayAfterDraw;
    bool m_bGameInProgress;
    long m_lLastPlayerToDraw;

    CUnoPlayersIter m_PlayersIter;

};

#endif //__UNOGAME_H_
