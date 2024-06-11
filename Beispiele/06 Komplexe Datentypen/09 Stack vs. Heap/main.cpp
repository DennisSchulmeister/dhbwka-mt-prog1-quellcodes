/***********************************************************************************************
 * Beispiel: Stack vs. Heap
 * ========================
 * 
 * Unsere C/C++-Kenntnisse vervollständigen sich immer mehr. Langsam sind wir bereit, nach dem
 * blauen Gürtel auf den braunen Gürtel, den letzten vor den Meistergraden, umzusteigen. Das
 * einzige, was uns hierzu noch fehlt, ist ein tieferes Verständnis dafür, wie der Hauptspeicher
 * von C und C++ verwaltet wird. Denn hier gibt es tatsächlich zwei Arten von Speicher, die wir
 * bisher noch gar nicht betrachtet haben: Den sogenannten Stack (zu Dinosaurierzeiten auf
 * deutsch auch Stapel- oder Kellerspeicher genannt) und den Heap (deutsch Halde, was aber
 * auch niemand mehr so sagt). Was hat es damit auf sich?
 * 
 * Um dies zu verstehen, müssen wir uns anschauen, wie der Hauptspeicher der Computers aus Sicht
 * eines typischen Programms unter Windows oder Linux aussieht. Hierzu muss man wissen, dass
 * moderne Computer den Hauptspeicher virtualisieren und jedem Programm daher vorgaukeln, es
 * hätte den maximal möglichen Hauptspeicher für sich alleine. Das Betriebssystem teilt den
 * Hauptspeicher in mehrere Bereiche ein, was man auch das Speicherlayout (englisch Memory
 * Layout) nennt: Vereinfacht sieht dieses so aus:
 * 
 *     ╔════════════════════════════════════════════════════════════╗
 *     ║  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓                       ║
 *     ║  ┃                                 ┃ (Adresse 0x000'00000) ║
 *     ║  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫    ·                  ║
 *     ║  ┃ Programmcode                    ┃ (Adresse 0x0804'8000) ║
 *     ║  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫    ·                  ║
 *     ║  ┃ Globale Variablen               ┃    ·                  ║
 *     ║  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫    ·                  ║
 *     ║  ┃                                 ┃    ·                  ║
 *     ║  ┃ Heap                            ┃    ·                  ║
 *     ║  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫    ·                  ║
 *     ║  ┃  🡇 🡇 🡇 🡇 🡇 🡇 🡇 🡇 🡇 🡇 🡇  ┃    ·                  ║
 *     ║  ┃                                 ┃    ·                  ║
 *     ║  ┃                                 ┃    ·                  ║
 *     ║  ┃                                 ┃    ·                  ║
 *     ║  ┃                                 ┃    ·                  ║
 *     ║  ┃  🡅 🡅 🡅 🡅 🡅 🡅 🡅 🡅 🡅 🡅 🡅  ┃    ·                  ║
 *     ║  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫ <── Stack Pointer     ║
 *     ║  ┃ Stack                           ┃    ·                  ║
 *     ║  ┃                                 ┃    ·                  ║
 *     ║  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫    ·                  ║
 *     ║  ┃                                 ┃    ·                  ║
 *     ║  ┃ Betriebssystem                  ┃    ·                  ║
 *     ║  ┃                                 ┃ (Adresse 0xFFFF'FFFF) ║
 *     ║  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛                       ║
 *     ╚════════════════════════════════════════════════════════════╝
 * 
 * Wie man sieht, gibt es zwei große Speicherbereiche in der Mitte, die in entgegengesetzte
 * Richtung aufeinander zugehen, wenn das Programm in einem der beiden Bereiche neuen Speicher
 * anfordert: Den Stack und den Heap. Bisher haben wir nur mit dem Stack gearbeitet, weil dort
 * alle lokalen Variablen, die innerhalb einer Funktion deklariert werden, angelegt werden.
 * Dieser Speicher wird von C/C++ automatisch verwaltet, ohne dass wir uns darum in irgend
 * einer Form kümmern müssen.
 * 
 * Der Compiler nutzt hierbei die beiden CPU-Instruktionen PUSH und POP, die es ermöglichen,
 * den Stack als einen LIFO-Speicher (Last In, First Out) zu benutzen, auf dem temporäre
 * Daten abgelegt werden können. Zu diesem Zweck besitzt die CPU ein eingebautes Register,
 * das Stack Pointer genannt wird (meist SP abgekürzt) und immer auf den Anfang des Stacks
 * zeigt. Die Instruktion PUSH schreibt einen Wert an diese Speicherstelle und verschiebt
 * den Stack Pointer anschließend nach unten. Die Anweisung POP macht das Gegenteil, indem
 * sie den letzten Wert, auf den der Stack Pointer zeigt, liest und den Stack Pointer danach
 * wieder nach oben schiebt:
 *
 *     1) Anfang          2) PUSH 4711     3) PUSH 815       4) POP            5) POP
 *     ┏━━━━━━┓          ┏━━━━━━┓          ┏━━━━━━┓          ┏━━━━━━┓          ┏━━━━━━┓
 *     ┃      ┃          ┃      ┃          ┃      ┃ <── SP   ┃      ┃          ┃      ┃
 *     ┣━━━━━━┫          ┣━━━━━━┫          ┣━━━━━━┫          ┣━━━━━━┫          ┣━━━━━━┫
 *     ┃      ┃          ┃      ┃  <── SP  ┃  815 ┃          ┃      ┃ <── SP   ┃      ┃
 *     ┣━━━━━━┫          ┣━━━━━━┫          ┣━━━━━━┫          ┣━━━━━━┫          ┣━━━━━━┫
 *     ┃      ┃ <── SP   ┃ 4711 ┃          ┃ 4711 ┃          ┃ 4711 ┃          ┃      ┃ <── SP
 *     ┗━━━━━━┛          ┗━━━━━━┛          ┗━━━━━━┛          ┗━━━━━━┛          ┗━━━━━━┛
 * 
 * Immer, wenn in C/C++ eine Funktion aufgerufen wird, werden die lokalen Variablen der Funktion
 * auf dem Stack abgelegt. Läuft die Funktion zu Ende, wird der Stack Pointer wieder auf die
 * vorherige Adresse zurück geschoben, um den Speicher für nachfolgende Funktionsaufrufe frei
 * zu geben. Die Werte selbst bleiben im Speicher liegen. Sie werden einfach beim nächsten
 * Funktionsaufruf mit anderen Daten überschrieben. Deshalb sehen wir oft Datenschrott auf dem
 * Bildschirm, wenn wir Zeiger falsch benutzen.
 * 
 * HINWEIS: Im Stack liegen noch mehr Daten. Bei den meisten Betriebssystemen und CPUs liegen
 * dort auch die Aufrufparameter einer Funktion, ihr Rückgabewert sowie die Rücksprungadresse,
 * bei welcher die Programmausführung nach Verlassen der Funktion fortgeführt wurde (der Punkt,
 * an dem in die Funktion abgesprungen wurde). Da diese Daten zusammen mit den lokalen Variablen
 * der Funktion eine Einheit auf dem Stack bilden, nennt man sie auch "Stack Frame" (deutsch
 * Funktionsrahmen). Mit jedem Aufruf einer Funktion wird ein neuer Stack Frame für die gerufene
 * Funktion angelegt und nach Beenden der Funktion wieder abgeräumt.
 * 
 * So komfortabel der Stack-Speicher auch ist (wir müssen uns um nichts kümmern), hat er das
 * Problem, dass darauf keine dauerhaften Daten abgelegt werden können. Manchmal will man aber
 * einen größeren Speicherbereich mit Daten füllen und diesen dann für lange Zeit (oft so lange,
 * wie das Programm läuft) weiternutzen. Auch, wenn die Funktion, die den Speicherbereich
 * angefordert hat, längst zu Ende gelaufen ist. Globale Variablen stellen eine Möglichkeit dar,
 * wie dies erreicht werden kann. Man muss hierfür lediglich außerhalb der main()-Funktion ein
 * Array oder irgend einen anderen Datencontainer entsprechender Größe deklarieren:
 * 
 *     double sound_samples[44100 * 10 * 2] = {};   // Puffer für Audiodaten
 * 
 *     int main(int argc, char **argv) {
 *         ...
 *     }
 * 
 * Dabei gibt es jedoch ein großes Problem: Der Compiler muss bereits zur Übersetzungszeit
 * wissen, wie groß der Speicherbereich sein soll. Man könnte in dem obigen Beispiel also
 * nicht beim Programmstart abfragen, wie viele Sekunden an Audiodaten gespeichert werden
 * sollen und das Array entsprechend anders dimensionieren. Dieses Problem lässt sich
 * allerdings lösen, indem man einfach ein std::vector<double> verwendet:
 * 
 *     vector<double> sound_samples = {};
 * 
 *     int main(int argc, char **argv) {
 *         sound_samples.resize(44100 * 10 * 2);    // Größe des Puffers ändern
 *     }
 * 
 * Möglich wird dies, weil das vector-Objekt zwar im Speicherbereich für globale Variablen liegt
 * und hierfür eine feste Größe besitzen muss. Für die eigentlichen Inhalte des Vektors reserviert
 * dieser allerdings zur Laufzeit einen separaten Speicherbereich im Heap-Speicher. Der Vektor
 * umfasst somit lediglich eine Hand voll Verwaltungsdaten sowie einen Zeiger auf einen, vom
 * Vektor-Objekt automatisch verwalteten, im Heap liegenden Datenspeicher.
 * 
 *     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
 *     ┃ Globale Variablen   [Vektor]──┐ ┃
 *     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━│━┫
 *     ┃         [Sampledaten.......]<─┘ ┃
 *     ┃ Heap                            ┃
 *     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
 * 
 * Der Vorteil des Heap-Speichers ist dabei, dass er vollkommen manuell verwaltet wird und man
 * daher maximale Kontrolle darüber hat, wann dort welche Daten wie lange abgelegt werden. Diese
 * Eigenschaft macht sich das Vektor-Objekt zu Nutze. Doch nicht nur die Datencontainer von C++
 * können dort Daten ablegen. Wir können das auch. Obwohl es durchaus Sinn macht, den Containern
 * von C++ die Arbeit zu überlassen, wenn man kann. Zum besseren Verständnis wollen wir dennoch
 * verstehen, wie der Heap-Speicher direkt genutzt werden kann.
 * 
 * In C benötigt man hierfür die beiden Funktionen malloc() und free():
 * 
 *  - malloc(size): Speicherbereich anfordern. Size ist die Größe in Bytes.
 *  - free(ptr):    Speicherbereich freigeben.
 * 
 * malloc() liefert hierfür einen Zeiger vom Typ void* zurück. Das wirkt eigenartig, weil der
 * Typ void in C/C++ eigentlich für "nichts" steht und es einen Zeiger auf nichts ja gar nicht
 * geben kann. Deshalb bedeutet "void" hier nicht "nichts", sondern "beliebige Daten mit für
 * den Compiler unbekanntem Datentyp". Derselbe Zeiger muss dann zu einem späteren Zeitpunkt
 * an free() übergeben werden, um den Speicher wieder freizugeben.
 * 
 * In C++ funktioniert der Heap ähnlich, anstatt malloc() und free() werden hier aber eher die
 * neuen Schlüsselwörter new und delete verwendet, da diese Typsicher verwendbar sind. Das
 * Programm unten zeigt, wie es geht. Wichtig zu beachten ist dabei folgendes:
 * 
 *  - "new ..."" liefert immer einen typisierten Zeige zurück (kein void*)
 *  - "delete Zeiger" gibt den Speicherbereich wieder frei.
 *  - Arrays müssen mit "delete[] Zeiger" freigegeben werden.
 * 
 * Mehr gibt es eigentlich nicht zu beachten. Außer, dass wir hier den -> Operator sehen, der
 * immer dann zum Einsatz kommt, wenn man auf die Elemente einer Struktur zugreifen will, dabei
 * aber "nur" einen Zeiger auf die Struktur hat. Ohne Zeiger würde man "variable.element"
 * schreiben. Mit Zeiger stattdessen "variable->element".
 * 
 * HINWEIS: Auch, wenn die Verwendung des Heaps einfach klingt. Es ist tatsächlich alles andere
 * als Trivial, ihn richtig zu verwenden. Der Grund hierfür ist, dass man unter allen möglichen
 * Programmabläufen sicherstellen muss, dass der auf dem Heap angeforderte Speicher auch
 * tatsächlich wieder freigegeben wird (außer das Programm wird sowieso gerade beendet).
 * Denn sonst hat man eine Speicherlücke, die den Hauptspeicher auffrisst und dadurch die
 * Performance runter zieht bzw. sogar zum Absturz wegen Speichermangel führen kann. In der
 * Regel ist es daher klug, die Container-Klassen von C++ wie std::array oder std::vector zu
 * verwenden und ihnen die Detailarbeit bezüglich Heap zu überlassen.
 ***********************************************************************************************/

#include <cstdint>      // Plattformunabhängige Ganzzahlen
#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::string, std::getline, ...
#include <vector>       // std::vector

using namespace std;

struct Soundfile {
    uint8_t  channels;
    uint32_t sample_rate;
    uint8_t  sample_size;
    long     length;

    vector<uint32_t> sample_data;
};

int main(int argc, char **argv) {
    cout << endl;

    // Speicher auf dem Heap anfordern
    int *heap_int   = new int;
    int *heap_array = new int[15];

    Soundfile *heap_struct = new Soundfile {
        .channels    = 2,
        .sample_rate = 44100,
        .sample_size = 2,
        .length      = 10 * 44100
    };

    // Mit den Speicherbereichen arbeiten
    *heap_int = 4711;

    cout << "*heap_int.......: " << *heap_int << endl;
    cout << " heap_array[]...: ";

    for (int i = 0; i < 15; i++) {
        heap_array[i] = i * 2;
        cout << heap_array[i] << " ";
    }

    cout << endl << endl;

    heap_struct->channels = 1;
    heap_struct->sample_data.resize(heap_struct->channels * heap_struct->length);

    cout << "heap_struct->sample_rate: " << heap_struct->sample_rate << endl;
    cout << endl;

    // Speicher wieder freigeben
    delete heap_int;
    delete[] heap_array;
    delete heap_struct;

    cout << "Hurra! Nicht abgestürzt! :-)" << endl;
    cout << endl;
}