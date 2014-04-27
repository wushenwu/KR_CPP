# Microsoft Developer Studio Generated NMAKE File, Based on studinfo.dsp
!IF "$(CFG)" == ""
CFG=studinfo - Win32 Debug
!MESSAGE No configuration specified. Defaulting to studinfo - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "studinfo - Win32 Release" && "$(CFG)" != "studinfo - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "studinfo.mak" CFG="studinfo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "studinfo - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "studinfo - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "studinfo - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\studinfo.exe"


CLEAN :
	-@erase "$(INTDIR)\CMyDate.obj"
	-@erase "$(INTDIR)\CMyString.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\studinfo.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\studinfo.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\studinfo.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\studinfo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\studinfo.pdb" /machine:I386 /out:"$(OUTDIR)\studinfo.exe" 
LINK32_OBJS= \
	"$(INTDIR)\studinfo.obj" \
	"$(INTDIR)\CMyString.obj" \
	"$(INTDIR)\CMyDate.obj" \
	"$(INTDIR)\main.obj"

"$(OUTDIR)\studinfo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "studinfo - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\studinfo.exe" "$(OUTDIR)\studinfo.bsc"


CLEAN :
	-@erase "$(INTDIR)\CMyDate.obj"
	-@erase "$(INTDIR)\CMyDate.sbr"
	-@erase "$(INTDIR)\CMyString.obj"
	-@erase "$(INTDIR)\CMyString.sbr"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\main.sbr"
	-@erase "$(INTDIR)\studinfo.obj"
	-@erase "$(INTDIR)\studinfo.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\studinfo.bsc"
	-@erase "$(OUTDIR)\studinfo.exe"
	-@erase "$(OUTDIR)\studinfo.ilk"
	-@erase "$(OUTDIR)\studinfo.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\studinfo.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ  /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\studinfo.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\studinfo.sbr" \
	"$(INTDIR)\CMyString.sbr" \
	"$(INTDIR)\CMyDate.sbr" \
	"$(INTDIR)\main.sbr"

"$(OUTDIR)\studinfo.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\studinfo.pdb" /debug /machine:I386 /out:"$(OUTDIR)\studinfo.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\studinfo.obj" \
	"$(INTDIR)\CMyString.obj" \
	"$(INTDIR)\CMyDate.obj" \
	"$(INTDIR)\main.obj"

"$(OUTDIR)\studinfo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("studinfo.dep")
!INCLUDE "studinfo.dep"
!ELSE 
!MESSAGE Warning: cannot find "studinfo.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "studinfo - Win32 Release" || "$(CFG)" == "studinfo - Win32 Debug"
SOURCE=.\CMyDate.cpp

!IF  "$(CFG)" == "studinfo - Win32 Release"


"$(INTDIR)\CMyDate.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "studinfo - Win32 Debug"


"$(INTDIR)\CMyDate.obj"	"$(INTDIR)\CMyDate.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\CMyString.cpp

!IF  "$(CFG)" == "studinfo - Win32 Release"


"$(INTDIR)\CMyString.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "studinfo - Win32 Debug"


"$(INTDIR)\CMyString.obj"	"$(INTDIR)\CMyString.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\main.cpp

!IF  "$(CFG)" == "studinfo - Win32 Release"


"$(INTDIR)\main.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "studinfo - Win32 Debug"


"$(INTDIR)\main.obj"	"$(INTDIR)\main.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\studinfo.cpp

!IF  "$(CFG)" == "studinfo - Win32 Release"


"$(INTDIR)\studinfo.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "studinfo - Win32 Debug"


"$(INTDIR)\studinfo.obj"	"$(INTDIR)\studinfo.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

