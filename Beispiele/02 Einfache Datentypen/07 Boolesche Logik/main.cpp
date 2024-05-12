/***********************************************************************************************
 * Beispiel: Boolesche Logik
 * =========================
 * 
 * Computer müssen oft Entscheidungen treffen. Anders als menschliche Entscheidungen basieren
 * diese aber immer auf Aussagen, die sich durch eine einfache Logik-Algebra als "Wahr" oder
 * "Falsch" ausdrücken lassen. Zwei Zustände. Wir praktisch, wo Computer doch binär arbeiten.
 * Diese Integration der Logik in die Mathematik verdanken wir George Boole, nach dem die
 * Booleschen Variablen und die Boolesche Logik, mit der diese bearbeitet werden, benannt sind.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
using namespace std;

void print_value(bool value, string name, string description) {
    cout << name << " " << (value ? "true " : "false") << " " << description << endl;
}

int main(int argc, char **argv) {

    bool value = false;
    print_value(value,            "value..............:", "");
    print_value(!value,           "!value.............:", "(Logisches NOT - Negierung)");
    cout << endl;

    bool value1 = true;
    bool value2 = false;
    print_value(value1,           "value1.............:", "");
    print_value(value2,           "value2.............:", "");
    print_value(value1 && value2, "value1 && value2...:", "(Logisches AND - Beide müssen true sein)");
    print_value(value1 || value2, "value1 || value2...:", "(Logisches OR  - Mindestens einer muss true sein)");
    cout << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Der Roboter darf nur fahren, wenn er aktiviert wurde UND KEIN Hinderniss erkannt wurde UND die Tür NICHT offen ist!" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;

    bool enabled   = true;
    bool obstacle  = false;
    bool door_open = true;
    print_value(enabled,   "enabled............:", "");
    print_value(obstacle,  "obstacle...........:", "");
    print_value(door_open, "door_open..........:", "");
    cout << endl << boolalpha;

    cout << "enabled && !obstacle && !door_open....: " << (enabled && !obstacle && !door_open)  << "  (Variante 1: Kein Hinderniss und Tür nicht offen)" << endl;
    cout << "enabled && !(obstacle || door_open)...: " << (enabled && !(obstacle || door_open)) << "  (Variante 2: Weder Hinderniss noch Tür offen)" << endl;
    cout << endl;

    cout << "Quizfrage: Warum darf der Roboter nicht fahren?" << endl;
    cout << endl;
}