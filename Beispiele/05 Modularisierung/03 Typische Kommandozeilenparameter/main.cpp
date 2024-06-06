/***********************************************************************************************
 * Beispiel: Typische Kommandozeilenparameter
 * ==========================================
 * 
 * Dieses Beispiel zeigt, wie ein C/C++-Programm auf Argumente reagieren kann, die ihm beim
 * Aufruf auf der Kommandozeile mitgegeben werden. Es handelt sich dabei um die for-Schleife
 * am Anfang der main-Funktion.
 *
 * Viele Kommandozeilenprogramme folgen der UNIX-Tradition, die Argumente mit einem Minuszeichen
 * beginnen zu lassen. Fast alle Programme unter Linux, macOS, Unix und auch immer mehr Windows
 * folgen diesem Schema. Meistens verstehen diese Programme folgende zwei Argumente, mit denen
 * allgemeine Informationen über das Programm sowie eine Hilfeseite abgerufen werden können:
 *
 *   -v bzw. --version: Anzeige von Programmname, Version und Lizenz
 *   -h bzw. --help: Anzeige einer Hilfeseite mit einer Beschreibung aller Argumente
 *
 * Auch dieses Beispiel folgt dieser Vorgabe, bei der die eigentliche Hauptlogik des Programms
 * gar nicht ausgeführt wird, wenn eines der beiden Argumente erkannt wurde. Zusätzlich kennt
 * es noch folgende Argumente, um zu zeigen, wie Kommandozeilenparameter genutzt werden können,
 * um Flags (Schalter) zu setzen oder benannte Werte zu übergeben:
 *
 *   -f bzw --flag: Setzt ein Flag
 *   -V WERT bzw. --value WERT: Übergibt einen Wert
 *
 * Natürlich kann ein Programm beliebig viele Flags und Werte als Argumente erwarten, um seinen
 * Ablauf zu beeinflussen. Hier soll nur das Vorgehen demonstriert werden, wie solche Argumente
 * im Programmcode behandelt werden. 
 *
 * Programme, die eine Sache gut machen und dabei über verschiedene Argumente gesteuert werden
 * können, sowie die Scripting-Fähigkeiten moderner Kommandozeileninterpreter sind die Basis
 * dafür, nicht nur den eigenen Computer als Power User richtig ausreizen zu können. Sie bilden
 * auch das Rückgrat vieler eingebetteter Systeme, Cloud- und Onlinedienste. Wo ein Terminal
 * ist, ist ein Weg ...
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::string, std::getline, ...

using namespace std;

// Vorwärtsdeklarationen
void show_version();
void show_help();

// Programmname und Version
constexpr const char *PROGRAM = "Demo-Programm";
constexpr const char *VERSION = "0.1.0";

int main(int argc, char **argv) {
    // Argumente interpretieren
    bool flag = false;
    string value = "";

    for (int i = 1; i < argc; i++) {
        string argument = argv[i];

        if (argument.compare("-v") == 0 || argument.compare("--version") == 0) {
            show_version();
            return 0;
        } else if (argument.compare("-h") == 0 || argument.compare("--help") == 0) {
            show_help();
            return 0;
        } else if (argument.compare("-f") == 0 || argument.compare("--flag") == 0) {
            flag = true;
        } else if (argument.compare("-V") == 0 || argument.compare("--value") == 0) {
            if (i + 1 == argc) {
                cerr << "Wert erwartet nach " << argument << endl;
                return -1;
            }

            i++;
            value = argv[i];
        } else {
            cerr << "Unbekanntes Argument: " << argument << endl;
            return -1;
        }
    }

    // Hauptlogik des Programms
    cout << endl;
    cout << "Übergebene Argumente" << endl;
    cout << "====================" << endl;
    cout << endl;
    cout << "Flag: " << flag << endl;
    cout << "Wert: " << value << endl;
    cout << endl;
    cout << "Siehe " << argv[0] << " --help zum Aufruf des Programms" << endl;
    cout << endl;
}

void show_version() {
    cout << endl;
    cout << PROGRAM << " " << VERSION << endl;
    cout << "(C) 2024 Dennis Schulmeister-Zimolong (CC-BY 4.0)" << endl;
    cout << endl;
}

void show_help() {
    cout << endl;
    cout << PROGRAM << " " << VERSION << endl;
    cout << endl;
    cout << "Dies ist ein einfaches Demoprogramm, das zeigt, die die Kommandozeilenparameter" << endl;
    cout << "eines Programms mit C/C++ ausgelesen und interpretiert werden können. Es bietet" << endl;
    cout << "darüber hinaus die üblichen Argumente zur Anzeige der Version und dieser Hilfe." << endl;
    cout << endl;
    cout << "Folgende Argumente dienen der Anzeige der eingebauten Dokumentation und führen" << endl;
    cout << "deshalb dazu, dass die Hauptlogik des Programms nicht ausgeführt wird:" << endl;
    cout << endl;
    cout << "  -v, --version            Versionsinformation anzeigen" << endl;
    cout << "  -h, --help               Diese Hilfeseite anzeigen" << endl;
    cout << endl;
    cout << "Darüber hinaus gibt es noch folgende Argumente:" << endl;
    cout << endl;
    cout << "  -f, --flag               Beispiel für ein Ja/Nein-Flag" << endl;
    cout << "  -V WERT, --value WERT    Beispiel für ein Argument mit Wert" << endl;
    cout << endl;
}