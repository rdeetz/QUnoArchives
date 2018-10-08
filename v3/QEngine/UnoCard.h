/////////////////////////////////////////////////////////////////////
//
// UnoCard.h - definition of the UnoCard object for the 
//             RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#ifndef __UNOCARD_H_
#define __UNOCARD_H_

#include "resource.h"

// CUnoCard

class ATL_NO_VTABLE CUnoCard : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CUnoCard, &CLSID_UnoCard>,
    public IDispatchImpl<IUnoCard, &IID_IUnoCard, &LIBID_QEngineLib>,
    public IUnoCardInit
{
public:
    CUnoCard();
    ~CUnoCard();

    DECLARE_REGISTRY_RESOURCEID(IDR_UNOCARD)
    DECLARE_NOT_AGGREGATABLE(CUnoCard)

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP(CUnoCard)
        COM_INTERFACE_ENTRY(IUnoCard)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IUnoCardInit)
    END_COM_MAP()

// IUnoCard
public:
    STDMETHOD(get_Value)(UnoValue* peValue);
    STDMETHOD(get_Color)(UnoColor* peColor);

// IUnoCardInit
public:
    STDMETHOD(Initialize)(UnoValue eValue, UnoColor eColor);

private:
    UnoValue m_eValue;
    UnoColor m_eColor;

};

#endif //__UNOCARD_H_
