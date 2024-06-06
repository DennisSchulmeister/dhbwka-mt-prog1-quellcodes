/***********************************************************************************************
 * Beispiel: Unterprogramme und Funktionen
 * =======================================
 * 
 * Bei den bisherigen Beispielen wird der meiste Quellcode von folgenden Zeilen eingeschlossen
 * und nur wenige Zeilen, wenn überhaupt, stehen außerhalb:
 *
 *     int main(int argc, char** argv) {
 *         // Quellcode hier   
 *     }
 *
 * Es handelt sich dabei um die sogenannte main-Funktion, die beim Start eines C/C++-Programms
 * automatisch ausgeführt wird. Um ihre Bedeutung haben wir uns bisher keine Gedanken gemacht.
 * Tatsächlich müssen die Zeilen aber genau so lauten, damit sich das Programm compilieren lässt.
 * Doch warum ist das so und was bedeutet die Schreibweise? Gehen sie Wort für Wort durch:
 *
 *     int main(int argc, char** argv) {
 *      ┃   ┃    ┃         ┃           ┃
 *      ┃   ┃    ┃         ┃           ┗━━ 5) Hier beginnt der Inhalt der Funktion
 *      ┃   ┃    ┃         ┃           
 *      ┃   ┃    ┃         ┗━━━━━━━━━━━━━━ 4) Der zweite Parameter ist vom Typ char** und heißt "argv"
 *      ┃   ┃    ┃
 *      ┃   ┃    ┗━━━━━━━━━━━━━━━━━━━━━━━━ 3) Der erste Parameter ist vom Typ int und heißt "argc"
 *      ┃   ┃
 *      ┃   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 2) Der Name der Funktion ist "main"   
 *      ┃
 *      ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 1) Die Funktion liefert einen Wert vom Typ int als Ergebnis
 *
 *         // Quellcode hier
 *
 *     }
 *     ┃
 *     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 6) Hier endet der Inhalt der Funktion
 *
 * Die Parameter "argc" und "argv" enthalten die Kommandozeilenparameter, mit denen das Programm
 * aufgerufen wurde, und werden vom Betriebssystem gesetzt. Der Rückgabewert ist der Statuscode,
 * mit dem signalisiert wird, ob das Programm erfolgreich beendet wurde. Dies schauen wir uns
 * allerdings erst in einem späteren Beispiel an. Wenn man beides nicht braucht, kann die
 * main-Funktion tatsächlich auch so geschrieben werden:
 *
 *     void main() {
 *      ┃   ┃    ┗━━━━━━━━━━━━━━━━━━━━━━━━ 3) Die Funktion besitzt keine Parameter
 *      ┃   ┃
 *      ┃   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 2) Der Name der Funktion ist weiterhin "main"
 *      ┃
 *      ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 1) Die Funktion liefert kein Ergebnis zurück (Typ void)
 *         // Quellcode hier
 *     }
 *
 * Wie sich herausstellt, können wir neben der main-Funktion beliebig viele weitere Funktionen
 * definieren, um einen Quellcode übersichtlicher zu gestalten. Sollen beispielsweise dieselben
 * Codezeilen an unterschiedlichen Stellen mehrfach verwendet werden, mussten wir sie bisher
 * jedesmal erneut eingeben (oder mit Copy & Paste kopieren). Das DRY-Prinzip (englisch für
 * "Don't Repeat Yourself") sagt uns aber, dass das meist kein guter Ansatz ist. Stattdessen
 * helfen uns Funktionen dabei, doppelten Quellcode zu vermeiden. Ihre Definition sieht dabei
 * wie folgt aus:
 *
 *     DATENTYP NAME(PARAMETER, PARAMETER, …) {
 *         ANWEISUNG;
 *         ANWEISUNG;
 *         ...
 *     }
 *
 * Im einfachsten Fall liefert sie kein Ergebnis, was durch den Typ "void" ausgedrückt wird, und
 * besitzt keine Parameter. Dies würde dann wie folgt aussehen:
 *
 *     void eine_einfache_funktion() {
 *         // Quellcode hier
 *     }
 *
 * Zum Vergleich hier eine Funktion mit vier Parametern unterschiedlicher Typen und dem Typ
 * double als Ergebnis. Hier macht sich die Herkunft des Worts "Funktion" bemerkbar. In ihrer
 * reinsten Form sind Funktionen dafür gedacht, ausführbare Programmlogik wie zum Beispiel
 * mathematische Berechnungen zu kapseln. In Sprachgebrauch von C/C++ hat verwendet man
 * deshalb einfach denselben mathematischen Begriff.
 *
 *     double simple_fm_oscillator(double car_f, int car_a, double mod_f, int mod_a) {
 *         double modulator = sin(2 * pi * mod_f) * mod_a / 127.0;
 *         double carrier   = sin(2 * pi * car_f + modulator) * car_a / 127.0;
 *         return carrier;
 *     }
 *
 *
 * Aufrufen würde man die Funktion wie folgt:
 *
 *     double sample = simple_fm_oscillator(440.0, 127, 880.0, 64);
 *
 * Oder als Teil einer größeren Berechnung:
 *
 *     double sample = ( simple_fm_oscillator(440.0, 127, 880.0, 64)
 *                     + simple_fm_oscillator(220.0, 64,  880.0, 127 ) / 2.0;
 *
 * Oder, wenn man am Ergebnis nicht interessiert ist (hier natürlich sinnlos, da die Funktion
 * keine "Seiteneffekte" hat, sondern nur ein Rechenergebnis produziert):
 *
 *     simple_fm_oscillator(440.0, 127, 880.0, 64); 
 *
 * Bedenkt man, dass sich die Informatik aus der Mathematik heraus entwickelt hat, ergibt die
 * Wortwahl tatsächlich Sinn. Doch auch ein anderer Anwendungsfall ist hier zu nennen: Die
 * übersichtliche Strukturierung eines größeren Algorithmus. In anderen Programmiersprachen
 * werden Funktionen daher auch oft Prozeduren oder Unterprogramme (english: sub programs)
 * genannt, um zu betonen, dass damit ein großes (Haupt)programm in mehrere kleine Teilprogramme
 * unterteilt werden kann. Meist schreibt man dann für jeden Teilschritt ein Unterprogramm und
 * ruft die Unterprogramme dann in der richtigen Reihenfolge im Hauptprogramm auf. Der unten
 * stehende Quellcode zeigt ein (nicht ganz ernst gemeintes) Beispiel hiefür.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::string, std::getline, ...

using namespace std;

// Funktion zur Erzeugung des Songtitels
string titel() {
    return "Der Windows-Song\n"
           "================\n"
           "\n";
}

// Funktion zur Erzeugung einer Strophe
string strophe(int nr) {
    switch (nr) {
        case 1:
            return "[STROPHE 1]\n"
                   "  Ich will surfen. Komm nicht rein.\n"
                   "  Falsches Passwort! Kann nicht sein!\n"
                   "  Fehlermeldung 108.\n"
                   "  Was hab ich denn nur falsch gemacht?!\n"
                   "\n";
        case 2:
            return "[STROPHE 2]\n"
                   "  Netzwerkfehler. Datenschrott.\n"
                   "  Blauer Bildschirm. Oh mein Gott!\n"
                   "  Unknown Error! Software platt.\n"
                   "  Hardware-Terror. Ich hab's satt!\n"
                   "\n";
        case 3:
            return "[STROPHE 3]\n"
                   "  Rechner streikt. Treiber fehlt.\n"
                   "  0190-Dialer wählt ...\n"
                   "  USB-Stick? Nicht erkannt.\n"
                   "  Irgendwas riecht hier verbrannt.\n"
                   "\n";
        default:
            return "";
    }
}

// Funktion zur Erzeugung des Refrains
string refrain() {
    return "[REFRAIN]\n"
           "  Ich hab Windows. Was denn sonst?\n"
           "  Alles andere ist doch nur Schlonz!\n"
           "  Doch geht der Rechner nicht mehr an.\n"
           "  Dann ist definitiv Linux dran!\n"
           "  Denn, Linux - das ist perfekt!\n"
           "  Warum hab ich das nicht schon längst entdeckt?\n"
           "\n";
}

// Funktion zur Erzeugung der abschließenden Textzeilen
string ende() {
        return "  Doch, wenn ich nur wüst,\n"
               "  Welche Distribution die richtige ist ...\n"
               "\n";
}

// Funktion zu Erzeugung der Lizenzhinweise
string lizenz() {
    return "(C) 2008 Dennis Schulmeister-Zimolong\n"
           "Lizenziert unter THE BEER-WARE LICENSE (Revision 42)\n"
           "Wenn dir der Song gefällt, trinke ein Bier (oder etwas anderes).\n";
}

// Hauptprogramm
int main(int argc, char **argv) {
    cout << endl;
    cout << titel();
    cout << strophe(1);
    cout << strophe(2);
    cout << refrain();
    cout << strophe(3);
    cout << refrain();
    cout << ende();
    cout << lizenz();
    cout << endl;
}