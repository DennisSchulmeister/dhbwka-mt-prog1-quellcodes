/***********************************************************************************************
 * Beispiel: Kommazahlen mit doppelter Genauigkeit (double)
 * ========================================================
 * 
 * Dieses Beispiel verwendet Kommazahlen mit doppelter Genauigkeit vom Typ double, um eine
 * physikalische Formel auszurechnen. Variablen vom Typ double sind 8 Bate groß und zeigen
 * daher weniger Rundingsfehler als einfach-genaue Zahlen vom Typ float. Sie sind dem Typ
 * float daher vorzuziehen, wenngleich sich die Rundingsfehler auch hier schnell beträchtlich
 * aufaddieren können!
 ***********************************************************************************************/
#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecission
#include <cmath>        // sqrt

using namespace std;

int main(int argc, char **argv) {
    // Periodendauer eines Pendels berechnen
    const double pi = 4 * atan(1);
    const double g = 9.8;       // Gravitation auf der Erde: 9,8m/s²
    double l = 1.50;            // Länge in Metern
    double t = 2 * pi * sqrt(l / g);

    cout << "Die Periodendauer eines Pendels mit Länge " << l << " Meter: ";
    cout << setprecision(4) << t << " Sekunden." << endl;

    // Verdeutlichung der besseren Genauigkeit von Double, aber immer noch mit Rundungsfehler!
    // Manche Dezimalzahlen lassen sich eben nicht exakt binär codieren!
    double d = 0.1;
    cout << "0,1 als Double: " << setprecision(25) << d << " Hoppla!" << endl;
}