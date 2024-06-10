/***********************************************************************************************
 * Beispiel: Referenzen auf Variablen
 * ==================================
 * 
 * An dieser Stelle angelangt, haben wir nun die weißen, gelben, orangenen und grünen Gürtel
 * im C/C++-Budō mit Bravour getragen und können uns langsam auf den blauen Gürtel, also den
 * vorletzten Gürtel vor den schwarzen Meistergraden, vorbereiten.
 * 
 * HINTERGRUND: Budō ist eine Familie japanischer Kampfsportarten wie Judo, Jui Jitsu oder Karate,
 * die neben der Technik vor allem auch mit einer inneren Haltung und Lehre, die als "der Weg ist
 * das Ziel" umschrieben werden kann, verbunden sind. Beispielsweise schreibt Wikipedia zu Judo:
 * "Zwei philosophische Prinzipien liegen dem Judo im Wesentlichen zugrunde: das gegenseitige
 * Helfen und Verstehen zum beiderseitigen Fortschritt und Wohlergehen und der bestmögliche
 * Einsatz von Körper und Geist". In diesen Sportarten wird ein Keikogi genannter Anzug getragen,
 * dessen Gürtelfarbe den persönlichen Fortschritt anzeigt. Dabei wird zwischen Schülergraden
 * (Kyū) und den Meistergraden (Dan) unterschieden.
 * 
 * Bezogen auf die Programmierung mit C/C++ heißt das, dass wir uns an Zeiger und Referenzen
 * heranwagen können, die für viele fortschrittlichen Programmieraufgaben benötigt werden.
 * Den Anfang machen Referenzen, die man sich als alternative Namen für bereits existierende
 * Variablen vorstellen kann. Haben wir zum Beispiel eine Integer-Variable wie die folgende:
 * 
 *     int nr1 = 4711;
 * 
 * Dann können wir mit folgender Syntax eine Referenz auf diese Variable definieren:
 * 
 *     int &ref_nr1 = nr1;
 * 
 * Ausschlaggebend ist hier das Undzeichen, das manchmal auch an den Datentyp statt den Namen
 * der Referenz angehängt wird. Die folgende Schreibweise bewirkt daher exakt dasselbe.
 * Über das Für und Wider beider Varianten streitet man sich im Internet noch heute. 💢
 * 
 *     int& ref_nr1 = nr1;
 * 
 * In beiden Fällen wird eine Referenz mit dem Namen "ref_nr1" deklariert, die auf dieselbe
 * Speicherstelle wie die Ursprungsvariable "nr1" zeigt. Man hat dadurch sozusagen zwei
 * Bezeichner für dieselbe Variable. Eine Zuweisung an "ref_nr1" ändert daher "auch" den Wert
 * von "nr1":
 * 
 *     ref_nr1 = 815;
 *     cout << nr1 << endl;     // Gibt "815" aus
 * 
 * Wichtig ist, dass eine Referenz immer auf eine bereits vorhandene Variable zeigen muss und
 * nachträglich auch nicht auf eine andere Variable umgebogen werden kann. Folgendes ist daher
 * nicht erlaubt:
 * 
 *     int& ref_nr2;            // Fehler! Eine Referenz muss immer initialisiert werden.
 * 
 * Soweit so schön, doch, wozu soll das gut sein? In der eben gezeigten Form zu nicht viel,
 * weshalb Referenzen in vielen Lehrbüchern gar nicht behandelt werden. In Zusammenhang mit
 * Funktionen können Sie allerdings sehr nützlich sein:
 * 
 * Indem man bestimmte Parameter einer Funktion als Referenz definiert, können die übergebenen
 * Wert innerhalb der Funktion geändert und die Änderung in der rufenden Umgebung sichtbar
 * gemacht werden. Anhand der Standardfunktion swap(), die in etwa wie folgt implementiert ist,
 * lässt sich das gut erklären:
 * 
 *     void swap(int &v1, int &v2) {
 *         int temp = v1;
 *         v1 = v2;
 *         v2 = v1;
 *     }
 *
 * v1 und v2 sind hier Referenzen und greifen daher direkt auf die Variable zu, die der Funktion
 * bei einem Aufruf übergeben werden. Dadurch wird es möglich, die Werte der beiden Variablem so
 * wie hier gezeigt zu vertauschen. (HINWEIS: Die echte Version der swap()-Methode hat noch ein
 * paar mehr Tricks auf Lager, damit sie nicht nur mit int-Variablen sondern allen Datentypen
 * funktioniert. Das Prinzip kommt aber hin.)
 * 
 *     int nr1 = 1, nr2 = 2;
 *     swap(nr1, nr2);
 *     cout << nr1 << ";" << nr2 << endl;  // Gibt "2;1" aus
 * 
 * Als Referenz gekennzeichnete Parameter können darüber hinaus helfen, die Performance eines
 * Programms zu verbessern, indem kostspielige Kopieraktionen beim Aufruf einer Funktion
 * vermieden werden. Hat man beispielsweise eine sehr langen String mit mehreren Megabytes
 * an Daten und eine Funktion, an welche die Daten übergeben werden sollen. Dann würde folgender
 * Aufruf die Daten vor jedem Aufruf komplett kopieren und dadurch sowohl Laufzeit als auch
 * Speicher verschwenden:
 * 
 *     string very_large_buffer = {"100 MB Daten hier ..."};
 *     void do_something_with_buffer(string buffer);           // Call-by-Value: Ineffizient!
 * 
 * Deklariert man den Parameter als Referenz, ist das Problem gelöst. Innerhalb der Funktion
 * greift man dan direkt auf die Ursprungsvariable, nur eben mit einem anderen Namen, zu.
 * Dabei kann man mit dem Schlüsselwort "const" noch zusätzlich sicherstellen, dass die Daten
 * innerhalb der Funktion nicht ausversehen verändert werden:
 * 
 *     string very_large_buffer = {"100 MB Daten hier ..."};
 *     void do_something_with_buffer(const string &buffer);    // Call-by-Reference
 * 
 * Passiert es dann doch, dass die Daten innerhalb der Funktion geändert werden, wirft bereits
 * der Compiler eine Fehlermeldung und verweigert den Dienst. Im Beispiel unten wird dies
 * anhand der Funktion values_to_string() gezeigt, die nur lesenden Zugriff auf die übergebenen
 * Daten benötigt. Natürlich lässt sich die Prüfung mit etwas Trickserei aushebeln. Aber der
 * Code hierfür ist so abenteuerlich, dass er auch weniger geübten Programmierer/innen sofort
 * komisch vorkommen sollte.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::string, std::getline, ...

using namespace std;

void swap_variables(int &v1, int &v2) {
    int temp = v1;
    v1 = v2;
    v2 = temp;
}

string values_to_string(const int &v1, const int &v2) {
    return string("nr1 = ") + to_string(v1) + string(", nr2 = ") + to_string(v2);
}

int main(int argc, char **argv) {
    cout << endl;

    int nr1 = 1, nr2 = 2;
    cout << "Initial......: " << values_to_string(nr1, nr2) << endl;

    swap_variables(nr1, nr2);
    cout << "Vertauscht...: " << values_to_string(nr1, nr2) << endl;

    int &ref1 = nr1;    // Referenz auf Variable nr1
    ref1 = 9;           // Ändert in Wirklichkeit nr1
    cout << "Referenz.....: " << values_to_string(nr1, nr2) << endl;

    cout << endl;
}