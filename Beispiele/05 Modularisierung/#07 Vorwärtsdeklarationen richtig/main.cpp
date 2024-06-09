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

using namespace std;

int main(int argc, char **argv) {
}