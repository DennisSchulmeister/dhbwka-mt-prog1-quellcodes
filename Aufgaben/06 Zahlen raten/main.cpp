/***********************************************************************************************
 * Aufgabe: Zahlen raten
 * =====================
 * 
 * Recherchieren Sie im Internet, wie Sie mit C/C++ zufällige Ganzzahlen ermitteln können.
 * Anschließend schreiben Sie eine Ratespiel, bei dem das Programm eine zufällige Zahl zwischen
 * null und 25 ermittelt, die man erraten muss. Hierzu soll das Programm in einer Schleife eine
 * Zahl über die Tastatur abfragen und daraufhin einen Hinweis anzeigen, ob die eingegebene
 * Zahl zu groß, zu niedrig oder genau richtig ist. Sobald die richtige Zahl eingegeben wurde,
 * sollen das Programm beendet und die Anzahl der Rateversuche angezeigt werden.
 *
 * Ein typischer Programmablauf könnte beispielsweise so aussehen:
 *
 *    Zahlen raten
 *    ============
 *
 *    Ich denke mir eine Zahl zwischen null und 25 aus.
 *    Sie müssen die Zahl erraten.
 *
 *    1. Versuch: 10
 *    Zu groß
 *
 *    2. Versuch: 5
 *    Zu klein
 *
 *    3. Versuch: 7
 *    Richtig!
 *
 *    Sie haben die Zahl in 3 Versuchen erraten.
 *
 * Einen Bonuspunkt gibt es, wenn die Meldung am Ende die Anzahl korrekt berücksichtigt,
 * also "in einem Versuch" statt "in X Versuchen" ausgibt, wenn die Anzahl eins ist.
 *
 * Achten Sie darauf, Eingabefehler sauber abzufangen. Grob falsche Eingaben sollen einfach
 * ignoriert und als falscher Rateversuch gezählt werden. Hierzu können Sie die Anweisung
 * continue benutzen, um wieder an den Anfang der Schleife zu springen.
 *
 * HINWEIS: Hier bietet es sich an, die beiden Anweisungen `break` und `continue` zu verwenden.
 *
 *   - break: Bricht eine Schleife ab
 *   - continue: Setzt die Schleife direkt beim nächsten Durchlauf fort
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecision
#include <string>       // std::string, std::getline, ...

using namespace std;

int main(int argc, char **argv) {
}