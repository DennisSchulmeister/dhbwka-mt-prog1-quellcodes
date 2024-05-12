/***********************************************************************************************
 * Beispiel: Tastatureingabe korrekt
 * =================================
 * 
 * Dies ist dasselbe Beispiel wie davor. Doch hier werden auch grob falsche Eingaben, wie die
 * Eingabe von Text statt einer Zahl abgefangen. Hierzu wird mit try/catch eine sogenannte
 * Ausnahme abgefangen, die die stoX()-Funktionen werfen, wenn sie einen String nicht verstehen.
 * Hierfür werden die entsprechenden Zeilen mit try/catch eingerahmt, wie unten gezeigt.
 *
 * Das Beispiel zeigt zwei Varianten:
 *
 *   1) Einfache alle Arten von Fehlern abfangen, da sowieso nur Fehleingaben vorkommen können.
 *   2) Genau die Art von Fehler abfangen, die hier tatsächlich auftritt.
 *
 * Variante 2 ist eher für große Programme relevant, in denen viel mit unterschiedlichen Arten
 * von Exceptions gearbeitet wird. Für unsere Zwecke ist es egal, welche Variante Sie nutzen.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::getline

using namespace std;

int main(int argc, char **argv) {
    // Hilfsvariablen
    string buffer;
    int    i_nr;
    double d_nr;

    cout << endl;
    
    // Ganzzahl einlesen mit Fehlerbehandlung.
    // Variante 1: Es werden einfach alle Arten von Fehler abgefangen
    try {
        cout << "Bitte eine Ganzzahl eingeben....: ";
        getline(cin, buffer);
        i_nr = stoi(buffer);
    } catch (...) {
        cerr << "FEHLER! Sie haben keine Ganzzahl eingeben." << endl;
    }

    // Kommazahl einlesen mit Fehlerbehandlung.
    // Variante 2: stoX() wirft immer eine invalid_argument-Exception
    try {
        cout << "Bitte eine Kommazahl eingeben...: ";
        getline(cin, buffer);
        d_nr = stod(buffer);
    } catch (invalid_argument &err) {
        cerr << "FEHLER: " << err.what() << "  - Sie haben keine Kommazahl eingegeben!" << endl;
    }

    // Eingelesene Werte anzeigen
    cout << endl;
    cout << "Folgendes haben Sie eingegeben:" << endl << endl;
    cout << "Ganzzahl....: " << i_nr << endl;
    cout << "Kommazahl...: " << d_nr << endl;
    cout << endl;
}