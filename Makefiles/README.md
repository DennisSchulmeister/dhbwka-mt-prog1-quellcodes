Makefile zum Bauen der Aufgaben und Beispiele
=============================================

1. [Beschreibung](#beschreibung)
1. [Anleitung](#anleitung)

Beschreibung
------------

Dieses Verzeichnis beinhaltet zwei Makefiles, die zum Bauen der Aufgaben und Beispiele
verwendet werden können. Dies hat den Vorteil, dass Sie die hierfür notwendigen Befehle
nicht einzeln auf der Kommandozeile eingeben müssen. Gleichzeitig funktionieren die
Makefiles unabhängig von der verwendeten IDE oder dem verwendeten Code-Editor.

Zwar bieten viele Editoren (und IDEs sowieso) eine eingebaute Möglichkeit, um in C oder C++
geschrieben Programme zu kompilieren. Bei größeren Projekten müssen hierfür jedoch verschiedene
Einstellungen vorgenommen werden, die dann nur mit der einen IDE bzw. dem einen Editor funktionieren.
Auch lässt sich der Build-Vorgang (so nennt sich das Kompilieren und Linken der Programme) so nur
schwer automatisieren. Makefiles hingegen funktionieren in nahezu jeder Umgebung, auch wenn sie
leider für ein bestimmtes Betriebssystem (bzw. eine bestimmte Shell) geschrieben werden müssen.

Alternativ zu Makefiles gibt es auch viele sog. Build-Systeme, die dieselben Vorteile wie Makefiles
bieten, dabei aber nicht an ein bestimmtes Betriebssystem gebunden sind. Beispiele hierfür sind:

* [Meson](http://mesonbuild.com/)
* [Scons](https://scons.org/)
* [Waf](https://waf.io/)
* [CMake](https://cmake.org/)
* [Autotools](https://www.gnu.org/software/automake/)

Für unsere bescheidenen Zwecke in der Vorlesung reichen jedoch die guten, alten Makefiles.
`make` ist bei jedem Compiler im Lieferumfang enthalten und wir sparen uns den Lernaufwand,
der mit den anderen Build-Tools einher geht. Nur, falls Sie planen, größere Anwendungen zu
schreiben, die auch auf anderen Betriebssystemen laufen sollen, sollten Sie sich natürlich
damit auseinandersetzen.

Anleitung
---------

Die Verwendung der Makefiles ist kinderleicht. Je nach Betriebssystem kopieren Sie einfach
eine der folgenden beiden Dateien in das Verzeichnis mit dem Quellcode, den Sie bauen wollen:

* `windows.mak` - Microsoft Windows
* `unix.mak` - Linux, Unix, Mac OS

Anschließend benennen Sie die Datei in `Makefile` (groß geschrieben) um, um den Dateinamen
nicht bei jedem Aufruf ausschreiben zu müssen. Wenn Sie dann in der Kommandozeile in das
jeweilige Verzeichnis wechseln, stehen Ihnen dort folgende Befehle zur Verfügung:

| **Befehl**   | **Funktion**                                                 |
|--------------|--------------------------------------------------------------|
| `make run`   | Kompilieren, Linken und Ausführen des Programms              |
| `make all`   | Kompilieren und Linken in einem Schritt                      |
| `make`       | Dasselbe wie `make all`                                      |
| `make clean` | Vom Compiler erzeugte Dateien wieder löschen                 |
| `make xyz.o` | Kompilieren der Quelldatei `xyz.cpp` zur Objektdatei `xyz.o` |