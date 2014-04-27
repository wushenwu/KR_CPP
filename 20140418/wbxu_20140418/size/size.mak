# Microsoft Developer Studio Generated NMAKE File, Based on size.dsp
!IF "$(CFG)" == ""
CFG=size - Win32 Debug
!MESSAGE No configuration specified. Defaulting to size - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "size - Win32 Release" && "$(CFG)" != "size - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "size.mak" CFG="size - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "size - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "size - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "size - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\size.exe"


CLEAN :
	-@erase "$(INTDIR)\size.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\size.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\size.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\size.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\size.pdb" /machine:I386 /out:"$(OUTDIR)\size.exe" 
LINK32_OBJS= \
	"$(INTDIR)\size.obj"

"$(OUTDIR)\size.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "size - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\size.exe" "$(OUTDIR)\size.bsc"


CLEAN :
	-@erase "$(INTDIR)\size.obj"
	-@erase "$(INTDIR)\size.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\size.bsc"
	-@erase "$(OUTDIR)\size.exe"
	-@erase "$(OUTDIR)\size.ilk"
	-@erase "$(OUTDIR)\size.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\size.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ  /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\size.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\size.sbr"

"$(OUTDIR)\size.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\size.pdb" /debug /machine:I386 /out:"$(OUTDIR)\size.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\size.obj"

"$(OUTDIR)\size.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("size.dep")
!INCLUDE "size.dep"
!ELSE 
!MESSAGE Warning: cannot find "size.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "size - Win32 Release" || "$(CFG)" == "size - Win32 Debug"
SOURCE=.\size.cpp

!IF  "$(CFG)" == "size - Win32 Release"


"$(INTDIR)\size.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "size - Win32 Debug"


"$(INTDIR)\size.obj"	"$(INTDIR)\size.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

