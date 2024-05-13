/***********************************************************************************************
 * Beispiel: Tastatureingabe mit getline
 * =====================================
 * 
 * Die Probleme mit scanf() und cin bei ungültigen Tastatureingaben lassen sich mit getline()
 * und ein paar Hilfsfunktionen wie stoi(), stod() usw. weitgehend lösen. getline() liest dabei
 * immer eine vollständige Zeile ein, die vor dem mit ENTER ausgelösten Zeilenumbruch endet.
 * Die Funktionen stoX() interpretieren diesen String dann, entsprechend dem letzten Buchstaben
 * in ihrem Namen als Integer, Float, Double, etc. Eselsbrücke: String to X
 *
 * Dadurch ist das Programm wesentlich robuster bei Fehleingaben. Ein kleines Problem gibt es
 * allerdings noch, das wir erst im nächsten Beispiel lösen werden. Aber probieren Sie es
 * ruhig aus. Was macht das Programm bei einfachen Fehleingaben (Komma- statt Ganzzahl)?
 * Und was macht es bei grob falschen Eingaben (Text statt Zahl)?
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::string, std::getline, ...

using namespace std;

int main(int argc, char **argv) {
    string text;
    string buffer;
    int    i_nr;
    double d_nr;

    cout << endl;
    
    cout << "Bitte einen Text eingeben.......: ";
    getline(cin, text);

    cout << "Bitte eine Ganzzahl eingeben....: ";
    getline(cin, buffer);
    i_nr = stoi(buffer);

    cout << "Bitte eine Kommazahl eingeben...: ";
    getline(cin, buffer);
    d_nr = stod(buffer);

    cout << endl;
    cout << "Folgendes haben Sie eingegeben:" << endl << endl;
    cout << "C++-String..: " << text << endl;
    cout << "Ganzzahl....: " << i_nr << endl;
    cout << "Kommazahl...: " << d_nr << endl;
    cout << endl;
}