# Globales Makefile zum Anpassen des verwendeten Betriebssystems. Dieses Makefile
# wird als Inlude in die Makefiles der Beispiele und Aufgaben eingebunden, damit
# Sie hier zentral festlegen können, mit welchem Betriebssystem Sie arbeiten wollen.

# Kommentieren Sie die folgenden Zeilen aus, wenn Sie kein Windows verwenden:
-include ../../Makefiles/windows.mak
-include ../../../Makefiles/windows.mak

# Stattdessen kommentieren Sie die folgenden Zeilen ein:
#-include ../../Makefiles/unix.mak
#-include ../../../Makefiles/unix.mak