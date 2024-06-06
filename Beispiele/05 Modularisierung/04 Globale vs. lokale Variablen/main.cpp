/***********************************************************************************************
 * Beispiel: Globale vs. lokale Variablen
 * ======================================
 * 
 * Je größer unserer Programme werden, desto mehr müssen wir uns bewusst werden, wie Variablen
 * in C/C++ funktionieren und welche Besonderheiten es dabei zu beachten gibt, vor allem, wenn
 * wir über die main-Funktion hinaus weitere Funktionen definieren. Dieses Beispiel zeigt hierbei
 * den Unterschied zwischen globalen und lokalen Variablen:
 *
 * LOKALE VARIABLEN: Alle innerhalb einer Funktion (bzw. genauer gesagt innerhalb eines mit
 * geschweiften Klammern definierten Codeblocks!) deklarierte Variablen, die deshalb auch nur
 * innerhalb dieser Funktion (bzw. dieses Codeblocks) existieren.
 *
 * GLOBALE VARIABLEN: Alle außerhalb einer Funktion deklarierten Variablen, die deshalb im
 * gesamten Programm nutzbar sind.
 *
 * Diese Definition beschreibt die so genannte "Sichtbarkeit" der Variablen – also an welchen
 * Stellen im Programm die Variablen sichtbar sind und genutzt werden können. Doch noch ein
 * weiterer Aspekt ist wichtig: Die Lebensdauer der Variablen:
 *
 * LOKALE VARIABLEN: Existieren nur, der sie umgebende Codeblock ausgeführt wird. Wird der
 * Codeblock verlassen, verschwinden die Variablen wieder und ihr Speicher wird freigegeben.
 * Bei rekursiven Funktionen (Funktionen, die sich selbst aufrufen, so wie unten im Beispiel
 * die Funktion function_a()), existiert eine eigene Kopie je Funktionsaufruf.
 *
 * GLOBALE VARIABLEN: Existieren während der gesamten Laufzeit des Programms und sind daher
 * einzigartig. Alle Funktionen greifen auf dieselbe Kopie desselben Werts zurück.
 *
 * Beide Konzepte zusammen - die Sichtbarkeit und die Lebensdauer - nennt man auch den
 * Gültigkeitsbereich. Also den Bereich im Quellcode, innerhalb dessen eine Variable gültig
 * ist, da sie sowohl sichtbar ist als auch noch nicht freigegeben wurde.
 *
 * Das untenstehende Beispiel verdeutlicht das Prinzip. Hier besitzt jede Funktion ihre eigene
 * Kopie der Variable `a`, weshalb das Programm hier problemlos hoch und wieder runter zählen
 * kann. Die Kopie der Variable `a` wird durch den Aufruf von `function_a(a + 1)` nicht
 * verändert, innerhalb von `function_a()` wird stattdessen eine eigene Kopie angelegt. Diese
 * wiederum bleibt beim rekursiven Selbstaufruf von `function_a()` ebenfalls unverändert, da
 * eine weitere Kopie angelegt wird. Die obere Zahlenreihe z#hlt daher erst munter hoch und
 * dann fröhlich wieder runter.
 *
 * Variable `b` ist hingegen eine globale Variable, die von allen Funktionen genutzt wird. Sie
 * verändert zwar am Anfang jedes Funktionsaufrufs ihren Wert, ändert ihn dann aber nicht mehr.
 * Und da es die Variable auch nur einmal im gesamten Programm gibt, behält sie ihren jeweils
 * letzten Wort so lange bei, bis ihr ein neuer Wert zugewiesen wird. Die zweite Zahlenreihe
 * zählt daher hoch, aber nicht mehr runter.
 *
 * Die eckigen Klammern in der Konsolenausgabe stehen für Funktionsaufrufe und verduetlichen
 * so, die Schachtelung der Funktionsaufrufe.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
using namespace std;

void function_a(int a);
void function_b();

int b = 1; // Globale Variable

int main(int argc, char **argv) {
    cout << endl;

    // Lokale Variable a
    int a = 1;

    cout << "a: [" << a;
    function_a(a + 1);
    cout << " " << a << "]";
    cout << endl;

    // Globale Variable b
    cout << "b: [" << b;
    function_b();
    cout << " " << b << "]";
    cout << endl;

    cout << endl;
}

void function_a(int a) {
    cout << " [" << a;
    if (a < 5) function_a(a + 1);
    cout << " " << a << "]";
}

void function_b() {
    b++;

    cout << " [" << b;
    if (b < 5) function_b();
    cout << " " << b << "]";
}