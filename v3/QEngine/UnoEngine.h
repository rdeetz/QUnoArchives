/////////////////////////////////////////////////////////////////////
//
// UnoEngine.h - definition of the UnoEngine object for the 
//               RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#ifndef __UNOENGINE_H_
#define __UNOENGINE_H_

#include "resource.h"

// CUnoEngine

class ATL_NO_VTABLE CUnoEngine : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CUnoEngine, &CLSID_UnoEngine>,
    public IDispatchImpl<IUnoEngine, &IID_IUnoEngine, &LIBID_QEngineLib>
{
public:
    CUnoEngine();
    ~CUnoEngine();

    DECLARE_REGISTRY_RESOURCEID(IDR_UNOENGINE)
    DECLARE_NOT_AGGREGATABLE(CUnoEngine)

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP(CUnoEngine)
        COM_INTERFACE_ENTRY(IUnoEngine)
        COM_INTERFACE_ENTRY(IDispatch)
    END_COM_MAP()

// IUnoEngine
public:
    STDMETHOD(get_ActiveGame)(IUnoGame** ppActiveGame);

private:
    CComPtr<IUnoGame> m_spGame;

};

#endif //__UNOENGINE_H_
