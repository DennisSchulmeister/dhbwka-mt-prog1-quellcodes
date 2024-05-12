/***********************************************************************************************
 * Beispiel: Binäroperationen
 * ==========================
 * 
 * Die heutigen Computer arbeiten, von experimentellen Quantencomputern abgesehen, alle binär.
 * Das heißt, jegliche Daten werden intern als eine Reihe von Bits dargestellt, die genau die
 * beiden Zustände Null und Eins annehmen können. Binäroperationen sind daher die einfachsten
 * Berechnungen, die ein Computer vornehmen kann, aus denen sich alle anderen ableiten lassen.
 * Dieses Beispiel zeigt, welche Möglichkeiten dabei bestehen.
 ***********************************************************************************************/

#include <cstdint>      // Plattformunabhängige Ganzzahlen
#include <iostream>     // std::cout, std::cin, ...
#include <bitset>       // std::bitset

using namespace std;

void print_value(uint8_t value, string name, string description) {
    cout << name << " " << bitset<8>(value) << " " << description << endl;
}

int main(int argc, char **argv) {
    uint8_t zero = 0;
    print_value(zero,            "zero..............:", "");
    print_value(~zero,           "~zero.............:", "(Bitweises NOT - Negierung)");
    cout << endl;

    uint8_t value = 0b01111000;
    print_value(value,           "value.............:", "");
    print_value(value >> 1,      "value >> 1........:", "(Bitshift Rechts)");
    print_value(value << 1,      "value << 1........:", "(Bitshift Links)");
    print_value(value << 2,      "value << 2........:", "(Bitshift Links)");
    print_value(value << 3,      "value << 3........:", "(Bitshift Links)");
    print_value(value << 4,      "value << 4........:", "(Bitshift Links)");
    print_value(value << 5,      "value << 5........:", "(Bitshift Links)");
    cout << endl;

    uint8_t value1 = 0b00001111;
    uint8_t value2 = 0b10101010;
    print_value(value1,          "value1............:", "");
    print_value(value2,          "value2............:", "");
    print_value(value1 & value2, "value1 & value2...:", "(Bitweises UND - Beide Bits müssen 1 sein)");
    print_value(value1 | value2, "value1 | value2...:", "(Bitweises ODER - Mindestens ein Bit muss 1 sein)");
    print_value(value1 ^ value2, "value1 ^ value2...:", "(Bitweises EXKLUSIV-ODER - Nur ein Bit darf 1 sein)");
    cout << endl;
}