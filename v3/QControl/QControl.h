

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Sun Feb 25 15:03:32 2007
 */
/* Compiler settings for .\QControl.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __QControl_h__
#define __QControl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IUnoCardView_FWD_DEFINED__
#define __IUnoCardView_FWD_DEFINED__
typedef interface IUnoCardView IUnoCardView;
#endif 	/* __IUnoCardView_FWD_DEFINED__ */


#ifndef __UnoCardView_FWD_DEFINED__
#define __UnoCardView_FWD_DEFINED__

#ifdef __cplusplus
typedef class UnoCardView UnoCardView;
#else
typedef struct UnoCardView UnoCardView;
#endif /* __cplusplus */

#endif 	/* __UnoCardView_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IUnoCardView_INTERFACE_DEFINED__
#define __IUnoCardView_INTERFACE_DEFINED__

/* interface IUnoCardView */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUnoCardView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8171D545-84BA-43FB-A82F-247D4379B74B")
    IUnoCardView : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Card( 
            /* [retval][out] */ IDispatch **ppCard) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Card( 
            /* [in] */ IDispatch *pCard) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BorderColor( 
            /* [retval][out] */ OLE_COLOR *pcBorderColor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BorderColor( 
            /* [in] */ OLE_COLOR cBorderColor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BorderStyle( 
            /* [retval][out] */ long *plBorderStyle) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BorderStyle( 
            /* [in] */ long lBorderStyle) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BorderVisible( 
            /* [retval][out] */ VARIANT_BOOL *pbBorderVisible) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BorderVisible( 
            /* [in] */ VARIANT_BOOL bBorderVisible) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BorderWidth( 
            /* [retval][out] */ long *plBorderWidth) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BorderWidth( 
            /* [in] */ long lBorderWidth) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MousePointer( 
            /* [retval][out] */ long *plMousePointer) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MousePointer( 
            /* [in] */ long lMousePointer) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TabStop( 
            /* [retval][out] */ VARIANT_BOOL *pbTabStop) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TabStop( 
            /* [in] */ VARIANT_BOOL bTabStop) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUnoCardViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUnoCardView * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUnoCardView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUnoCardView * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUnoCardView * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUnoCardView * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUnoCardView * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUnoCardView * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Card )( 
            IUnoCardView * This,
            /* [retval][out] */ IDispatch **ppCard);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Card )( 
            IUnoCardView * This,
            /* [in] */ IDispatch *pCard);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BorderColor )( 
            IUnoCardView * This,
            /* [retval][out] */ OLE_COLOR *pcBorderColor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BorderColor )( 
            IUnoCardView * This,
            /* [in] */ OLE_COLOR cBorderColor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BorderStyle )( 
            IUnoCardView * This,
            /* [retval][out] */ long *plBorderStyle);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BorderStyle )( 
            IUnoCardView * This,
            /* [in] */ long lBorderStyle);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BorderVisible )( 
            IUnoCardView * This,
            /* [retval][out] */ VARIANT_BOOL *pbBorderVisible);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BorderVisible )( 
            IUnoCardView * This,
            /* [in] */ VARIANT_BOOL bBorderVisible);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BorderWidth )( 
            IUnoCardView * This,
            /* [retval][out] */ long *plBorderWidth);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BorderWidth )( 
            IUnoCardView * This,
            /* [in] */ long lBorderWidth);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MousePointer )( 
            IUnoCardView * This,
            /* [retval][out] */ long *plMousePointer);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MousePointer )( 
            IUnoCardView * This,
            /* [in] */ long lMousePointer);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabStop )( 
            IUnoCardView * This,
            /* [retval][out] */ VARIANT_BOOL *pbTabStop);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabStop )( 
            IUnoCardView * This,
            /* [in] */ VARIANT_BOOL bTabStop);
        
        END_INTERFACE
    } IUnoCardViewVtbl;

    interface IUnoCardView
    {
        CONST_VTBL struct IUnoCardViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUnoCardView_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUnoCardView_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUnoCardView_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUnoCardView_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUnoCardView_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUnoCardView_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUnoCardView_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IUnoCardView_get_Card(This,ppCard)	\
    (This)->lpVtbl -> get_Card(This,ppCard)

#define IUnoCardView_put_Card(This,pCard)	\
    (This)->lpVtbl -> put_Card(This,pCard)

#define IUnoCardView_get_BorderColor(This,pcBorderColor)	\
    (This)->lpVtbl -> get_BorderColor(This,pcBorderColor)

#define IUnoCardView_put_BorderColor(This,cBorderColor)	\
    (This)->lpVtbl -> put_BorderColor(This,cBorderColor)

#define IUnoCardView_get_BorderStyle(This,plBorderStyle)	\
    (This)->lpVtbl -> get_BorderStyle(This,plBorderStyle)

#define IUnoCardView_put_BorderStyle(This,lBorderStyle)	\
    (This)->lpVtbl -> put_BorderStyle(This,lBorderStyle)

#define IUnoCardView_get_BorderVisible(This,pbBorderVisible)	\
    (This)->lpVtbl -> get_BorderVisible(This,pbBorderVisible)

#define IUnoCardView_put_BorderVisible(This,bBorderVisible)	\
    (This)->lpVtbl -> put_BorderVisible(This,bBorderVisible)

#define IUnoCardView_get_BorderWidth(This,plBorderWidth)	\
    (This)->lpVtbl -> get_BorderWidth(This,plBorderWidth)

#define IUnoCardView_put_BorderWidth(This,lBorderWidth)	\
    (This)->lpVtbl -> put_BorderWidth(This,lBorderWidth)

#define IUnoCardView_get_MousePointer(This,plMousePointer)	\
    (This)->lpVtbl -> get_MousePointer(This,plMousePointer)

#define IUnoCardView_put_MousePointer(This,lMousePointer)	\
    (This)->lpVtbl -> put_MousePointer(This,lMousePointer)

#define IUnoCardView_get_TabStop(This,pbTabStop)	\
    (This)->lpVtbl -> get_TabStop(This,pbTabStop)

#define IUnoCardView_put_TabStop(This,bTabStop)	\
    (This)->lpVtbl -> put_TabStop(This,bTabStop)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoCardView_get_Card_Proxy( 
    IUnoCardView * This,
    /* [retval][out] */ IDispatch **ppCard);


void __RPC_STUB IUnoCardView_get_Card_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUnoCardView_put_Card_Proxy( 
    IUnoCardView * This,
    /* [in] */ IDispatch *pCard);


void __RPC_STUB IUnoCardView_put_Card_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoCardView_get_BorderColor_Proxy( 
    IUnoCardView * This,
    /* [retval][out] */ OLE_COLOR *pcBorderColor);


void __RPC_STUB IUnoCardView_get_BorderColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUnoCardView_put_BorderColor_Proxy( 
    IUnoCardView * This,
    /* [in] */ OLE_COLOR cBorderColor);


void __RPC_STUB IUnoCardView_put_BorderColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoCardView_get_BorderStyle_Proxy( 
    IUnoCardView * This,
    /* [retval][out] */ long *plBorderStyle);


void __RPC_STUB IUnoCardView_get_BorderStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUnoCardView_put_BorderStyle_Proxy( 
    IUnoCardView * This,
    /* [in] */ long lBorderStyle);


void __RPC_STUB IUnoCardView_put_BorderStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoCardView_get_BorderVisible_Proxy( 
    IUnoCardView * This,
    /* [retval][out] */ VARIANT_BOOL *pbBorderVisible);


void __RPC_STUB IUnoCardView_get_BorderVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUnoCardView_put_BorderVisible_Proxy( 
    IUnoCardView * This,
    /* [in] */ VARIANT_BOOL bBorderVisible);


void __RPC_STUB IUnoCardView_put_BorderVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoCardView_get_BorderWidth_Proxy( 
    IUnoCardView * This,
    /* [retval][out] */ long *plBorderWidth);


void __RPC_STUB IUnoCardView_get_BorderWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUnoCardView_put_BorderWidth_Proxy( 
    IUnoCardView * This,
    /* [in] */ long lBorderWidth);


void __RPC_STUB IUnoCardView_put_BorderWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoCardView_get_MousePointer_Proxy( 
    IUnoCardView * This,
    /* [retval][out] */ long *plMousePointer);


void __RPC_STUB IUnoCardView_get_MousePointer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUnoCardView_put_MousePointer_Proxy( 
    IUnoCardView * This,
    /* [in] */ long lMousePointer);


void __RPC_STUB IUnoCardView_put_MousePointer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoCardView_get_TabStop_Proxy( 
    IUnoCardView * This,
    /* [retval][out] */ VARIANT_BOOL *pbTabStop);


void __RPC_STUB IUnoCardView_get_TabStop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUnoCardView_put_TabStop_Proxy( 
    IUnoCardView * This,
    /* [in] */ VARIANT_BOOL bTabStop);


void __RPC_STUB IUnoCardView_put_TabStop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUnoCardView_INTERFACE_DEFINED__ */



#ifndef __QControlLib_LIBRARY_DEFINED__
#define __QControlLib_LIBRARY_DEFINED__

/* library QControlLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_QControlLib;

EXTERN_C const CLSID CLSID_UnoCardView;

#ifdef __cplusplus

class DECLSPEC_UUID("029B4FE1-EC0D-4975-9D23-9D97849D18F7")
UnoCardView;
#endif
#endif /* __QControlLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


