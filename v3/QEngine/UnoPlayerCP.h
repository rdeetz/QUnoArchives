/////////////////////////////////////////////////////////////////////
//
// UnoPlayerCP.h - definition and implementation of the UnoPlayer 
//                 events proxy object for the 
//                 RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#ifndef _UNOPLAYERCP_H_
#define _UNOPLAYERCP_H_

#include "QEDispID.h"

template <class T>
class CProxyIUnoPlayerEvents : 
    public IConnectionPointImpl<T, &DIID_IUnoPlayerEvents, CComDynamicUnkArray>
{
public:
    VOID Fire_ChooseWildColor(UnoColor* peColor) {
        T* pT = static_cast<T*>(this);
        CComVariant* pvars = new CComVariant[1];
        int nConnections = m_vec.GetSize();
        
        for (int nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++) {
            pT->Lock();
            CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
            pT->Unlock();

            IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);

            if (pDispatch != NULL) {
                pvars[0].vt = (VT_I4 | VT_BYREF);
                pvars[0].plVal = reinterpret_cast<long*>(peColor);
                DISPPARAMS disp = { pvars, NULL, 1, 0 };
                pDispatch->Invoke(DISPID_UNOPLAYEREVENTS_CHOOSEWILDCOLOR, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
            }
        }

        delete[] pvars;
    }
};

#endif
