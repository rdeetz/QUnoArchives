/////////////////////////////////////////////////////////////////////
//
// QGlobal.h - definition of the global constants for the 
//             RogCorp QUno 3.0 user interface
//
// Copyright © 2000-2001 Roger Deetz
//

#ifndef __QGLOBAL_H_
#define __QGLOBAL_H_

#define Q_MODULE_QUNO       _T("QUNO.EXE")
#define Q_MODULE_QENGINE    _T("QENGINE.DLL")
#define Q_MODULE_QCONTROL   _T("QCONTROL.DLL")

#define Q_VERSION_FILEDESCRIPTION   _T("FileDescription")
#define Q_VERSION_FILEVERSION       _T("FileVersion")

#define Q_BUFFER_LARGETEXT      1024

#define Q_GAME_EXTENSION    _T("uno")
#define Q_GAME_FILTER       _T("*.uno")
#define Q_GAME_SEPARATOR    _T(" - ")

// TODO: this should be a string resource!
#define Q_FILTER_GAME        _T("RogCorp QUno Games (*.uno)\0*.uno\0\0")

#define Q_HANDSIZE_MIN          1
#define Q_HANDSIZE_DEFAULT      5
#define Q_HANDSIZE_MAX          20

#define Q_TARGET_HORIZRES       800

#define Q_WINDOW_HIDEFAULT_LEFT    100
#define Q_WINDOW_HIDEFAULT_TOP     100
#define Q_WINDOW_HIDEFAULT_RIGHT   800
#define Q_WINDOW_HIDEFAULT_BOTTOM  600

#define Q_WINDOW_LODEFAULT_LEFT    10
#define Q_WINDOW_LODEFAULT_TOP     10
#define Q_WINDOW_LODEFAULT_RIGHT   620
#define Q_WINDOW_LODEFAULT_BOTTOM  450

#define Q_REGISTRY_KEY_ROOT         _T("Software\\RogCorp\\QUno\\3.0")
#define Q_REGISTRY_KEY_WINDOW       _T("\\Window")
#define Q_REGISTRY_KEY_HELP         _T("\\Help")
#define Q_REGISTRY_KEY_GAMES        _T("\\Games")
#define Q_REGISTRY_KEY_PLAYERS      _T("\\Players")
#define Q_REGISTRY_KEYLITE_PLAYERS  _T("Players") // this is used when the leading slash is not needed

#define Q_REGISTRY_VALUE_WINDOWLEFT      _T("WindowLeft")
#define Q_REGISTRY_VALUE_WINDOWTOP       _T("WindowTop")
#define Q_REGISTRY_VALUE_WINDOWRIGHT     _T("WindowRight")
#define Q_REGISTRY_VALUE_WINDOWBOTTOM    _T("WindowBottom")
#define Q_REGISTRY_VALUE_WINDOWSTATE     _T("WindowState")
#define Q_REGISTRY_VALUE_LOCALHELPFILE   _T("LocalHelpFile")
#define Q_REGISTRY_VALUE_ROGCORPURL      _T("RogCorpURL")
#define Q_REGISTRY_VALUE_SHOWQUICKHINTS  _T("ShowQuickHints")
#define Q_REGISTRY_VALUE_ALLOWSAVEDGAMES _T("AllowSavedGames")
#define Q_REGISTRY_VALUE_HANDSIZE        _T("HandSize")
#define Q_REGISTRY_VALUE_PLAYAFTERDRAW   _T("PlayAfterDraw")
#define Q_REGISTRY_VALUE_PLAYER_NAME     _T("Name")
#define Q_REGISTRY_VALUE_PLAYER_TYPE     _T("Type")

#endif //__QGLOBAL_H_
