/////////////////////////////////////////////////////////////////////
//
// UnoHand.h - definition of the UnoHand object for the 
//             RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#ifndef __UNOHAND_H_
#define __UNOHAND_H_

#include "resource.h"

// CUnoHand

class ATL_NO_VTABLE CUnoHand : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CUnoHand, &CLSID_UnoHand>,
    public IDispatchImpl<IUnoHand, &IID_IUnoHand, &LIBID_QEngineLib>
{
public:
    CUnoHand();
    ~CUnoHand();

    DECLARE_REGISTRY_RESOURCEID(IDR_UNOHAND)
    DECLARE_NOT_AGGREGATABLE(CUnoHand)

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP(CUnoHand)
        COM_INTERFACE_ENTRY(IUnoHand)
        COM_INTERFACE_ENTRY(IDispatch)
    END_COM_MAP()

// IUnoHand
public:
    STDMETHOD(get_Count)(long* plCount);
    STDMETHOD(get_Item)(long lIndex, IUnoCard** ppCard);
    STDMETHOD(Add)(IUnoCard* pCard);
    STDMETHOD(Remove)(long lIndex, IUnoCard** ppCard);
    STDMETHOD(Clear)();
    STDMETHOD(get__NewEnum)(IUnknown** ppUnkEnum);

private:
    CSimpleArray<VARIANT> m_Cards;

};

#endif //__UNOHAND_H_
