/***********************************************************************************************
 * Aufgabe: DIN-Blattgrößen
 * ========================
 * 
 * Ein Blatt der Größe DIN A0 hat die Maße 841 × 1189 mm, was in etwa 1 m² im Seitenverhältnis
 * 5:7 bzw. genau 1∶√2 entspricht. Für die nächst kleineren Formate (DIN A1, DIN A2, …) halbiert
 * man jeweils die längere Seite.
 *
 * Schreiben Sie ein Programm, dass ausgehend von DIN A0 alle Maße bis DIN A9 ausrechnet und
 * tabellarisch auf der Konsole ausgibt. Die Programmausgabe soll in etwa so aussehen:
 *
 *     Format  Breite  Länge
 *     ======  ======  =====
 *
 *     DIN A0  841     1189
 *     DIN A1  595      841
 *     DIN A2  420      595
 *     ...
 *
 * HINWEIS: Am einfachsten nutzen Sie eine for-Schleife, die von null bis neun zählt sowie
 * zwei außerhalb der Schleife definierte Variablen für Breite und Länge. Pluspunkte gibt es
 * für die rechtsbündige Ausrichtung der Zahlen.
 *
 * Verwenden Sie Integer-Variablen für die Berechnung. Die Ergebnisse können Sie auf Wikipedia
 * überprüfen: https://de.wikipedia.org/wiki/Papierformat#ISO-_und_DIN-Papierformate
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecision
#include <string>       // std::string, std::getline, ...

using namespace std;

int main(int argc, char **argv) {
}