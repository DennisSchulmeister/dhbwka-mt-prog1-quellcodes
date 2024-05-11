/***********************************************************************************************
 * Beispiel: Kommazahlen mit einfacher Genauigkeit (float)
 * =======================================================
 * 
 * Dieses Beispiel zeigt, wie wir C/C++ als einen besseren "Taschenrechner" verwenden können.
 * indem wir einfach ein paar Variablen definieren und Formeln ausrechnen. Hierbei verwenden
 * wir Kommazahlen mit einfacher Genauigkeit vom Typ float. Diese sind 4 Byte groß und zeigen
 * daher wesentlich öfters Rundungsfehler als Kommazahlen vom Typ double.
 ***********************************************************************************************/
#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecission

using namespace std;

int main(int argc, char **argv) {
    // Umrechnung von Temperatur in Fahrenheit nach Celsius
    float t1_f = 77.0;
    float t1_c = (t1_f - 32) * (5 / 9);

    cout << t1_f << " °F entspricht " << t1_c << " °C." << endl;

    // Umrechnung von Celsius nach Fahrenheit
    float t2_c = 35.0;
    float t2_f = (t2_c * (9 / 5)) + 32;

    cout << t2_c << " °C entspricht " << t2_f << " °F." << endl;

    // Verdeutlichung der reduzierten Genauigkeit von Float
    float f = 0.1;
    cout << "0,1 als Float: " << setprecision(25) << f << " Ups!" << endl;
}