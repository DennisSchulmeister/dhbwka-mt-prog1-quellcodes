/***********************************************************************************************
 * Beispiel: for/each-Schleifen
 * ============================
 * 
 * Die bisher gesehenen if, switch/case, while, do/while und for-Anweisungen stammen alle von
 * der Sprache C und finden sich daher in dieser Form auch in vielen anderen Sprachen wieder.
 * C++, C#, Java, JavaScript, Perl, PHP uvm. nutzen dieselben Anweisungen mit derselben Syntax.
 *
 * Später wurde jeder dieser Programmiersprachen unabhängig voneinander eine for/each-Schleife
 * hinzugefügt, mit der man über die Einträge einer Liste (oder einer anderen aufzählbaren
 * Datenstruktur)iterieren kann. Die Syntax unterscheidet sich von Sprache zu Sprache. In C++
 * lautet sie:
 *
 *    for (DEKLARATION : DATENSTRUKTUR) ANWEISUNG
 *
 * Beziehungsweise wie immer mit Codeblock anstelle der einzelnen Anweisung:
 *
 *    for (DEKLARATION : DATENSTRUKTUR) {
 *        ANWEISUNG;
 *        ANWEISUNG;
 *        ...
 *    }
 *
 * DEKLARATION muss eine Variable deklarieren, die zu den Einträgen der Datenstruktur passt.
 * Also beispielsweise einen Integer, wenn die Struktur eine Liste von Integern beinhaltet.
 * Die Schleife wird dann für jeden Eintrag in der Liste durchgeführt, wobei der aktuelle
 * Wert in der Variable abgelegt wird.
 *
 * Das Beispiel unten verwendet ein Vektor-Objekt als Liste mit Strings, obwohl wir Vektoren
 * bisher noch gar nicht kennengelernt haben und auch sonst noch keine aufzählbaren (iterierbare)
 * Datentypen kennen. Vektoren schauen wir uns bei den komplexen Datentypen noch genauer an.
 *
 * Eine weitere Besonderheit ist die Variablendeklaration in dem Beispiel unten. Eigentlich
 * müsste Sie wie folgt lauten, da die Liste lauter C++-Strings enthält:
 *
 *    for (string word : words) ...
 *
 * Tatsächlich steht hier aber:
 *
 *    for (auto word : words) ...
 *
 * Das Schlüsselwort auto steht hier für "automatisch", womit der Compiler angewiesen wird, den
 * Typ der Variable automatisch zu ermitteln. Dies klappt, weil klar ist, dass wir über eine
 * Liste mit Strings iterieren und die Variable somit nur ein String sein kann. Manchmal kann
 * man somit komplexe Typbeschreibungen umgehen und Tipparbeit sparen. Da man dadurch aber beim
 * Programmieren nicht direkt sieht, welchen Typ die Variable hat, verwenden wir auto in den
 * Beispielen nicht so oft.
 *
 * TRIVIA: Der angezeigte Beispielsatz war unter Windows 95 (erschienen im August 1995) der
 * der Beispieltext, mit dem in der Systemsteuerung eine Vorschau für die installierten
 * Schriftarten angezeigt wurde. 🚕
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::string, std::getline, ...
#include <vector>       // std::vector

using namespace std;

int main(int argc, char **argv) {
    vector<string> words = {
        "Franz",
        "jagt",
        "im",
        "völlig",
        "verwahrlosten",
        "Taxi",
        "quer",
        "durch",
        "München.",
    };

    cout << endl;

    for (auto word : words) {
        cout << word << " ";
    }
    
    cout << endl;
    cout << endl;
}
