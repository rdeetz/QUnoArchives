# Microsoft Developer Studio Generated NMAKE File, Based on QControl.dsp
!IF "$(CFG)" == ""
CFG=QControl - Win32 Debug
!MESSAGE No configuration specified. Defaulting to QControl - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "QControl - Win32 Debug" && "$(CFG)" != "QControl - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "QControl.mak" CFG="QControl - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "QControl - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "QControl - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "QControl - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "..\Debug\QControl.dll" "$(OUTDIR)\QControl.bsc" ".\Debug\regsvr32.trg"

!ELSE 

ALL : "QEngine - Win32 Debug" "..\Debug\QControl.dll" "$(OUTDIR)\QControl.bsc" ".\Debug\regsvr32.trg"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"QEngine - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\QControl.obj"
	-@erase "$(INTDIR)\QControl.pch"
	-@erase "$(INTDIR)\QControl.res"
	-@erase "$(INTDIR)\QControl.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\UnoCardView.obj"
	-@erase "$(INTDIR)\UnoCardView.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\QControl.bsc"
	-@erase "$(OUTDIR)\QControl.exp"
	-@erase "$(OUTDIR)\QControl.lib"
	-@erase "$(OUTDIR)\QControl.pdb"
	-@erase "..\Debug\QControl.dll"
	-@erase "..\Debug\QControl.ilk"
	-@erase ".\QControl.h"
	-@erase ".\QControl.tlb"
	-@erase ".\QControl_i.c"
	-@erase ".\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\QControl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\QControl.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\QControl.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\QControl.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\UnoCardView.sbr"

"$(OUTDIR)\QControl.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\QControl.pdb" /debug /machine:I386 /def:".\QControl.def" /out:"../Debug/QControl.dll" /implib:"$(OUTDIR)\QControl.lib" /pdbtype:sept 
DEF_FILE= \
	".\QControl.def"
LINK32_OBJS= \
	"$(INTDIR)\QControl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\UnoCardView.obj" \
	"$(INTDIR)\QControl.res" \
	"..\QEngine\Debug\QEngine.lib"

"..\Debug\QControl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=\Dev\QUno\Debug\QControl.dll
InputPath=\Dev\QUno\Debug\QControl.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "QControl - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

!IF "$(RECURSE)" == "0" 

ALL : "..\Release\QControl.dll" ".\QControl.tlb" ".\QControl.h" ".\QControl_i.c" ".\Release\regsvr32.trg"

!ELSE 

ALL : "QEngine - Win32 Release" "..\Release\QControl.dll" ".\QControl.tlb" ".\QControl.h" ".\QControl_i.c" ".\Release\regsvr32.trg"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"QEngine - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\QControl.obj"
	-@erase "$(INTDIR)\QControl.pch"
	-@erase "$(INTDIR)\QControl.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\UnoCardView.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\QControl.exp"
	-@erase "$(OUTDIR)\QControl.lib"
	-@erase "..\Release\QControl.dll"
	-@erase ".\QControl.h"
	-@erase ".\QControl.tlb"
	-@erase ".\QControl_i.c"
	-@erase ".\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Fp"$(INTDIR)\QControl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\QControl.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\QControl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\QControl.pdb" /machine:I386 /def:".\QControl.def" /out:"../Release/QControl.dll" /implib:"$(OUTDIR)\QControl.lib" 
DEF_FILE= \
	".\QControl.def"
LINK32_OBJS= \
	"$(INTDIR)\QControl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\UnoCardView.obj" \
	"$(INTDIR)\QControl.res" \
	"..\QEngine\Release\QEngine.lib"

"..\Release\QControl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Release
TargetPath=\Dev\QUno\Release\QControl.dll
InputPath=\Dev\QUno\Release\QControl.dll
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
!IF EXISTS("QControl.dep")
!INCLUDE "QControl.dep"
!ELSE 
!MESSAGE Warning: cannot find "QControl.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "QControl - Win32 Debug" || "$(CFG)" == "QControl - Win32 Release"
SOURCE=.\QControl.cpp

!IF  "$(CFG)" == "QControl - Win32 Debug"


"$(INTDIR)\QControl.obj"	"$(INTDIR)\QControl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QControl.pch" ".\QControl.h" ".\QControl_i.c"


!ELSEIF  "$(CFG)" == "QControl - Win32 Release"


"$(INTDIR)\QControl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QControl.pch"


!ENDIF 

SOURCE=.\QControl.idl
MTL_SWITCHES=/nologo /tlb ".\QControl.tlb" /h "QControl.h" /iid "QControl_i.c" /Oicf 

".\QControl.tlb"	".\QControl.h"	".\QControl_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


SOURCE=.\QControl.rc

"$(INTDIR)\QControl.res" : $(SOURCE) "$(INTDIR)" ".\QControl.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "QControl - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\QControl.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\QControl.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "QControl - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Fp"$(INTDIR)\QControl.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\QControl.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\UnoCardView.cpp

!IF  "$(CFG)" == "QControl - Win32 Debug"


"$(INTDIR)\UnoCardView.obj"	"$(INTDIR)\UnoCardView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QControl.pch" ".\QControl.h"


!ELSEIF  "$(CFG)" == "QControl - Win32 Release"


"$(INTDIR)\UnoCardView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QControl.pch"


!ENDIF 

!IF  "$(CFG)" == "QControl - Win32 Debug"

"QEngine - Win32 Debug" : 
   cd "\Dev\QUno\QEngine"
   $(MAKE) /$(MAKEFLAGS) /F .\QEngine.mak CFG="QEngine - Win32 Debug" 
   cd "..\QControl"

"QEngine - Win32 DebugCLEAN" : 
   cd "\Dev\QUno\QEngine"
   $(MAKE) /$(MAKEFLAGS) /F .\QEngine.mak CFG="QEngine - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\QControl"

!ELSEIF  "$(CFG)" == "QControl - Win32 Release"

"QEngine - Win32 Release" : 
   cd "\Dev\QUno\QEngine"
   $(MAKE) /$(MAKEFLAGS) /F .\QEngine.mak CFG="QEngine - Win32 Release" 
   cd "..\QControl"

"QEngine - Win32 ReleaseCLEAN" : 
   cd "\Dev\QUno\QEngine"
   $(MAKE) /$(MAKEFLAGS) /F .\QEngine.mak CFG="QEngine - Win32 Release" RECURSE=1 CLEAN 
   cd "..\QControl"

!ENDIF 


!ENDIF 

