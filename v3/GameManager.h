/////////////////////////////////////////////////////////////////////
//
// GameManager.h - definition of the game manager object for the 
//                 RogCorp QUno 3.0 user interface
//
// Copyright © 2000-2001 Roger Deetz
//

#ifndef __GAMEMANAGER_H_
#define __GAMEMANAGER_H_

#include "resource.h"

#include "QEngine\QEngine.h"
#include "QEngine\QEDispID.h"

// CGameManager

class CGameManager :
    public IDispEventImpl<1, CGameManager, &DIID_IUnoGameEvents, &LIBID_QEngineLib>
{
public:
    CGameManager();
    ~CGameManager();

    BEGIN_SINK_MAP(CGameManager)
        SINK_ENTRY_EX(1, DIID_IUnoGameEvents, DISPID_UNOGAMEEVENTS_PLAYERTURN, OnPlayerTurn)
        SINK_ENTRY_EX(1, DIID_IUnoGameEvents, DISPID_UNOGAMEEVENTS_PLAYERCHOOSEWILDCOLOR, OnPlayerChooseWildColor)
        SINK_ENTRY_EX(1, DIID_IUnoGameEvents, DISPID_UNOGAMEEVENTS_PLAYERUNO, OnPlayerUno)
        SINK_ENTRY_EX(1, DIID_IUnoGameEvents, DISPID_UNOGAMEEVENTS_PLAYEROUT, OnPlayerOut)
        SINK_ENTRY_EX(1, DIID_IUnoGameEvents, DISPID_UNOGAMEEVENTS_GAMEOVER, OnGameOver)
    END_SINK_MAP()

    void Initialize();
    void Terminate();

    bool Open(LPTSTR lpFile = NULL);
    bool Save(LPTSTR lpFile = NULL);

    void GetGameTitle(LPTSTR lpGameTitle, bool bProvideDefault = false);
    void SetGameTitle(LPCTSTR lpGameTitle);
    long GetHandSize();
    void SetHandSize(long lHandSize);
    bool GetPlayAfterDraw();
    void SetPlayAfterDraw(bool bPlayAfterDraw);
    long GetPlayerCount();
    bool GetPlayer(long lIndex, LPTSTR lpPlayerName, UnoPlayerType* pePlayerType);
    bool SetPlayer(long lIndex, LPCTSTR lpPlayerName, UnoPlayerType ePlayerType);
    bool AddPlayer(LPCTSTR lpPlayerName, UnoPlayerType ePlayerType);
    bool RemovePlayer(LPCTSTR lpPlayerName);

    void __stdcall OnPlayerTurn(long lPlayer);
    void __stdcall OnPlayerChooseWildColor(long lPlayer, UnoColor* peColor);
    void __stdcall OnPlayerUno(long lPlayer);
    void __stdcall OnPlayerOut(long lPlayer, VARIANT_BOOL* pbKeepPlaying);
    void __stdcall OnGameOver(long lPlayer);

private:
    void StartGame();
    void StopGame();

    void LoadGameSettings();
    void SaveGameSettings();
    void LoadPlayers();
    void SavePlayers();

    CComPtr<IUnoGame> m_spGame;

    long m_lHandSize;
    bool m_bPlayAfterDraw;
    CSimpleMap<CComBSTR, UnoPlayerType> m_Players;

};

extern CGameManager g_GameManager;

#endif //__GAMEMANAGER_H_
