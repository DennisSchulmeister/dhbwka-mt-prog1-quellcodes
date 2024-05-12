/***********************************************************************************************
 * Beispiel: Tastatureingabe mit cin
 * =================================
 * 
 * Anstelle von scanf() verwendet man in C++ häufig das cin-Objekt für Tastatureingaben, analog
 * zu cout für Konsolenausgaben. Hier wird der >> Bit-Shift-Operator als "Eingaben von der
 * Tastatur reinschieben" umgedeutet. Dadurch fallen die lästigen Formatstrings von scanf()
 * weg. Ansonsten verhält sich das Programm aber genauso komisch bei Fehleingaben. Ebenso lassen
 * sich keine Strings mit Leerzeichen einlesen.
 *
 * Probieren Sie es aus! Geben Sie auch hier zunächst korrekte Werte und dann verschiedene
 * fehlerhafte Werte ein. Schon eigenartig, wie sich das Programm teilweise verhält. :-)
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
using namespace std;

int main(int argc, char **argv) {
    char   text[100];
    int    i_nr;
    double d_nr;

    cout << endl;
    
    cout << "Bitte ein Wort eingeben.........: ";
    cin >> text;

    cout << "Bitte eine Ganzzahl eingeben....: ";
    cin >> i_nr;

    cout << "Bitte eine Kommazahl eingeben...: ";
    cin >> d_nr;

    cout << endl;
    cout << "Folgendes haben Sie eingegeben:" << endl << endl;
    cout << "C-String....: " << text << endl;
    cout << "Ganzzahl....: " << i_nr << endl;
    cout << "Kommazahl...: " << d_nr << endl;
    cout << endl;
}