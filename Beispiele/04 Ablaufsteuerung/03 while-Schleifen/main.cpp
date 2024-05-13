/***********************************************************************************************
 * Beispiel: while-Schleifen
 * =========================
 * 
 * Neben Fallunterscheidungen spielen Wiederholungen eine große Rolle bei der Programmierung.
 * Denn häufig hat man Algorithmen, bei denen etwas so lange wiederholt werden soll, wie eine
 * bestimmte Bedingung zutrifft bzw. so lange, bis sie eintrifft. Dies ist genau die Aufgabe
 * der while-Anweisung die hierfür wie folgt definiert ist:
 *
 *     while (AUSDRUCK) ANWEISUNG
 *
 * Man nennt dieses Konstrukt eine Schleife (englisch: loop). Das Programm wertet hierbei den
 * AUSDRUCK aus und prüft, ob dieser true ergibt. Falls ja, wird die ANWEISUNG ausgeführt.
 * Anschließend wird der AUSDRUCK erneut geprüft, um zu schauen, ob die ANWEISUNG ausgeführt
 * werden soll. Dies passiert so lange, bis der AUSDRUCK false wird.
 *
 * Wie so oft wird anstelle der ANWEISUNG typischerweise ein Codeblock mit mehreren Anweisungen
 * geschrieben. Dies sieht dann so aus:
 *
 *    while (AUSDRUCK) {
 *        ANWEISUNG;
 *        ANWEISUNG;
 *        ...
 *    }
 *
 * Innerhalb des Codeblocks kann die break-Anweisung verwendet werden, um die Schleife vorzeitig
 * zu beenden. Zum Beispiel so:
 *
 *    while (true) {
 *        ...
 *        if (BEDINGUNG) break;
 *        ...
 *    }
 *
 * BEMERKUNG: `while (true)` wird auch Endlosschleife genannt (englisch: endless loop), da seine
 * Bedingung immer true ergibt und die Schleife ohne die break-Anweisung niemals enden würde.
 *
 * HINWEIS: Das Programm erzeugt X/Y-Paare einer einfachen Fourier-Reihe und schreibt diese
 * auf die Konsole. Wenn Sie die Werte in eine Textdatei umleiten, können Sie diese mit GNUPlot
 * wie folgt visualisieren:
 *
 *    1. Programm compilieren: make
 *    2. Programm ausführen: .\main.exe > example.data
 *    3. Webseite gnuplot.io aufrufen
 *    4. Datei dort mit dem "Upload"-Button hochladen
 *    5. Im Script-Bereich folgenden Befehl eingeben: plot "example.data"
 *    6. Klick auf "Run", um das GNUPlot-Skript auszuführen.
 *
 * Die PNG-Datei in diesem Verzeichnis zeigt das Ergebnis.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::string, std::getline, ...
#include <cmath>        // sin, cos, ...

using namespace std;

constexpr double pi = 104348.0 / 33215.0;
constexpr double dx = 0.01;
constexpr int    n = 10;

int main(int argc, char **argv) {
    double x = 0.0;

    while (x < 2 * pi) {
        int i = 1;
        double y = 0.0;

        while (i < n) {
            y += sin(i * x);
            i++;
        }

        y /= n;
        cout << x << " " << y << endl;
        x += dx;
    }
}