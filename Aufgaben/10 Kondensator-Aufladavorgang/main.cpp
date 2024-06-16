/***********************************************************************************************
 * Aufgabe: Kondensator-Aufladevorgang
 * ===================================
 *
 * Der Kondensator gehört zu den wichtigsten Bauteilen der Elektronik, da wie ein kleiner Akku
 * Ladungen speichern und wieder abgeben kann. Seine Ladung baut sich stetig auf, wenn man über
 * einen Vorwiderstand eine Spannung angelegt wird und baut sich in umgekehrter Richtung wieder
 * ab, wenn die Spannung entfernt wird. Das zeitliche Verhalten kann mit folgenden Parametern
 * berechnet werden:
 * 
 *   C = Kapazität des Kondensators in Farad (F)
 *   R = Widerstand der umliegenden Schaltung in Ohm (Ω)
 *   U = Angelegte Spannung in Volt (V)
 * 
 * Die maximale Ladung des Kondensators ist: Qmax = C × |U|
 * Die zeitabhängige Ladung während des Aufladevorgangs: Q(t) = Qmax × (1 - e^(-t/RC))
 * 
 * Zeit t in Sekunden, Ladung Q in Coulomb. Das ^-Zeichen steht hier für die Potenz.
 * In C++ können Sie hierfür die Funktion std::exp aus dem Include <cmath> verwenden.
 * exp(n) berechnet "e hoch n" und exp(-t / R / C) berechnet "e hoch (-t/RC)".
 * 
 * Gute Werte zum Visualisieren dieser Formel sind: C = 0,05; R = 10, U = 5. Gemäß der
 * Formel 𝜏 = R×C erreicht der Kondensator hier nach 0,5 Sekunden ca. 63% der Ladung,
 * so dass es genügt, das Interval t = [0…3] zu plotten, um den Verlauf zu visualisieren.
 * 
 * Siehe: https://www.desmos.com/calculator/l5v1zlizdw
 * Oder Datei: Simulation in Desmos.png
 * 
 * HINWEIS: Es genügt, wenn Sie nur die letzte Version des Programms in Moodle zur Bewertung
 * hochladen. Wenn Sie so vorgehen, wie unten beschrieben, lassen sich die alten Versionen
 * anhand der auskommentierten Quellcodezeilen trotzdem nachvollziehen.
 *
 * a) Zwei Funktionen
 * ------------------
 * 
 * Schreiben Sie ein Programm, das die Werte für C, R und U abfragt und anschließend Q(t)
 * für das Intervall [0…3] in 0,1er-Schritten auf der Konsole ausgibt. Die Ausgabe soll im
 * CSV-Format erfolgen, so dass die Werte beispielsweise in Excel visualisiert werden könnten:
 * 
 *     t ; Q(t)
 *     0 ; 0
 *     0.1 ; 0.04531
 *     0.2 ; 0.08242
 *     ...
 * 
 * Teilen Sie die Logik in unterschiedliche Funktionen auf:
 * 
 *   1) main-Funktion: Abfrage der Parameter und Hauptschleife des Programms
 *   2) Eine Funktion zum Ausrechnen von Q(t) für ein gegebenes t, R, C und U
 *   3) Eine Funktion zum Ausgeben einer CSV-Zeile
 * 
 * Beachten Sie, dass C, R und U der zweiten Funktion als Parameter übergeben werden müssen.
 * Verwenden Sie keine globalen Variablen. Zusätzlich sollen Funktion zwei und drei NACH der
 * main-Funktion implementiert werden, so dass Sie entsprechende Vorwärtsdeklarationen in das
 * Programm einbauen müssen.
 * 
 * b) C-Arrays
 * -----------
 * 
 * Kommentieren Sie die Schleife in der der main-Funktion aus und ersetzen diese durch eine
 * neue Version:
 * 
 *     int main(int argc, char **argv) {
 *        Quellcode zur Abfrage der Werte
 * 
 *        // // Variante a: Zwei Funktionen
 *        // ...
 *        // ... alter Quellcode ...
 *        // ...
 * 
 *        // Variante b: C-Arrays
 *        Neuer Quellcode hier
 *     }
 * 
 * Ändern Sie die main-Funktion stattdessen so ab, dass die errechneten Werte erst in ein C-Array
 * mit 30 Elementen geschrieben werden. Anschließend sollen in einer zweiten Schleife die im Array
 * gespeicherten Werte wie gehabt auf der Konsole ausgegeben werden. Das Array können Sie wie folgt
 * deklarieren:
 * 
 *     constexpr int N  = 30;
 *     double values[N] = {};
 * 
 * c) std::vector
 * --------------
 * 
 * Kommentieren Sie auch den obigen Quellcode der main-Funktion aus und ersetzen ihn durch eine
 * neue Variante, die statt einem C-Array einen std::vector verwendet. Diesen können Sie wie
 * folgt deklarieren:
 * 
 *     vector<double> values = {};
 * 
 * d) Struktur in Vektor
 * ---------------------
 * 
 * Für diese Version müssen Sie den Quellcode nicht auskommentieren. Ändern sie ihn aber so ab,
 * dass eine Struktur mit den beiden Werten t und q im Vektor abgelegt werden, die jeweils für
 * die Zeit und die Ladung des Kondensators stehen:
 * 
 *     struct value_t {
 *         double t;
 *         double q;
 *     };
 *
 * Die Konsolenausgabe soll dementsprechend die beiden Werte aus der Struktur verwenden. 
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecision
#include <string>       // std::string, std::getline, ...
#include <cmath>        // pow, sin, ...
#include <cstdlib>      // rand
#include <fstream>      // std::ifstream, std::ofstream, ...
#include <vector>       // std::vector

using namespace std;

int main(int argc, char **argv) {
}