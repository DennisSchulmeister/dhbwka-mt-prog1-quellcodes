/***********************************************************************************************
 * Beispiel: Mehrere Quellcode-Dateien klassisch
 * =============================================
 * 
 * Die einfachen Programme, die bis bisher geschrieben haben, passten alle wunderbar in je eine
 * einzige Quellcode-Datei. Für kleine bis mittlere Programme ist da auch garnichts dagegen
 * einzuwenden. Denn weniger ist mehr, wie man so schön sagt. Und warum etwas komplizierter
 * machen, als es wirklich sein muss?
 * 
 * Ab einer bestimmten Größe (die jede/r für sich anders definiert), ist es allerdings doch
 * übersichtlicher, den Quellcode in mehrere Dateien aufzuteilen. Auch kann man dadurch die
 * Zeit zum Compilieren des Programms nach einer Quellcode-Änderung reduzieren, da dann nur
 * die veränderten Dateien, nicht aber der gesamte Quellcode, neu übersetzt werden müssen.
 * 
 * Das liegt daran, dass für den Compiler jede *.cpp-Datei eine eigene "Übersetzungseinheit",
 * darstellt, die unabhängig von allen anderen Dateien übersetzt wird. Jede *.cpp-Datei wird
 * dabei zu einer Objektcode-Datei (Objektmodul) mit der Endung *.o compiliert, die der Linker
 * dann im nächsten Schritt mit den anderen *.o-Dateien kombiniert, um das fertige Programm
 * zu erzeugen. Zum Beispiel:
 * 
 *    main.cpp    ──Compiler──> main.o    ──┐
 *                                          ├──Linker──> main.exe
 *    message.cpp ──Compiler──> message.o ──┘
 * 
 * Um den Quellcode übersichtlicher zu gestalten, muss man also nur weitere *.cpp-Dateien
 * anlegen und den Quellcode entsprechend aufteilen. Jedoch gibt es dann Probleme, wenn man
 * von einer *.cpp-Datei auf die Inhalte (beispielsweise die Funktionen) einer anderen *.cpp-
 * Datei zugreifen will. Da der Compiler jede *.cpp-Datei isoliert betrachtet, kennt er die
 * Inhalte der anderen Dateien nicht und wirft entsprechend mit Fehlermeldungen um sich.
 * 
 * Sollen einzelne Inhalte einer *.cpp-Datei über die eigene Datei hinaus verwendet werden, muss
 * daher eine Header-Datei angelegt werden, welche diese Inhalte deklariert. Damit sind folgende
 * Inhalte gemeint, die in die Header-Datei gehören:
 * 
 *  - Selbst-definierte Datentypen (struct, class, enum, typedef)
 *  - Konstanten (const, constexpr, #define)
 *  - Präprozessor-Makros (#define)
 *  - Globale Variablen (extern)
 *  - Vorwärtsdeklarationen von Funktionen
 *  - inline-Funktionen, die auf keine "privaten" Inhalte der *.cpp-Datei benötigten
 * 
 * Dabei gehören nur "öffentliche" Deklarationen in die Header-Datei von Dingen, die für
 * die Verwendung in anderen *.cpp-Dateien vorgesehen sind. Alles, was nur innerhalb der
 * eigenen *.cpp-Datei benötigt wird, sind "private" Inhalte, die nicht in den Header
 * gehören. Das vollständige Bild sieht dadurch so aus:
 * 
 *    main.cpp    ──Präprozessor: #include "message.hpp"──Compiler──> main.o    ──┐
 *                                                                                ├──Linker──> main.exe
 *    message.cpp ──Präprozessor: #include "message.hpp"──Compiler──> message.o ──┘
 * 
 * Beide *.cpp-Dateien beinhalten die Zeile #include "message.hpp", die der Präprozessor durch
 * den Inhalt der Header-Datei ersetzt. Erst dann bekommt der Compiler den Code zu sehen und
 * kennt dadurch die notwendigen Deklarationen. Dabei stört es den Compiler beim Übersetzen der
 * main.cpp nicht, dass es noch keine Implementierungen zu den eingebundenen Deklarationen gibt.
 * In die *.o-Datei wird dann einfach ein Verweis aufgenommen, den der Linker beim Zusammenfügen
 * der *.o-Dateien auflösen muss. Findet der Linker eine gleichnamige Implementierung in einer
 * der anderen *.o-Dateien, fügt er sie ein und erzeugt die fertige Programmdatei.
 * 
 * Ein Problem gibt es dann aber immer noch: Selbst bei privaten Inhalten, die nur innerhalb
 * einer einzigen *.cpp-Datei benötigt werden, kann es zu Namenskonflikten kommen. In diesem
 * Beispiel handelt es sich dabei um die Funktion get_random_number(), die zwar in message.cpp
 * implementiert wurde, aber nicht in der message.hpp aufgelistet wurde. Der Linker liefert
 * beim Zusammenfügen der *.o-Dateien einen Fehler, weil die Datei "main.o" eine gleichnamige
 * Funktion beinhaltet. Zur Lösung dieses Problems bietet C++ Namespaces (deutsch: Namensräume).
 * Diese werden wie folgt deklariert:
 * 
 *     namespace NAME {
 *         DEKLARATIONEN …
 *     }
 * 
 * Die Dateien "message.hpp" und "message.cpp" beinhalten daher eine solche Anweisung, die die
 * meisten Zeilen dieser Dateien einschließt:
 * 
 *     namespace message {
 *         ...
 *     }
 * 
 * Dadurch wird die Funktion get_random_number() ausgeschrieben zu message::get_random_number(),
 * was keinen Namenskonflikt mehr verursacht.
 * 
 * HINWEIS: Eine andere Art, über *.o-Dateien nachzudenken, ist, sie als "Bibliotheken" zu
 * betrachten. Unter Windows kennen Sie vielleicht *.dll-Dateien, was "Dynamic-Link Library"
 * bedeutet. Unter Linux, macOS, und Unix heißen dieselben Dateien *.so (Shared Object). Sie
 * enthalten wiederverwendbare Funktionen und anderen Code, der von mehreren Programmen genutzt
 * werden kann. Entweder, weil man den gleichen Code in verschiedenen Programmen verwenden
 * oder Bibliotheken von anderen Softwareanbietern nutzen will. So oder so muss das Betriebssystem
 * die verwendeten Bibliotheken beim Start des Programms laden und die Verweise im Programmcode
 * auflösen. Dies wird "dynamische Bindung" genannt: "Dynamisch", weil es erst zur Laufzeit und
 * und nicht während der Entwicklung passiert, und "Bindung", weil der Programmcode mit dem
 * Bibliothekscode verbunden wird. Die *.o-Dateien des Compilers sind ähnlich, aber die Bindung
 * wird schon vom Linker hergestellt, wenn die ausführbare Datei erstellt wird. Die *.o-Dateien
 * werden anschließend nicht mehr benötigt.
 ***********************************************************************************************/

#include "message.hpp"  // Deklarationen zur Objektdatei message.o, die aus message.cpp erzeugt wird
#include <iostream>     // std::cout, std::cin, ...

using namespace std;

int get_random_number() {
    return 42;
}

int main(int argc, char **argv) {
    cout << endl;
    cout << message::get_random_message() << endl;
    cout << get_random_number() << endl;
    cout << endl;
}