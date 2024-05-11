/***********************************************************************************************
 * Beispiel: Variablen deklarieren
 * ===============================
 * 
 * Der Mikroprozessor eines Computers macht im Grunde genommen nichts anderes, als Daten aus dem
 * Hauptspeicher in den Prozessor zu laden, damit zu rechnen und dann in der Regel wieder in den
 * Speicher zu schreiben. Beim Programmieren können wir die Werte entweder als Festwerte direkt
 * in den Quellcode schreiben, beispielsweise um 3 * 7 auszurechnen. Oder wir können "Variablen"
 * deklarieren, die eine Speicherstelle zur Aufnahme eines Datenwerts reservieren.
 *
 * Jede Variable besitzt dabei einen "Typ", der ausdrückt, wie viel Speicher sie beansprucht und
 * welche Art von Werten in ihr abgelegt werden können. Dieses Beispiel zeigt die wichtigsten
 * Datentypen in C/C++ und wie jeweils eine Variable davon deklariert und mit einem Wert
 * initialisiert werden kann.
 ***********************************************************************************************/
#include <cstdint>      // Plattformunabhängige Ganzzahlen
#include <string>       // C++ Strings

using namespace std;

int main(int argc, char **argv) {
    // Ganzzahlen (plattformabhängig)
    char      c  = 'A';
    short     s  = -123;
    int       i  = -12345;
    long      l  = -1234567;
    long long ll = -123456789;

    unsigned short     us  = 255;
    unsigned int       ui  = 12345;
    unsigned long      ul  = 1234567;
    unsigned long long ull = 123456789;

    // Ganzzahlen (plattformunabhängig)
    int8_t  i8  = -123;
    int16_t i16 = -12345;
    int32_t i32 = -1234567;
    int64_t i64 = -123456789;

    uint8_t  ui8  = 123;
    uint16_t ui16 = 12345;
    uint32_t ui32 = 1234567;
    uint64_t ui64 = 123456789;

    // Gleitkommazahlen
    float       f  = 8.15;
    double      d  = 47.11;
    long double ld = 3.6;

    // Zeichenketten
    char   cstring[]  = "Alte C-Strings";
    string cpp_string = "Neuere C++-Strings";

    // Man beachte die eckigen Klammern nach dem Namen des C-Strings. Diese sagen aus, dass es sich bei der
    // Variable um ein "Array", also mehrere char-Werte hintereinander handelt. Das letzte Zeichen in diesem
    // Array ist immer ein NULL-Byte, welches das Ende des Strings kennzeichnet.
    //
    // Genau genommen wird der Variable mit dem C++-String ebenfalls ein C-String als Char-Array zugewiesen,
    // da doppelte Anführungszeichen immer ein solches definieren. Dieses wird bei der Zuweisung aber automatisch
    // in den gewünschten Datentyp "string" umgewandelt.
}