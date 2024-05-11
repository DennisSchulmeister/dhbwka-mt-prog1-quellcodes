/***********************************************************************************************
 * Beispiel: Deklaration, Ausdruck, Anweisung
 * ==========================================
 * 
 * Die meisten Zeilen in C/C++ sind Anweisungen, die den Computer im weitesten Sinne auffordern,
 * etwas zu tun, während das Programm läuft. Sie müssen mit einem Semikolon abgeschlossen werden,
 * um sie von nachfolgenden Anweisungen zu unterscheiden. Denn in einer Zeile dürfen beliebig
 * viele Anweisungen stehen.
 *
 * Wenn wir mit Variablen arbeiten, müssen wir diese zunächst deklarieren. Wir benötigen also
 * eine Anweisungen, die eine neue Variable anlegt und optional mit einem Wert versieht. Sie
 * wird Deklaration genannt.
 *
 * Das eigentliche Rechnen mit Variablen und anderen Daten erfolgt in sog. Ausdrücken, die
 * meistens mehrere Werte über einen oder mehrere Operatoren miteinander verknüpfen. Ausdrücke
 * liefern dabei immer ein Ergebnis, mit dem entweder weitergerechnet und das innerhalb einer
 * Anweisung (bspw. einer Zuweisung) verwendet werden kann. Man beachte, dass bereits die bloße
 * Nennung einer Variable als Ausdruck gilt, da hierdurch ihr aktueller Wert ermittelt wird.
 *
 * WICHTIG: Eine Zeile kann, wie unten gezeigt, sowohl Anweisung, Ausdruck und Deklaration
 * gleichzeitig sein, wobei Deklarationen ja ohnehin Anweisungen sind.
 ***********************************************************************************************/

#include <iostream>      // std::cout, std::cin, ...
using namespace std;

int main(int argc, char **argv) {
    // Deklaration: Eine Anweisung, die eine neue Variable definiert
    int value;

    // Zuweisung: Ein Ausdruck, der einen Wert in einer Variable ablegt.
    // In der hier gezeigten Form mit Semikolon abgeschlossen, ebenfalls eine Anweisung
    value = 4711;

    // Deklaration und Zuweisung in einem
    int number = 1234;

    // Ausdruck (engl. expression): Eine Berechnung, die ein Rechenergebnis erzeugt.
    // Verknüpft in der Regel mehrere Werte über Rechenoperatoren wie hier dem Malzeichen.
    // In der hier gezeigten Form meistens sinnlos, da mit dem Ergebnis nichts gemacht wird
    // und der Ausdruck keine Seiteneffekte besitzt.
    7 * 8;

    // Ein weiterer Ausdruck (expression): Die Nennung einer Variable zählt bereits als Ausdruck,
    // der im Ergebnis den aktuellen Wert der Variable liefert.
    value;

    // Zuweisung und Ausdruck: Das Ergebnis des Ausdrucks wird der Variable zugewiesen.
    value = 7 * 8;

    // Ausdruck mit Seiteneffekt: cout nutzt den << (Bit Shift Left) Operator für Bildschirmausgaben.
    // Streng genommen handelt es sich um zwei Ausdrücke: Zunächst wird "value" auf den aktuellen Wert
    // der Variablen reduziert, der dann über den << Operator mit cout verknüpft wird.
    cout << value;
    
    // Zeilenumbruch ausgeben, um nachfolgende Konsolenausgaben besser abzugrenzen
    // Preisfrage: Worum handelt es sich hierbei?
    cout << endl;
}