/***********************************************************************************************
 * Beispiel: Zeichenketten in C++
 * ==============================
 * 
 * Aufgrund der diversen Probleme, die C-Strings insbesondere mit Pufferüberläufen haben, bieten
 * alle später erschienenen Programmiersprachen richtige String-Datentypen, die diese Probleme
 * versuchen zu vermeiden. In C++ ist dies der Typ std::string, der intern zwar ebenfalls mit
 * einem Char-Array arbeitet, seine Länge aber vollkommen automatisch verwaltet. Pufferüberläufe
 * weren dadurch sehr viel unwahrscheinlicher zu Kosten von etwas Laufzeit-Overhead, der auf
 * heutigen Computern aber so gut wie immer vernachlässigbar ist.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::string, std::getline, ...

using namespace std;

int main(int argc, char **argv) {
    string buffer;

    buffer.append("This is");
    buffer.append(" the ");
    buffer.append("Länd! 🧔");

    cout << endl;
    cout << "\"" << buffer << "\" (" << buffer.length() << " von " << buffer.capacity() << " Bytes)" << endl;

    cout << endl;
    cout << "HINWEIS: Strings zählen Bytes, nicht Zeichen! Zählen Sie nach ..." << endl;
}