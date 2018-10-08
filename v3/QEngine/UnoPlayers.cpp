/////////////////////////////////////////////////////////////////////
//
// UnoPlayers.cpp - implementation of the UnoPlayers object for the 
//                  RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#include "stdafx.h"
#include "QEngine.h"
#include "UnoPlayers.h"

CUnoPlayers::CUnoPlayers() {

}

CUnoPlayers::~CUnoPlayers() {
    Clear();
    ATLTRACE(_T("Players destroyed\n"));
}

// IUnoPlayers

STDMETHODIMP CUnoPlayers::get_Count(long* plCount) {
    *plCount = m_Players.GetSize();

    return S_OK;
}

STDMETHODIMP CUnoPlayers::get_Item(long lIndex, IUnoPlayer** ppPlayer) {
    if ((lIndex >=0) && (lIndex < m_Players.GetSize())) {
        CComPtr<IUnoPlayer> spPlayer;
        spPlayer.Attach(reinterpret_cast<IUnoPlayer*>(m_Players[lIndex].pdispVal));
        spPlayer.CopyTo(ppPlayer);
        spPlayer.Detach();

    } else {
        *ppPlayer = NULL;

        ATLTRACE(_T("Players Item index is out of range\n"));
        return S_FALSE;
    }

    return S_OK;
}

STDMETHODIMP CUnoPlayers::Add(IUnoPlayer* pPlayer) {
    if (pPlayer) {
        VARIANT vPlayer;
        VariantInit(&vPlayer);

        vPlayer.vt = VT_DISPATCH;
        vPlayer.pdispVal = pPlayer;

        (vPlayer.pdispVal)->AddRef();

        m_Players.Add(vPlayer);

    } else {
        ATLTRACE(_T("Players Add player is NULL\n"));
        return S_FALSE;
    }

    return S_OK;
}

STDMETHODIMP CUnoPlayers::Remove(long lIndex, IUnoPlayer** ppPlayer) {
    if ((lIndex >=0) && (lIndex < m_Players.GetSize())) {
        CComPtr<IUnoPlayer> spPlayer;
        spPlayer.Attach(reinterpret_cast<IUnoPlayer*>(m_Players[lIndex].pdispVal));
        spPlayer.CopyTo(ppPlayer);
        spPlayer.Detach();

        (m_Players[lIndex].pdispVal)->Release();

        m_Players.RemoveAt(lIndex);

    } else {
        *ppPlayer = NULL;

        ATLTRACE(_T("Players Remove index is out of range\n"));
        return S_FALSE;
    }

    return S_OK;
}

STDMETHODIMP CUnoPlayers::Clear() {
    for (long lIndex = 0; lIndex < m_Players.GetSize(); lIndex++) {
        (m_Players[lIndex].pdispVal)->Release();
    }

    m_Players.RemoveAll();

    return S_OK;
}

STDMETHODIMP CUnoPlayers::get__NewEnum(IUnknown** ppUnkEnum) {
    long lSize = m_Players.GetSize();

    CComObject<CComEnumVariant>* pEnum = NULL;
    CComObject<CComEnumVariant>::CreateInstance(&pEnum);

    pEnum->AddRef();
    pEnum->Init(&(m_Players.m_aT)[0], &(m_Players.m_aT)[lSize], NULL, AtlFlagCopy);
    pEnum->QueryInterface(ppUnkEnum);
    pEnum->Release();

    return S_OK;
}
