########################################################################################################
# Mechatronik: Programmieren I - Makefile zum Bauen der Aufgaben und Beispiele
# Kombiniertes Makefile für Windows PowerShell (Default), Linux, macOS und Unix
# Kopiervorlage, die 1:1 in die Projektverzeichnisse übernommen werden kann.
#
# Version 1.01 vom 24.05.2024, 13:39 Uhr
########################################################################################################


###### Konfiguration ###################################################################################

# Hier den Namen des zu erstellenden Programms ändern, wenn es nicht `main.exe` heißen soll
PROGRAM = main

ifeq ($(SHELL),sh.exe)
	OS = WINDOWS
	PROGRAM := $(PROGRAM).exe
else
	OS = UNIX
endif

OBJS := $(patsubst %.c,%.o,$(wildcard *.c)) $(patsubst %.cpp,%.o,$(wildcard *.cpp))

# Verwendete Compiler
CC  := gcc
CXX := g++

ifeq ($(BUILD_MODE),release)
	CFLAGS += -O2
else
	CFLAGS += -g
endif

# Targets, die von keinen Quelldateien direkt abhängig sind
.PHONY: default all clean cleanU run runU


###### Standard-Target: EXE-Datei bauen ################################################################

default: all
all: $(PROGRAM)


.PHONY: shell
shell:
	echo $(SHELL)

###### Programm kompilieren und ausführen ###############################################################
run: $(PROGRAM)
ifeq ($(OS),WINDOWS)
	chcp 65001
	.\$(PROGRAM)
else
	./$(PROGRAM)
endif

###### Programm compilieren und EXE-Datai bauen ########################################################

$(PROGRAM): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^
	$(EXTRA_CMDS)

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<


###### Automatisch erzeugte Dateien aufräumen ###########################################################

clean:
ifeq ($(OS),WINDOWS)
	del $(PROGRAM) *.o *.d
else
	rm -f ${PROGRAM} *.o *.d
endif