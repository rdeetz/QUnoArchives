/////////////////////////////////////////////////////////////////////
//
// UnoPlayers.h - definition of the UnoPlayers object for the 
//                RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#ifndef __UNOPLAYERS_H_
#define __UNOPLAYERS_H_

#include "resource.h"

// CUnoPlayers

class ATL_NO_VTABLE CUnoPlayers : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CUnoPlayers, &CLSID_UnoPlayers>,
    public IDispatchImpl<IUnoPlayers, &IID_IUnoPlayers, &LIBID_QEngineLib>
{
public:
    CUnoPlayers();
    ~CUnoPlayers();

    DECLARE_REGISTRY_RESOURCEID(IDR_UNOPLAYERS)
    DECLARE_NOT_AGGREGATABLE(CUnoPlayers)

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP(CUnoPlayers)
        COM_INTERFACE_ENTRY(IUnoPlayers)
        COM_INTERFACE_ENTRY(IDispatch)
    END_COM_MAP()

// IUnoPlayers
public:
    STDMETHOD(get_Count)(long* plCount);
    STDMETHOD(get_Item)(long lIndex, IUnoPlayer** ppPlayer);
    STDMETHOD(Add)(IUnoPlayer* pPlayer);
    STDMETHOD(Remove)(long lIndex, IUnoPlayer** ppPlayer);
    STDMETHOD(Clear)();
    STDMETHOD(get__NewEnum)(IUnknown** ppUnkEnum);

private:
    CSimpleArray<VARIANT> m_Players;

};

#endif //__UNOPLAYERS_H_
