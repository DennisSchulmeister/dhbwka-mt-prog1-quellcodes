/***********************************************************************************************
 * Beispiel: Kommandozeilenparameter
 * =================================
 * 
 * Ein besonderes Merkmal der Kommandozeile ist, dass sie nicht einfach nur Programme ausführen
 * kann, indem man ihren Namen eingibt und ENTER drückt. Man kann den Programmen zusätzlich so
 * genannte Kommandozeilenparameter (auch Argumente genannt) mitgegeben und somit die Ausführung
 * der Programme beeinflussen. In der Vorlesung machen wir dies beispielsweise immer dann, wenn
 * wir "make" ausführen, um ein Programm zu compilieren oder zu starten. Schreiben wir:
 *
 *     make run
 *
 * Dann rufen wir das Programm "make" mit dem Argument "run" aus. Geben wir stattdessen folgenden
 * Befehl ein:
 *
 *      g++ -c -g -o main.o main.cpp
 *
 * Dann rufen wir das Programm "g++" (unseren C++-Compiler) mit den Argumenten "-c", "-g", "-o"
 * "main.o" und "main.cpp" auf. Die Reihenfolge spielt dabei teilweise eine Rolle: So muss der
 * Name der compilierten Quellcodedatei immer ganz am Ende stehen. Und nach "-o" muss der Name
 * der zu erzeugenden Datei, hier also "main.o" stehen. Unser Compiler will das so.
 *
 * Wichtig ist, dass derartige Regeln weder vom Betriebssystem noch vom Kommandozeileninterpreter
 * (so heißt das Programm, das unsere Eingaben im Terminal entgegen nimmt und verarbeitet)
 * vorgegeben werden. Einzig und allein das aufgerufene Programm bestimmt, welche Argumente,
 * wenn überhaupt, es erwartet und wie diese kombiniert werden können. Wenig überraschend können
 * deshalb auch C/C++-Programme Kommandozeilenparameter verarbeiten. Dies ist genau der Zweck
 * der beiden Parameter "argc" und "argv", die der main-Funktion übergeben werden:
 *
 *   - argc: Anzahl der Argumente (argument count)
 *   - argv: Liste der Argumente (argument vector)
 *
 * Der Begriff Vektor darf hier allerdings nicht mit dem Datentyp "vector" von C++ verwechselt
 * werden. Es handelt sich stattdessen um ein einfaches Array (deutsch Feld) mit Zeigern auf
 * C-Strings. Vektoren, Arrays und Zeiger haben wir bisher zwar noch nicht kennengelernt. Das
 * folgende Beispiel zeigt aber, dass die Kommandozeilenparameter trotzdem leicht ausgelesen
 * werden können. Im nächsten Beispiel sehen wir dann, wie sie interpretiert werden können.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
using namespace std;

int main(int argc, char **argv) {
    cout << endl;
    cout << "Kommandozeilenparameter" << endl;
    cout << "=======================" << endl;
    cout << endl;
    cout << "Anzahl: " << argc << endl;
    cout << endl;

    for (int i = 0; i < argc; i++) {
        char *argument = argv[i]; // Zur Verdeutlichung in einer eigenen Zeile
        // Alternativ: string argument = argv[i]

        cout << "[" << i << "] " << argument << endl;
    }

    cout << endl;
}