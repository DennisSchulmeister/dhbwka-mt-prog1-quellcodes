/***********************************************************************************************
 * Aufgabe: Funktionen plotten als CSV-Datei
 * =========================================
 *
 * a) In der ersten Version soll das Programm die Werte der Funktion y = 2x² + x³ - ½ berechnen
 * und tabellarisch ausgeben. Dabei sollen der Wertebereich von x sowie die Schrittweite am
 * Anfang abgefragt werden werden. Ein beispielhafter Ablauf könnte daher so aussehen:
 *
 *     Beginn bei x = -3
 *       Ende bei x = 1.5
 *     Schrittweite = 0.1
 *
 *         x     y
 *     ===== =====
 *
 *     -3.000 -9.500
 *     -2.900 -8.069
 *     -2.800 -6.772
 *     …
 *
 * HINWEIS: Nutzen Sie folgenden Code, um die Ausgabe zu formatieren:
 *
 *    cout << setprecision(3) << fixed;
 *    if (x > 0) cout << " ";
 *    cout << setw(5) << x << " ";
 *    if (y > 0) cout << " ";
 *    cout << setw(5) << y << endl;
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecision
#include <string>       // std::string, std::getline, ...
#include <cmath>        // pow, sin, ...
#include <cstdlib>      // rand
#include <fstream>      // std::ifstream, std::ofstream, ...

using namespace std;

int main(int argc, char **argv) {
    // Benutzereingaben abfragen
    double x_min, x_max, x_step;

    try {
        string buffer;
        cout << endl;

        cout << "Beginn bei x = ";
        cin >> buffer;
        x_min = stod(buffer);

        cout << "  Ende bei x = ";
        cin >> buffer;
        x_max = stod(buffer);

        cout << "Schrittweite = ";
        cin >> buffer;
        x_step = stod(buffer);
    } catch (...) {
        cerr << "Scherzkeks! Bitte gültige Zahlen eingeben ...";
        return -1;
    }

    cout << endl;
    cout << setw(5) << "x" << " ";
    cout << setw(5) << "y" << endl;
    cout << "===== =====" << endl;
    cout << endl;

    if (x_min > x_max) swap(x_min, x_max);

    // Funktionswerte berechnen und ausgeben
    for (double x = x_min; x < x_max; x+= x_step) {
        double y = 2 * pow(x, 2) + pow(x, 3) - 0.5;
                
        cout << setprecision(3) << fixed;
        if (x >= 0) cout << " ";
        cout << setw(5) << x << " ";
        if (y >= 0) cout << " ";
        cout << setw(5) << y << endl;
    }
}