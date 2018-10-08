/////////////////////////////////////////////////////////////////////
//
// UnoPlayersIter.h - definition of the UnoPlayersIter object for the 
//                    RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#ifndef __UNOPLAYERSITER_H_
#define __UNOPLAYERSITER_H_

#include "resource.h"

enum UnoPlayersIterType {
    UnoFirst    = 0,
    UnoPrevious = 1,
    UnoCurrent  = 2,
    UnoNext     = 3,
    UnoLast     = 4
};

// CUnoPlayersIter

class CUnoPlayersIter
{
public:
    CUnoPlayersIter();
    ~CUnoPlayersIter();

    HRESULT Initialize(IUnoGameCmd* pGameCmd);
    HRESULT Terminate();
    HRESULT Count(long* plCount);
    HRESULT Item(UnoPlayersIterType eIterType, IUnoPlayerCmd** ppPlayer);
    HRESULT Item(UnoPlayersIterType eIterType, long* plPlayerIndex);
    HRESULT Add(long lPlayerIndex, IUnoPlayerCmd* pPlayer);
    HRESULT Remove(UnoPlayersIterType eIterType, IUnoPlayerCmd** ppPlayer);
    HRESULT Clear();
    HRESULT Reverse();

private:
    void UpdateIndex(UnoPlayersIterType eIterType);

    CSimpleMap<long, IUnoPlayerCmd*> m_Players;
    long m_lIndex;
    bool m_bForward;
    CComPtr<IUnoGameCmd> m_spGameCmd;

};

#endif //__UNOPLAYERSITER_H_
