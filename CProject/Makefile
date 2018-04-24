# Project: acd
CPP  = g++.exe -D__DEBUG__ -g
CC   = gcc.exe -D__DEBUG__ -g
WINDRES = windres.exe
RES  = 
ACDINC = ./include
ACDSOURCE =./source
OBJ  = cmodule.o $(RES)
LINKOBJ  = cmodule.o $(RES)
LIBS =  -L"D:/TDM-GCC-64/x86_64-w64-mingw32/lib"  C:/Python27/libs/libpython27.a     -g3 -fmessage-length=0 
INCS =  -I"D:/TDM-GCC-64/include"  -I"C:/Python27/include"  -I"./include" 
CXXINCS =  -I"D:/TDM-GCC-64/x86_64-w64-mingw32/include"  -I"D:/TDM-GCC-64/include"  -I"C:/Python27/include"  -I"./include" 
BIN  = acd.pyd
CXXFLAGS = $(CXXINCS) -gdwarf-2  -g -DDEBUG  -g3 -fmessage-length=0 -DMS_WIN64
## -fshort-double
CFLAGS = $(INCS)   -fshort-double -g3 -fmessage-length=0
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before acd.pyd all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

DLLWRAP=dllwrap.exe
DEFFILE=libAcd.def
STATICLIB=libAcd.a


$(BIN): $(LINKOBJ)
	$(DLLWRAP) --output-def $(DEFFILE) --driver-name c++ --implib $(STATICLIB) $(LINKOBJ) $(LIBS) -o $(BIN) 


cmodule.o: $(ACDSOURCE)/cmodule.cpp
	$(CPP) -c $(ACDSOURCE)/cmodule.cpp -o cmodule.o  $(CXXFLAGS) 

    
    
#    $(CXXFLAGS)    -D__CYGWIN__    -D__cplusplus
#C:/Python27/libs/python27.lib 
