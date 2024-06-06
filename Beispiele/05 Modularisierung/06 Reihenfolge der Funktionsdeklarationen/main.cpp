/***********************************************************************************************
 * Beispiel: Reihenfolge der Funktionsdeklarationen
 * ================================================
 * 
 * Wenn wir eine selbstdefinierte Funktion aufrufen, kann es manchmal passieren, dass sich das
 * Programm nicht compilieren lässt und der Compiler stattdessen folgenden Fehler meldet:
 *
 *    main.cpp: In function ‘int main(int, char**)’:
 *    main.cpp:31:5: error: ‘nach_main’ was not declared in this scope
 *       31 |     nach_main();
 *          |     ^~~~~~~~~
 *
 * Andere Funktionen lassen sich aber problemlos aufrufen. Woran kann das liegen? Der Grund ist
 * ziemlich einfach: Auch wenn es eine passende Funktion gibt, die zu dem Aufruf passt, hat sie
 * die Compiler bis zum Zeitpunkt ihrer Verwendung noch nicht gesehen und kennt sie daher noch
 * nicht. Das liegt daran, dass der Compiler den Quellcode von oben nach unten Zeile für Zeile
 * verarbeitet und deshalb nur Dinge kennen kann, die vor der gerade verarbeiteten Zeile stehen.
 * Die Funktion wird also erst weiter unten definiert und kann davor nicht verwendet werden.
 *
 * Die einfachste Möglichkeit, dieses Problem zu lösen, besteht darin, einfach die Reihenfolge
 * zu ändern und alle eigenen Funktionen an den Anfang des Programms vor der main-Funktion zu
 * platzieren. Ruft eine Funktion dabei eine andere Funktion auf, muss die gerufene Funktion
 * ebenfalls vor die rufende Funktion geschoben werden.
 *
 * In den meisten Fällen reicht das schon, um den Compiler zufrieden zu stellen. Jedoch hat es
 * den Nachteil, dass die bei Programmstart ausgeführte main-Funktion ganz zwangsläufig immer
 * ganz am Ende der Quellcodedatei steht. Eine andere Möglichkeit besteht deshalb darin, die
 * Reihenfolge nicht zu ändern, und stattdessen so genannte "Vorwärtsdeklarationen" an den
 * Anfang des Programms zu schreiben, um dem Compiler die Funktionen vorab bekannt zu machen.
 * Dies funktioniert ganz einfach: Man nimmt einfach die Funktionsdefinition und kopiert alles
 * vor der ersten geschweiften Klammer an den Anfang des Programms und beendet die Zeile mit
 * einem Semikolon.
 *
 * Haben wir zum Beispiel folgende Funktionen:
 *
 *     void sage_hallo() {
 *         // Quellcode hier
 *     }
 *
 *     double fm_osc(double f, double t) {
 *         // Quellcode hier
 *     }
 *
 * Dann können wir folgende Zeilen an den Anfang des Programms schreiben, um die Funktionen
 * vorab zu deklarieren:
 *
 *     void sag_hallo();
 *     double fm_osc(double f, double t);
 *
 * Anschließend können wir die Funktionen an jeder Stelle aufrufen, selbst, wenn die Funktionen
 * erst weiter unten vollständig definiert werden. Dies erlaubt es uns dann unter anderem, die
 * main-Funktion ganz oben vor den anderen Funktionen (aber nach deren Vorwärtsdeklarationen)
 * zu positionieren.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
using namespace std;


// Vorwärtsdeklaration der Funktion nach_main(), damit die Funktion auch schon vor ihrer
// Definition aufgerufen werden kann. Dies entspricht einfach der Signatur der Funktion,
// also allem vor der öffnenden geschweiften Klammer, gefolgt von einem Semikolon.
void nach_main();


// Diese Funktion benötigt keine Vorwärtsdeklaration, weil der erste Aufruf erst in einer
// Zeile darunter erfolgt.
void vor_main() {
    cout << "void vor_main(): Ich stehe vor der main-Funktion und brauche keine Vorwärtsdeklaration." << endl;
}


// Unsere gute alte main-Funktion
int main(int argc, char **argv) {
    cout << endl;

    vor_main();
    cout << "void main(): Ich bin die main-Funktion. Mich kennt ihr ja." << endl;
    nach_main();

    cout << endl;
}


// Der Aufruf dieser Funktion steht vor Funktion selbst. Sie benötigt daher eine Vorwärtsdeklaration
// am Anfang der Quellcodedatei.
void nach_main() {
    cout << "void nach_main(): Ich stehe nach der main-Funktion und brauche deshalb eine Vorwärtsdeklaration." << endl;
}