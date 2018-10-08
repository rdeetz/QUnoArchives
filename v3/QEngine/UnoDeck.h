/////////////////////////////////////////////////////////////////////
//
// UnoDeck.h - definition of the UnoDeck object for the 
//             RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#ifndef __UNODECK_H_
#define __UNODECK_H_

#include "resource.h"

// CUnoDeck

class ATL_NO_VTABLE CUnoDeck : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CUnoDeck, &CLSID_UnoDeck>,
    public IDispatchImpl<IUnoDeck, &IID_IUnoDeck, &LIBID_QEngineLib>
{
public:
    CUnoDeck();
    ~CUnoDeck();

    DECLARE_REGISTRY_RESOURCEID(IDR_UNODECK)
    DECLARE_NOT_AGGREGATABLE(CUnoDeck)

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP(CUnoDeck)
        COM_INTERFACE_ENTRY(IUnoDeck)
        COM_INTERFACE_ENTRY(IDispatch)
    END_COM_MAP()

// IUnoDeck
public:
    STDMETHOD(get_DrawCount)(long* plDrawCount);
    STDMETHOD(get_PlayedCount)(long* plPlayedCount);
    STDMETHOD(get_ActiveCard)(IUnoCard** ppActiveCard);
    STDMETHOD(Draw)(IUnoCard** ppCard);
    STDMETHOD(Play)(IUnoCard* pCard);

private:
    void Initialize();
    void Terminate();
    HRESULT CreateCard(UnoValue eValue, UnoColor);
    void Shuffle();

    CSimpleArray<IUnoCard*> m_DrawStack;
    CSimpleArray<IUnoCard*> m_PlayedStack;

};

#endif //__UNODECK_H_
