# Microsoft Visual C++ generated build script - Do not modify

PROJ = QUNO
DEBUG = 0
PROGTYPE = 0
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = /d_DEBUG
R_RCDEFINES = /dNDEBUG
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = C:\MS16\VC\PROJECTS\QUNO\
USEMFC = 1
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = /YcSTDAFX.H
CUSEPCHFLAG = 
CPPUSEPCHFLAG = /YuSTDAFX.H
FIRSTC =             
FIRSTCPP = STDAFX.CPP  
RC = rc
CFLAGS_D_WEXE = /nologo /G2 /W3 /Zi /AM /Od /D "_DEBUG" /FR /GA /Fd"QUNO.PDB"
CFLAGS_R_WEXE = /nologo /Gs /G2 /W3 /AM /O1 /D "NDEBUG" /FR /GA
LFLAGS_D_WEXE = /NOLOGO /NOD /PACKC:61440 /STACK:10240 /ALIGN:16 /ONERROR:NOEXE /CO
LFLAGS_R_WEXE = /NOLOGO /NOD /PACKC:61440 /STACK:10240 /ALIGN:16 /ONERROR:NOEXE
LIBS_D_WEXE = mafxcwd oldnames libw mlibcew commdlg shell 
LIBS_R_WEXE = mafxcw oldnames libw mlibcew commdlg shell 
RCFLAGS = /nologo /z
RESFLAGS = /nologo /t
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
SBRS = STDAFX.SBR \
		QUNO.SBR \
		MAINFRM.SBR \
		QUNOCARD.SBR


QUNO_RCDEP = c:\ms16\vc\projects\quno\res\quno.ico \
	c:\ms16\vc\projects\quno\res\deck.bmp \
	c:\ms16\vc\projects\quno\res\card.bmp \
	c:\ms16\vc\projects\quno\res\red_one.bmp \
	c:\ms16\vc\projects\quno\res\red_two.bmp \
	c:\ms16\vc\projects\quno\res\red_thre.bmp \
	c:\ms16\vc\projects\quno\res\red_four.bmp \
	c:\ms16\vc\projects\quno\res\red_five.bmp \
	c:\ms16\vc\projects\quno\res\red_six.bmp \
	c:\ms16\vc\projects\quno\res\red_seve.bmp \
	c:\ms16\vc\projects\quno\res\red_eigh.bmp \
	c:\ms16\vc\projects\quno\res\red_nine.bmp \
	c:\ms16\vc\projects\quno\res\red_zero.bmp \
	c:\ms16\vc\projects\quno\res\red_draw.bmp \
	c:\ms16\vc\projects\quno\res\red_skip.bmp \
	c:\ms16\vc\projects\quno\res\wild.bmp \
	c:\ms16\vc\projects\quno\res\quno.rc2


STDAFX_DEP = c:\ms16\vc\projects\quno\stdafx.h


QUNO_DEP = c:\ms16\vc\projects\quno\stdafx.h \
	c:\ms16\vc\projects\quno\quno.h \
	c:\ms16\vc\projects\quno\mainfrm.h


MAINFRM_DEP = c:\ms16\vc\projects\quno\stdafx.h \
	c:\ms16\vc\projects\quno\quno.h \
	c:\ms16\vc\projects\quno\mainfrm.h


QUNOCARD_DEP = c:\ms16\vc\projects\quno\qunocard.h


all:	$(PROJ).EXE $(PROJ).BSC

QUNO.RES:	QUNO.RC $(QUNO_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r QUNO.RC

STDAFX.OBJ:	STDAFX.CPP $(STDAFX_DEP)
	$(CPP) $(CFLAGS) $(CPPCREATEPCHFLAG) /c STDAFX.CPP

QUNO.OBJ:	QUNO.CPP $(QUNO_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c QUNO.CPP

MAINFRM.OBJ:	MAINFRM.CPP $(MAINFRM_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c MAINFRM.CPP

QUNOCARD.OBJ:	QUNOCARD.CPP $(QUNOCARD_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c QUNOCARD.CPP


$(PROJ).EXE::	QUNO.RES

$(PROJ).EXE::	STDAFX.OBJ QUNO.OBJ MAINFRM.OBJ QUNOCARD.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
STDAFX.OBJ +
QUNO.OBJ +
MAINFRM.OBJ +
QUNOCARD.OBJ +
$(OBJS_EXT)
$(PROJ).EXE
$(MAPFILE)
c:\ms16\vc\lib\+
c:\ms16\vc\mfc\lib\+
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
