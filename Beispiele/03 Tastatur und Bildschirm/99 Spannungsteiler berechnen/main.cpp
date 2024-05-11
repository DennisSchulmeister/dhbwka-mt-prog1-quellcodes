/***********************************************************************************************
 * Beispiel: Spannungsteiler berechnen
 * ===================================
 * 
 * Dies ist ein einfaches Beispiel, wie Zahlen von der Tastatur eingelesen und für einfache
 * Berechnungen verwendet werden können. Als Beispiel wird hier ein einfacher Spannungsteiler
 * berechnet, bei dem gilt: U1 / U2 = R1 / R2.
 ***********************************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char **argv) {
    cout << "Spannungsteiler berechnen" << endl;
    cout << "=========================" << endl;
    cout << endl;

    float u_ges, u1, u2, r1, r2;

    cout << "Gesamtspannung in Volt: ";
    cin >> u_ges;

    cout << "Gewünschte Teilspannung in Volt: ";
    cin >> u1;

    u2 = u_ges - u1;

    if (u2 < 0) {
        cerr << "Das geht physikalisch leider nicht. Außer Sie sind Gott!" << endl;
        return 1;
    }

    cout << "Erster Widerstand in Ohm: ";
    cin >> r1;

    r2 = (u2 * r1) / u1;

    cout << "Zweiter Widerstand in Ohm: " << fixed <<  setprecision(0) << r2 << endl;

    return 0;
}