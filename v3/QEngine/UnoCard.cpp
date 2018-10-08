/////////////////////////////////////////////////////////////////////
//
// UnoCard.cpp - implementation of the UnoCard object for the 
//               RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#include "stdafx.h"
#include "QEngine.h"
#include "UnoCard.h"

CUnoCard::CUnoCard() {
    m_eValue = UnoNoValue;
    m_eColor = UnoNoColor;
}

CUnoCard::~CUnoCard() {
    ATLTRACE(_T("Card destroyed\n"));
}

// IUnoCard

STDMETHODIMP CUnoCard::get_Value(UnoValue* peValue) {
    *peValue = m_eValue;

    return S_OK;
}

STDMETHODIMP CUnoCard::get_Color(UnoColor* peColor) {
    *peColor = m_eColor;

    return S_OK;
}

// IUnoCardInit

STDMETHODIMP CUnoCard::Initialize(UnoValue eValue, UnoColor eColor) {
    if (m_eValue != UnoNoValue) {
        ATLTRACE(_T("Card is already initialized\n"));
        return S_FALSE;
    }

    m_eValue = eValue;
    m_eColor = eColor;

    return S_OK;
}
