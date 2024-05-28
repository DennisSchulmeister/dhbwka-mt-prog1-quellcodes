/***********************************************************************************************
 * Aufgabe: Funktionen plotten als CSV-Datei
 * =========================================
 *
 * b) In der zweiten Version soll das Programm unterschiedliche Funktionen plotten können.
 * Definieren Sie hierfür ein sog. Unterprogramm (tatsächlich auch Funktion genannt) mit
 * folgendem Quellcode:
 *
 *     double polynom(double x) {
 *         return 2 * pow(x, 2) + pow(x, 3) - 0.5;
 *     }
 *
 * Hier wird eine C/C++-Funktion mit dem Namen "polynom" definiert, die einen Parameter vom Typ
 * double mit dem Namen "x" übergeben bekommt und einen double-Wert als Ergebnis liefert.
 * Dort, wo bisher die Berechnung der Formal stand, können Sie stattdessen die neue Funktion
 * aufrufen. In etwa so:
 *
 *     double y = polynom(x);
 *
 * Definieren Sie auf dieselbe Weise drei weitere Funktionen für folgende Formeln:
 *
 *     * Sinus mit Rauschen: sin(x) + (1.0 * rand() / RAND_MAX / 3);
 *     * Sinus mit Schwebung: sin(5 * x) + sin(5.5 * x);
 *     * Fouriersynthese (Sägezahn): 
 *
 *        30
 *         ⎲
 *         | sin(n * x * sign) / n 
 *         ⎳
 *         n=1
 *
 *         Bei ungeraden n muss sign = 1, bei geraden n muss sign = -1 sein.
 *
 * Ändern Sie das Programm anschließend so ab, dass die zu berechnende Funktion beim Start
 * abgefragt wird. In etwa so:
 *
 *     ================
 *     Funktionsplotter
 *     ================
 *     
 *     [1] Polynom 3ten Grades
 *     [2] Sinus mit Rauschen
 *     [3] Sinus mit Schwebung
 *     [4] Fouriersynthese (Sägezahn)
 *
 *         Funktion = 2
 *     Beginn bei x = 0
 *       Ende bei x = 3.2
 *     Schrittweite = 0.1
 *     
 *         x     y
 *     ===== =====
 *     
 *      0.000  0.000
 *      0.100  0.100
 *      0.200  0.199
 *      …
 *
 * Hierfür benötigen Sie eine if- oder switch/case-Anweisung in der Berechnungsschleife.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecision
#include <string>       // std::string, std::getline, ...
#include <cmath>        // pow, sin, ...
#include <cstdlib>      // rand, RAND_MAX
#include <fstream>      // std::ifstream, std::ofstream, ...

using namespace std;

double polynom(double x) {
    return 2 * pow(x, 2) + pow(x, 3) - 0.5;
}

double sin_noise(double x) {
    return sin(x) + (rand() / RAND_MAX / 10);
}

double sin_beating(double x) {
    return sin(5 * x) + sin(5.5 * x);
}

double fourier_sawtooth(double x) {
    double y = 0.0;
    int sign = -1;

    for (int n = 1; n < 30; n++) {
        sign *= -1;
        y += sin(n * x * sign) / n;
    }

    return y;
}

int main(int argc, char **argv) {
    // Benutzereingaben abfragen
    double x_min, x_max, x_step;
    int function;

    try {
        string buffer;
        cout << endl;

        cout << "================" << endl;
        cout << "Funktionsplotter" << endl;
        cout << "================" << endl;
        cout << endl;
        cout << "[1] Polynom 3ten Grades" << endl;
        cout << "[2] Sinus mit Rauschen" << endl;
        cout << "[3] Sinus mit Schwebung" << endl;
        cout << "[4] Fouriersynthese (Sägezahn)" << endl;
        cout << endl;

        cout << "    Funktion = ";
        cin >> buffer;
        function = stoi(buffer);

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
        double y;

        switch (function) {
            case 1:
                y = polynom(x);
                break;
            case 2:
                y = sin_noise(x);
                break;
            case 3:
                y = sin_beating(x);
                break;
            case 4:
                y = fourier_sawtooth(x);
                break;
            default:
                cerr << "Unbekannte Funktion!" << endl;
                return -1;
        }
                
        cout << setprecision(3) << fixed;
        if (x >= 0) cout << " ";
        cout << setw(5) << x << " ";
        if (y >= 0) cout << " ";
        cout << setw(5) << y << endl;
    }
}