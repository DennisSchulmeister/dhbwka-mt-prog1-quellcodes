/***********************************************************************************************
 * Beispiel: Funktionen mit statischen Variablen
 * =============================================
 * 
 * Dieses Beispiel zeigt einen Anwendungsfall, der in eingebetteten Systemen häufig vorkommt:
 * Die regelmäßige Ausführung unterschiedlicher Tasks in exakten Zeitabständen. Hierfür kann man
 * sich zum Beispiel einen Roboter vorstellen, der verschiedene Sensoren besitzt, um seine Umwelt
 * wahrzunehmen und mehrere Aktoren, um diese zu beeinflussen. Sein Steuerprogramm muss daher
 * immer wiederkehrend folgende Aufgaben ausführen:
 *
 *   1. Sensordaten auslesen
 *   2. Entscheidungslogik ausführen
 *   3. Aktoren ansteuern
 *
 * Das Herzstück ist dabei die Entscheidungslogik, die anhand der vorliegenden Sensordaten
 * entscheidet, wie sich der Roboter verhalten soll. Im einfachsten Fall besteht das Programm
 * daher einfach aus einer Endlosschleife, in der die drei Schritte permanent hintereinander
 * ausgeführt werden. In der realen Welt muss allerdings der Faktor Zeit berücksichtigt werden.
 * Der DHT11-Umweltsensor kann beispielsweise nur alle zwei Sekunden einen neuen Wert liefern.
 * Ein Gleichstrommotor benötigt eine bestimmte Zeit, um die angestrebte Drehzahl zu erreichen.
 * Und so weiter. Zwar können die Bauteile aus Softwaresicht in sehr kurzer Zeit angesprochen
 * werden. Das physische Bauteil benötigt aber gewisse Zeit, bis es reagiert. Ein realer Roboter
 * muss daher unterschiedliche Tasks in unterschiedlichen Zeitabständen ausführen. Zum Beispiel:
 *
 *    - Sensor-Task 1: Ultraschall-Abstandssensoren abfragen, alle 100 Millisekunden
 *    - Sensor-Task 2: DHT11-Umweltsensor abfragen, alle zwei Sekunden
 *    - Sensor-Task 3: Aufprallsensor (Kontaktschalter) abfragen, alle 10 Millisekunden
 *    - Sensor-Task 4: Fahrgeschwindigkeit messen, alle 10 Millisekunden
 *    - Logik-Task: Entscheidungslogik ausführen, alle 10 Millisekunden
 *    - Aktor-Task 1: Gleichstrommotoren ansteuern, alle 100 Millisekunden
 *    - ...
 *
 * Häufig kommen hierfür Echtzeit-Betriebssysteme (englisch: Realtime Operating System) zum
 * Einsatz, die unterschiedliche Grade von Echtzeit für die einzelnen Tasks garantieren.
 * Einfachere Anwendungen kommen aber auch ohne aus, wie das folgende Beispiel zeigt. Hier
 * werden mehrere Funktionen für die einzelnen Tasks definiert, die in der Hauptschleife des
 * Programms regelmäßig aufgerufen werden. Jede Funktion prüft dann, ob genügend Zeit seit
 * der letzten Ausführung vergangen ist und beendet sich vorzeitig selbst, falls nicht.
 *
 * Hierfür muss sich jede Funktionen allerdings den Zeitpunkt der letzten Ausführung merken,
 * wofür in anderen Programmiersprachen meist globale Variablen zum Einsatz kommen. In C/C++
 * gibt es aber noch eine andere, elegantere Möglichkeit: Statische Variablen. Sie existieren,
 * wie lokale Variablen, nur innerhalb einer Funktion, verhalten sich sonst aber wie globale
 * Variablen. Sie behalten daher ihren Wert zwischen zwei Aufrufen bei (und können bei
 * rekursiven Aufrufen der Funktion zu allerlei Bugs führen).
 *
 * Im Beispiel unten wird dies durch task2() verdeutlicht. Die folgende Zeile definiert eine
 * statische Variable vom Typ chrono::steady_clock::time_point und initialisiert sie mit der
 * aktuellen Zeit:
 *
 *     static chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
 *
 * Natürlich wird die Initialisierung nur beim ersten Aufruf der Funktion ausgeführt. Bei
 * allen darauffolgenden Aufrufen wird der Ausdruck rechts des Gleichheitszeichens ignoriert
 * und stattdessen der letzte Wert der Variablen wiederhergestellt. Dadurch kann dann mit
 * folgenden Zeilen geprüft werden, wann der Task tatsächlich laufen soll:
 *
 *     chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
 *     if (t2 - t1 < chrono::seconds(3)) return;
 *     t1 = t2;
 *
 * task1() zeigt zum Vergleich dasselbe Prinzip mit einer globalen Variable. Funktional sind
 * beide Varianten identisch. Die Version mit statischen Variablen ist aber übersichtlicher.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <thread>       // std::this_thread::sleep_for
#include <chrono>       // std::chrono::seconds

using namespace std;

void task1();
void task2();

int main(int argc, char **argv) {
    cout << endl;
    cout << "Programm beenden mit Strg+C" << endl;
    cout << endl;

    while (true) {
        // Programm für 100 Millisekunden anhalten, um die CPU zu entlasten
        this_thread::sleep_for(chrono::milliseconds(100));

        task1();
        task2();
    }
}

// Task 1: Globale Variable für den Zeitpunkt der letzten Ausführung
chrono::steady_clock::time_point t1 = chrono::steady_clock::now();

void task1() {
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    if (t2 - t1 < chrono::seconds(2)) return;
    t1 = t2;

    cout << ">> Task 1: Alle 2 Sekunden ..." << endl;
    
}

// Task 2: Statische Variable für den Zeitpunkt der letzten Ausführung
void task2() {
    static chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    if (t2 - t1 < chrono::seconds(3)) return;
    t1 = t2;

    cout << ">>>> Task 2: Alle 3 Sekunden ..." << endl;

}