/////////////////////////////////////////////////////////////////////
//
// UnoDeck.cpp - implementation of the UnoDeck object for the 
//               RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#include "stdafx.h"
#include "QEngine.h"
#include "UnoDeck.h"

CUnoDeck::CUnoDeck() {
    Initialize();
}

CUnoDeck::~CUnoDeck() {
    Terminate();
    ATLTRACE(_T("Deck destroyed\n"));
}

void CUnoDeck::Initialize() {
    HRESULT hr;

    hr = CreateCard(UnoZero, UnoRed);
    hr = CreateCard(UnoOne, UnoRed);
    hr = CreateCard(UnoTwo, UnoRed);
    hr = CreateCard(UnoThree, UnoRed);
    hr = CreateCard(UnoFour, UnoRed);
    hr = CreateCard(UnoFive, UnoRed);
    hr = CreateCard(UnoSix, UnoRed);
    hr = CreateCard(UnoSeven, UnoRed);
    hr = CreateCard(UnoEight, UnoRed);
    hr = CreateCard(UnoNine, UnoRed);
    hr = CreateCard(UnoDrawTwo, UnoRed);
    hr = CreateCard(UnoSkip, UnoRed);
    hr = CreateCard(UnoReverse, UnoRed);

    hr = CreateCard(UnoZero, UnoBlue);
    hr = CreateCard(UnoOne, UnoBlue);
    hr = CreateCard(UnoTwo, UnoBlue);
    hr = CreateCard(UnoThree, UnoBlue);
    hr = CreateCard(UnoFour, UnoBlue);
    hr = CreateCard(UnoFive, UnoBlue);
    hr = CreateCard(UnoSix, UnoBlue);
    hr = CreateCard(UnoSeven, UnoBlue);
    hr = CreateCard(UnoEight, UnoBlue);
    hr = CreateCard(UnoNine, UnoBlue);
    hr = CreateCard(UnoDrawTwo, UnoBlue);
    hr = CreateCard(UnoSkip, UnoBlue);
    hr = CreateCard(UnoReverse, UnoBlue);

    hr = CreateCard(UnoZero, UnoYellow);
    hr = CreateCard(UnoOne, UnoYellow);
    hr = CreateCard(UnoTwo, UnoYellow);
    hr = CreateCard(UnoThree, UnoYellow);
    hr = CreateCard(UnoFour, UnoYellow);
    hr = CreateCard(UnoFive, UnoYellow);
    hr = CreateCard(UnoSix, UnoYellow);
    hr = CreateCard(UnoSeven, UnoYellow);
    hr = CreateCard(UnoEight, UnoYellow);
    hr = CreateCard(UnoNine, UnoYellow);
    hr = CreateCard(UnoDrawTwo, UnoYellow);
    hr = CreateCard(UnoSkip, UnoYellow);
    hr = CreateCard(UnoReverse, UnoYellow);

    hr = CreateCard(UnoZero, UnoGreen);
    hr = CreateCard(UnoOne, UnoGreen);
    hr = CreateCard(UnoTwo, UnoGreen);
    hr = CreateCard(UnoThree, UnoGreen);
    hr = CreateCard(UnoFour, UnoGreen);
    hr = CreateCard(UnoFive, UnoGreen);
    hr = CreateCard(UnoSix, UnoGreen);
    hr = CreateCard(UnoSeven, UnoGreen);
    hr = CreateCard(UnoEight, UnoGreen);
    hr = CreateCard(UnoNine, UnoGreen);
    hr = CreateCard(UnoDrawTwo, UnoGreen);
    hr = CreateCard(UnoSkip, UnoGreen);
    hr = CreateCard(UnoReverse, UnoGreen);

    hr = CreateCard(UnoWild, UnoNoColor);
    hr = CreateCard(UnoWild, UnoNoColor);
    hr = CreateCard(UnoWild, UnoNoColor);
    hr = CreateCard(UnoWild, UnoNoColor);

    hr = CreateCard(UnoWildDrawFour, UnoNoColor);
    hr = CreateCard(UnoWildDrawFour, UnoNoColor);
    hr = CreateCard(UnoWildDrawFour, UnoNoColor);
    hr = CreateCard(UnoWildDrawFour, UnoNoColor);

    Shuffle();

    return;
}

void CUnoDeck::Terminate() {
	long lIndex = 0;

    for (lIndex = 0; lIndex < m_DrawStack.GetSize(); lIndex++) {
        (m_DrawStack[lIndex])->Release();
    }

    m_DrawStack.RemoveAll();

    for (lIndex = 0; lIndex < m_PlayedStack.GetSize(); lIndex++) {
        (m_PlayedStack[lIndex])->Release();
    }

    m_PlayedStack.RemoveAll();

    return;
}

HRESULT CUnoDeck::CreateCard(UnoValue eValue, UnoColor eColor) {
    CComPtr<IUnoCard> spCard;
    HRESULT hr = spCard.CoCreateInstance(CLSID_UnoCard);

    if (SUCCEEDED(hr) && spCard) {
        CComPtr<IUnoCardInit> spCardInit;
        hr = spCard.QueryInterface(&spCardInit);

        if (SUCCEEDED(hr)) {
            hr = spCardInit->Initialize(eValue, eColor);
        }

        (spCard.p)->AddRef();

        m_DrawStack.Add(spCard.p);
    }

    return hr;
}

void CUnoDeck::Shuffle() {
    srand((unsigned)GetTickCount());

    // TODO: this is a very simple shuffling algorithim

    long lSize = m_DrawStack.GetSize();

    for (long lIndex = 0; lIndex < lSize; lIndex++) {
        long lRandomIndex = (rand() % lSize);

        IUnoCard* pTemp = m_DrawStack[lRandomIndex];
        m_DrawStack.RemoveAt(lRandomIndex);
        m_DrawStack.Add(pTemp);
    }

    return;
}

// IUnoDeck

STDMETHODIMP CUnoDeck::get_DrawCount(long* plDrawCount) {
    *plDrawCount = m_DrawStack.GetSize();

    return S_OK;
}

STDMETHODIMP CUnoDeck::get_PlayedCount(long* plPlayedCount) {
    *plPlayedCount = m_PlayedStack.GetSize();

    return S_OK;
}

STDMETHODIMP CUnoDeck::get_ActiveCard(IUnoCard** ppActiveCard) {
    if (m_PlayedStack.GetSize() > 0) {
        long lIndex = (m_PlayedStack.GetSize() - 1);

        CComPtr<IUnoCard> spCard;
        spCard.Attach(m_PlayedStack[lIndex]);
        spCard.CopyTo(ppActiveCard);
        spCard.Detach();

    } else {
        *ppActiveCard = NULL;

        ATLTRACE(_T("Deck ActiveCard does not exist\n"));
        return S_FALSE;
    }

    return S_OK;
}

STDMETHODIMP CUnoDeck::Draw(IUnoCard** ppCard) {
    if (m_DrawStack.GetSize() <= 0) {
        ATLTRACE(_T("Deck Draw out of cards, collecting played cards\n"));

        long lPlayedCards = (m_PlayedStack.GetSize() - 1);

        for (long lIndex = (lPlayedCards - 1); lIndex >= 0; lIndex--) {
            IUnoCard* pTemp = m_PlayedStack[0];
            m_PlayedStack.RemoveAt(0);
            m_DrawStack.Add(pTemp);
        }

        Shuffle();
    }

    if (m_DrawStack.GetSize() <= 0) {
        *ppCard = NULL;

        ATLTRACE(_T("Deck Draw out of cards, no cards to collect\n"));
        return S_FALSE;
    }

    CComPtr<IUnoCard> spCard;
    spCard.Attach(m_DrawStack[0]);
    spCard.CopyTo(ppCard);
    spCard.Detach();

    (m_DrawStack[0])->Release();

    m_DrawStack.RemoveAt(0);

    return S_OK;
}

STDMETHODIMP CUnoDeck::Play(IUnoCard* pCard) {
    if (pCard) {
        pCard->AddRef();
    
        m_PlayedStack.Add(pCard);

    } else {
        ATLTRACE(_T("Deck Play card is NULL\n"));
        return S_FALSE;
    }

    return S_OK;
}
