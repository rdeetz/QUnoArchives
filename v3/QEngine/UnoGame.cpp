/////////////////////////////////////////////////////////////////////
//
// UnoGame.cpp - implementation of the UnoGame object for the 
//               RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#include "stdafx.h"
#include "QEngine.h"
#include "UnoGame.h"

CUnoGame::CUnoGame() {
    m_spPlayers.CoCreateInstance(CLSID_UnoPlayers);
    m_spDeck.CoCreateInstance(CLSID_UnoDeck);
    m_eWildColor = UnoNoColor;
    m_lHandSize = Q_DEFAULT_HANDSIZE;
    m_bPlayAfterDraw = VARIANT_TRUE;
    m_bGameInProgress = false;
    m_lLastPlayerToDraw = -1;
    m_bRequiresSave = FALSE;
}

CUnoGame::~CUnoGame() {
    ATLTRACE(_T("Game destroyed\n"));
}

void CUnoGame::DealCards(long lPlayerCount) {
    for (long i = 0; i < m_lHandSize; i++) {
        for (long lIndex = 0; lIndex < lPlayerCount; lIndex++) {
            CComPtr<IUnoCard> spCard;
            HRESULT hr = m_spDeck->Draw(&spCard);

            if (SUCCEEDED(hr) && spCard) {
                CComPtr<IUnoPlayer> spPlayer;
                hr = m_spPlayers->get_Item(lIndex, &spPlayer);

                if (SUCCEEDED(hr) && spPlayer) {
                    CComPtr<IUnoHand> spHand;
                    hr = spPlayer->get_Hand(&spHand);

                    if (SUCCEEDED(hr) && spHand) {
                        hr = spHand->Add(spCard);
                    }
                }
            }
        }
    }

    return;
}

void CUnoGame::InitializePlayersIter(long lPlayerCount) {
    CComPtr<IUnoGameCmd> spGameCmd;
    HRESULT hr = this->QueryInterface(IID_IUnoGameCmd, reinterpret_cast<void**>(&spGameCmd));

    if (SUCCEEDED(hr)) {
        hr = m_PlayersIter.Initialize(spGameCmd);

        if (SUCCEEDED(hr)) {
            for (long lIndex = 0; lIndex < lPlayerCount; lIndex++) {
                CComPtr<IUnoPlayer> spPlayer;
                hr = m_spPlayers->get_Item(lIndex, &spPlayer);

                if (SUCCEEDED(hr) && spPlayer) {
                    CComPtr<IUnoPlayerCmd> spPlayerCmd;
                    hr = spPlayer.QueryInterface(&spPlayerCmd);

                    if (SUCCEEDED(hr)) {
                        hr = m_PlayersIter.Add(lIndex, spPlayerCmd);
                    }
                }
            }
        }
    }

    return;
}

void CUnoGame::TerminatePlayersIter() {
    m_PlayersIter.Terminate();

    return;
}

void CUnoGame::PlayFirstCard() {
    bool bINeedACard = true;

    while (bINeedACard) {
        CComPtr<IUnoCard> spFirstCard;
        HRESULT hr = m_spDeck->Draw(&spFirstCard);

        if (SUCCEEDED(hr) && spFirstCard) {
            hr = m_spDeck->Play(spFirstCard);

            bINeedACard = IsCardWild(spFirstCard);
        }
    }

    return;
}

void CUnoGame::MakePlayerChooseWildColor(UnoPlayersIterType eIterType) {
    long lPlayerIndex;
    HRESULT hr = m_PlayersIter.Item(eIterType, &lPlayerIndex);

    UnoColor eWildColor = m_eWildColor;

    if (SUCCEEDED(hr) && (lPlayerIndex >= 0)) {
        bool bINeedAColor = true;

        while (bINeedAColor) {
            Fire_PlayerChooseWildColor(lPlayerIndex, &eWildColor);

            if (eWildColor != UnoNoColor) {
                bINeedAColor = false;
            }
        }
    }

    m_eWildColor = eWildColor;

    return;
}

void CUnoGame::MakePlayerDraw(UnoPlayersIterType eIterType, long lHowMany) {
    long lPlayerIndex;
    HRESULT hr = m_PlayersIter.Item(eIterType, &lPlayerIndex);

    if (SUCCEEDED(hr) && (lPlayerIndex >= 0)) {
        CComPtr<IUnoPlayer> spPlayer;
        hr = m_spPlayers->get_Item(lPlayerIndex, &spPlayer);

        if (SUCCEEDED(hr) && spPlayer) {
            CComPtr<IUnoHand> spHand;
            hr = spPlayer->get_Hand(&spHand);

            if (SUCCEEDED(hr) && spHand) {
                for (long lIndex = 0; lIndex < lHowMany; lIndex++) {
                    CComPtr<IUnoCard> spCard;
                    hr = m_spDeck->Draw(&spCard);

                    if (SUCCEEDED(hr) && spCard) {
                        hr = spHand->Add(spCard);
                    }
                }
            }
        }
    }

    return;
}

bool CUnoGame::CanPlayerPass(UnoPlayersIterType eIterType) {
    bool bPass = false;

    long lPlayerIndex;
    HRESULT hr = m_PlayersIter.Item(eIterType, &lPlayerIndex);

    if (SUCCEEDED(hr) && (lPlayerIndex >= 0)) {
        if (m_lLastPlayerToDraw == lPlayerIndex) {
            bPass = true;
        }
    }

    return bPass;
}

bool CUnoGame::IsCardWild(IUnoCard* pCard) {
    bool bIsCardWild = false;

    UnoValue eValue;
    HRESULT hr = pCard->get_Value(&eValue);

    if (SUCCEEDED(hr)) {
        bIsCardWild = ((eValue == UnoWild) || (eValue == UnoWildDrawFour));
    }

    return bIsCardWild;
}

bool CUnoGame::CheckPlayers() {
    bool bContinue = false;

    long lCurrentPlayerIndex;
    HRESULT hr = m_PlayersIter.Item(UnoCurrent, &lCurrentPlayerIndex);

    if (SUCCEEDED(hr) && (lCurrentPlayerIndex >= 0)) {
        CComPtr<IUnoPlayer> spCurrentPlayer;
        hr = m_spPlayers->get_Item(lCurrentPlayerIndex, &spCurrentPlayer);

        if (SUCCEEDED(hr) && spCurrentPlayer) {
            CComPtr<IUnoHand> spHand;
            hr = spCurrentPlayer->get_Hand(&spHand);

            if (SUCCEEDED(hr) && spHand) {
                long lCount;
                hr = spHand->get_Count(&lCount);

                bContinue = true; // we got this far, so we're okay now

                if (lCount == Q_UNO) {
                    Fire_PlayerUno(lCurrentPlayerIndex);

                } else if (lCount <= 0) {
                    CComPtr<IUnoPlayerCmd> spDummy;
                    hr = m_PlayersIter.Remove(UnoCurrent, &spDummy);

                    long lPlayerCount;
                    hr = m_PlayersIter.Count(&lPlayerCount);

                    VARIANT_BOOL bKeepPlaying = VARIANT_TRUE;
                    Fire_PlayerOut(lCurrentPlayerIndex, &bKeepPlaying);

                    if (!bKeepPlaying || (lPlayerCount < Q_MIN_PLAYERSSIZE)) {
                        bContinue = false;
                    }
                }
            }
        }
    }

    return bContinue;
}

void CUnoGame::DoNextPlayer() {
    CComPtr<IUnoCard> spCard;
    HRESULT hr = m_spDeck->get_ActiveCard(&spCard);

    if (SUCCEEDED(hr) && spCard) {
        UnoValue eValue;
        hr = spCard->get_Value(&eValue);

        long lDummy;

        switch (eValue) {
            case UnoWildDrawFour:
                MakePlayerChooseWildColor(UnoCurrent);
                MakePlayerDraw(UnoNext, Q_DRAWCOUNT_FOUR);
                break;

            case UnoWild:
                MakePlayerChooseWildColor(UnoCurrent);
                break;

            case UnoDrawTwo:
                MakePlayerDraw(UnoNext, Q_DRAWCOUNT_TWO);
                m_eWildColor = UnoNoColor;
                break;

            case UnoSkip:
                hr = m_PlayersIter.Item(UnoNext, &lDummy);
                m_eWildColor = UnoNoColor;
                break;

            case UnoReverse:
                hr = m_PlayersIter.Reverse();
                m_eWildColor = UnoNoColor;
                break;

            case UnoZero:
            case UnoOne:
            case UnoTwo:
            case UnoThree:
            case UnoFour:
            case UnoFive:
            case UnoSix:
            case UnoSeven:
            case UnoEight:
            case UnoNine:
                m_eWildColor = UnoNoColor;
                break;

            default:
                ATLTRACE(_T("Game DoNextPlayer card value is unknown\n"));
                return;
                break;
        }

        long lNextPlayerIndex;
        hr = m_PlayersIter.Item(UnoNext, &lNextPlayerIndex);

        if (SUCCEEDED(hr) && (lNextPlayerIndex >= 0)) {
            Fire_PlayerTurn(lNextPlayerIndex);
        }
    }

    return;
}

// IUnoGame

STDMETHODIMP CUnoGame::get_Title(BSTR* pbstrTitle) {
    m_bstrTitle.CopyTo(pbstrTitle);

    return S_OK;
}

STDMETHODIMP CUnoGame::put_Title(BSTR bstrTitle) {
    m_bstrTitle = bstrTitle;

    return S_OK;
}

STDMETHODIMP CUnoGame::get_Players(IUnoPlayers** ppPlayers) {
    m_spPlayers.CopyTo(ppPlayers);

    return S_OK;
}

STDMETHODIMP CUnoGame::get_Deck(IUnoDeck** ppDeck) {
    m_spDeck.CopyTo(ppDeck);

    return S_OK;
}

STDMETHODIMP CUnoGame::get_WildColor(UnoColor* peWildColor) {
    *peWildColor = m_eWildColor;

    return S_OK;
}

STDMETHODIMP CUnoGame::put_WildColor(UnoColor eWildColor) {
    m_eWildColor = eWildColor;

    return S_OK;
}

STDMETHODIMP CUnoGame::CreatePlayer(BSTR bstrName, UnoPlayerType eType, IUnoPlayer** ppPlayer) {
    CComPtr<IUnoPlayer> spPlayer;
    HRESULT hr = spPlayer.CoCreateInstance(CLSID_UnoPlayer);

    if (SUCCEEDED(hr) && spPlayer) {
        hr = spPlayer->put_Name(bstrName);
        hr = spPlayer->put_Type(eType);

        hr = m_spPlayers->Add(spPlayer);

        spPlayer.CopyTo(ppPlayer);
    }

    return hr;
}

STDMETHODIMP CUnoGame::Start() {
    long lPlayerCount;
    HRESULT hr = m_spPlayers->get_Count(&lPlayerCount);

    if (FAILED(hr) || (lPlayerCount < Q_MIN_PLAYERSSIZE)) {
        ATLTRACE(_T("Game Start there are not enough players in the game\n"));
        return S_FALSE;
    }

    if (m_bGameInProgress) {
        ATLTRACE(_T("Game Start a game is in progress\n"));
        return S_FALSE;
    }

    m_bGameInProgress = true;

    DealCards(lPlayerCount);

    PlayFirstCard();

    InitializePlayersIter(lPlayerCount);

    long lFirstPlayerIndex;
    hr = m_PlayersIter.Item(UnoFirst, &lFirstPlayerIndex);

    if (SUCCEEDED(hr) && (lFirstPlayerIndex >= 0)) {
        Fire_PlayerTurn(lFirstPlayerIndex);
    }

    return hr;
}

STDMETHODIMP CUnoGame::Stop() {
    TerminatePlayersIter();

    Fire_GameOver();

    return S_OK;
}

STDMETHODIMP CUnoGame::IsCardPlayable(IUnoCard* pCard, VARIANT_BOOL* pbIsCardPlayable) {
    *pbIsCardPlayable = VARIANT_TRUE;

    if (!pCard) {
        *pbIsCardPlayable = VARIANT_FALSE;

        ATLTRACE(_T("Game IsCardPlayable card is NULL\n"));
        return S_FALSE;
    }

    CComPtr<IUnoCard> spActiveCard;
    HRESULT hr = m_spDeck->get_ActiveCard(&spActiveCard);

    if (SUCCEEDED(hr) && spActiveCard) {
        if (!IsCardWild(pCard)) {
            UnoValue eValue;
            hr = pCard->get_Value(&eValue);

            UnoColor eColor;
            hr = pCard->get_Color(&eColor);

            if (IsCardWild(spActiveCard)) {
                if (eColor != m_eWildColor) {
                    *pbIsCardPlayable = VARIANT_FALSE;
                }
            
            } else {
                UnoValue eActiveValue;
                hr = spActiveCard->get_Value(&eActiveValue);

                UnoColor eActiveColor;
                hr = spActiveCard->get_Color(&eActiveColor);

                if (!((eValue == eActiveValue) || (eColor == eActiveColor))) {
                    *pbIsCardPlayable = VARIANT_FALSE;
                }
            }
        }
    }

    return hr;
}

STDMETHODIMP CUnoGame::get_HandSize(long* plHandSize) {
    *plHandSize = m_lHandSize;

    return S_OK;
}

STDMETHODIMP CUnoGame::put_HandSize(long lHandSize) {
    if (lHandSize < Q_MIN_HANDSIZE) {
        ATLTRACE(_T("Game HandSize is not large enough\n"));
        return S_FALSE;
    }

    m_lHandSize = lHandSize;

    return S_OK;
}

STDMETHODIMP CUnoGame::get_PlayAfterDraw(VARIANT_BOOL* pbPlayAfterDraw) {
    *pbPlayAfterDraw = m_bPlayAfterDraw;

    return S_OK;
}

STDMETHODIMP CUnoGame::put_PlayAfterDraw(VARIANT_BOOL bPlayAfterDraw) {
    m_bPlayAfterDraw = bPlayAfterDraw;

    return S_OK;
}

// IUnoGameCmd

STDMETHODIMP CUnoGame::Draw(IUnoCard** ppCard) {
    HRESULT hr = m_spDeck->Draw(ppCard);

    UnoPlayersIterType eIterType;

    if (m_bPlayAfterDraw) {
        eIterType = UnoCurrent;
    } else {
        eIterType = UnoNext;
    }

    long lPlayerIndex;
    hr = m_PlayersIter.Item(eIterType, &lPlayerIndex);

    if (SUCCEEDED(hr) && (lPlayerIndex >= 0)) {
        if (m_bPlayAfterDraw) {
            m_lLastPlayerToDraw = lPlayerIndex;
        }

        Fire_PlayerTurn(lPlayerIndex);
    }

    return hr;
}

STDMETHODIMP CUnoGame::Play(IUnoCard* pCard, VARIANT_BOOL* pbPlayed) {
    VARIANT_BOOL bPlayable;
    HRESULT hr = IsCardPlayable(pCard, &bPlayable);

    if (!bPlayable) {
        *pbPlayed = VARIANT_FALSE;

        ATLTRACE(_T("Game Play card is not playable\n"));
        return S_OK;
    }

    hr = m_spDeck->Play(pCard);

    if (m_bPlayAfterDraw) {
        m_lLastPlayerToDraw = -1;
    }

    *pbPlayed = VARIANT_TRUE;

    return hr;
}

STDMETHODIMP CUnoGame::Pass(VARIANT_BOOL* pbPassed) {
    if (!m_bPlayAfterDraw) {
        *pbPassed = VARIANT_FALSE;

        ATLTRACE(_T("Game Pass players cannot pass if PlayAfterDraw is 'false'\n"));
        return S_FALSE;
    }

    if (CanPlayerPass(UnoCurrent)) {
        long lNextPlayerIndex;
        HRESULT hr = m_PlayersIter.Item(UnoNext, &lNextPlayerIndex);

        if (SUCCEEDED(hr) && (lNextPlayerIndex >= 0)) {
            m_lLastPlayerToDraw = -1;

            Fire_PlayerTurn(lNextPlayerIndex);
        }

        *pbPassed = VARIANT_TRUE;

    } else {
        *pbPassed = VARIANT_FALSE;

        ATLTRACE(_T("Game Pass current player cannot pass\n"));
    }

    return S_OK;
}

STDMETHODIMP CUnoGame::TurnCompleted() {
    bool bContinue = CheckPlayers();

    if (bContinue) {
        DoNextPlayer();
    } else {
        Stop();
    }

    return S_OK;
}
