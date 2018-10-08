# Microsoft Developer Studio Project File - Name="Quno" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Quno - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Quno.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Quno.mak" CFG="Quno - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Quno - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Quno - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Quno - Win32 Release"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /Yu"STDAFX.H" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR /Yu"STDAFX.H" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 oldnames.lib /nologo /stack:0x2800 /subsystem:windows /machine:IX86
# ADD LINK32 oldnames.lib /nologo /stack:0x2800 /subsystem:windows /machine:IX86

!ELSEIF  "$(CFG)" == "Quno - Win32 Debug"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /Yu"STDAFX.H" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR /Yu"STDAFX.H" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 oldnames.lib /nologo /stack:0x2800 /subsystem:windows /debug /machine:IX86 /pdbtype:sept
# ADD LINK32 oldnames.lib /nologo /stack:0x2800 /subsystem:windows /debug /machine:IX86 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Quno - Win32 Release"
# Name "Quno - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat"
# Begin Source File

SOURCE=.\mainfrm.cpp
# End Source File
# Begin Source File

SOURCE=.\qdialogs.cpp
# End Source File
# Begin Source File

SOURCE=.\quno.cpp
# End Source File
# Begin Source File

SOURCE=.\Quno.def
# End Source File
# Begin Source File

SOURCE=.\Quno.rc
# End Source File
# Begin Source File

SOURCE=.\qunocard.cpp
# End Source File
# Begin Source File

SOURCE=.\stdafx.cpp
# ADD BASE CPP /Yc"STDAFX.H"
# ADD CPP /Yc"STDAFX.H"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\mainfrm.h
# End Source File
# Begin Source File

SOURCE=.\qdialogs.h
# End Source File
# Begin Source File

SOURCE=.\quno.h
# End Source File
# Begin Source File

SOURCE=.\qunocard.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\stdafx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\RES\BLU_DRAW.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\BLU_EIGH.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\BLU_FIVE.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\BLU_FOUR.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\BLU_NINE.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\BLU_ONE.BMP
# End Source File
# Begin Source File

SOURCE=.\res\blu_reve.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\BLU_SEVE.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\BLU_SIX.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\BLU_SKIP.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\BLU_THRE.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\BLU_TWO.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\BLU_ZERO.BMP
# End Source File
# Begin Source File

SOURCE=.\res\blue.bmp
# End Source File
# Begin Source File

SOURCE=.\res\compute.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cowboy.bmp
# End Source File
# Begin Source File

SOURCE=.\res\deckhi.bmp
# End Source File
# Begin Source File

SOURCE=.\res\deckhim.bmp
# End Source File
# Begin Source File

SOURCE=.\res\decklo.bmp
# End Source File
# Begin Source File

SOURCE=.\res\deckmid.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\GRE_DRAW.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\GRE_EIGH.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\GRE_FIVE.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\GRE_FOUR.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\GRE_NINE.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\GRE_ONE.BMP
# End Source File
# Begin Source File

SOURCE=.\res\gre_reve.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\GRE_SEVE.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\GRE_SIX.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\GRE_SKIP.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\GRE_THRE.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\GRE_TWO.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\GRE_ZERO.BMP
# End Source File
# Begin Source File

SOURCE=.\res\green.bmp
# End Source File
# Begin Source File

SOURCE=.\res\hint.ico
# End Source File
# Begin Source File

SOURCE=.\res\nerd.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\QUNO.ICO
# End Source File
# Begin Source File

SOURCE=.\res\quno.rc2
# End Source File
# Begin Source File

SOURCE=.\res\red.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\RED_DRAW.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\RED_EIGH.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\RED_FIVE.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\RED_FOUR.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\RED_NINE.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\RED_ONE.BMP
# End Source File
# Begin Source File

SOURCE=.\res\red_reve.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\RED_SEVE.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\RED_SIX.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\RED_SKIP.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\RED_THRE.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\RED_TWO.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\RED_ZERO.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\WILD.BMP
# End Source File
# Begin Source File

SOURCE=.\res\wild_draw.bmp
# End Source File
# Begin Source File

SOURCE=.\res\wizard.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\YEL_DRAW.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\YEL_EIGH.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\YEL_FIVE.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\YEL_FOUR.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\YEL_NINE.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\YEL_ONE.BMP
# End Source File
# Begin Source File

SOURCE=.\res\yel_reve.bmp
# End Source File
# Begin Source File

SOURCE=.\RES\YEL_SEVE.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\YEL_SIX.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\YEL_SKIP.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\YEL_THRE.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\YEL_TWO.BMP
# End Source File
# Begin Source File

SOURCE=.\RES\YEL_ZERO.BMP
# End Source File
# Begin Source File

SOURCE=.\res\yellow.bmp
# End Source File
# End Group
# Begin Group "Help Files"

# PROP Default_Filter "*.htm; *.gif"
# Begin Source File

SOURCE=.\hlp\qunoabout.gif
# End Source File
# Begin Source File

SOURCE=.\hlp\qunohelp.htm
# End Source File
# Begin Source File

SOURCE=.\hlp\qunohint.gif
# End Source File
# Begin Source File

SOURCE=.\hlp\qunoicon.gif
# End Source File
# Begin Source File

SOURCE=.\hlp\qunomain.gif
# End Source File
# Begin Source File

SOURCE=.\hlp\qunooptions.gif
# End Source File
# Begin Source File

SOURCE=.\hlp\qunowild.gif
# End Source File
# End Group
# Begin Source File

SOURCE=.\QUno.doc
# End Source File
# End Target
# End Project
