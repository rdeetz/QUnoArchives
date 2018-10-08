/////////////////////////////////////////////////////////////////////
//
// UnoEngine.cpp - implementation of the UnoEngine object for the 
//                 RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#include "stdafx.h"
#include "QEngine.h"
#include "UnoEngine.h"

CUnoEngine::CUnoEngine() {

}

CUnoEngine::~CUnoEngine() {
    ATLTRACE(_T("Engine destroyed\n"));
}

// IUnoEngine

STDMETHODIMP CUnoEngine::get_ActiveGame(IUnoGame** ppActiveGame) {
    m_spGame.CopyTo(ppActiveGame);

    return S_OK;
}
