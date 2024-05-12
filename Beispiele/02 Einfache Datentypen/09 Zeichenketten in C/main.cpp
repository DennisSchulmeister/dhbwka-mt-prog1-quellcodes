/***********************************************************************************************
 * Beispiel: Zeichenketten in C
 * ============================
 * 
 * Textbasierte Daten werden mit sogenannten Zeichenketten (engl. strings) verarbeitet. Diese
 * sind in der älteren Sprache C sehr einfach definiert: Ein String ist nichts anderes als eine
 * Menge von Char-Werten (Bytes), die hintereinander im Speicher stehen. Eine solche Variable,
 * die mehrere Werte vom selben Typ hintereinander speichert, wird auch "Array" (deutsch: Feld)
 * genannt. Das letzte Zeichen ist immer ein vom Compiler automatisch angehängtes NULL-Byte,
 * damit das Ende des Strings sicher erkannt werden kann.
 *
 * So einfach wie sie definiert sind, haben Strings in C doch gewisse Probleme. Einerseits kann
 * man sehr performanten Code damit schreiben. Andererseits lauert an vielen Stellen die Gefahr
 * von Pufferüberläufen, womit gemeint ist, dass man mehr Zeichen in einen String schreibt, als
 * dieser eigentlich zur Verfügung stellt, wodurch ausversehen (oder absichtlich ?!?) andere
 * Daten des Programms oder im schlimmsten Fall sogar der Programmcode selbst überschrieben
 * werden. Sehr viele Sicherheitslücken von bekannten Programmen beruhen auf diesem Prinzip!
 *
 * Ein weiteres Problem ergibt sich aus der verwendeten Textcodierung, dem sog. Zeichensatz.
 * Denn ein String ist einfach eine Folge von Bytes, die gemäß einem Zeichensatz interpretiert
 * werden müssen. Heute ist das oft UTF-8, leider aber nicht immer. Bestimmte Aufgaben, wie
 * das Zählen der sichtbaren Zeichen, können dadurch etwas umständlich werden, da die Sprache
 * C hier keine Unterstützung bietet.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <cstring>      // strlen, strcat, ...
using namespace std;

int main(int argc, char **argv) {
    char buffer[100] = {0};                         // Puffer zur Aufnahme des zusammengefügten Strings
    char word1[]     = u8"Hallo ihr schönen ";      // Erster Teilstring
    char word2[]     = u8"Strings!";                // Zweiter Teilstring

    strncat(buffer, word1, sizeof(buffer) - 1);     // Strings zusammenfügen unter Berücksichtigung der Puffer-Größe.
    strncat(buffer, " ",   sizeof(buffer) - 1);     // Dies ist die "sichere" Variante von strcat().
    strncat(buffer, word2, sizeof(buffer) - 1);     // WICHTIG: Bei der Maximallänge eins abziehen für das NULL-Byte am Ende!

    size_t len = strlen(buffer);

    cout << endl;
    cout << "\"" << buffer << " \" (" << len << " von " << (sizeof(buffer) - 1) << " Bytes)" << endl;

    cout << endl;
    cout << u8"HINWEIS: Strings zählen Bytes, nicht Zeichen! Zählen Sie nach ..." << endl;
}