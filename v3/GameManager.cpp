/////////////////////////////////////////////////////////////////////
//
// GameManager.cpp - implementation of the game manager object for the 
//                   RogCorp QUno 3.0 user interface
//
// Copyright © 2000-2001 Roger Deetz
//

#include "stdafx.h"
#include "GameManager.h"
#include "QGlobal.h"
#include "App.h"

CGameManager::CGameManager() {

}

CGameManager::~CGameManager() {

}

void CGameManager::Initialize() {
    LoadGameSettings();
    LoadPlayers();

    return;
}

void CGameManager::Terminate() {
    StopGame();

    SaveGameSettings();
    SavePlayers();

    return;
}

bool CGameManager::Open(LPTSTR lpFile) {
    if (lstrlen(lpFile) > 0) {
        PathUnquoteSpaces(lpFile);

        if (PathFileExists(lpFile)) {
            ATLTRACE(_T("GameManager Open File: %s\n"), lpFile);

            // TODO: open the file and load the game
            //       (and stop any game in progress)
            //StopGame();
            StartGame(); // TEMP

            LPTSTR lpGameTitle = PathFindFileName(lpFile);
            PathRemoveExtension(lpGameTitle);

            SetGameTitle(lpGameTitle);

        } else {
            StartGame();
            SetGameTitle(_T(""));
        }

    } else {
        StartGame();
        SetGameTitle(_T(""));
    }

    g_App.UpdateWindowTitle();

    // TODO: need to "refresh" the main window

    return true;
}

bool CGameManager::Save(LPTSTR lpFile) {
    if (lstrlen(lpFile) > 0) {
        ATLTRACE(_T("GameManager Save File: %s\n"), lpFile);

        // TODO: save the current game to the provided file

        PathUnquoteSpaces(lpFile);

        LPTSTR lpGameTitle = PathFindFileName(lpFile);
        PathRemoveExtension(lpGameTitle);

        SetGameTitle(lpGameTitle);

        g_App.UpdateWindowTitle();

    } else {
        // TODO: save the current game to the current file
        //       (caller should check if there is a current file, 
        //       but we should also be ready for this)
    }

    return true;
}

void CGameManager::GetGameTitle(LPTSTR lpGameTitle, bool bProvideDefault) {
    USES_CONVERSION;

    CComBSTR bstrGameTitle;

    if (m_spGame) {
        m_spGame->get_Title(&bstrGameTitle);
    }

    if (bstrGameTitle.Length() <= 0) {
        if (bProvideDefault) {
            TCHAR szNewGame[MAX_PATH];
            LoadString(_Module.m_hInstResource, IDS_DEFAULTGAME, szNewGame, MAX_PATH);

            lstrcpy(lpGameTitle, szNewGame);

        } else {
            lstrcpy(lpGameTitle, _T(""));
        }

    } else {
        lstrcpy(lpGameTitle, OLE2T(bstrGameTitle));
    }

    return;
}

void CGameManager::SetGameTitle(LPCTSTR lpGameTitle) {
    CComBSTR bstrGameTitle = lpGameTitle;

    if (m_spGame) {
        m_spGame->put_Title(bstrGameTitle);
    }

    return;
}

long CGameManager::GetHandSize() {
    return m_lHandSize;
}

void CGameManager::SetHandSize(long lHandSize) {
    m_lHandSize = lHandSize;

    return;
}

bool CGameManager::GetPlayAfterDraw() {
    return m_bPlayAfterDraw;
}

void CGameManager::SetPlayAfterDraw(bool bPlayAfterDraw) {
    m_bPlayAfterDraw = bPlayAfterDraw;

    return;
}

long CGameManager::GetPlayerCount() {
    return m_Players.GetSize();
}

bool CGameManager::GetPlayer(long lIndex, LPTSTR lpPlayerName, UnoPlayerType* pePlayerType) {
    USES_CONVERSION;

    bool bOk = false;

    if ((lIndex >= 0) && (lIndex < m_Players.GetSize())) {
        lstrcpy(lpPlayerName, OLE2T(m_Players.GetKeyAt(lIndex)));
        *pePlayerType = m_Players.GetValueAt(lIndex);
        bOk = true;
    }

    return bOk;
}

bool CGameManager::SetPlayer(long lIndex, LPCTSTR lpPlayerName, UnoPlayerType ePlayerType) {
    bool bOk = false;

    if ((lIndex >= 0) && (lIndex < m_Players.GetSize())) {
        CComBSTR bstrPlayerName(lpPlayerName);
        m_Players.m_aKey[lIndex] = bstrPlayerName;
        m_Players.m_aVal[lIndex] = ePlayerType;
        bOk = true;
        //bOk = (bool)m_Players.SetAt(bstrPlayerName, ePlayerType);
    }

    return bOk;
}

bool CGameManager::AddPlayer(LPCTSTR lpPlayerName, UnoPlayerType ePlayerType) {
    bool bOk = false;

    CComBSTR bstrPlayerName(lpPlayerName);

    if (m_Players.Add(bstrPlayerName, ePlayerType)) {
        bOk = true;
    }

    return bOk;
}

bool CGameManager::RemovePlayer(LPCTSTR lpPlayerName) {
    bool bOk = false;

    if (m_Players.GetSize() > 0) {
        CComBSTR bstrPlayerName(lpPlayerName);

        if (m_Players.Remove(bstrPlayerName)) {
            bOk = true;
        }
    }

    return bOk;
}

void __stdcall CGameManager::OnPlayerTurn(long lPlayer) {
    return;
}

void __stdcall CGameManager::OnPlayerChooseWildColor(long lPlayer, UnoColor* peColor) {
    return;
}

void __stdcall CGameManager::OnPlayerUno(long lPlayer) {
    return;
}

void __stdcall CGameManager::OnPlayerOut(long lPlayer, VARIANT_BOOL* pbKeepPlaying) {
    return;
}

void __stdcall CGameManager::OnGameOver(long lPlayer) {
    // TODO: only respond to this if we're not closing a game in progress
    return;
}

void CGameManager::StartGame() {
    StopGame();

    HRESULT hr = m_spGame.CoCreateInstance(CLSID_UnoGame);

    if (SUCCEEDED(hr) && m_spGame) {
        DispEventAdvise(static_cast<IUnknown*>(m_spGame));

        hr = m_spGame->put_HandSize(m_lHandSize);

        VARIANT_BOOL vbPlayAfterDraw;
        m_bPlayAfterDraw ? vbPlayAfterDraw = VARIANT_TRUE : vbPlayAfterDraw = VARIANT_FALSE;
        hr = m_spGame->put_PlayAfterDraw(vbPlayAfterDraw);

        // TODO: we'll need to keep track of the players still playing
        //       separately for 'KeepPlaying' suppression

        for (long i = 0; i < m_Players.GetSize(); i++) {
            CComPtr<IUnoPlayer> spPlayer;
            hr = m_spGame->CreatePlayer(m_Players.GetKeyAt(i), m_Players.GetValueAt(i), &spPlayer);
        }

        hr = m_spGame->Start();
    }

    return;
}

void CGameManager::StopGame() {
    if (m_spGame) {
        HRESULT hr = m_spGame->Stop();

        DispEventUnadvise(static_cast<IUnknown*>(m_spGame));

        m_spGame.Release();
    }

    return;
}

void CGameManager::LoadGameSettings() {
    m_lHandSize = Q_HANDSIZE_DEFAULT;
    m_bPlayAfterDraw = true;

    TCHAR szGamesKey[MAX_PATH] = Q_REGISTRY_KEY_ROOT;
    lstrcat(szGamesKey, Q_REGISTRY_KEY_GAMES);

    CRegKey reg;
    LONG lResult = reg.Create(HKEY_CURRENT_USER, szGamesKey);

    if (lResult == ERROR_SUCCESS) {
        DWORD dwHandSize;
        lResult = reg.QueryValue(dwHandSize, Q_REGISTRY_VALUE_HANDSIZE);

        if (lResult == ERROR_SUCCESS) {
            m_lHandSize = (long)dwHandSize;
        }

        DWORD dwPlayAfterDraw;
        lResult = reg.QueryValue(dwPlayAfterDraw, Q_REGISTRY_VALUE_PLAYAFTERDRAW);

        if (lResult == ERROR_SUCCESS) {
            (dwPlayAfterDraw) ? m_bPlayAfterDraw = true : m_bPlayAfterDraw = false;
        }
    }

    return;
}

void CGameManager::SaveGameSettings() {
    TCHAR szGamesKey[MAX_PATH] = Q_REGISTRY_KEY_ROOT;
    lstrcat(szGamesKey, Q_REGISTRY_KEY_GAMES);

    CRegKey reg;
    LONG lResult = reg.Create(HKEY_CURRENT_USER, szGamesKey);

    if (lResult == ERROR_SUCCESS) {
        lResult = reg.SetValue(m_lHandSize, Q_REGISTRY_VALUE_HANDSIZE);

        DWORD dwPlayAfterDraw;
        (m_bPlayAfterDraw) ? dwPlayAfterDraw = 1 : dwPlayAfterDraw = 0;

        lResult = reg.SetValue(dwPlayAfterDraw, Q_REGISTRY_VALUE_PLAYAFTERDRAW);
    }

    return;
}

void CGameManager::LoadPlayers() {
    TCHAR szPlayersKey[MAX_PATH] = Q_REGISTRY_KEY_ROOT;
    lstrcat(szPlayersKey, Q_REGISTRY_KEY_PLAYERS);

    CRegKey reg;
    LONG lResult = reg.Create(HKEY_CURRENT_USER, szPlayersKey);

    if (lResult == ERROR_SUCCESS) {
        DWORD dwPlayersCount = 0;
        lResult = RegQueryInfoKey(reg.m_hKey, NULL, NULL, NULL, &dwPlayersCount, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

        if ((lResult == ERROR_SUCCESS) && (dwPlayersCount > 0)) {
            DWORD dwPlayerIndex = 0;
            TCHAR szPlayer[MAX_PATH];
            DWORD dwPlayer = MAX_PATH;
            FILETIME ftLastWriteTime;

            lResult = RegEnumKeyEx(reg.m_hKey, dwPlayerIndex, szPlayer, &dwPlayer, NULL, NULL, NULL, &ftLastWriteTime);

            while (lResult == ERROR_SUCCESS) {
                CRegKey regPlayer;
                LONG lPlayerResult = regPlayer.Open(reg.m_hKey, szPlayer);

                if (lPlayerResult == ERROR_SUCCESS) {
                    CComBSTR bstrPlayerName;
                    TCHAR szPlayerName[MAX_PATH];
                    DWORD dwPlayerNameLen = MAX_PATH;
                    lPlayerResult = regPlayer.QueryValue(szPlayerName, Q_REGISTRY_VALUE_PLAYER_NAME, &dwPlayerNameLen);

                    if (lPlayerResult == ERROR_SUCCESS) {
                        bstrPlayerName = szPlayerName;
                    }

                    UnoPlayerType ePlayerType;
                    DWORD dwPlayerType;
                    lPlayerResult = regPlayer.QueryValue(dwPlayerType, Q_REGISTRY_VALUE_PLAYER_TYPE);

                    if (lPlayerResult == ERROR_SUCCESS) {
                        ePlayerType = (UnoPlayerType)dwPlayerType;
                    }

                    m_Players.Add(bstrPlayerName, ePlayerType);
                }

                dwPlayerIndex++;

                lResult = RegEnumKeyEx(reg.m_hKey, dwPlayerIndex, szPlayer, &dwPlayer, NULL, NULL, NULL, &ftLastWriteTime);
            }

        } else {
            CComBSTR bstrComputer;
            bstrComputer.LoadString(IDS_DEFAULTCOMPUTER);

            CComBSTR bstrPlayer;
            bstrPlayer.LoadString(IDS_DEFAULTPLAYER);

            m_Players.Add(bstrComputer, UnoComputer);
            m_Players.Add(bstrPlayer, UnoHuman);
        }
    }

    return;
}

void CGameManager::SavePlayers() {
    USES_CONVERSION;

    CRegKey reg;
    LONG lResult = reg.Create(HKEY_CURRENT_USER, Q_REGISTRY_KEY_ROOT);

    if (lResult == ERROR_SUCCESS) {
        lResult = reg.RecurseDeleteKey(Q_REGISTRY_KEYLITE_PLAYERS);
        lResult = reg.Create(reg.m_hKey, Q_REGISTRY_KEYLITE_PLAYERS);

        if (lResult == ERROR_SUCCESS) {
            for (long lIndex = 0; lIndex < m_Players.GetSize(); lIndex++) {
                LPCTSTR lpPlayer = OLE2CT(m_Players.GetKeyAt(lIndex));

                CRegKey regPlayer;
                LONG lPlayerResult = regPlayer.Create(reg.m_hKey, lpPlayer);

                if (lPlayerResult == ERROR_SUCCESS) {
                    lPlayerResult = regPlayer.SetValue(lpPlayer, Q_REGISTRY_VALUE_PLAYER_NAME);
                    lPlayerResult = regPlayer.SetValue((DWORD)m_Players.GetValueAt(lIndex), Q_REGISTRY_VALUE_PLAYER_TYPE);
                }
            }
        }
    }

    m_Players.RemoveAll();

    return;
}
