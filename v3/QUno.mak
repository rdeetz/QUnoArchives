# Microsoft Developer Studio Generated NMAKE File, Based on QUno.dsp
!IF "$(CFG)" == ""
CFG=QUno - Win32 Debug
!MESSAGE No configuration specified. Defaulting to QUno - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "QUno - Win32 Debug" && "$(CFG)" != "QUno - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "QUno.mak" CFG="QUno - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "QUno - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "QUno - Win32 Release" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "QUno - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\QUno.exe" "$(OUTDIR)\QUno.bsc" ".\Debug\regsvr32.trg"

!ELSE 

ALL : "QControl - Win32 Debug" "QEngine - Win32 Debug" "$(OUTDIR)\QUno.exe" "$(OUTDIR)\QUno.bsc" ".\Debug\regsvr32.trg"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"QEngine - Win32 DebugCLEAN" "QControl - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\App.obj"
	-@erase "$(INTDIR)\App.sbr"
	-@erase "$(INTDIR)\GameManager.obj"
	-@erase "$(INTDIR)\GameManager.sbr"
	-@erase "$(INTDIR)\MainFrame.obj"
	-@erase "$(INTDIR)\MainFrame.sbr"
	-@erase "$(INTDIR)\QDialogs.obj"
	-@erase "$(INTDIR)\QDialogs.sbr"
	-@erase "$(INTDIR)\QUno.obj"
	-@erase "$(INTDIR)\QUno.pch"
	-@erase "$(INTDIR)\QUno.res"
	-@erase "$(INTDIR)\QUno.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\QUno.bsc"
	-@erase "$(OUTDIR)\QUno.exe"
	-@erase "$(OUTDIR)\QUno.ilk"
	-@erase "$(OUTDIR)\QUno.pdb"
	-@erase ".\QUno.h"
	-@erase ".\QUno.tlb"
	-@erase ".\QUno_i.c"
	-@erase ".\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\QUno.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\QUno.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\QUno.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\App.sbr" \
	"$(INTDIR)\MainFrame.sbr" \
	"$(INTDIR)\QDialogs.sbr" \
	"$(INTDIR)\QUno.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\GameManager.sbr"

"$(OUTDIR)\QUno.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib comctl32.lib shlwapi.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\QUno.pdb" /debug /machine:I386 /out:"$(OUTDIR)\QUno.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\App.obj" \
	"$(INTDIR)\MainFrame.obj" \
	"$(INTDIR)\QDialogs.obj" \
	"$(INTDIR)\QUno.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\QUno.res" \
	"$(INTDIR)\GameManager.obj" \
	".\QEngine\Debug\QEngine.lib" \
	".\QControl\Debug\QControl.lib"

"$(OUTDIR)\QUno.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\QUno.exe
InputPath=.\Debug\QUno.exe
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	"$(TargetPath)" /RegServer 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	echo Server registration done! 
<< 
	

!ELSEIF  "$(CFG)" == "QUno - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\QUno.exe" ".\QUno.tlb" ".\QUno.h" ".\QUno_i.c" ".\Release\regsvr32.trg"

!ELSE 

ALL : "QControl - Win32 Release" "QEngine - Win32 Release" "$(OUTDIR)\QUno.exe" ".\QUno.tlb" ".\QUno.h" ".\QUno_i.c" ".\Release\regsvr32.trg"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"QEngine - Win32 ReleaseCLEAN" "QControl - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\App.obj"
	-@erase "$(INTDIR)\GameManager.obj"
	-@erase "$(INTDIR)\MainFrame.obj"
	-@erase "$(INTDIR)\QDialogs.obj"
	-@erase "$(INTDIR)\QUno.obj"
	-@erase "$(INTDIR)\QUno.pch"
	-@erase "$(INTDIR)\QUno.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\QUno.exe"
	-@erase ".\QUno.h"
	-@erase ".\QUno.tlb"
	-@erase ".\QUno_i.c"
	-@erase ".\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\QUno.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\QUno.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\QUno.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib version.lib comctl32.lib shlwapi.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\QUno.pdb" /machine:I386 /out:"$(OUTDIR)\QUno.exe" 
LINK32_OBJS= \
	"$(INTDIR)\App.obj" \
	"$(INTDIR)\MainFrame.obj" \
	"$(INTDIR)\QDialogs.obj" \
	"$(INTDIR)\QUno.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\QUno.res" \
	"$(INTDIR)\GameManager.obj" \
	".\QEngine\Release\QEngine.lib" \
	".\QControl\Release\QControl.lib"

"$(OUTDIR)\QUno.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Release
TargetPath=.\Release\QUno.exe
InputPath=.\Release\QUno.exe
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	"$(TargetPath)" /RegServer 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	echo Server registration done! 
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
!IF EXISTS("QUno.dep")
!INCLUDE "QUno.dep"
!ELSE 
!MESSAGE Warning: cannot find "QUno.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "QUno - Win32 Debug" || "$(CFG)" == "QUno - Win32 Release"
SOURCE=.\App.cpp

!IF  "$(CFG)" == "QUno - Win32 Debug"


"$(INTDIR)\App.obj"	"$(INTDIR)\App.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QUno.pch"


!ELSEIF  "$(CFG)" == "QUno - Win32 Release"


"$(INTDIR)\App.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QUno.pch"


!ENDIF 

SOURCE=.\GameManager.cpp

!IF  "$(CFG)" == "QUno - Win32 Debug"


"$(INTDIR)\GameManager.obj"	"$(INTDIR)\GameManager.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QUno.pch"


!ELSEIF  "$(CFG)" == "QUno - Win32 Release"


"$(INTDIR)\GameManager.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QUno.pch"


!ENDIF 

SOURCE=.\MainFrame.cpp

!IF  "$(CFG)" == "QUno - Win32 Debug"


"$(INTDIR)\MainFrame.obj"	"$(INTDIR)\MainFrame.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QUno.pch"


!ELSEIF  "$(CFG)" == "QUno - Win32 Release"


"$(INTDIR)\MainFrame.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QUno.pch"


!ENDIF 

SOURCE=.\QDialogs.cpp

!IF  "$(CFG)" == "QUno - Win32 Debug"


"$(INTDIR)\QDialogs.obj"	"$(INTDIR)\QDialogs.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QUno.pch"


!ELSEIF  "$(CFG)" == "QUno - Win32 Release"


"$(INTDIR)\QDialogs.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QUno.pch"


!ENDIF 

SOURCE=.\QUno.cpp

!IF  "$(CFG)" == "QUno - Win32 Debug"


"$(INTDIR)\QUno.obj"	"$(INTDIR)\QUno.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QUno.pch" ".\QUno.h" ".\QUno_i.c"


!ELSEIF  "$(CFG)" == "QUno - Win32 Release"


"$(INTDIR)\QUno.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\QUno.pch"


!ENDIF 

SOURCE=.\QUno.idl
MTL_SWITCHES=/nologo /tlb ".\QUno.tlb" /h "QUno.h" /iid "QUno_i.c" /Oicf 

".\QUno.tlb"	".\QUno.h"	".\QUno_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


SOURCE=.\QUno.rc

"$(INTDIR)\QUno.res" : $(SOURCE) "$(INTDIR)" ".\QUno.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "QUno - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\QUno.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\QUno.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "QUno - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\QUno.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\QUno.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

!IF  "$(CFG)" == "QUno - Win32 Debug"

"QEngine - Win32 Debug" : 
   cd ".\QEngine"
   $(MAKE) /$(MAKEFLAGS) /F .\QEngine.mak CFG="QEngine - Win32 Debug" 
   cd ".."

"QEngine - Win32 DebugCLEAN" : 
   cd ".\QEngine"
   $(MAKE) /$(MAKEFLAGS) /F .\QEngine.mak CFG="QEngine - Win32 Debug" RECURSE=1 CLEAN 
   cd ".."

!ELSEIF  "$(CFG)" == "QUno - Win32 Release"

"QEngine - Win32 Release" : 
   cd ".\QEngine"
   $(MAKE) /$(MAKEFLAGS) /F .\QEngine.mak CFG="QEngine - Win32 Release" 
   cd ".."

"QEngine - Win32 ReleaseCLEAN" : 
   cd ".\QEngine"
   $(MAKE) /$(MAKEFLAGS) /F .\QEngine.mak CFG="QEngine - Win32 Release" RECURSE=1 CLEAN 
   cd ".."

!ENDIF 

!IF  "$(CFG)" == "QUno - Win32 Debug"

"QControl - Win32 Debug" : 
   cd ".\QControl"
   $(MAKE) /$(MAKEFLAGS) /F .\QControl.mak CFG="QControl - Win32 Debug" 
   cd ".."

"QControl - Win32 DebugCLEAN" : 
   cd ".\QControl"
   $(MAKE) /$(MAKEFLAGS) /F .\QControl.mak CFG="QControl - Win32 Debug" RECURSE=1 CLEAN 
   cd ".."

!ELSEIF  "$(CFG)" == "QUno - Win32 Release"

"QControl - Win32 Release" : 
   cd ".\QControl"
   $(MAKE) /$(MAKEFLAGS) /F .\QControl.mak CFG="QControl - Win32 Release" 
   cd ".."

"QControl - Win32 ReleaseCLEAN" : 
   cd ".\QControl"
   $(MAKE) /$(MAKEFLAGS) /F .\QControl.mak CFG="QControl - Win32 Release" RECURSE=1 CLEAN 
   cd ".."

!ENDIF 


!ENDIF 

