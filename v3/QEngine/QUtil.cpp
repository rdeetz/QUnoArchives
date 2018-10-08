/////////////////////////////////////////////////////////////////////
//
// QUtil.cpp - implementation of global utilities for the 
//             RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#include "stdafx.h"
#include "QEngine.h"
#include "QUtil.h"

bool IsCardWild(IUnoCard* pCard) {
    bool bIsCardWild = false;

    UnoValue eValue;
    HRESULT hr = pCard->get_Value(&eValue);

    if (SUCCEEDED(hr)) {
        bIsCardWild = ((eValue == UnoWild) || (eValue == UnoWildDrawFour));
    }

    return bIsCardWild;
}
