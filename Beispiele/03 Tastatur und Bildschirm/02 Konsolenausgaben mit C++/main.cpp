/***********************************************************************************************
 * Beispiel: Konsolenausgaben mit C++
 * ==================================
 * 
 * Obwohl die von C stammende printf()-Funktion in C++ ebenfalls verfügbar ist, wird dort meist
 * mit dem cout-Objekt gearbeitet, um Daten auf der Konsole auszugeben. Dieses überschreibt den
 * << Bit-Shift-Operator mit einer Logik, die "Wert auf die Konsole schiebt". Die Werte werden
 * dabei automatisch ihrem Datentyp entsprechend formatiert, wobei die Formatierung angepasst
 * werden kann. Welche Variante man besser oder leserlicher findet, ist Geschmackssache. :-)
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
using namespace std;

int main(int argc, char **argv) {
    cout << endl << "Textausgabe mit cout in C++. Die Sensation! :-)" << endl << endl;

    char   text[] = "Hallo Konsole!";
    int    i_nr   = 4711;
    double d_nr   = 8.15;

    cout << "C-String....: " << text << endl;
    cout << "Ganzzahl....: " << i_nr << endl;
    cout << "Kommazahl...: " << d_nr << endl;
    cout << endl;
}