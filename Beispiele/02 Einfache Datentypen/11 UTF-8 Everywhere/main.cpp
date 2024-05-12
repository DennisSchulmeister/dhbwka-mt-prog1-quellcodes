/***********************************************************************************************
 * Beispiel: UTF-8 Everywhere
 * ==========================
 * 
 * Eines der verwirrendsten Themen in der Programmierung ist die korrekte Kodierung von Text,
 * da dieses Thema historisch viele Wendungen genommen hat. Die ursprüngliche Annahme, dass
 * jedes Zeichen mit einem Byte codiert werden kann, stellte sich schnell als falsch heraus.
 * Doch auch die Einführung regionaler Zeichensätze, bei denen alle Bytes > 127 andere
 * Sonderzeichen codierten, löste das Problem nur teilweise. Als Folge daraus entstand ab
 * 1988 Unicode, dessen Entwicklung aber auch von vielen Annahmen geprägt ist, die sich später
 * als problematisch herausstellten.
 *
 * Fast die ganze Welt hat sich inzwischen darauf geeinigt, Text im UTF-8 Format zu codieren,
 * da dieses Format mit ASCII kompatibel ist und somit viele Dinge einfach macht, trotzdem aber
 * alle Unicode-Zeichen speichern kann. Die große Ausnahme ist aktuell noch MS Windows, wo
 * UTF-8 aus Kompatibilitätsgründen nur langsam Einzug hält. Doch auch hier empfiehlt es sich,
 * wo immer möglich mit UTF-8 zu arbeiten.
 *
 * Hintergründe hierzu: http://utf8everywhere.org/
 * UTF-8 leicht verständlich: https://dev.to/rdentato/utf-8-strings-in-c-1-3-42a4
 *
 * Was muss man wissen?
 *
 *  - Unicode Codepoints: Ordnen jedem Zeichen eine Zahl zu.
 *  - UTF-8, UTF-16, ...: Legen fest, wie die Zahlen binär codiert werden.
 *  - UTF-8 ist heute die mit Abstand wichtigste Codierung. Alle anderen sind Sonderfälle.
 *  - UTF-8 codiert jedes Zeichen mit ein bis vier Bytes.
 *  - Anhand der Bitmuster kann man leicht erkennen, was welches Byte bedeutet.
 *
 * Die Empfehlung ist, einfach immer mit UTF-8 zu arbeiten und nur dann davon abzuweichen, wenn
 * man wirklich muss. Beispielsweise, weil man eine Windows API aufruft, die kein UTF-8 kennt.
 *
 * Dieses Beispiel zeigt, wie UTF-8 funktioniert und wie leicht man damit in C/C++ arbeiten kann.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::string
#include <bitset>       // std::bitset

using namespace std;


// Weiter unten ausprogrammierte Hilfsfunktionen
size_t single_byte_codepoints(string str);
size_t multi_byte_codepoints(string str);
size_t all_codepoints(string str);


/**
 * Hauptfunktion unseres Programms.
 */
int main(int argc, char **argv) {
    // Unser Test-String
    string str = "Wörld 😀";

    // Ausgabe des Strings auf der Konsole
    cout << endl;
    cout << "string str1 = \"" << str << "\";" << endl;
    cout << endl;

    // Bitmuster der einzelnen Bytes anzeigen
    for (char &c : str) cout << bitset<8>(c) << " ";
    cout << endl;

    // Bitmuster als vorzeichenlose Ganzzahlen anzeigen
    for (char &c : str) { cout.width(8); cout << left << +((unsigned char) c) << " "; }
    cout << endl;

    // ASCII-Darstellung der einzelnen Bytes anzeigen
    for (char &c : str) { cout << c << "        "; }
    cout << endl;
    cout << endl;

    // Bytes und UTF-8 Codepoints zählen
    cout << "Länge in Bytes.................: " << str.length() << endl;
    cout << "UTF-8 Single-Byte-Codepoints...: " << single_byte_codepoints(str) << endl;
    cout << "UTF-8 Multi-Byte-Codepoints....: " << multi_byte_codepoints(str) << endl;
    cout << "UTF-8 Codepoints gesamt........: " << all_codepoints(str) << endl;
    cout << endl;
    cout << "Unter der Annahme, dass die Quellcode-Datei UTF-8-codiert ist!" << endl;
    cout << endl;
    cout << "Bitmuster 0xxxxxxx: Single-Byte-Codepoint (ASCII-Zeichen)" << endl;
    cout << "Bitmuster 11xxxxxx: Erstes Byte eines Multi-Byte-Codepoints (Sonderzeichen)" << endl;
    cout << "Bitmuster 10xxxxxx: Folgebyte eines Multi-Byte-Codepoints (bis zu drei)" << endl;
    cout << endl;
}


/**
 * Hilfsfunktionen zum Zählen der Single-Byte-Codepoints in einem UTF-8-String.
 * Aufgrund der Bitmuster müssen einfach alle Bytes <= 127 gesucht werden.
 */
size_t single_byte_codepoints(string str) {
    size_t result = 0;
    for (char &c : str) if ((unsigned char) c <= 127) result++;
    return result;
}


/**
 * Hilfsfunktionen zum Zählen der Multi-Byte-Codepoints in einem UTF-8-String.
 * Aufgrund der Bitmuster müssen einfach alle Bytes >= 192 gesucht werden.
 */
size_t multi_byte_codepoints(string str) {
    size_t result = 0;
    for (char &c : str) if ((unsigned char) c >= 192) result++;
    return result;
}


/**
 * Hilfsfunktion zum Zählen aller Codepoints in einem UTF-8-String. Oft entspricht dies
 * der Anzahl Zeichen in dem String. Dies stimm allerdings nicht immer, da Unicode viele
 * "Combining Characters" kennt, die das vorausgehende Zeichen modifizieren, selbst aber
 * unsichtbar sind. Vgl. https://en.wikipedia.org/wiki/Combining_character
 *
 * In der Praxis ist aber weit seltener ein Problem, als man denkt. Meistens reicht es,
 * mit der Anzahl Bytes zu arbeiten und nicht einmal die UTF-8 Codepoints zu zählen,
 * wenn man nicht gerade eine auf Text spezialisierte Anwendung wie programmiert.
 */
size_t all_codepoints(string str) {
    size_t result = 0;

    for (char &c : str) {
        if ((unsigned char) c <= 127 || (unsigned char) c >= 192) {
            result++;
        }
    }

    return result;
}