/***********************************************************************************************
 * Implementierung: message.cpp
 * ============================
 * 
 * Dies ist die Implementierungsdatei vom Objektmodul "message.o". Hier wird die im Header
 * deklarierte Funktion get_random_message() implementiert.
 * 
 * Zusätzlich gibt es noch die private Funktion get_random_number(), die nur intern genutzt wird
 * und deshalb in der Header-Datei absichtlich nicht aufgezählt wurde. Allerdings brauchen wir
 * hier einen Namespace, damit der Linker keinen Konflikt mit der gleichnamigen Funktion in der
 * main.cpp meldet.
 ***********************************************************************************************/
#include "message.hpp"  // Eigene Header-Datei

#include <string>       // std::string, std::getline, ...
#include <cstdlib>      // rand
#include <ctime>        // time
#include <cassert>      // assert

using namespace std;

namespace message {
    // Nicht-öffentliche Funktion, die nur innerhalb dieses Moduls verfügbar ist, weil sie
    // nicht in der Header-Datei deklariert wurde. ACHTUNG: In der main.cpp gibt es ebenfalls
    // Funktion mit demselben Namen. Damit der Linker uns das nicht um die Ohren wirft, befindet
    // sich der Inhalt dieser Datei in einem eigenen Namespace (deutsch: Namensraum).
    int get_random_number() {
        srand(time(nullptr));
        return rand() % 3;
    }

    // Öffentliche Funktion, die aus anderen Modulen heraus aufgerufen werden kann
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
}