# Microsoft Visual C++ generated build script - Do not modify

PROJ = QUNO
DEBUG = 0
PROGTYPE = 0
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = -d_DEBUG
R_RCDEFINES = -dNDEBUG
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = C:\MSDEV\PROJECTS\QUNO16\
USEMFC = 1
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC =             
FIRSTCPP = MAINFRM.CPP 
RC = rc
CFLAGS_D_WEXE = /nologo /W3 /FR /G2 /Zi /D_DEBUG /Od /AM /GA /Fd"QUNO.PDB"
CFLAGS_R_WEXE = /nologo /W3 /FR /O1 /DNDEBUG /AM /GA
LFLAGS_D_WEXE = /NOLOGO /ONERROR:NOEXE /NOD /PACKC:61440 /CO /ALIGN:16 /STACK:10240
LFLAGS_R_WEXE = /NOLOGO /ONERROR:NOEXE /NOD /PACKC:61440 /ALIGN:16 /STACK:10240
LIBS_D_WEXE = mafxcwd oldnames libw commdlg shell olecli olesvr mlibcew
LIBS_R_WEXE = mafxcw oldnames libw commdlg shell olecli olesvr mlibcew
RCFLAGS = /nologo
RESFLAGS = /nologo
RUNFLAGS = 
DEFFILE = QUNO.DEF
OBJS_EXT = 
LIBS_EXT = 
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS_D_WEXE)
LFLAGS = $(LFLAGS_D_WEXE)
LIBS = $(LIBS_D_WEXE)
MAPFILE = nul
RCDEFINES = $(D_RCDEFINES)
!else
CFLAGS = $(CFLAGS_R_WEXE)
LFLAGS = $(LFLAGS_R_WEXE)
LIBS = $(LIBS_R_WEXE)
MAPFILE = nul
RCDEFINES = $(R_RCDEFINES)
!endif
!if [if exist MSVC.BND del MSVC.BND]
!endif
SBRS = MAINFRM.SBR \
		QUNO.SBR \
		QUNOCARD.SBR \
		STDAFX.SBR


MAINFRM_DEP = c:\msdev\projects\quno16\stdafx.h \
	c:\msdev\projects\quno16\quno.h \
	c:\msdev\projects\quno16\mainfrm.h \
	c:\msdev\projects\quno16\qunocard.h


QUNO_DEP = c:\msdev\projects\quno16\stdafx.h \
	c:\msdev\projects\quno16\quno.h \
	c:\msdev\projects\quno16\mainfrm.h \
	c:\msdev\projects\quno16\qunocard.h


QUNOCARD_DEP = c:\msdev\projects\quno16\stdafx.h \
	c:\msdev\projects\quno16\qunocard.h


STDAFX_DEP = c:\msdev\projects\quno16\stdafx.h


QUNO_RCDEP = c:\msdev\projects\quno16\res\quno.ico \
	c:\msdev\projects\quno16\res\deck.bmp \
	c:\msdev\projects\quno16\res\red_one.bmp \
	c:\msdev\projects\quno16\res\red_two.bmp \
	c:\msdev\projects\quno16\res\red_thre.bmp \
	c:\msdev\projects\quno16\res\red_four.bmp \
	c:\msdev\projects\quno16\res\red_five.bmp \
	c:\msdev\projects\quno16\res\red_six.bmp \
	c:\msdev\projects\quno16\res\red_seve.bmp \
	c:\msdev\projects\quno16\res\red_eigh.bmp \
	c:\msdev\projects\quno16\res\red_nine.bmp \
	c:\msdev\projects\quno16\res\red_zero.bmp \
	c:\msdev\projects\quno16\res\red_draw.bmp \
	c:\msdev\projects\quno16\res\red_skip.bmp \
	c:\msdev\projects\quno16\res\wild.bmp \
	c:\msdev\projects\quno16\res\blu_zero.bmp \
	c:\msdev\projects\quno16\res\blu_one.bmp \
	c:\msdev\projects\quno16\res\blu_two.bmp \
	c:\msdev\projects\quno16\res\blu_thre.bmp \
	c:\msdev\projects\quno16\res\blu_four.bmp \
	c:\msdev\projects\quno16\res\blu_draw.bmp \
	c:\msdev\projects\quno16\res\blu_eigh.bmp \
	c:\msdev\projects\quno16\res\blu_five.bmp \
	c:\msdev\projects\quno16\res\blu_nine.bmp \
	c:\msdev\projects\quno16\res\blu_seve.bmp \
	c:\msdev\projects\quno16\res\blu_six.bmp \
	c:\msdev\projects\quno16\res\blu_skip.bmp \
	c:\msdev\projects\quno16\res\gre_draw.bmp \
	c:\msdev\projects\quno16\res\gre_eigh.bmp \
	c:\msdev\projects\quno16\res\gre_five.bmp \
	c:\msdev\projects\quno16\res\gre_four.bmp \
	c:\msdev\projects\quno16\res\gre_nine.bmp \
	c:\msdev\projects\quno16\res\gre_one.bmp \
	c:\msdev\projects\quno16\res\gre_seve.bmp \
	c:\msdev\projects\quno16\res\gre_six.bmp \
	c:\msdev\projects\quno16\res\gre_skip.bmp \
	c:\msdev\projects\quno16\res\gre_thre.bmp \
	c:\msdev\projects\quno16\res\gre_two.bmp \
	c:\msdev\projects\quno16\res\gre_zero.bmp \
	c:\msdev\projects\quno16\res\yel_draw.bmp \
	c:\msdev\projects\quno16\res\yel_eigh.bmp \
	c:\msdev\projects\quno16\res\yel_five.bmp \
	c:\msdev\projects\quno16\res\yel_four.bmp \
	c:\msdev\projects\quno16\res\yel_nine.bmp \
	c:\msdev\projects\quno16\res\yel_one.bmp \
	c:\msdev\projects\quno16\res\yel_seve.bmp \
	c:\msdev\projects\quno16\res\yel_six.bmp \
	c:\msdev\projects\quno16\res\yel_skip.bmp \
	c:\msdev\projects\quno16\res\yel_thre.bmp \
	c:\msdev\projects\quno16\res\yel_two.bmp \
	c:\msdev\projects\quno16\res\yel_zero.bmp \
	c:\msdev\projects\quno16\res\quno.rc2


all:	$(PROJ).EXE $(PROJ).BSC

MAINFRM.OBJ:	MAINFRM.CPP $(MAINFRM_DEP)
	$(CPP) $(CFLAGS) $(CPPCREATEPCHFLAG) /c MAINFRM.CPP

QUNO.OBJ:	QUNO.CPP $(QUNO_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c QUNO.CPP

QUNOCARD.OBJ:	QUNOCARD.CPP $(QUNOCARD_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c QUNOCARD.CPP

STDAFX.OBJ:	STDAFX.CPP $(STDAFX_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c STDAFX.CPP

QUNO.RES:	QUNO.RC $(QUNO_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r QUNO.RC


$(PROJ).EXE::	QUNO.RES

$(PROJ).EXE::	MAINFRM.OBJ QUNO.OBJ QUNOCARD.OBJ STDAFX.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
MAINFRM.OBJ +
QUNO.OBJ +
QUNOCARD.OBJ +
STDAFX.OBJ +
$(OBJS_EXT)
$(PROJ).EXE
$(MAPFILE)
d:\msvc15\lib\+
d:\msvc15\mfc\lib\+
$(LIBS)
$(DEFFILE);
<<
	link $(LFLAGS) @$(PROJ).CRF
	$(RC) $(RESFLAGS) QUNO.RES $@
	@copy $(PROJ).CRF MSVC.BND

$(PROJ).EXE::	QUNO.RES
	if not exist MSVC.BND 	$(RC) $(RESFLAGS) QUNO.RES $@

run: $(PROJ).EXE
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
