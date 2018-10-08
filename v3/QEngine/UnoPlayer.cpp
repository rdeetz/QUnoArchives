/////////////////////////////////////////////////////////////////////
//
// UnoPlayer.cpp - implementation of the UnoPlayer object for the 
//                 RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#include "stdafx.h"
#include "QEngine.h"
#include "UnoPlayer.h"

CUnoPlayer::CUnoPlayer() {
    m_eType = UnoComputer;
    m_spHand.CoCreateInstance(CLSID_UnoHand);
}

CUnoPlayer::~CUnoPlayer() {
    ATLTRACE(_T("Player destroyed\n"));
}

// IUnoPlayer

STDMETHODIMP CUnoPlayer::get_Name(BSTR* pbstrName) {
    m_bstrName.CopyTo(pbstrName);

    return S_OK;
}

STDMETHODIMP CUnoPlayer::put_Name(BSTR bstrName) {
    m_bstrName = bstrName;

    return S_OK;
}

STDMETHODIMP CUnoPlayer::get_Type(UnoPlayerType* peType) {
    *peType = m_eType;

    return S_OK;
}

STDMETHODIMP CUnoPlayer::put_Type(UnoPlayerType eType) {
    m_eType = eType;

    return S_OK;
}

STDMETHODIMP CUnoPlayer::get_Hand(IUnoHand** ppHand) {
    m_spHand.CopyTo(ppHand);

    return S_OK;
}

STDMETHODIMP CUnoPlayer::Draw() {
    if (m_spGameCmd) {
        CComPtr<IUnoCard> spCard;
        HRESULT hr = m_spGameCmd->Draw(&spCard);

        if (SUCCEEDED(hr) && spCard) {
            hr = m_spHand->Add(spCard);
        }

    } else {
        ATLTRACE(_T("Player Draw game commander is NULL\n"));
        return S_FALSE;
    }

    return S_OK;
}

STDMETHODIMP CUnoPlayer::Play(long lIndex, VARIANT_BOOL* pbPlayed) {
    *pbPlayed = VARIANT_FALSE;

    if (m_spGameCmd) {
        CComPtr<IUnoCard> spCard;
        HRESULT hr = m_spHand->get_Item(lIndex, &spCard);

        if (SUCCEEDED(hr) && spCard) {
            hr = m_spGameCmd->Play(spCard, pbPlayed);

            if (pbPlayed) {
                CComPtr<IUnoCard> spDummy;
                hr = m_spHand->Remove(lIndex, &spDummy);

                hr = m_spGameCmd->TurnCompleted();
            }
        }

    } else {
        ATLTRACE(_T("Player Play game commander is NULL\n"));
        return S_FALSE;
    }

    return S_OK;
}

STDMETHODIMP CUnoPlayer::Pass(VARIANT_BOOL* pbPassed) {
    *pbPassed = VARIANT_FALSE;

    if (m_spGameCmd) {
        HRESULT hr = m_spGameCmd->Pass(pbPassed);

    } else {
        ATLTRACE(_T("Player Pass game commander is NULL\n"));
        return S_FALSE;
    }

    return S_OK;
}

// IUnoPlayerCmd

STDMETHODIMP CUnoPlayer::Initialize(IUnoGameCmd* pGameCmd) {
    if (pGameCmd) {
        m_spGameCmd = pGameCmd;

    } else {
        ATLTRACE(_T("Player Initialize game commander is NULL\n"));
        return S_FALSE;
    }

    return S_OK;
}

STDMETHODIMP CUnoPlayer::Terminate() {
    if (m_spGameCmd) {
        m_spGameCmd.Release();

    } else {
        ATLTRACE(_T("Player Terminate game commander is NULL\n"));
        return S_FALSE;
    }

    return S_OK;
}
