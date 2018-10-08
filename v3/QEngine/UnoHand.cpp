/////////////////////////////////////////////////////////////////////
//
// UnoHand.cpp - implementation of the UnoHand object for the 
//               RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#include "stdafx.h"
#include "QEngine.h"
#include "UnoHand.h"

CUnoHand::CUnoHand() {

}

CUnoHand::~CUnoHand() {
    Clear();
    ATLTRACE(_T("Hand destroyed\n"));
}

// IUnoHand

STDMETHODIMP CUnoHand::get_Count(long* plCount) {
    *plCount = m_Cards.GetSize();

    return S_OK;
}

STDMETHODIMP CUnoHand::get_Item(long lIndex, IUnoCard** ppCard) {
    if ((lIndex >=0) && (lIndex < m_Cards.GetSize())) {
        CComPtr<IUnoCard> spCard;
        spCard.Attach(reinterpret_cast<IUnoCard*>(m_Cards[lIndex].pdispVal));
        spCard.CopyTo(ppCard);
        spCard.Detach();

    } else {
        *ppCard = NULL;

        ATLTRACE(_T("Hand Item index is out of range\n"));
        return S_FALSE;
    }

    return S_OK;
}

STDMETHODIMP CUnoHand::Add(IUnoCard* pCard) {
    if (pCard) {
        VARIANT vCard;
        VariantInit(&vCard);

        vCard.vt = VT_DISPATCH;
        vCard.pdispVal = pCard;

        (vCard.pdispVal)->AddRef();

        m_Cards.Add(vCard);

    } else {
        ATLTRACE(_T("Hand Add card is NULL\n"));
        return S_FALSE;
    }

    return S_OK;
}

STDMETHODIMP CUnoHand::Remove(long lIndex, IUnoCard** ppCard) {
    if ((lIndex >=0) && (lIndex < m_Cards.GetSize())) {
        CComPtr<IUnoCard> spCard;
        spCard.Attach(reinterpret_cast<IUnoCard*>(m_Cards[lIndex].pdispVal));
        spCard.CopyTo(ppCard);
        spCard.Detach();

        (m_Cards[lIndex].pdispVal)->Release();

        m_Cards.RemoveAt(lIndex);

    } else {
        *ppCard = NULL;

        ATLTRACE(_T("Hand Remove index is out of range\n"));
        return S_FALSE;
    }

    return S_OK;
}

STDMETHODIMP CUnoHand::Clear() {
    for (long lIndex = 0; lIndex < m_Cards.GetSize(); lIndex++) {
        (m_Cards[lIndex].pdispVal)->Release();
    }

    m_Cards.RemoveAll();

    return S_OK;
}

STDMETHODIMP CUnoHand::get__NewEnum(IUnknown** ppUnkEnum) {
    long lSize = m_Cards.GetSize();

    CComObject<CComEnumVariant>* pEnum = NULL;
    CComObject<CComEnumVariant>::CreateInstance(&pEnum);

    pEnum->AddRef();
    pEnum->Init(&(m_Cards.m_aT)[0], &(m_Cards.m_aT)[lSize], NULL, AtlFlagCopy);
    pEnum->QueryInterface(ppUnkEnum);
    pEnum->Release();

    return S_OK;
}
