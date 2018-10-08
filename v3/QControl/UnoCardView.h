/////////////////////////////////////////////////////////////////////
//
// UnoCardView.h - definition of the UnoCardView control for the 
//                 RogCorp QControls Library 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#ifndef __UNOCARDVIEW_H_
#define __UNOCARDVIEW_H_

#include "resource.h"

#include "QCDispID.h"

// CUnoCardView

class ATL_NO_VTABLE CUnoCardView : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CUnoCardView, &CLSID_UnoCardView>,
    public CComControl<CUnoCardView>,
    //public IDispatchImpl<IUnoCardView, &IID_IUnoCardView, &LIBID_QControlLib>,
    public CStockPropImpl<CUnoCardView, IUnoCardView, &IID_IUnoCardView, &LIBID_QControlLib>,
    public IPersistStreamInitImpl<CUnoCardView>,
    public IPersistPropertyBagImpl<CUnoCardView>,
    public IOleObjectImpl<CUnoCardView>,
    public IOleControlImpl<CUnoCardView>,
    public IOleInPlaceActiveObjectImpl<CUnoCardView>,
    public IOleInPlaceObjectWindowlessImpl<CUnoCardView>,
    public IViewObjectExImpl<CUnoCardView>,
    public IObjectSafetyImpl<CUnoCardView, (INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA)>
{
public:
    CUnoCardView();
    ~CUnoCardView();

    DECLARE_REGISTRY_RESOURCEID(IDR_UNOCARDVIEW)
    DECLARE_NOT_AGGREGATABLE(CUnoCardView)

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP(CUnoCardView)
        COM_INTERFACE_ENTRY(IUnoCardView)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IOleObject)
        COM_INTERFACE_ENTRY(IOleControl)
        COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
        COM_INTERFACE_ENTRY(IOleInPlaceObject)
        COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
        COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
        COM_INTERFACE_ENTRY(IPersistStreamInit)
        COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
        COM_INTERFACE_ENTRY_IMPL(IPersistPropertyBag)
        COM_INTERFACE_ENTRY(IViewObjectEx)
        COM_INTERFACE_ENTRY(IViewObject2)
        COM_INTERFACE_ENTRY(IViewObject)
        COM_INTERFACE_ENTRY(IObjectSafety)
    END_COM_MAP()

    BEGIN_PROP_MAP(CUnoCardView)
        PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
        PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
        PROP_ENTRY("BorderColor", DISPID_BORDERCOLOR, CLSID_StockColorPage)
        PROP_ENTRY("BorderStyle", DISPID_BORDERSTYLE, CLSID_NULL)
        PROP_ENTRY("BorderVisible", DISPID_BORDERVISIBLE, CLSID_NULL)
        PROP_ENTRY("BorderWidth", DISPID_BORDERWIDTH, CLSID_NULL)
        PROP_ENTRY("MousePointer", DISPID_MOUSEPOINTER, CLSID_NULL)
        PROP_ENTRY("TabStop", DISPID_TABSTOP, CLSID_NULL)
        //PROP_ENTRY("Property Description", dispid, clsid)
        //PROP_PAGE(CLSID_StockColorPage)
    END_PROP_MAP()

    BEGIN_MSG_MAP(CUnoCardView)
        CHAIN_MSG_MAP(CComControl<CUnoCardView>)
        DEFAULT_REFLECTION_HANDLER()
    END_MSG_MAP()

    DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

    //LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    //LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    //LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

    HRESULT OnDraw(ATL_DRAWINFO& di);

    OLE_COLOR m_clrBorderColor;
    LONG m_nBorderStyle;
    BOOL m_bBorderVisible;
    LONG m_nBorderWidth;
    LONG m_nMousePointer;
    BOOL m_bTabStop;

// IUnoCardView
public:
    STDMETHOD(get_Card)(IDispatch** ppCard);
    STDMETHOD(put_Card)(IDispatch* pCard);

private:
    CComPtr<IDispatch> m_spCard;

};

#endif //__UNOCARDVIEW_H_
