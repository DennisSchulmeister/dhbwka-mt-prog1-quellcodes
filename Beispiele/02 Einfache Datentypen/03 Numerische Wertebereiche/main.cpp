/***********************************************************************************************
 * Beispiel: Numerische Wertebereiche
 * ==================================
 * 
 * Die klassischen Datentypen char, short, int ... haben keine exakt definierte Größe in C/C++,
 * da der Sprachstandard jeweils nur eine Mindestgröße und damit Wertebereiche zusichert. Diese
 * Angaben stammen aber aus längst vergangenen Zeiten mehrere CPU-Generationen zurückliegend.
 * Die tatsächlichen Wertebereiche hängen hingen von CPU-Architektur und Compiler ab und können
 * über verschiedene Konstanten abgefragt werden. Dieses Beispiel gibt sie auf der Konsole aus.
 ***********************************************************************************************/
#include <iostream>     // std::cout, std::cin, ...
#include <climits>      // Min/Max-Werte für Ganzzahlen
#include <cfloat>       // Min/Max-Werte für Kommazahlen

using namespace std;

int main(int argc, char **argv) {
    char c; short s; int i; long l; long long ll;
    float f; double d; long double ld;

    cout << endl;
    cout << "Vorzeichenbehaftete Ganzzahlen" << endl;
    cout << "==============================" << endl;
    cout << endl;
    cout << "signed char................: " << SCHAR_MIN << " bis " << SCHAR_MAX << " (" << sizeof(c)  << " Byte)" << endl;
    cout << "short (int)................: " << SHRT_MIN  << " bis " << SHRT_MAX  << " (" << sizeof(s)  << " Byte)" << endl;
    cout << "int........................: " << INT_MIN   << " bis " << INT_MAX   << " (" << sizeof(i)  << " Byte)" << endl;
    cout << "long (int).................: " << LONG_MIN  << " bis " << LONG_MAX  << " (" << sizeof(l)  << " Byte)" << endl;
    cout << "long long (int)............: " << LLONG_MIN << " bis " << LLONG_MAX << " (" << sizeof(ll) << " Byte)" << endl;
    cout << endl;

    cout << "Vorzeichenlose Ganzzahlen" << endl;
    cout << "=========================" << endl;
    cout << endl;
    cout << "unsigned char..............: 0 bis " << UCHAR_MAX  << " (" << sizeof(c)  << " Byte)" << endl;
    cout << "unsigned short (int).......: 0 bis " << USHRT_MAX  << " (" << sizeof(s)  << " Byte)" << endl;
    cout << "unsigned int...............: 0 bis " << UINT_MAX   << " (" << sizeof(i)  << " Byte)" << endl;
    cout << "unsigned long (int)........: 0 bis " << ULONG_MAX  << " (" << sizeof(l)  << " Byte)" << endl;
    cout << "unsigned long long (int)...: 0 bis " << ULLONG_MAX << " (" << sizeof(ll) << " Byte)" << endl;
    cout << endl;

    cout << "Gleitkommazahlen" << endl;
    cout << "================" << endl;
    cout << endl;
    cout << "float.....................: " << FLT_MIN  << " bis " << FLT_MAX  << " (" << sizeof(f)  << " Byte)" << endl;
    cout << "double....................: " << DBL_MIN  << " bis " << DBL_MAX  << " (" << sizeof(d)  << " Byte)" << endl;
    cout << "long double...............: " << LDBL_MIN << " bis " << LDBL_MAX << " (" << sizeof(ld) << " Byte)" << endl;
    cout << endl;
}