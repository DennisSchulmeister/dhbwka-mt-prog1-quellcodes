/***********************************************************************************************
 * Aufgabe: Funktionen plotten als CSV-Datei
 * =========================================
 *
 * c) In der finalen Ausbaustufe soll das Programm die berechneten Werte wahlweise in eine
 * CSV-Datei schreiben können, damit sie beispielsweise in einer Tabellenkalkulation
 * weiterverarbeitet werden können. Die Konsolenausgabe ändert sich dadurch zu:
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
 *       Ende bei x = 12.8
 *     Schrittweite = 0.01
 *        Dateiname = sin_noise.csv
 *
 * Wird kein Dateiname eingegeben, sollen die Zahlen wie bisher auf der Konsole ausgegeben
 * werden. Andernfalls, können Sie sie mit folgenden Zeilen in eine CSV-Datei schreiben
 * (CSV = Comma-Separated Value, wobei ein Semikolon gebräuchlicher ist).
 *
 *     // Zu schreibende Datei öffnen
 *     string filename = "test.csv";
 *
 *     ofstream file;
 *     file.open(filename);
 *
 *     // Kopfzeile in die Datei schreiben
 *     file << "x;y" << endl;
 *
 *     // Variablen x und y in die Datei schreiben
 *     file << x << ";" << x << endl;
 *
 *     // Datei ordentlich schließen
 *     file.close();
 *
 * Plotten Sie die Funktionen mit einer Tabellenkalkulation Ihrer Wahl als Liniendiagramm.
 * Achten Sie dabei allerdings darauf, dass die Zahlen korrekt importiert und auch tatsächlich
 * als Zahlen erkannt werden. :-)
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
    return sin(x) + (1.0 * rand() / RAND_MAX / 3);
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
    string filename;
    ofstream file;

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

        cout << "   Dateiname = ";
        cin >> filename;
    } catch (...) {
        cerr << "Scherzkeks! Bitte gültige Zahlen eingeben ...";
        return -1;
    }

    if (filename.empty()) {
        cout << endl;
        cout << setw(5) << "x" << " ";
        cout << setw(5) << "y" << endl;
        cout << "===== =====" << endl;
        cout << endl;
    } else {
        file.open(filename);
        file << "x;y" << endl;
    };

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

        if (filename.empty()) {
            cout << setprecision(3) << fixed;
            if (x >= 0) cout << " ";
            cout << setw(5) << x << " ";
            if (y >= 0) cout << " ";
            cout << setw(5) << y << endl;
        } else {
            file << x << ";" << y << endl;
        }
    }

    if (filename.empty()) file.close();
}