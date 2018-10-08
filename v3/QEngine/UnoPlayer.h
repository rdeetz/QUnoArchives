/////////////////////////////////////////////////////////////////////
//
// UnoPlayer.h - definition of the UnoPlayer object for the 
//               RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#ifndef __UNOPLAYER_H_
#define __UNOPLAYER_H_

#include "resource.h"

// CUnoPlayer

class ATL_NO_VTABLE CUnoPlayer : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CUnoPlayer, &CLSID_UnoPlayer>,
    public IDispatchImpl<IUnoPlayer, &IID_IUnoPlayer, &LIBID_QEngineLib>,
    public IUnoPlayerCmd
{
public:
    CUnoPlayer();
    ~CUnoPlayer();

    DECLARE_REGISTRY_RESOURCEID(IDR_UNOPLAYER)
    DECLARE_NOT_AGGREGATABLE(CUnoPlayer)

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP(CUnoPlayer)
        COM_INTERFACE_ENTRY(IUnoPlayer)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IUnoPlayerCmd)
    END_COM_MAP()

// IUnoPlayer
public:
    STDMETHOD(get_Name)(BSTR* pbstrName);
    STDMETHOD(put_Name)(BSTR bstrName);
    STDMETHOD(get_Type)(UnoPlayerType* peType);
    STDMETHOD(put_Type)(UnoPlayerType eType);
    STDMETHOD(get_Hand)(IUnoHand** ppHand);
    STDMETHOD(Draw)();
    STDMETHOD(Play)(long lIndex, VARIANT_BOOL* pbPlayed);
    STDMETHOD(Pass)(VARIANT_BOOL* pbPassed);

// IUnoPlayerCmd
public:
    STDMETHOD(Initialize)(IUnoGameCmd* pGameCmd);
    STDMETHOD(Terminate)();

private:
    CComBSTR m_bstrName;
    UnoPlayerType m_eType;
    CComPtr<IUnoHand> m_spHand;
    CComPtr<IUnoGameCmd> m_spGameCmd;

};

#endif //__UNOPLAYER_H_
