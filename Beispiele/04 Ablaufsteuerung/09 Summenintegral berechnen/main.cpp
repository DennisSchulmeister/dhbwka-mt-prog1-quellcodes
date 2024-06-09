/***********************************************************************************************
 * Beispiel: Summenintegral berechnen
 * ==================================
 * 
 * Dieses Beispiel zeigt ein weiteres Fallbeispiel für Schleifen und Bedingungen. Die numerische
 * Berechnung des Summenintegrals. Das Lernziel hierbei ist, dass sich manche komplexen Dinge
 * numerisch auf Schleifen und Summen reduzieren lassen, da wir sowieso nicht "mathematisch
 * korrekt" mit unendlich kleinen Schritten rechnen können.
 *
 * Ein Integral ist definiert als der Flächeninhalt zwischen einer Funktion und der X-Achse.
 * In der numerischen Integration zerlegen wir die Funktion daher ein eine endliche Anzahl
 * kleiner Teilstücke und berechnen dann immer die Rechteckfläche unterhalb der Teilstücke.
 * Dies wird Summenintegral genannt, da wir einfach nur die Rechteckflächen aufaddieren müssen.
 * Je kleiner die Schrittweite (Breite der Teilstücke) ist, desto mehr nähern wir uns dem
 * tatsächlichen Integral an.
 *
 *     ⮝
 *     │        ┌──┐
 *     │        │░░│
 *     │     ┌──┤░░│
 *     │     │░░│░░├──┐
 *     │     │░░│░░│░░│
 *     │  ┌──┤░░│░░│░░│
 *     │  │░░│░░│░░│░░├──┐
 *     ├──┤░░│░░│░░│░░│░░├──┐
 *     │░░│░░│░░│░░│░░│░░│░░│
 *     └─────────────────────➤
 *
 * Die erste Schleife berechnet die Funktion f(x) = (x-2)³ + 2(x-2)² sowie ihr Summenintegral.
 * Die Werte werden in den beiden Vektoren f und f1 abgelegt, um in der zweiten Schleife
 * als ASCII-Grafik angezeigt zu werden.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::string, std::getline, ...
#include <vector>       // std::vector
#include <cmath>        // pow (Potenz, englisch: power)

using namespace std;

constexpr double x_max = 2.5;       // Obere Grenze von x für die Berechnung
constexpr double x_min = 0;         // Untere Grenze von x für die Berechnung
constexpr double y_max = 1.5;       // Obere Grenze von y für den Plot
constexpr double y_min = 0;         // Untere Grenze von y für den Plot
constexpr double step  = 0.05;      // Intervallgröße für Berechnung und Plot


int main(int argc, char **argv) {
    //---------------------------------------//
    // Funktionswerte und Integral berechnen //
    //---------------------------------------//
    vector<double> f, f1;
    double y1 = 0.0;

    for (double x = x_min; x <= x_max; x += step) {
        // Funktionswerte y berechnen und speichern
        double y = pow(x-2, 3) + 2 * pow(x-2, 2);
        f.push_back(y);

        // Summenintegral y1 berechnen und speichern
        y1 += y * step;
        f1.push_back(y1);
    }

    //----------------------------------------------------//
    // Pseudo-grafische Anzeige der Werte auf der Konsole //
    //----------------------------------------------------//
    cout << endl;

    for (double y_axis = y_max; y_axis >= y_min; y_axis -= step) {
        for (int i = 0; i < f.size(); i++) {
            double y  = f.at(i);
            double y1 = f1.at(i);
            char   c  = ' ';

            if (y <= y_axis && y >= y_axis - step) {
                c = '*';
            }
            
            if (y1 <= y_axis && y1 >= y_axis - step) {
                if (c == ' ') c = '#';
                else c = 'X';
            }

            cout << c;
        }

        cout << endl;
    }

    cout << endl;
}
