/////////////////////////////////////////////////////////////////////
//
// UnoGameCP.h - definition and implementation of the UnoGame 
//               events proxy object for the 
//               RogCorp QUno Engine 1.0
//
// Copyright © 2000-2001 Roger Deetz
//

#ifndef _UNOGAMECP_H_
#define _UNOGAMECP_H_

#include "QEDispID.h"

template <class T>
class CProxyIUnoGameEvents : 
    public IConnectionPointImpl<T, &DIID_IUnoGameEvents, CComDynamicUnkArray>
{
public:
    VOID Fire_PlayerTurn(long lPlayer) {
        T* pT = static_cast<T*>(this);
        CComVariant* pvars = new CComVariant[1];
        int nConnections = m_vec.GetSize();

        for (int nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++) {
            pT->Lock();
            CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
            pT->Unlock();

            IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);

            if (pDispatch != NULL) {
                pvars[0] = lPlayer;
                DISPPARAMS disp = { pvars, NULL, 1, 0 };
                pDispatch->Invoke(DISPID_UNOGAMEEVENTS_PLAYERTURN, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
            }
        }

        delete[] pvars;
    }

    VOID Fire_PlayerChooseWildColor(long lPlayer, UnoColor* peColor) {
        T* pT = static_cast<T*>(this);
        CComVariant* pvars = new CComVariant[2];
        int nConnections = m_vec.GetSize();
        
        for (int nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++) {
            pT->Lock();
            CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
            pT->Unlock();

            IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);

            if (pDispatch != NULL) {
                pvars[1] = lPlayer;
                pvars[0].vt = (VT_I4 | VT_BYREF);
                pvars[0].plVal = reinterpret_cast<long*>(peColor);
                DISPPARAMS disp = { pvars, NULL, 2, 0 };
                pDispatch->Invoke(DISPID_UNOGAMEEVENTS_PLAYERCHOOSEWILDCOLOR, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
            }
        }

        delete[] pvars;
    }

    VOID Fire_PlayerUno(long lPlayer) {
        T* pT = static_cast<T*>(this);
        CComVariant* pvars = new CComVariant[1];
        int nConnections = m_vec.GetSize();

        for (int nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++) {
            pT->Lock();
            CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
            pT->Unlock();

            IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);

            if (pDispatch != NULL) {
                pvars[0] = lPlayer;
                DISPPARAMS disp = { pvars, NULL, 1, 0 };
                pDispatch->Invoke(DISPID_UNOGAMEEVENTS_PLAYERUNO, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
            }
        }

        delete[] pvars;
    }

    VOID Fire_PlayerOut(long lPlayer, VARIANT_BOOL* pbKeepPlaying) {
        T* pT = static_cast<T*>(this);
        CComVariant* pvars = new CComVariant[2];
        int nConnections = m_vec.GetSize();

        for (int nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++) {
            pT->Lock();
            CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
            pT->Unlock();

            IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);

            if (pDispatch != NULL) {
                pvars[1] = lPlayer;
                pvars[0].vt = (VT_BOOL | VT_BYREF);
                pvars[0].pboolVal = pbKeepPlaying;
                DISPPARAMS disp = { pvars, NULL, 2, 0 };
                pDispatch->Invoke(DISPID_UNOGAMEEVENTS_PLAYEROUT, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
            }
        }

        delete[] pvars;
    }

    VOID Fire_GameOver() {
        T* pT = static_cast<T*>(this);
        int nConnections = m_vec.GetSize();

        for (int nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++) {
            pT->Lock();
            CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
            pT->Unlock();

            IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);

            if (pDispatch != NULL) {
                DISPPARAMS disp = { NULL, NULL, 0, 0 };
                pDispatch->Invoke(DISPID_UNOGAMEEVENTS_GAMEOVER, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
            }
        }
    }
};

#endif
