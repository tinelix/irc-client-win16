# Microsoft Visual C++ generated build script - Do not modify

PROJ = TLX_IRC
DEBUG = 1
PROGTYPE = 0
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = /d_DEBUG 
R_RCDEFINES = /dNDEBUG 
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = C:\HOME\TLX_IRC\
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC = ABOUTDLG.C  
FIRSTCPP =             
RC = rc
CFLAGS_D_WEXE = /nologo /G2 /W3 /Zi /AM /Od /D "_DEBUG" /FR /GA /Fd"TLX_IRC.PDB"
CFLAGS_R_WEXE = /nologo /W3 /Gf /O1 /D "WINVER"="0x0300" /D "NDEBUG" /FR /GA /GEs /GEm
LFLAGS_D_WEXE = /NOLOGO /NOD /PACKC:61440 /STACK:10240 /ALIGN:16 /ONERROR:NOEXE /CO  
LFLAGS_R_WEXE = /NOLOGO /NOD /PACKC:61440 /ALIGN:16 /ONERROR:NOEXE  
LIBS_D_WEXE = oldnames libw mlibcew winsock.lib commdlg.lib olecli.lib olesvr.lib shell.lib 
LIBS_R_WEXE = oldnames libw slibcew commdlg.lib olecli.lib olesvr.lib shell.lib 
RCFLAGS = /nologo 
RESFLAGS = /nologo /30 
RUNFLAGS = 
DEFFILE = SRC\TLX_IRC.DEF
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
SBRS = ABOUTDLG.SBR \
		APP.SBR \
		MAINWND.SBR \
		CONNMDLG.SBR \
		ETEXTDLG.SBR \
		PRFSTDLG.SBR \
		IRCCLNT.SBR


ABOUTDLG_DEP = c:\home\tlx_irc\src\aboutdlg.h \
	c:\home\tlx_irc\src\globals.h


APP_DEP = c:\home\tlx_irc\src\globals.h \
	c:\home\tlx_irc\src\mainwnd.h \
	c:\programs\msvc\include\winsock.h


MAINWND_DEP = c:\home\tlx_irc\src\aboutdlg.h \
	c:\home\tlx_irc\src\etextdlg.h \
	c:\home\tlx_irc\src\globals.h \
	c:\home\tlx_irc\src\mainwnd.h \
	c:\home\tlx_irc\src\connmdlg.h \
	c:\home\tlx_irc\src\ircclnt.h


RESOURCE_RCDEP = c:\home\tlx_irc\src\tlx_irc.ver


CONNMDLG_DEP = c:\home\tlx_irc\src\connmdlg.h \
	c:\home\tlx_irc\src\etextdlg.h \
	c:\home\tlx_irc\src\globals.h


ETEXTDLG_DEP = c:\home\tlx_irc\src\etextdlg.h \
	c:\home\tlx_irc\src\prfstdlg.h \
	c:\home\tlx_irc\src\globals.h


PRFSTDLG_DEP = c:\home\tlx_irc\src\prfstdlg.h \
	c:\home\tlx_irc\src\globals.h


IRCCLNT_DEP = c:\programs\msvc\include\winsock.h \
	c:\home\tlx_irc\src\ircclnt.h


all:	$(PROJ).EXE $(PROJ).BSC

ABOUTDLG.OBJ:	SRC\ABOUTDLG.C $(ABOUTDLG_DEP)
	$(CC) $(CFLAGS) $(CCREATEPCHFLAG) /c SRC\ABOUTDLG.C

APP.OBJ:	SRC\APP.C $(APP_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c SRC\APP.C

MAINWND.OBJ:	SRC\MAINWND.C $(MAINWND_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c SRC\MAINWND.C

RESOURCE.RES:	SRC\RESOURCE.RC $(RESOURCE_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r -FoC:\HOME\TLX_IRC\RESOURCE.RES SRC\RESOURCE.RC

CONNMDLG.OBJ:	SRC\CONNMDLG.C $(CONNMDLG_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c SRC\CONNMDLG.C

ETEXTDLG.OBJ:	SRC\ETEXTDLG.C $(ETEXTDLG_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c SRC\ETEXTDLG.C

PRFSTDLG.OBJ:	SRC\PRFSTDLG.C $(PRFSTDLG_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c SRC\PRFSTDLG.C

IRCCLNT.OBJ:	SRC\IRCCLNT.C $(IRCCLNT_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c SRC\IRCCLNT.C


$(PROJ).EXE::	RESOURCE.RES

$(PROJ).EXE::	ABOUTDLG.OBJ APP.OBJ MAINWND.OBJ CONNMDLG.OBJ ETEXTDLG.OBJ PRFSTDLG.OBJ \
	IRCCLNT.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
ABOUTDLG.OBJ +
APP.OBJ +
MAINWND.OBJ +
CONNMDLG.OBJ +
ETEXTDLG.OBJ +
PRFSTDLG.OBJ +
IRCCLNT.OBJ +
$(OBJS_EXT)
$(PROJ).EXE
$(MAPFILE)
c:\programs\msvc\lib\+
c:\programs\msvc\mfc\lib\+
$(LIBS)
$(DEFFILE);
<<
	link $(LFLAGS) @$(PROJ).CRF
	$(RC) $(RESFLAGS) RESOURCE.RES $@
	@copy $(PROJ).CRF MSVC.BND

$(PROJ).EXE::	RESOURCE.RES
	if not exist MSVC.BND 	$(RC) $(RESFLAGS) RESOURCE.RES $@

run: $(PROJ).EXE
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
