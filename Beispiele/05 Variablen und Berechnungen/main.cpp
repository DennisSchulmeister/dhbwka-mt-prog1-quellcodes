/***********************************************************************************************
 * Beispiel: Variablen und Berechnungen
 * ====================================
 * 
 * Dieses Beispiel zeigt, wie wir C/C++ als einen besseren "Taschenrechner" verwenden können.
 * indem wir einfach ein paar Variablen definieren und Formeln ausrechnen. Natürlich würde
 * man für solche einfachen Sachen normalerweiße nicht gleich ein Programm schreiben. Aber
 * Variablen und Berechnungen braucht man beim Programmieren doch immer wieder.
 ***********************************************************************************************/
#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecission
#include <cmath>        // sqrt

using namespace std;

int main(int argc, char **argv) {
    //////////////////////////////////////////////////////////
    //// Datentyp Float: Achtung! Reduzierte Genauigkeit! ////
    //////////////////////////////////////////////////////////

    // Umrechnung von Temperatur in Fahrenheit nach Celsius
    float t1_f = 77.0;
    float t1_c = (t1_f - 32) * (5 / 9);

    cout << to_string(t1_f) << " °F entspricht " << to_string(t1_c) << " °C." << endl;

    // Umrechnung von Celsius nach Fahrenheit
    float t2_c = 35.0;
    float t2_f = (t2_c * (9 / 5)) + 32;

    cout << to_string(t2_c) << " °C entspricht " << to_string(t2_f) << " °F." << endl;

    // Verdeutlichung der reduzierten Genauigkeit von Float
    float f = 0.1;
    cout << "0,1 als Float: " << setprecision(25) << f << " Ups!!" << endl;

    cout << endl;

    ///////////////////////////////////////////////////////////
    //// Datentype Double: Wesentlich bessere Genauigkeit! ////
    ///////////////////////////////////////////////////////////

    // Periodendauer eines Pendels berechnen
    const double pi = 4 * atan(1);
    const double g = 9.8;       // Gravitation auf der Erde: 9,8m/s²
    double l = 1.50;            // Länge in Metern
    double t = 2 * pi * sqrt(l / g);

    cout << "Die Periodendauer eines Pendels mit Länge " << l << " Meter: ";
    cout << setprecision(4) << t << " Sekunden." << endl;

    // Verdeutlichung der besseren Genauigkeit von Double, aber immer noch mit Rundungsfehler!
    // Manche Dezimalzahlen lassen sich nicht exakt binär codieren!
    double d = 0.1;
    cout << "0,1 als Double: " << setprecision(25) << d << " Hoppla!" << endl;

    return 0;
}