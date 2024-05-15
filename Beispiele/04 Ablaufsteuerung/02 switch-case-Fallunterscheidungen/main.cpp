/***********************************************************************************************
 * Beispiel: switch/case-Fallunterscheidungen
 * ==========================================
 * 
 * Liefert ein Ausdruck ein numerisches Ergebnis, das man mit mehreren Festwerten vergleichen
 * will, würde man das mit if/else typischereise so schreiben:
 *
 *    if (i == 0) ...
 *    else if (i == 1) ...
 *    else if (i == 2) ...
 *    else ...
 *
 * Alternativ kann der Quellcode mit der switch-Anweisung ohne die vielen Wiederholungen
 * geschrieben werden:
 *
 *     switch (i) {
 *         case 0: ...
 *         case 1: ...
 *         case 2: ...
 *         default: ...
 *     }
 *
 * Die allgemeine Syntax von switch/case ist daher:
 *
 *     switch (AUSDRUCK) {
 *         case KONSTANTE1:
 *             ANWEISUNG;
 *             ANWEISUNG;
 *             ...
 *             break;
 *
 *         case KONSTANTE2:
 *             ANWEISUNG;
 *             ANWEISUNG;
 *             ...
 *             break;
 *
 *         ...
 *
 *         default:
 *             ANWEISUNG;
 *             ANWEISUNG;
 *             ...
 *     }
 *
 * Dabei wird das Ergebnis von AUSDRUCK mit den Konstanten (genauer gesagt, Ausdrücke, die
 * einen konstanten, zur Compilierzeit bekannten Wert liefern) auf Gleichheit verglichen
 * und der erste zutreffende case-Zweig ausgeführt. Trifft keiner zu, wird der default-Zweig
 * ausgeführt. Wie immer kann der default-Zweig entfallen.
 *
 * DOCH VORSICHT: Am Ende eines case-Zweigs muss der switch-Block mit break verlassen werden.
 * Andernfalls führt das Programm auch die anderen Zweige darunter aus! Folgendes ist falsch:
 *
 *    switch (i) {
 *        case 0: cout << "Montag"   << endl;
 *        case 1: cout << "Dienstag" << endl;
 *        case 2: cout << "Mittwoch" << endl;
 *        ...
 *    }
 *
 * Das Programm würde bei i = 0 alle Wochentage ausgeben, bei i = 1 alle ab Dienstag usw.
 * Korrekt wäre stattdessen:
 *
 *    switch (i) {
 *        case 0:
 *            cout << "Montag" << endl;
 *            break;
 *        case 1:
 *            cout << "Dienstag" << endl;
 *            break;
 *        case 2:
 *            cout << "Mittwoch" << endl;
 *            break;
 *        ...
 *    }
 *
 * Allerdings kann dieses Verhalten auch erwünscht sein, wie in folgendem Beispiel:
 *
 *     switch (buchstabe) {
 *         case 'a':
 *         case 'A':
 *             cout << "Sie haben ein A eingegeben." << endl;
 *             break;
 *         case 'b':
 *         case 'B':
 *             cout << "Sie haben ein B eingegeben." << endl;
 *             break;
 *         default:
 *             cout << "Sie haben irgendetwas anderes eingegeben." << endl;
 *     }
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::string, std::getline, ...

using namespace std;

int main(int argc, char **argv) {
    cout << endl;

    for (int i = 0; i < 7; i++) {
        switch (i) {
            case 0:
                cout << "Montag" << endl;
                break;
            case 1:
                cout << "Dienstag" << endl;
                break;
            case 2:
                cout << "Mittwoch" << endl;
                break;
            case 3:
                cout << "Donnerstag" << endl;
                break;
            case 4:
                cout << "Freitag" << endl;
                break;
            default:
                cout << "Wochenende! 😎" << endl;
        }
    }

    cout << endl;
}