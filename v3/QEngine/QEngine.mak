# Microsoft Developer Studio Generated NMAKE File, Based on QEngine.dsp
!IF "$(CFG)" == ""
CFG=QEngine - Win32 Debug
!MESSAGE No configuration specified. Defaulting to QEngine - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "QEngine - Win32 Debug" && "$(CFG)" != "QEngine - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "QEngine.mak" CFG="QEngine - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "QEngine - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "QEngine - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "QEngine - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "..\Debug\QEngine.dll" "$(OUTDIR)\QEngine.bsc" ".\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\QEngine.obj"
	-@erase "$(INTDIR)\QEngine.pch"
	-@erase "$(INTDIR)\QEngine.res"
	-@erase "$(INTDIR)\QEngine.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\UnoCard.obj"
	-@erase "$(INTDIR)\UnoCard.sbr"
	-@erase "$(INTDIR)\UnoDeck.obj"
	-@erase "$(INTDIR)\UnoDeck.sbr"
	-@erase "$(INTDIR)\UnoEngine.obj"
	-@erase "$(INTDIR)\UnoEngine.sbr"
	-@erase "$(INTDIR)\UnoGame.obj"
	-@erase "$(INTDIR)\UnoGame.sbr"
	-@erase "$(INTDIR)\UnoHand.obj"
	-@erase "$(INTDIR)\UnoHand.sbr"
	-@erase "$(INTDIR)\UnoPlayer.obj"
	-@erase "$(INTDIR)\UnoPlayer.sbr"
	-@erase "$(INTDIR)\UnoPlayers.obj"
	-@erase "$(INTDIR)\UnoPlayers.sbr"
	-@erase "$(INTDIR)\UnoPlayersIter.obj"
	-@erase "$(INTDIR)\UnoPlayersIter.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\QEngine.bsc"
	-@erase "$(OUTDIR)\QEngine.exp"
	-@erase "$(OUTDIR)\QEngine.lib"
	-@erase "$(OUTDIR)\QEngine.pdb"
	-@erase "..\Debug\QEngine.dll"
	-@erase "..\Debug\QEngine.ilk"
	-@erase ".\QEngine.h"
	-@erase ".\QEngine.tlb"
	-@erase ".\QEngine_i.c"
	-@erase ".\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\QEngine.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\QEngine.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\QEngine.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\QEngine.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\UnoCard.sbr" \
	"$(INTDIR)\UnoDeck.sbr" \
	"$(INTDIR)\UnoEngine.sbr" \
	"$(INTDIR)\UnoGame.sbr" \
	"$(INTDIR)\UnoHand.sbr" \
	"$(INTDIR)\UnoPlayer.sbr" \
	"$(INTDIR)\UnoPlayers.sbr" \
	"$(INTDIR)\UnoPlayersIter.sbr"

"$(OUTDIR)\QEngine.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\QEngine.pdb" /debug /machine:I386 /def:".\QEngine.def" /out:"../Debug/QEngine.dll" /implib:"$(OUTDIR)\QEngine.lib" /pdbtype:sept 
DEF_FILE= \
	".\QEngine.def"
LINK32_OBJS= \
	"$(INTDIR)\QEngine.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\UnoCard.obj" \
	"$(INTDIR)\UnoDeck.obj" \
	"$(INTDIR)\UnoEngine.obj" \
	"$(INTDIR)\UnoGame.obj" \
	"$(INTDIR)\UnoHand.obj" \
	"$(INTDIR)\UnoPlayer.obj" \
	"$(INTDIR)\UnoPlayers.obj" \
	"$(INTDIR)\UnoPlayersIter.obj" \
	"$(INTDIR)\QEngine.res"

"..\Debug\QEngine.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=\Dev\QUno\Debug\QEngine.dll
InputPath=\Dev\QUno\Debug\QEngine.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "QEngine - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\Release\QEngine.dll" ".\QEngine.tlb" ".\QEngine.h" ".\QEngine_i.c" ".\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\QEngine.obj"
	-@erase "$(INTDIR)\QEngine.pch"
	-@erase "$(INTDIR)\QEngine.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\UnoCard.obj"
	-@erase "$(INTDIR)\UnoDeck.obj"
	-@erase "$(INTDIR)\UnoEngine.obj"
	-@erase "$(INTDIR)\UnoGame.obj"
	-@erase "$(INTDIR)\UnoHand.obj"
	-@erase "$(INTDIR)\UnoPlayer.obj"
	-@erase "$(INTDIR)\UnoPlayers.obj"
	-@erase "$(INTDIR)\UnoPlayersIter.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\QEngine.exp"
	-@erase "$(OUTDIR)\QEngine.lib"
	-@erase "..\Release\QEngine.dll"
	-@erase ".\QEngine.h"
	-@erase ".\QEngine.tlb"
	-@erase ".\QEngine_i.c"
	-@erase ".\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\QEngine.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\QEngine.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\QEngine.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\QEngine.pdb" /machine:I386 /def:".\QEngine.def" /out:"../Release/QEngine.dll" /implib:"$(OUTDIR)\QEngine.lib" 
DEF_FILE= \
	".\QEngine.def"
LINK32_OBJS= \
	"$(INTDIR)\QEngine.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\UnoCard.obj" \
	"$(INTDIR)\UnoDeck.obj" \
	"$(INTDIR)\UnoEngine.obj" \
	"$(INTDIR)\UnoGame.obj" \
	"$(INTDIR)\UnoHand.obj" \
	"$(INTDIR)\UnoPlayer.obj" \
	"$(INTDIR)\UnoPlayers.obj" \
	"$(INTDIR)\UnoPlayersIter.obj" \
	"$(INTDIR)\QEngine.res"

"..\Release\QEngine.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Release
TargetPath=\Dev\QUno\Release\QEngine.dll
InputPath=\Dev\QUno\Release\QEngine.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL_PROJ=/nologo 

!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("QEngine.dep")
!INCLUDE "QEngine.dep"
!ELSE 
!MESSAGE Warning: cannot find "QEngine.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "QEngine - Win32 Debug" || "$(CFG)" == "QEngine - Win32 Release"
SOURCE=.\QEngine.cpp

!IF  "$(CFG)" == "QEngine - Win32 Debug"


"$(INTDIR)\QEngine.obj"	"$(INTDIR)\QEngine.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch" ".\QEngine_i.c" ".\QEngine.h"


!ELSEIF  "$(CFG)" == "QEngine - Win32 Release"


"$(INTDIR)\QEngine.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch"


!ENDIF 

SOURCE=.\QEngine.idl
MTL_SWITCHES=/nologo /tlb ".\QEngine.tlb" /h "QEngine.h" /iid "QEngine_i.c" /Oicf 

".\QEngine.tlb"	".\QEngine.h"	".\QEngine_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


SOURCE=.\QEngine.rc

"$(INTDIR)\QEngine.res" : $(SOURCE) "$(INTDIR)" ".\QEngine.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "QEngine - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\QEngine.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\QEngine.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "QEngine - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\QEngine.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\QEngine.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\UnoCard.cpp

!IF  "$(CFG)" == "QEngine - Win32 Debug"


"$(INTDIR)\UnoCard.obj"	"$(INTDIR)\UnoCard.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch" ".\QEngine.h"


!ELSEIF  "$(CFG)" == "QEngine - Win32 Release"


"$(INTDIR)\UnoCard.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch"


!ENDIF 

SOURCE=.\UnoDeck.cpp

!IF  "$(CFG)" == "QEngine - Win32 Debug"


"$(INTDIR)\UnoDeck.obj"	"$(INTDIR)\UnoDeck.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch" ".\QEngine.h"


!ELSEIF  "$(CFG)" == "QEngine - Win32 Release"


"$(INTDIR)\UnoDeck.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch"


!ENDIF 

SOURCE=.\UnoEngine.cpp

!IF  "$(CFG)" == "QEngine - Win32 Debug"


"$(INTDIR)\UnoEngine.obj"	"$(INTDIR)\UnoEngine.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch" ".\QEngine.h"


!ELSEIF  "$(CFG)" == "QEngine - Win32 Release"


"$(INTDIR)\UnoEngine.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch"


!ENDIF 

SOURCE=.\UnoGame.cpp

!IF  "$(CFG)" == "QEngine - Win32 Debug"


"$(INTDIR)\UnoGame.obj"	"$(INTDIR)\UnoGame.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch" ".\QEngine.h"


!ELSEIF  "$(CFG)" == "QEngine - Win32 Release"


"$(INTDIR)\UnoGame.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch"


!ENDIF 

SOURCE=.\UnoHand.cpp

!IF  "$(CFG)" == "QEngine - Win32 Debug"


"$(INTDIR)\UnoHand.obj"	"$(INTDIR)\UnoHand.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch" ".\QEngine.h"


!ELSEIF  "$(CFG)" == "QEngine - Win32 Release"


"$(INTDIR)\UnoHand.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch"


!ENDIF 

SOURCE=.\UnoPlayer.cpp

!IF  "$(CFG)" == "QEngine - Win32 Debug"


"$(INTDIR)\UnoPlayer.obj"	"$(INTDIR)\UnoPlayer.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch" ".\QEngine.h"


!ELSEIF  "$(CFG)" == "QEngine - Win32 Release"


"$(INTDIR)\UnoPlayer.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch"


!ENDIF 

SOURCE=.\UnoPlayers.cpp

!IF  "$(CFG)" == "QEngine - Win32 Debug"


"$(INTDIR)\UnoPlayers.obj"	"$(INTDIR)\UnoPlayers.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch" ".\QEngine.h"


!ELSEIF  "$(CFG)" == "QEngine - Win32 Release"


"$(INTDIR)\UnoPlayers.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch"


!ENDIF 

SOURCE=.\UnoPlayersIter.cpp

!IF  "$(CFG)" == "QEngine - Win32 Debug"


"$(INTDIR)\UnoPlayersIter.obj"	"$(INTDIR)\UnoPlayersIter.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch" ".\QEngine.h"


!ELSEIF  "$(CFG)" == "QEngine - Win32 Release"


"$(INTDIR)\UnoPlayersIter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QEngine.pch"


!ENDIF 


!ENDIF 

