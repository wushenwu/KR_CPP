# Microsoft Developer Studio Generated NMAKE File, Based on desk.dsp
!IF "$(CFG)" == ""
CFG=desk - Win32 Debug
!MESSAGE No configuration specified. Defaulting to desk - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "desk - Win32 Release" && "$(CFG)" != "desk - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "desk.mak" CFG="desk - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "desk - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "desk - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "desk - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\desk.exe"


CLEAN :
	-@erase "$(INTDIR)\computer.obj"
	-@erase "$(INTDIR)\desk.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\person.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\desk.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\desk.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\desk.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\desk.pdb" /machine:I386 /out:"$(OUTDIR)\desk.exe" 
LINK32_OBJS= \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\desk.obj" \
	"$(INTDIR)\computer.obj" \
	"$(INTDIR)\person.obj"

"$(OUTDIR)\desk.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "desk - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\desk.exe" "$(OUTDIR)\desk.bsc"


CLEAN :
	-@erase "$(INTDIR)\computer.obj"
	-@erase "$(INTDIR)\computer.sbr"
	-@erase "$(INTDIR)\desk.obj"
	-@erase "$(INTDIR)\desk.sbr"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\main.sbr"
	-@erase "$(INTDIR)\person.obj"
	-@erase "$(INTDIR)\person.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\desk.bsc"
	-@erase "$(OUTDIR)\desk.exe"
	-@erase "$(OUTDIR)\desk.ilk"
	-@erase "$(OUTDIR)\desk.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\desk.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\desk.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\main.sbr" \
	"$(INTDIR)\desk.sbr" \
	"$(INTDIR)\computer.sbr" \
	"$(INTDIR)\person.sbr"

"$(OUTDIR)\desk.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\desk.pdb" /debug /machine:I386 /out:"$(OUTDIR)\desk.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\desk.obj" \
	"$(INTDIR)\computer.obj" \
	"$(INTDIR)\person.obj"

"$(OUTDIR)\desk.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("desk.dep")
!INCLUDE "desk.dep"
!ELSE 
!MESSAGE Warning: cannot find "desk.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "desk - Win32 Release" || "$(CFG)" == "desk - Win32 Debug"
SOURCE=.\computer.cpp

!IF  "$(CFG)" == "desk - Win32 Release"


"$(INTDIR)\computer.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "desk - Win32 Debug"


"$(INTDIR)\computer.obj"	"$(INTDIR)\computer.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\desk.cpp

!IF  "$(CFG)" == "desk - Win32 Release"


"$(INTDIR)\desk.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "desk - Win32 Debug"


"$(INTDIR)\desk.obj"	"$(INTDIR)\desk.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\main.cpp

!IF  "$(CFG)" == "desk - Win32 Release"


"$(INTDIR)\main.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "desk - Win32 Debug"


"$(INTDIR)\main.obj"	"$(INTDIR)\main.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\person.cpp

!IF  "$(CFG)" == "desk - Win32 Release"


"$(INTDIR)\person.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "desk - Win32 Debug"


"$(INTDIR)\person.obj"	"$(INTDIR)\person.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

