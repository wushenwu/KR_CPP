# Microsoft Developer Studio Generated NMAKE File, Based on codestat.dsp
!IF "$(CFG)" == ""
CFG=codestat - Win32 Debug
!MESSAGE No configuration specified. Defaulting to codestat - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "codestat - Win32 Release" && "$(CFG)" != "codestat - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "codestat.mak" CFG="codestat - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "codestat - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "codestat - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "codestat - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\codestat.exe"


CLEAN :
	-@erase "$(INTDIR)\codestat.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\codestat.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\codestat.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\codestat.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\codestat.pdb" /machine:I386 /out:"$(OUTDIR)\codestat.exe" 
LINK32_OBJS= \
	"$(INTDIR)\codestat.obj"

"$(OUTDIR)\codestat.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "codestat - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\codestat.exe" "$(OUTDIR)\codestat.bsc"


CLEAN :
	-@erase "$(INTDIR)\codestat.obj"
	-@erase "$(INTDIR)\codestat.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\codestat.bsc"
	-@erase "$(OUTDIR)\codestat.exe"
	-@erase "$(OUTDIR)\codestat.ilk"
	-@erase "$(OUTDIR)\codestat.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\codestat.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\codestat.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\codestat.sbr"

"$(OUTDIR)\codestat.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\codestat.pdb" /debug /machine:I386 /out:"$(OUTDIR)\codestat.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\codestat.obj"

"$(OUTDIR)\codestat.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
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


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("codestat.dep")
!INCLUDE "codestat.dep"
!ELSE 
!MESSAGE Warning: cannot find "codestat.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "codestat - Win32 Release" || "$(CFG)" == "codestat - Win32 Debug"
SOURCE=.\codestat.cpp

!IF  "$(CFG)" == "codestat - Win32 Release"


"$(INTDIR)\codestat.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "codestat - Win32 Debug"


"$(INTDIR)\codestat.obj"	"$(INTDIR)\codestat.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

