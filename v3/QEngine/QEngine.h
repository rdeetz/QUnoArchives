

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Sun Feb 25 15:03:25 2007
 */
/* Compiler settings for .\QEngine.idl:
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

#ifndef __QEngine_h__
#define __QEngine_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IUnoCard_FWD_DEFINED__
#define __IUnoCard_FWD_DEFINED__
typedef interface IUnoCard IUnoCard;
#endif 	/* __IUnoCard_FWD_DEFINED__ */


#ifndef __IUnoCardInit_FWD_DEFINED__
#define __IUnoCardInit_FWD_DEFINED__
typedef interface IUnoCardInit IUnoCardInit;
#endif 	/* __IUnoCardInit_FWD_DEFINED__ */


#ifndef __IUnoHand_FWD_DEFINED__
#define __IUnoHand_FWD_DEFINED__
typedef interface IUnoHand IUnoHand;
#endif 	/* __IUnoHand_FWD_DEFINED__ */


#ifndef __IUnoPlayer_FWD_DEFINED__
#define __IUnoPlayer_FWD_DEFINED__
typedef interface IUnoPlayer IUnoPlayer;
#endif 	/* __IUnoPlayer_FWD_DEFINED__ */


#ifndef __IUnoPlayerCmd_FWD_DEFINED__
#define __IUnoPlayerCmd_FWD_DEFINED__
typedef interface IUnoPlayerCmd IUnoPlayerCmd;
#endif 	/* __IUnoPlayerCmd_FWD_DEFINED__ */


#ifndef __IUnoPlayers_FWD_DEFINED__
#define __IUnoPlayers_FWD_DEFINED__
typedef interface IUnoPlayers IUnoPlayers;
#endif 	/* __IUnoPlayers_FWD_DEFINED__ */


#ifndef __IUnoDeck_FWD_DEFINED__
#define __IUnoDeck_FWD_DEFINED__
typedef interface IUnoDeck IUnoDeck;
#endif 	/* __IUnoDeck_FWD_DEFINED__ */


#ifndef __IUnoGame_FWD_DEFINED__
#define __IUnoGame_FWD_DEFINED__
typedef interface IUnoGame IUnoGame;
#endif 	/* __IUnoGame_FWD_DEFINED__ */


#ifndef __IUnoGameCmd_FWD_DEFINED__
#define __IUnoGameCmd_FWD_DEFINED__
typedef interface IUnoGameCmd IUnoGameCmd;
#endif 	/* __IUnoGameCmd_FWD_DEFINED__ */


#ifndef __IUnoEngine_FWD_DEFINED__
#define __IUnoEngine_FWD_DEFINED__
typedef interface IUnoEngine IUnoEngine;
#endif 	/* __IUnoEngine_FWD_DEFINED__ */


#ifndef __IUnoGameEvents_FWD_DEFINED__
#define __IUnoGameEvents_FWD_DEFINED__
typedef interface IUnoGameEvents IUnoGameEvents;
#endif 	/* __IUnoGameEvents_FWD_DEFINED__ */


#ifndef __UnoCard_FWD_DEFINED__
#define __UnoCard_FWD_DEFINED__

#ifdef __cplusplus
typedef class UnoCard UnoCard;
#else
typedef struct UnoCard UnoCard;
#endif /* __cplusplus */

#endif 	/* __UnoCard_FWD_DEFINED__ */


#ifndef __UnoHand_FWD_DEFINED__
#define __UnoHand_FWD_DEFINED__

#ifdef __cplusplus
typedef class UnoHand UnoHand;
#else
typedef struct UnoHand UnoHand;
#endif /* __cplusplus */

#endif 	/* __UnoHand_FWD_DEFINED__ */


#ifndef __UnoPlayer_FWD_DEFINED__
#define __UnoPlayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class UnoPlayer UnoPlayer;
#else
typedef struct UnoPlayer UnoPlayer;
#endif /* __cplusplus */

#endif 	/* __UnoPlayer_FWD_DEFINED__ */


#ifndef __UnoPlayers_FWD_DEFINED__
#define __UnoPlayers_FWD_DEFINED__

#ifdef __cplusplus
typedef class UnoPlayers UnoPlayers;
#else
typedef struct UnoPlayers UnoPlayers;
#endif /* __cplusplus */

#endif 	/* __UnoPlayers_FWD_DEFINED__ */


#ifndef __UnoDeck_FWD_DEFINED__
#define __UnoDeck_FWD_DEFINED__

#ifdef __cplusplus
typedef class UnoDeck UnoDeck;
#else
typedef struct UnoDeck UnoDeck;
#endif /* __cplusplus */

#endif 	/* __UnoDeck_FWD_DEFINED__ */


#ifndef __UnoGame_FWD_DEFINED__
#define __UnoGame_FWD_DEFINED__

#ifdef __cplusplus
typedef class UnoGame UnoGame;
#else
typedef struct UnoGame UnoGame;
#endif /* __cplusplus */

#endif 	/* __UnoGame_FWD_DEFINED__ */


#ifndef __UnoEngine_FWD_DEFINED__
#define __UnoEngine_FWD_DEFINED__

#ifdef __cplusplus
typedef class UnoEngine UnoEngine;
#else
typedef struct UnoEngine UnoEngine;
#endif /* __cplusplus */

#endif 	/* __UnoEngine_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_QEngine_0000 */
/* [local] */ 

typedef /* [public][public][public][helpstring] */ 
enum __MIDL___MIDL_itf_QEngine_0000_0001
    {	UnoNoValue	= -6,
	UnoWildDrawFour	= -5,
	UnoWild	= -4,
	UnoDrawTwo	= -3,
	UnoSkip	= -2,
	UnoReverse	= -1,
	UnoZero	= 0,
	UnoOne	= 1,
	UnoTwo	= 2,
	UnoThree	= 3,
	UnoFour	= 4,
	UnoFive	= 5,
	UnoSix	= 6,
	UnoSeven	= 7,
	UnoEight	= 8,
	UnoNine	= 9
    } 	UnoValue;

typedef /* [public][public][public][public][public][public][helpstring] */ 
enum __MIDL___MIDL_itf_QEngine_0000_0002
    {	UnoNoColor	= 0,
	UnoRed	= 1,
	UnoBlue	= 2,
	UnoYellow	= 3,
	UnoGreen	= 4
    } 	UnoColor;

typedef /* [public][public][public][public][helpstring] */ 
enum __MIDL___MIDL_itf_QEngine_0000_0003
    {	UnoComputer	= 0,
	UnoHuman	= 1
    } 	UnoPlayerType;



extern RPC_IF_HANDLE __MIDL_itf_QEngine_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_QEngine_0000_v0_0_s_ifspec;

#ifndef __IUnoCard_INTERFACE_DEFINED__
#define __IUnoCard_INTERFACE_DEFINED__

/* interface IUnoCard */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUnoCard;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3CD772B7-C253-44B2-A711-A09FA4579443")
    IUnoCard : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ UnoValue *peValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Color( 
            /* [retval][out] */ UnoColor *peColor) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUnoCardVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUnoCard * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUnoCard * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUnoCard * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUnoCard * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUnoCard * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUnoCard * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUnoCard * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IUnoCard * This,
            /* [retval][out] */ UnoValue *peValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Color )( 
            IUnoCard * This,
            /* [retval][out] */ UnoColor *peColor);
        
        END_INTERFACE
    } IUnoCardVtbl;

    interface IUnoCard
    {
        CONST_VTBL struct IUnoCardVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUnoCard_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUnoCard_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUnoCard_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUnoCard_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUnoCard_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUnoCard_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUnoCard_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IUnoCard_get_Value(This,peValue)	\
    (This)->lpVtbl -> get_Value(This,peValue)

#define IUnoCard_get_Color(This,peColor)	\
    (This)->lpVtbl -> get_Color(This,peColor)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoCard_get_Value_Proxy( 
    IUnoCard * This,
    /* [retval][out] */ UnoValue *peValue);


void __RPC_STUB IUnoCard_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoCard_get_Color_Proxy( 
    IUnoCard * This,
    /* [retval][out] */ UnoColor *peColor);


void __RPC_STUB IUnoCard_get_Color_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUnoCard_INTERFACE_DEFINED__ */


#ifndef __IUnoCardInit_INTERFACE_DEFINED__
#define __IUnoCardInit_INTERFACE_DEFINED__

/* interface IUnoCardInit */
/* [unique][helpstring][hidden][uuid][object] */ 


EXTERN_C const IID IID_IUnoCardInit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EBA254CD-A44B-42bf-950F-D0B13CCBED6F")
    IUnoCardInit : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ UnoValue eValue,
            /* [in] */ UnoColor eColor) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUnoCardInitVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUnoCardInit * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUnoCardInit * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUnoCardInit * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IUnoCardInit * This,
            /* [in] */ UnoValue eValue,
            /* [in] */ UnoColor eColor);
        
        END_INTERFACE
    } IUnoCardInitVtbl;

    interface IUnoCardInit
    {
        CONST_VTBL struct IUnoCardInitVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUnoCardInit_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUnoCardInit_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUnoCardInit_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUnoCardInit_Initialize(This,eValue,eColor)	\
    (This)->lpVtbl -> Initialize(This,eValue,eColor)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IUnoCardInit_Initialize_Proxy( 
    IUnoCardInit * This,
    /* [in] */ UnoValue eValue,
    /* [in] */ UnoColor eColor);


void __RPC_STUB IUnoCardInit_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUnoCardInit_INTERFACE_DEFINED__ */


#ifndef __IUnoHand_INTERFACE_DEFINED__
#define __IUnoHand_INTERFACE_DEFINED__

/* interface IUnoHand */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUnoHand;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9AC2D47E-B781-429A-A750-C74B76C4FBF6")
    IUnoHand : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *plCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long lIndex,
            /* [retval][out] */ IUnoCard **ppCard) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IUnoCard *pCard) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ long lIndex,
            /* [retval][out] */ IUnoCard **ppCard) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppUnkEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUnoHandVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUnoHand * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUnoHand * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUnoHand * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUnoHand * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUnoHand * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUnoHand * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUnoHand * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IUnoHand * This,
            /* [retval][out] */ long *plCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IUnoHand * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ IUnoCard **ppCard);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IUnoHand * This,
            /* [in] */ IUnoCard *pCard);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IUnoHand * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ IUnoCard **ppCard);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IUnoHand * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IUnoHand * This,
            /* [retval][out] */ IUnknown **ppUnkEnum);
        
        END_INTERFACE
    } IUnoHandVtbl;

    interface IUnoHand
    {
        CONST_VTBL struct IUnoHandVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUnoHand_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUnoHand_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUnoHand_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUnoHand_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUnoHand_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUnoHand_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUnoHand_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IUnoHand_get_Count(This,plCount)	\
    (This)->lpVtbl -> get_Count(This,plCount)

#define IUnoHand_get_Item(This,lIndex,ppCard)	\
    (This)->lpVtbl -> get_Item(This,lIndex,ppCard)

#define IUnoHand_Add(This,pCard)	\
    (This)->lpVtbl -> Add(This,pCard)

#define IUnoHand_Remove(This,lIndex,ppCard)	\
    (This)->lpVtbl -> Remove(This,lIndex,ppCard)

#define IUnoHand_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define IUnoHand_get__NewEnum(This,ppUnkEnum)	\
    (This)->lpVtbl -> get__NewEnum(This,ppUnkEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoHand_get_Count_Proxy( 
    IUnoHand * This,
    /* [retval][out] */ long *plCount);


void __RPC_STUB IUnoHand_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoHand_get_Item_Proxy( 
    IUnoHand * This,
    /* [in] */ long lIndex,
    /* [retval][out] */ IUnoCard **ppCard);


void __RPC_STUB IUnoHand_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUnoHand_Add_Proxy( 
    IUnoHand * This,
    /* [in] */ IUnoCard *pCard);


void __RPC_STUB IUnoHand_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUnoHand_Remove_Proxy( 
    IUnoHand * This,
    /* [in] */ long lIndex,
    /* [retval][out] */ IUnoCard **ppCard);


void __RPC_STUB IUnoHand_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUnoHand_Clear_Proxy( 
    IUnoHand * This);


void __RPC_STUB IUnoHand_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoHand_get__NewEnum_Proxy( 
    IUnoHand * This,
    /* [retval][out] */ IUnknown **ppUnkEnum);


void __RPC_STUB IUnoHand_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUnoHand_INTERFACE_DEFINED__ */


#ifndef __IUnoPlayer_INTERFACE_DEFINED__
#define __IUnoPlayer_INTERFACE_DEFINED__

/* interface IUnoPlayer */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUnoPlayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("38342573-8727-44EB-8C19-468B4E26AFFA")
    IUnoPlayer : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ UnoPlayerType *peType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Type( 
            /* [in] */ UnoPlayerType eType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Hand( 
            /* [retval][out] */ IUnoHand **ppHand) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Draw( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Play( 
            /* [in] */ long lIndex,
            /* [retval][out] */ VARIANT_BOOL *pbPlayed) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Pass( 
            /* [retval][out] */ VARIANT_BOOL *pbPassed) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUnoPlayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUnoPlayer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUnoPlayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUnoPlayer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUnoPlayer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUnoPlayer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUnoPlayer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUnoPlayer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IUnoPlayer * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IUnoPlayer * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IUnoPlayer * This,
            /* [retval][out] */ UnoPlayerType *peType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Type )( 
            IUnoPlayer * This,
            /* [in] */ UnoPlayerType eType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Hand )( 
            IUnoPlayer * This,
            /* [retval][out] */ IUnoHand **ppHand);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Draw )( 
            IUnoPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Play )( 
            IUnoPlayer * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ VARIANT_BOOL *pbPlayed);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Pass )( 
            IUnoPlayer * This,
            /* [retval][out] */ VARIANT_BOOL *pbPassed);
        
        END_INTERFACE
    } IUnoPlayerVtbl;

    interface IUnoPlayer
    {
        CONST_VTBL struct IUnoPlayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUnoPlayer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUnoPlayer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUnoPlayer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUnoPlayer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUnoPlayer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUnoPlayer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUnoPlayer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IUnoPlayer_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#define IUnoPlayer_put_Name(This,bstrName)	\
    (This)->lpVtbl -> put_Name(This,bstrName)

#define IUnoPlayer_get_Type(This,peType)	\
    (This)->lpVtbl -> get_Type(This,peType)

#define IUnoPlayer_put_Type(This,eType)	\
    (This)->lpVtbl -> put_Type(This,eType)

#define IUnoPlayer_get_Hand(This,ppHand)	\
    (This)->lpVtbl -> get_Hand(This,ppHand)

#define IUnoPlayer_Draw(This)	\
    (This)->lpVtbl -> Draw(This)

#define IUnoPlayer_Play(This,lIndex,pbPlayed)	\
    (This)->lpVtbl -> Play(This,lIndex,pbPlayed)

#define IUnoPlayer_Pass(This,pbPassed)	\
    (This)->lpVtbl -> Pass(This,pbPassed)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoPlayer_get_Name_Proxy( 
    IUnoPlayer * This,
    /* [retval][out] */ BSTR *pbstrName);


void __RPC_STUB IUnoPlayer_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUnoPlayer_put_Name_Proxy( 
    IUnoPlayer * This,
    /* [in] */ BSTR bstrName);


void __RPC_STUB IUnoPlayer_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoPlayer_get_Type_Proxy( 
    IUnoPlayer * This,
    /* [retval][out] */ UnoPlayerType *peType);


void __RPC_STUB IUnoPlayer_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUnoPlayer_put_Type_Proxy( 
    IUnoPlayer * This,
    /* [in] */ UnoPlayerType eType);


void __RPC_STUB IUnoPlayer_put_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoPlayer_get_Hand_Proxy( 
    IUnoPlayer * This,
    /* [retval][out] */ IUnoHand **ppHand);


void __RPC_STUB IUnoPlayer_get_Hand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUnoPlayer_Draw_Proxy( 
    IUnoPlayer * This);


void __RPC_STUB IUnoPlayer_Draw_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUnoPlayer_Play_Proxy( 
    IUnoPlayer * This,
    /* [in] */ long lIndex,
    /* [retval][out] */ VARIANT_BOOL *pbPlayed);


void __RPC_STUB IUnoPlayer_Play_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUnoPlayer_Pass_Proxy( 
    IUnoPlayer * This,
    /* [retval][out] */ VARIANT_BOOL *pbPassed);


void __RPC_STUB IUnoPlayer_Pass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUnoPlayer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_QEngine_0265 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_QEngine_0265_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_QEngine_0265_v0_0_s_ifspec;

#ifndef __IUnoPlayerCmd_INTERFACE_DEFINED__
#define __IUnoPlayerCmd_INTERFACE_DEFINED__

/* interface IUnoPlayerCmd */
/* [unique][helpstring][hidden][uuid][object] */ 


EXTERN_C const IID IID_IUnoPlayerCmd;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F39552D5-D885-4aeb-A401-27C1CD05616F")
    IUnoPlayerCmd : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ IUnoGameCmd *pGameCmd) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Terminate( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUnoPlayerCmdVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUnoPlayerCmd * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUnoPlayerCmd * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUnoPlayerCmd * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IUnoPlayerCmd * This,
            /* [in] */ IUnoGameCmd *pGameCmd);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Terminate )( 
            IUnoPlayerCmd * This);
        
        END_INTERFACE
    } IUnoPlayerCmdVtbl;

    interface IUnoPlayerCmd
    {
        CONST_VTBL struct IUnoPlayerCmdVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUnoPlayerCmd_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUnoPlayerCmd_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUnoPlayerCmd_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUnoPlayerCmd_Initialize(This,pGameCmd)	\
    (This)->lpVtbl -> Initialize(This,pGameCmd)

#define IUnoPlayerCmd_Terminate(This)	\
    (This)->lpVtbl -> Terminate(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IUnoPlayerCmd_Initialize_Proxy( 
    IUnoPlayerCmd * This,
    /* [in] */ IUnoGameCmd *pGameCmd);


void __RPC_STUB IUnoPlayerCmd_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IUnoPlayerCmd_Terminate_Proxy( 
    IUnoPlayerCmd * This);


void __RPC_STUB IUnoPlayerCmd_Terminate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUnoPlayerCmd_INTERFACE_DEFINED__ */


#ifndef __IUnoPlayers_INTERFACE_DEFINED__
#define __IUnoPlayers_INTERFACE_DEFINED__

/* interface IUnoPlayers */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUnoPlayers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3A59ABF4-82DD-4587-B034-8226A780129D")
    IUnoPlayers : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *plCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long lIndex,
            /* [retval][out] */ IUnoPlayer **ppPlayer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IUnoPlayer *pPlayer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ long lIndex,
            /* [retval][out] */ IUnoPlayer **ppPlayer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppUnkEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUnoPlayersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUnoPlayers * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUnoPlayers * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUnoPlayers * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUnoPlayers * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUnoPlayers * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUnoPlayers * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUnoPlayers * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IUnoPlayers * This,
            /* [retval][out] */ long *plCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IUnoPlayers * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ IUnoPlayer **ppPlayer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IUnoPlayers * This,
            /* [in] */ IUnoPlayer *pPlayer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IUnoPlayers * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ IUnoPlayer **ppPlayer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IUnoPlayers * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IUnoPlayers * This,
            /* [retval][out] */ IUnknown **ppUnkEnum);
        
        END_INTERFACE
    } IUnoPlayersVtbl;

    interface IUnoPlayers
    {
        CONST_VTBL struct IUnoPlayersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUnoPlayers_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUnoPlayers_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUnoPlayers_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUnoPlayers_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUnoPlayers_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUnoPlayers_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUnoPlayers_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IUnoPlayers_get_Count(This,plCount)	\
    (This)->lpVtbl -> get_Count(This,plCount)

#define IUnoPlayers_get_Item(This,lIndex,ppPlayer)	\
    (This)->lpVtbl -> get_Item(This,lIndex,ppPlayer)

#define IUnoPlayers_Add(This,pPlayer)	\
    (This)->lpVtbl -> Add(This,pPlayer)

#define IUnoPlayers_Remove(This,lIndex,ppPlayer)	\
    (This)->lpVtbl -> Remove(This,lIndex,ppPlayer)

#define IUnoPlayers_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define IUnoPlayers_get__NewEnum(This,ppUnkEnum)	\
    (This)->lpVtbl -> get__NewEnum(This,ppUnkEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoPlayers_get_Count_Proxy( 
    IUnoPlayers * This,
    /* [retval][out] */ long *plCount);


void __RPC_STUB IUnoPlayers_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoPlayers_get_Item_Proxy( 
    IUnoPlayers * This,
    /* [in] */ long lIndex,
    /* [retval][out] */ IUnoPlayer **ppPlayer);


void __RPC_STUB IUnoPlayers_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUnoPlayers_Add_Proxy( 
    IUnoPlayers * This,
    /* [in] */ IUnoPlayer *pPlayer);


void __RPC_STUB IUnoPlayers_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUnoPlayers_Remove_Proxy( 
    IUnoPlayers * This,
    /* [in] */ long lIndex,
    /* [retval][out] */ IUnoPlayer **ppPlayer);


void __RPC_STUB IUnoPlayers_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUnoPlayers_Clear_Proxy( 
    IUnoPlayers * This);


void __RPC_STUB IUnoPlayers_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoPlayers_get__NewEnum_Proxy( 
    IUnoPlayers * This,
    /* [retval][out] */ IUnknown **ppUnkEnum);


void __RPC_STUB IUnoPlayers_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUnoPlayers_INTERFACE_DEFINED__ */


#ifndef __IUnoDeck_INTERFACE_DEFINED__
#define __IUnoDeck_INTERFACE_DEFINED__

/* interface IUnoDeck */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUnoDeck;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8E4B6F66-A9BA-463A-949D-F0EA7B952148")
    IUnoDeck : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DrawCount( 
            /* [retval][out] */ long *plDrawCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PlayedCount( 
            /* [retval][out] */ long *plPlayedCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveCard( 
            /* [retval][out] */ IUnoCard **ppActiveCard) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Draw( 
            /* [retval][out] */ IUnoCard **ppCard) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Play( 
            /* [in] */ IUnoCard *pCard) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUnoDeckVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUnoDeck * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUnoDeck * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUnoDeck * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUnoDeck * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUnoDeck * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUnoDeck * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUnoDeck * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DrawCount )( 
            IUnoDeck * This,
            /* [retval][out] */ long *plDrawCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlayedCount )( 
            IUnoDeck * This,
            /* [retval][out] */ long *plPlayedCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveCard )( 
            IUnoDeck * This,
            /* [retval][out] */ IUnoCard **ppActiveCard);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Draw )( 
            IUnoDeck * This,
            /* [retval][out] */ IUnoCard **ppCard);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Play )( 
            IUnoDeck * This,
            /* [in] */ IUnoCard *pCard);
        
        END_INTERFACE
    } IUnoDeckVtbl;

    interface IUnoDeck
    {
        CONST_VTBL struct IUnoDeckVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUnoDeck_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUnoDeck_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUnoDeck_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUnoDeck_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUnoDeck_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUnoDeck_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUnoDeck_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IUnoDeck_get_DrawCount(This,plDrawCount)	\
    (This)->lpVtbl -> get_DrawCount(This,plDrawCount)

#define IUnoDeck_get_PlayedCount(This,plPlayedCount)	\
    (This)->lpVtbl -> get_PlayedCount(This,plPlayedCount)

#define IUnoDeck_get_ActiveCard(This,ppActiveCard)	\
    (This)->lpVtbl -> get_ActiveCard(This,ppActiveCard)

#define IUnoDeck_Draw(This,ppCard)	\
    (This)->lpVtbl -> Draw(This,ppCard)

#define IUnoDeck_Play(This,pCard)	\
    (This)->lpVtbl -> Play(This,pCard)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoDeck_get_DrawCount_Proxy( 
    IUnoDeck * This,
    /* [retval][out] */ long *plDrawCount);


void __RPC_STUB IUnoDeck_get_DrawCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoDeck_get_PlayedCount_Proxy( 
    IUnoDeck * This,
    /* [retval][out] */ long *plPlayedCount);


void __RPC_STUB IUnoDeck_get_PlayedCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoDeck_get_ActiveCard_Proxy( 
    IUnoDeck * This,
    /* [retval][out] */ IUnoCard **ppActiveCard);


void __RPC_STUB IUnoDeck_get_ActiveCard_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUnoDeck_Draw_Proxy( 
    IUnoDeck * This,
    /* [retval][out] */ IUnoCard **ppCard);


void __RPC_STUB IUnoDeck_Draw_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUnoDeck_Play_Proxy( 
    IUnoDeck * This,
    /* [in] */ IUnoCard *pCard);


void __RPC_STUB IUnoDeck_Play_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUnoDeck_INTERFACE_DEFINED__ */


#ifndef __IUnoGame_INTERFACE_DEFINED__
#define __IUnoGame_INTERFACE_DEFINED__

/* interface IUnoGame */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUnoGame;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8AA84C28-AC63-4DCF-8FAD-8C0694C0361F")
    IUnoGame : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Title( 
            /* [retval][out] */ BSTR *pbstrTitle) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Title( 
            /* [in] */ BSTR bstrTitle) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Players( 
            /* [retval][out] */ IUnoPlayers **ppPlayers) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Deck( 
            /* [retval][out] */ IUnoDeck **ppDeck) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WildColor( 
            /* [retval][out] */ UnoColor *peWildColor) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WildColor( 
            /* [in] */ UnoColor eWildColor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreatePlayer( 
            /* [in] */ BSTR bstrName,
            /* [in] */ UnoPlayerType eType,
            /* [retval][out] */ IUnoPlayer **ppPlayer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsCardPlayable( 
            /* [in] */ IUnoCard *pCard,
            /* [retval][out] */ VARIANT_BOOL *pbIsCardPlayable) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HandSize( 
            /* [retval][out] */ long *plHandSize) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HandSize( 
            /* [in] */ long lHandSize) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PlayAfterDraw( 
            /* [retval][out] */ VARIANT_BOOL *pbPlayAfterDraw) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PlayAfterDraw( 
            /* [in] */ VARIANT_BOOL bPlayAfterDraw) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUnoGameVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUnoGame * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUnoGame * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUnoGame * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUnoGame * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUnoGame * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUnoGame * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUnoGame * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            IUnoGame * This,
            /* [retval][out] */ BSTR *pbstrTitle);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Title )( 
            IUnoGame * This,
            /* [in] */ BSTR bstrTitle);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Players )( 
            IUnoGame * This,
            /* [retval][out] */ IUnoPlayers **ppPlayers);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Deck )( 
            IUnoGame * This,
            /* [retval][out] */ IUnoDeck **ppDeck);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WildColor )( 
            IUnoGame * This,
            /* [retval][out] */ UnoColor *peWildColor);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WildColor )( 
            IUnoGame * This,
            /* [in] */ UnoColor eWildColor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreatePlayer )( 
            IUnoGame * This,
            /* [in] */ BSTR bstrName,
            /* [in] */ UnoPlayerType eType,
            /* [retval][out] */ IUnoPlayer **ppPlayer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Start )( 
            IUnoGame * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IUnoGame * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsCardPlayable )( 
            IUnoGame * This,
            /* [in] */ IUnoCard *pCard,
            /* [retval][out] */ VARIANT_BOOL *pbIsCardPlayable);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HandSize )( 
            IUnoGame * This,
            /* [retval][out] */ long *plHandSize);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HandSize )( 
            IUnoGame * This,
            /* [in] */ long lHandSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlayAfterDraw )( 
            IUnoGame * This,
            /* [retval][out] */ VARIANT_BOOL *pbPlayAfterDraw);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PlayAfterDraw )( 
            IUnoGame * This,
            /* [in] */ VARIANT_BOOL bPlayAfterDraw);
        
        END_INTERFACE
    } IUnoGameVtbl;

    interface IUnoGame
    {
        CONST_VTBL struct IUnoGameVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUnoGame_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUnoGame_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUnoGame_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUnoGame_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUnoGame_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUnoGame_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUnoGame_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IUnoGame_get_Title(This,pbstrTitle)	\
    (This)->lpVtbl -> get_Title(This,pbstrTitle)

#define IUnoGame_put_Title(This,bstrTitle)	\
    (This)->lpVtbl -> put_Title(This,bstrTitle)

#define IUnoGame_get_Players(This,ppPlayers)	\
    (This)->lpVtbl -> get_Players(This,ppPlayers)

#define IUnoGame_get_Deck(This,ppDeck)	\
    (This)->lpVtbl -> get_Deck(This,ppDeck)

#define IUnoGame_get_WildColor(This,peWildColor)	\
    (This)->lpVtbl -> get_WildColor(This,peWildColor)

#define IUnoGame_put_WildColor(This,eWildColor)	\
    (This)->lpVtbl -> put_WildColor(This,eWildColor)

#define IUnoGame_CreatePlayer(This,bstrName,eType,ppPlayer)	\
    (This)->lpVtbl -> CreatePlayer(This,bstrName,eType,ppPlayer)

#define IUnoGame_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define IUnoGame_Stop(This)	\
    (This)->lpVtbl -> Stop(This)

#define IUnoGame_IsCardPlayable(This,pCard,pbIsCardPlayable)	\
    (This)->lpVtbl -> IsCardPlayable(This,pCard,pbIsCardPlayable)

#define IUnoGame_get_HandSize(This,plHandSize)	\
    (This)->lpVtbl -> get_HandSize(This,plHandSize)

#define IUnoGame_put_HandSize(This,lHandSize)	\
    (This)->lpVtbl -> put_HandSize(This,lHandSize)

#define IUnoGame_get_PlayAfterDraw(This,pbPlayAfterDraw)	\
    (This)->lpVtbl -> get_PlayAfterDraw(This,pbPlayAfterDraw)

#define IUnoGame_put_PlayAfterDraw(This,bPlayAfterDraw)	\
    (This)->lpVtbl -> put_PlayAfterDraw(This,bPlayAfterDraw)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoGame_get_Title_Proxy( 
    IUnoGame * This,
    /* [retval][out] */ BSTR *pbstrTitle);


void __RPC_STUB IUnoGame_get_Title_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUnoGame_put_Title_Proxy( 
    IUnoGame * This,
    /* [in] */ BSTR bstrTitle);


void __RPC_STUB IUnoGame_put_Title_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoGame_get_Players_Proxy( 
    IUnoGame * This,
    /* [retval][out] */ IUnoPlayers **ppPlayers);


void __RPC_STUB IUnoGame_get_Players_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoGame_get_Deck_Proxy( 
    IUnoGame * This,
    /* [retval][out] */ IUnoDeck **ppDeck);


void __RPC_STUB IUnoGame_get_Deck_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoGame_get_WildColor_Proxy( 
    IUnoGame * This,
    /* [retval][out] */ UnoColor *peWildColor);


void __RPC_STUB IUnoGame_get_WildColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUnoGame_put_WildColor_Proxy( 
    IUnoGame * This,
    /* [in] */ UnoColor eWildColor);


void __RPC_STUB IUnoGame_put_WildColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUnoGame_CreatePlayer_Proxy( 
    IUnoGame * This,
    /* [in] */ BSTR bstrName,
    /* [in] */ UnoPlayerType eType,
    /* [retval][out] */ IUnoPlayer **ppPlayer);


void __RPC_STUB IUnoGame_CreatePlayer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUnoGame_Start_Proxy( 
    IUnoGame * This);


void __RPC_STUB IUnoGame_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUnoGame_Stop_Proxy( 
    IUnoGame * This);


void __RPC_STUB IUnoGame_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUnoGame_IsCardPlayable_Proxy( 
    IUnoGame * This,
    /* [in] */ IUnoCard *pCard,
    /* [retval][out] */ VARIANT_BOOL *pbIsCardPlayable);


void __RPC_STUB IUnoGame_IsCardPlayable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoGame_get_HandSize_Proxy( 
    IUnoGame * This,
    /* [retval][out] */ long *plHandSize);


void __RPC_STUB IUnoGame_get_HandSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUnoGame_put_HandSize_Proxy( 
    IUnoGame * This,
    /* [in] */ long lHandSize);


void __RPC_STUB IUnoGame_put_HandSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoGame_get_PlayAfterDraw_Proxy( 
    IUnoGame * This,
    /* [retval][out] */ VARIANT_BOOL *pbPlayAfterDraw);


void __RPC_STUB IUnoGame_get_PlayAfterDraw_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUnoGame_put_PlayAfterDraw_Proxy( 
    IUnoGame * This,
    /* [in] */ VARIANT_BOOL bPlayAfterDraw);


void __RPC_STUB IUnoGame_put_PlayAfterDraw_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUnoGame_INTERFACE_DEFINED__ */


#ifndef __IUnoGameCmd_INTERFACE_DEFINED__
#define __IUnoGameCmd_INTERFACE_DEFINED__

/* interface IUnoGameCmd */
/* [unique][helpstring][hidden][uuid][object] */ 


EXTERN_C const IID IID_IUnoGameCmd;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A141AC69-1DC2-41ab-AD9A-D8A992BDB5DC")
    IUnoGameCmd : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Draw( 
            /* [retval][out] */ IUnoCard **ppCard) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Play( 
            /* [in] */ IUnoCard *pCard,
            /* [retval][out] */ VARIANT_BOOL *pbPlayed) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Pass( 
            /* [retval][out] */ VARIANT_BOOL *pbPassed) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE TurnCompleted( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUnoGameCmdVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUnoGameCmd * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUnoGameCmd * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUnoGameCmd * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Draw )( 
            IUnoGameCmd * This,
            /* [retval][out] */ IUnoCard **ppCard);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Play )( 
            IUnoGameCmd * This,
            /* [in] */ IUnoCard *pCard,
            /* [retval][out] */ VARIANT_BOOL *pbPlayed);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Pass )( 
            IUnoGameCmd * This,
            /* [retval][out] */ VARIANT_BOOL *pbPassed);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *TurnCompleted )( 
            IUnoGameCmd * This);
        
        END_INTERFACE
    } IUnoGameCmdVtbl;

    interface IUnoGameCmd
    {
        CONST_VTBL struct IUnoGameCmdVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUnoGameCmd_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUnoGameCmd_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUnoGameCmd_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUnoGameCmd_Draw(This,ppCard)	\
    (This)->lpVtbl -> Draw(This,ppCard)

#define IUnoGameCmd_Play(This,pCard,pbPlayed)	\
    (This)->lpVtbl -> Play(This,pCard,pbPlayed)

#define IUnoGameCmd_Pass(This,pbPassed)	\
    (This)->lpVtbl -> Pass(This,pbPassed)

#define IUnoGameCmd_TurnCompleted(This)	\
    (This)->lpVtbl -> TurnCompleted(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IUnoGameCmd_Draw_Proxy( 
    IUnoGameCmd * This,
    /* [retval][out] */ IUnoCard **ppCard);


void __RPC_STUB IUnoGameCmd_Draw_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IUnoGameCmd_Play_Proxy( 
    IUnoGameCmd * This,
    /* [in] */ IUnoCard *pCard,
    /* [retval][out] */ VARIANT_BOOL *pbPlayed);


void __RPC_STUB IUnoGameCmd_Play_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IUnoGameCmd_Pass_Proxy( 
    IUnoGameCmd * This,
    /* [retval][out] */ VARIANT_BOOL *pbPassed);


void __RPC_STUB IUnoGameCmd_Pass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IUnoGameCmd_TurnCompleted_Proxy( 
    IUnoGameCmd * This);


void __RPC_STUB IUnoGameCmd_TurnCompleted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUnoGameCmd_INTERFACE_DEFINED__ */


#ifndef __IUnoEngine_INTERFACE_DEFINED__
#define __IUnoEngine_INTERFACE_DEFINED__

/* interface IUnoEngine */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUnoEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A4D1FD39-50F0-418B-9922-B7FA39181007")
    IUnoEngine : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveGame( 
            /* [retval][out] */ IUnoGame **ppActiveGame) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUnoEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUnoEngine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUnoEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUnoEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUnoEngine * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUnoEngine * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUnoEngine * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUnoEngine * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveGame )( 
            IUnoEngine * This,
            /* [retval][out] */ IUnoGame **ppActiveGame);
        
        END_INTERFACE
    } IUnoEngineVtbl;

    interface IUnoEngine
    {
        CONST_VTBL struct IUnoEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUnoEngine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUnoEngine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUnoEngine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUnoEngine_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUnoEngine_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUnoEngine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUnoEngine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IUnoEngine_get_ActiveGame(This,ppActiveGame)	\
    (This)->lpVtbl -> get_ActiveGame(This,ppActiveGame)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnoEngine_get_ActiveGame_Proxy( 
    IUnoEngine * This,
    /* [retval][out] */ IUnoGame **ppActiveGame);


void __RPC_STUB IUnoEngine_get_ActiveGame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUnoEngine_INTERFACE_DEFINED__ */



#ifndef __QEngineLib_LIBRARY_DEFINED__
#define __QEngineLib_LIBRARY_DEFINED__

/* library QEngineLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_QEngineLib;

#ifndef __IUnoGameEvents_DISPINTERFACE_DEFINED__
#define __IUnoGameEvents_DISPINTERFACE_DEFINED__

/* dispinterface IUnoGameEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID_IUnoGameEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F14F3FC7-F49C-428b-88ED-2B3A83B31558")
    IUnoGameEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IUnoGameEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUnoGameEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUnoGameEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUnoGameEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUnoGameEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUnoGameEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUnoGameEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUnoGameEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IUnoGameEventsVtbl;

    interface IUnoGameEvents
    {
        CONST_VTBL struct IUnoGameEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUnoGameEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUnoGameEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUnoGameEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUnoGameEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUnoGameEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUnoGameEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUnoGameEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IUnoGameEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_UnoCard;

#ifdef __cplusplus

class DECLSPEC_UUID("8AB1463C-7F38-4B1A-86D9-E84E403EC2D6")
UnoCard;
#endif

EXTERN_C const CLSID CLSID_UnoHand;

#ifdef __cplusplus

class DECLSPEC_UUID("BE19A0C4-BE05-4601-988D-EE351B2910F1")
UnoHand;
#endif

EXTERN_C const CLSID CLSID_UnoPlayer;

#ifdef __cplusplus

class DECLSPEC_UUID("14266EC4-B716-4E41-AD78-77EFC5868EFB")
UnoPlayer;
#endif

EXTERN_C const CLSID CLSID_UnoPlayers;

#ifdef __cplusplus

class DECLSPEC_UUID("54691592-17CB-4DED-A1C2-5B54214FD0E8")
UnoPlayers;
#endif

EXTERN_C const CLSID CLSID_UnoDeck;

#ifdef __cplusplus

class DECLSPEC_UUID("ECFD4994-D9FB-4A4A-86D7-99F48A1081F1")
UnoDeck;
#endif

EXTERN_C const CLSID CLSID_UnoGame;

#ifdef __cplusplus

class DECLSPEC_UUID("46AFD017-CEF0-47B5-B2F2-0477AE5D0C0C")
UnoGame;
#endif

EXTERN_C const CLSID CLSID_UnoEngine;

#ifdef __cplusplus

class DECLSPEC_UUID("601BC646-1D1E-4E3D-8A9B-8E01AF7AA847")
UnoEngine;
#endif
#endif /* __QEngineLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


