# Mechatronik: Programmieren I - Makefile vom Bauen der Aufgaben und Beispiele
# Linux/Unix/Mac/GitBash-Variante: Kein Programmsuffix .exe, Löschbefehl rm
#
# Aufruf mit: make -f unix.mak ...
# Außer, Sie benennen die Datei in `Makefile` um. :-)

# Hier den Namen des zu erstellenden Programms ändern, wenn es nicht `main` heißen soll
PROGRAM = main
OBJS := $(patsubst %.c,%.o,$(wildcard *.c)) $(patsubst %.cpp,%.o,$(wildcard *.cpp))

# Verwendete Compiler
CC  := gcc
CXX := g++

ifeq ($(BUILD_MODE),release)
	CFLAGS += -O2
else
	CFLAGS += -g
endif

.PHONY: default all clean run

default: all

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^
	$(EXTRA_CMDS)

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm $(PROGRAM) *.o

run: $(PROGRAM)
	./$(PROGRAM)