/***********************************************************************************************
 * Beispiel: Vorwärtsdeklaration richtig
 * =====================================
 * 
 * Im vorherigen Beispiel haben wir gesehen, dass der Compiler eine Vorwärtsdeklaration von
 * Funktionen benötigt, wenn diese bereits vor ihrer Definition weiter oben im Quellcode
 * aufgerufen werden sollen. Doch wie soll man dabei konkret vorgehen? Wann soll man eine
 * Vorwärtsdeklaration an welcher Stelle im Quellcode einbauen und wann soll man stattdessen
 * einfach die Reihenfolge der Funktionsdeklarationen ändern?
 *
 * Natürlich gibt es hier keine absoluten Wahrheiten, denn diese gibt es bekanntlich nur in der
 * Mathematik (und auch da wäre ich mir nicht immer sicher). Dennoch lassen sich auf diese
 * Fragen überraschend einfache Antworten finden:
 *
 *   1. Funktionen, die thematisch zusammengehören, sollten zusammen stehen. Die Reihenfolge
 *      ist dabei letztlich egal bzw. sollte so gewählt werden, dass man die Funktionsweise
 *      gut nachvollziehen kann. Hilfsfunktionen stehen deshalb meist nach der Funktion, in
 *      der sie am meisten genutzt werden.
 *
 *   2. Um das Reihenfolgeproblem zu vermeiden, legt man einfach für JEDE Funktion, mit Ausnahme
 *      der main-Funktion, eine Vorwärtsdeklaration an.
 *
 *   3. Vorwärtsdeklarationen stehen immer am Anfang des Quellcodes vor der ersten richtigen
 *      Funktionsdefinition.
 *
 * Mit diesen Regeln müssen wir uns um Reihenfolgeprobleme von Funktionen niemals Gedanken
 * machen. Und gleichzeitig sind wir darauf vorbereitet, größere Programme, wie im nächsten
 * Beispiel gezeigt, in mehrere Quellcode-Dateien zu gliedern.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::string, std::getline, ...
#include <cstdlib>      // rand
#include <ctime>        // time
#include <cassert>      // assert

using namespace std;


// Vorwärtsdeklarationen aller Funktionen
int get_random_number();
string get_random_message();


int main(int argc, char **argv) {
    cout << endl;
    cout << get_random_message() << endl;
    cout << endl;
}


string get_random_message() {
    int nr = get_random_number();
    assert(nr >= 0 && nr <= 2);

    switch (nr) {
        case 0:   return "Hallo!";
        case 1:   return "Wie geht es Ihnen?";
        case 2:   return "Was wollen Sie heute machen?";

        // Fehlermeldung beim Compilieren unterdrücken. Durch den assert() oben ist
        // bereits sichergestellt, dass der Fall nie eintreten kann. Falls doch,
        // stürzt das Programm unter Angabe der Quellcodezeile ab.
        default:  return "";
    }
}


// Steht zur Verdeutlichung absichtlich nach ihrer Verwendung
int get_random_number() {
    srand(time(nullptr));
    return rand() % 3;
}