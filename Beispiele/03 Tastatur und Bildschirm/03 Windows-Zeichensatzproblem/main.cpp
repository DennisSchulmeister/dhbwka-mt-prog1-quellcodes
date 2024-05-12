/***********************************************************************************************
 * Beispiel: Windows-Zeichensatzproblem
 * ====================================
 * 
 * Im Beispiel "UTF-8 Everywhere" wurde schon auf die Problematik der vielen verschiedenen
 * Zeichensätze und der historischen Entwicklung von Unicode hingewiesen. Diese Probleme machen
 * sich für Programmieranfänger*innen vor allem bei Konsolenausgaben unter Windows bemerkbar,
 * da die Beispiele mit UTF-8 arbeiten, das Konsolenfenster unter Windows aus Gründen der
 * Kompatibilität aber mit einem anderen Zeichensatz arbeitet.
 *
 * Damit die Anzeige stimmt, muss der Zeichensatz auf der Konsole mit folgendem Befehl
 * auf UTF-8 umgestellt werden, bevor das Programm gestartet wird:
 *
 *    chcp 65001
 *
 * Alternativ könnte das Programm den Zeichensatz der Konsole ändern oder, eigentlich korrekt,
 * die Windows API nutzen, um den eingestellten Zeichensatz abzufragen und die Text vor der
 * Anzeige umzuwandeln. Damit wäre das Programm aber nicht mehr "plattformunabhängig" und
 * liese sich nur unter Windows compilieren und nutzen. Zwar ließen sich die betroffenen
 * Codezeilen mit #ifdef betriebssystemabhängig abweichend definieren. Für uns lohnt sich der
 * ganze Aufwand aber nicht.
 *
 * Compilieren und Starten Sie das Programm stattedessen einfach immer mit folgendem Befehl:
 *
 *    make run
 *
 * Das Makefile führt dann den oben genannten Befehl aus, um den Zeichensatz umzustellen.
 * Ob dies funktioniert, können Sie mit diesem Programm testen.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
using namespace std;

int main(int argc, char **argv) {
    cout << endl;
    cout << "Hier kommen ein paar Umlaute: Ä Ö Ü ä ö ü" << endl;
    cout << "Sehen diese richtig aus?" << endl;
    cout << endl;
}