/***********************************************************************************************
 * Beispiel: Aufzählungen mit enum class
 * =====================================
 * 
 * Hier sehen wir nun dasselbe Beispiel wie zuvor, nur auf "enum class" statt "enum" umgeschrieben.
 * Wir behalten alle Vorteile von "enum", die kurzgefasst waren:
 * 
 *  - Definition eines eigenen Datentyps
 *  - Automatisch hochgezählte, numerische Konstanten
 *  - Verwendung der Konstanten als int-Zahlen weiterhin möglich
 *  - Prüfung der zulässigen Werte durch den Computer
 * 
 * Es werden aber die Nachteile von "enum" behoben:
 * 
 *  - Die Namen der Konstanten müssen nicht mehr eindeutig sein, da die Konstanten anders im
 *    Quellcode angesprochen werden. Man muss den Typ immer mit angeben und dabei Konstante
 *    und Typ mit dem ::-Operator (Scope Resolution Operator) verknüpfen:
 * 
 *        Weekday day = Weekday::Monday;
 * 
 *  - Der Compiler erzeugt keine automatischen Casts zum Typ int mehr. Das ist zwar einerseits
 *    lästig, wenn man einen Aufzählungswert zum Beispiel mit "cout" ausgeben will. Andererseits
 *    kann man das Problem mit einem einfachen Typ-Cast einfach lösen und hat dadurch auch gleich
 *    die Codestelle gekennzeichnet:
 * 
 *        cout << (int) day << endl;
 *                 │
 *                 └─── (Typecast)
 *    
 *    Passiert es dann doch, dass man einen Wochentag unbewusst mit einem anderen Datentyp
 *    kombiniert, beschwert sich der Compiler möglichst früh und möglichst laut.
 * 
 * Insgesamt sollte man daher "enum class" in den meisten Fällen "enum" vorziehen.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
using namespace std;

enum class Weekday {
    monday, tuesday, wednesday, thursday, friday, saturday, sunday
};

enum class Month {
    january = 1,
    february, march, april, may, june, july, august, september, october, november, december
};

int main(int argc, char **argv) {
    Weekday day = Weekday::monday;
    Month month = Month::june;

    cout << endl;
    cout << "Montag...: " << (int) day << endl;
    cout << "Juni.....: " << (int) month << endl;
    cout << endl;
}