/***********************************************************************************************
 * Beispiel: if-Fallunterscheidungen
 * =================================
 * 
 * Bei den einfachen Datentypen haben wir bereits gesehen, wie sich mit der Booleschen Logik
 * Ausdrücke definieren lassen, die true oder false (einen sog. Wahrheitswert) als Ergebnis
 * liefern. Diese können mit der if-Anweisung genutzt werden, um einzelne Teile eines Programms
 * nur dann auszuführen, wenn ein bestimmte Bedingung zutrifft.
 *
 * if und else sind die Arbeitspferde für Fallunterscheidungen. Dieses Programm zeigt, wie sie
 * funktionieren am Beispiel des Hooke'schen Gesetzes zur Dehnung einer Feder.
 *
 * Die allgemeine Syntax von if/else ist:
 *
 *    if (AUSDRUCK) ANWEISUNG1;
 *    else ANWEISUNG2;
 *
 * Ergibt der AUSDRUCK den Wert true, wird ANWEISUNG1 ausgeführt. Andernfalls ANWEISUNG2.
 * Der else-Zweig kann dabei auch entfallen, wenn er nicht benötigt wird.
 *
 * Üblicherweise werden ANWEISUNG1 und ANWEISUNG2 darüber hinaus als Codeblöcke in geschweiften
 * Klammern geschrieben, da somit mehrere Anweisungen ausgeführt werden können. Zum Beispiel:
 *
 *    if (AUSDRUCK) {
 *        ANWEISUNG;
 *        ANWEISUNG;
 *        ANWEISUNG;
 *    }
 *
 * Da if selbst auch eine Anweisung ist, können mehrere if-Abfragen kombiniert werden, so dass
 * mehrere Bedingungen nacheinander geprüft werden:
 *
 *    if (AUSDRUCK1) ANWEISUNG1;
 *    else if (AUSDRUCK2) ANWEISUNG2;
 *    else if (AUSDRUCK3) ANWEISUNG3;
 *    else ANWEISUNG4;
 *
 * Dabei werden die Ausdrücke in der angegebenen Reihenfolge ausgewertet und entweder ANWEISUNG1,
 * ANWEISUNG2, ANWEISUNG3 oder ANWEISUNG4 ausgeführt. Typischerweise sieht das so aus:
 *
 *    if (AUSDRUCK1) {
 *        ...
 *    } else if (AUSDRUCK2) {
 *        ...
 *    } else if (AUSDRUCK3) {
 *        ...
 *    } else {
 *        ...
 *    }
 *
 * Der Quellcode unten zeigt noch eine Besonderheit: Die Verwendung des ternären Operators ?:
 * bei den Variablendeklarationen in den Zeilen 72, 77 und 82. Er ist wie folgt definiert:
 *
 *    AUSDRUCK1 ? AUSDRUCK2 : AUSDRUCK3
 *
 * Ergibt AUSDRUCK1 den Wert true, wird AUSDRUCK2 ausgewertet und als Ergebnis zurück geliefert.
 * Andernfalls wird AUSDRUCK3 ausgewertet und als Ergebnis zurückgeliefert.
 *
 * In den genannten Zeilen wird dies genutzt, um zu erkennen, ob ein Wert eingebeben wurde.
 * Falls nein (buffer.compare("") == 0 ergibt true), werden die Variablen mit einem Default-Wert
 * initialisiert. Andernfalls mit der als double interpretierten Eingabe.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::getline

using namespace std;

int main(int argc, char **argv) {
    try {
        string buffer;

        cout << endl;
        cout << "Dehnung einer Feder" << endl;
        cout << "===================" << endl;
        cout << endl;

        // Federkonstante eingeben
        cout << "Federkonstante in N/m [52.0].......: ";
        getline(cin, buffer);
        double k = buffer.compare("") == 0 ? 52.0 : stod(buffer);   // Zuweisung mit ternärem ?: Operator

        // Maximale Dehnung der Feder eingeben
        cout << "Maximaler Federweg in m [0.33].....: ";
        getline(cin, buffer);
        double x_max = buffer.compare("") == 0 ? 0.33 : stod(buffer);   // Zuweisung mit ternärem ?: Operator

        // Gewicht eingeben
        cout << "Gewicht an der Feder in kg [1.5]...: ";
        getline(cin, buffer);
        double m = buffer.compare("") == 0 ? 1.5 : stod(buffer);   // Zuweisung mit ternärem ?: Operator

        // Auslenkung der Feder berechnen
        constexpr double g = 9.81;
        double F = m * g;
        double x = F / k;

        cout << endl;
        cout << "Berechnete Auslenkung der Feder....: " << x << " m" << endl;
        cout << "Zustand der Feder..................: ";

        if (x <= x_max * 0.75) {
            cout << "Kein Problem 🙂" << endl;
        } else if (x <= x_max) {
            cout << "Grad noch so 🤔" << endl;
        } else {
            cout << "Kaput! 🫣" << endl;
        }
    } catch (...) {
        cerr << "Scherzkeks! Sie haben keine gültige Zahl eingegeben." << endl;
    }

    cout << endl;
}