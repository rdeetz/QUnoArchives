/////////////////////////////////////////////////////////////////////
//
// UnoCardView.cpp - implementation of the UnoCardView control for the 
//                   RogCorp QControls Library 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#include "stdafx.h"
#include "QControl.h"
#include "UnoCardView.h"

CUnoCardView::CUnoCardView() {
    m_clrBorderColor = RGB(0, 0, 0);
    m_nBorderStyle = 0;
    m_bBorderVisible = TRUE;
    m_nBorderWidth = 1;
    m_nMousePointer = 0;
    m_bTabStop = TRUE;
}

CUnoCardView::~CUnoCardView() {
    ATLTRACE(_T("CardView destroyed\n"));
}

HRESULT CUnoCardView::OnDraw(ATL_DRAWINFO& di) {
    RECT& rc = *(RECT*)di.prcBounds;

    HPEN hPen = CreatePen(m_nBorderStyle, m_nBorderWidth, m_clrBorderColor);
    HGDIOBJ hOldPen = SelectObject(di.hdcDraw, hPen);

    Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);

    SetTextAlign(di.hdcDraw, TA_CENTER | TA_BASELINE);

    LPCTSTR pszText = _T("Welcome to UnoCardView!");

    TextOut(di.hdcDraw, (rc.left + rc.right) / 2, (rc.top + rc.bottom) / 2, pszText, lstrlen(pszText));

    SelectObject(di.hdcDraw, hOldPen);
    DeleteObject(hPen);

    return S_OK;
}

// IUnoCardView

STDMETHODIMP CUnoCardView::get_Card(IDispatch** ppCard) {
    m_spCard.CopyTo(ppCard);

    return S_OK;
}

STDMETHODIMP CUnoCardView::put_Card(IDispatch* pCard) {
    if (pCard) {
        m_spCard = pCard;

    } else {
        ATLTRACE(_T("CardView card is NULL\n"));
        return S_FALSE;
    }

    return S_OK;
}
