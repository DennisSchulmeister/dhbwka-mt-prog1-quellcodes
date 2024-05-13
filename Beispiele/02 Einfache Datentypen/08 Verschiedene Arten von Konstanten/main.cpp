/***********************************************************************************************
 * Beispiel: Verschiedene Arten von Konstanten
 * ===========================================
 * 
 * x
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecision

using namespace std;

#define PI 3.14159                              // Präprozessor: Macht Suchen & Ersetzen vor dem Compilieren
const double pi = 3.14159;                      // Als konstant gekennzeichnete Variable im Speicher
constexpr double pi2 = 104348.0 / 33215.0;      // Eine echte Konstante, die bereits beim Compilieren ausgerechnet wird.

int main(int argc, char **argv) {
    cout << setprecision(25);
    cout << "#define PI 3.14159..........................: " << PI  << endl;
    cout << "const double pi = 3.14159...................: " << pi  << endl;
    cout << "constexpr double pi2 = 104348.0 / 33215.0...: " << pi2 << endl;
    cout << endl;
    cout << "Man beachte zusätzlich die Rundungsfehler der binären Gleitkommazahlen. :-)" << endl;
}