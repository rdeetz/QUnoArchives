/////////////////////////////////////////////////////////////////////
//
// UnoPlayersIter.cpp - implementation of the UnoPlayersIter object for the 
//                      RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#include "stdafx.h"
#include "QEngine.h"
#include "UnoPlayersIter.h"

CUnoPlayersIter::CUnoPlayersIter() {
    m_lIndex = 0;
    m_bForward = true;
}

CUnoPlayersIter::~CUnoPlayersIter() {
    Terminate();
    ATLTRACE(_T("PlayersIter destroyed\n"));
}

HRESULT CUnoPlayersIter::Initialize(IUnoGameCmd* pGameCmd) {
    if (pGameCmd) {
        m_spGameCmd = pGameCmd;

    } else {
        ATLTRACE(_T("PlayersIter Initialize game commander is NULL\n"));
        return S_FALSE;
    }

    return S_OK;
}

HRESULT CUnoPlayersIter::Terminate() {
    if (m_spGameCmd) {
        m_spGameCmd.Release();
    }

    Clear();

    return S_OK;
}

HRESULT CUnoPlayersIter::Count(long* plCount) {
    *plCount = m_Players.GetSize();

    return S_OK;
}

HRESULT CUnoPlayersIter::Item(UnoPlayersIterType eIterType, IUnoPlayerCmd** ppPlayer) {
    if (m_Players.GetSize() <= 0) {
        *ppPlayer = NULL;

        ATLTRACE(_T("PlayersIter Item no players in the list\n"));
        return S_FALSE;
    }

    UpdateIndex(eIterType);

    CComPtr<IUnoPlayerCmd> spPlayer;
    spPlayer.Attach(m_Players.GetValueAt(m_lIndex));
    spPlayer.CopyTo(ppPlayer);
    spPlayer.Detach();

    return S_OK;
}

HRESULT CUnoPlayersIter::Item(UnoPlayersIterType eIterType, long* plPlayerIndex) {
    if (m_Players.GetSize() <= 0) {
        *plPlayerIndex = -1;

        ATLTRACE(_T("PlayersIter Item no players in the list\n"));
        return S_FALSE;
    }

    UpdateIndex(eIterType);

    *plPlayerIndex = m_Players.GetKeyAt(m_lIndex);

    return S_OK;
}

HRESULT CUnoPlayersIter::Add(long lPlayerIndex, IUnoPlayerCmd* pPlayer) {
    if (pPlayer) {
        pPlayer->AddRef();

        if (m_spGameCmd) {
            pPlayer->Initialize(m_spGameCmd);
        }

        m_Players.Add(lPlayerIndex, pPlayer);

    } else {
        ATLTRACE(_T("PlayersIter Add player is NULL\n"));
        return S_FALSE;
    }

    return S_OK;
}

HRESULT CUnoPlayersIter::Remove(UnoPlayersIterType eIterType, IUnoPlayerCmd** ppPlayer) {
    CComPtr<IUnoPlayerCmd> spPlayer;
    HRESULT hr = Item(eIterType, &spPlayer);

    if (SUCCEEDED(hr) && spPlayer) {
        spPlayer.CopyTo(ppPlayer);

        (m_Players.GetValueAt(m_lIndex))->Terminate();
        (m_Players.GetValueAt(m_lIndex))->Release();

        m_Players.Remove(m_Players.GetKeyAt(m_lIndex));

    } else {
        *ppPlayer = NULL;

        ATLTRACE(_T("PlayersIter Remove no player to remove\n"));
        return S_FALSE;
    }

    return S_OK;
}

HRESULT CUnoPlayersIter::Clear() {
    for (long lIndex = 0; lIndex < m_Players.GetSize(); lIndex++) {
        (m_Players.GetValueAt(lIndex))->Terminate();
        (m_Players.GetValueAt(lIndex))->Release();
    }

    m_Players.RemoveAll();

    return S_OK;
}

HRESULT CUnoPlayersIter::Reverse() {
    m_bForward = (!m_bForward);

    return S_OK;
}

void CUnoPlayersIter::UpdateIndex(UnoPlayersIterType eIterType) {
    long lLastIndex = (m_Players.GetSize() - 1);

    switch (eIterType) {
        case UnoFirst:
            m_lIndex = 0;
            break;

        case UnoPrevious:
            if (m_bForward) {
                m_lIndex--;

                if (m_lIndex < 0) {
                    m_lIndex = lLastIndex;
                }

            } else {
                m_lIndex++;

                if (m_lIndex > lLastIndex) {
                    m_lIndex = 0;
                }
            }

            break;

        case UnoCurrent:
            if (m_lIndex > lLastIndex) {
                m_lIndex = lLastIndex;
            }

            if (m_lIndex < 0) {
                m_lIndex = 0;
            }

            break;

        case UnoNext:
            if (m_bForward) {
                m_lIndex++;

                if (m_lIndex > lLastIndex) {
                    m_lIndex = 0;
                }

            } else {
                m_lIndex--;

                if (m_lIndex < 0) {
                    m_lIndex = lLastIndex;
                }
            }

            break;

        case UnoLast:
            m_lIndex = lLastIndex;
            break;

        default:
            ATLTRACE(_T("PlayersIter UpdateIndex iterator type is unknown\n"));
            break;
    }

    return;
}
