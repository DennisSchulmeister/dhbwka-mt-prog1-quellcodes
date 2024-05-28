/***********************************************************************************************
 * Aufgabe: PPM-Grafikdateien erzeugen
 * ===================================
 *
 * Wer mathematische Berechnungen ausführen und die Ergebnisse in eine Textdatei schreiben kann,
 * kann ganz leicht Grafiken mit C und C++ erstellen. Denn auf diese Weise können ganz leicht
 * Bilddateien im PPM-Format (Portable PixMap) erstellt werden. Diese sehen wie folgt aus:
 *
 *    P3
 *    Breite Höhe
 *    255
 *    R G B
 *    R G B
 *    R G B
 *
 * Anstelle der Zeilenumbrüche können auch Leerzeichen verwendet werden. Einzelne Zeilen machen
 * es aber leichter, das Format zu verstehen. Breite und Höhe sind die Anzahl der Pixel in X-
 * und Y-Richtung als formatierte Ganzzahl. R, G und B hingegen sind Ganzzahlen von 0 … 255, die
 * für den Rot-, Grün- und Blauanteil eines Pixels stehen. Die Pixel werde von oben links
 * beginnend zeilenweise in die Datei geschrieben.
 *
 * a) Zunächst wollen wir ein ganz simples Beispielbild mit nur drei Pixeln generieren. Diese
 * sollen die Farben Rot, Grün und Blau besitzen und in einer Zeile nebeneinander stehen.
 * Schreiben Sie hierfür ein Programm, das folgende Daten in eine Textdatei namens test.ppm
 * schreibt:
 *
 *     P3
 *     3 1
 *     255
 *     255 0 0
 *     0 255 0
 *     0 0 255
 *
 * Folgende Anweisungen benötigen Sie:
 *
 *     ofstream file;            // Deklaration einer Variable vom Typ "output file stream"
 *     file.open("test.ppm");    // Datei öffnen (löscht ihren Inhalt)
 *     file <<  "P3" << endl;    // Neue Zeile in die Datei schreiben
 *     file.close();             // Datei ordentlich schließen
 *
 * Versuchen Sie die Datei in einem Grafikprogramm anzuzeigen. Zoomen Sie ganz nah ran, um die
 * einzelnen Pixel zu sehen.
 *
 * b) Nachdem dies nun geklappt hat, wollen wir eine etwas ansprechendere Grafik generieren:
 * Eine Farbpalette, die bei festem Blauanteil die Anteile für Rot und Grün auf den beiden
 * Achsen variiert und in einer Datei namens colormap.ppm speichert.
 *
 * Legen Sie hierfür zunächst zwei Integer-Variablen für die Breite und Höhe des Bildes an
 * und passen Sie den Quellcode so an, dass diese an der richtigen Stelle in die Bilddatei
 * geschrieben werden:
 *
 *     int width = 320, height = 240;
 *     ...
 *
 * Entfernen Sie anschließend die Zeilen, in denen die drei Testpixel geschrieben werden und
 * ersetzen Sie diese durch zwei geschachtelte for-Schleifen. Die äußere Schleife soll die
 * Y-Werte (Zeilen) und die innere Schleife die X-Werte (Spalten) zählen.
 *
 * Schreiben Sie innerhalb der inneren Schleifen folgende Farbwerte in die Datei:
 *
 *    int r = 255.0 * x / width;
 *    int g = 255.0 * y / height;
 *    int b = 50;
 *
 * Betrachten Sie auch diese Datei in einem Grafikprogramm.
 *
 * c) Durch Variieren der Formeln für r, g, und b können Sie jetzt schon ganz interessante
 * Bilder generieren. Probieren Sie ruhig ein wenig aus. Als Ausgangslage können Sie z.B.
 * folgende Formeln verwenden:
 *
 *     double sy = 0.5 + sin(3.14 * y / height * 3) / 2.0;
 *     double sx = 0.5 + sin(3.14 * x / width * 4) / 2.0;
 *
 *     int r = 130 * sx * sy;
 *     int g = 0;
 *     int b = 50;
 *
 * d) Zum Schluss wollen wir einen schönen himmelblauen, linearen Farbverlauf berechnen und
 * dabei Strukturen in C/C++ kennenlernen. Denn Strukturen ermöglichen es uns, mehrere Werte,
 * die zusammengehören, in eine Variable zu packen. Beispielsweise die Farbwerte eines Pixels.
 * Fügen Sie hierfür vor der main()-Funktion folgende Zeilen ein:
 *
 *     struct rgb {
 *         int r;
 *         int g;
 *         int b;
 *     };
 *
 * Sie definieren einen neuen Datentyp namens "rgb" mit den drei Integer-Werten r, g, und b.
 * Damit können wir nun zwei Variablen mit der Start- und der Zielfarbe des Farbverlaufs
 * anlegen:
 * * * d) Zum Schluss wollen wir einen schönen himmelblauen, linearen Farbverlauf berechnen und
 * dabei Strukturen in C/C++ kennenlernen. Denn Strukturen ermöglichen es uns, mehrere Werte,
 * die zusammengehören, in eine Variable zu packen. Beispielsweise die Farbwerte eines Pixels.
 * Fügen Sie hierfür vor der main()-Funktion folgende Zeilen ein:
 *
 *     struct rgb {
 *         int r;
 *         int g;
 *         int b;
 *     };
 *
 * Sie definieren einen neuen Datentyp namens "rgb" mit den drei Integer-Werten r, g, und b.
 * Damit können wir nun zwei Variablen mit der Start- und der Zielfarbe des Farbverlaufs
 * anlegen:
 *
 *     rgb start = {30, 140, 210};
 *     rgb end = {210, 240, 255};
 *
 * Mit start.r, start.g, start.b sowie end.r, end.g, end.b kann auf die einzelnen Farbanteile
 * zugegriffen werden. Dies benötigen wir für folgende Hilfsvariable:
 *
 *     rgb delta = {
 *         end.r - start.r,
 *         end.g - start.g,
 *         end.b - start.b
 *     };
 *
 * Der Farbverlauf kann dann mit folgenden Formeln berechnet werden:
 *
 *     int r = start.r + (1.0 * delta.r * y / height);
 *     int g = start.g + (1.0 * delta.g * y / height);
 *     int b = start.b + (1.0 * delta.b * y / height);
 *
 * HINWEIS: Hier wird es zwar nicht benötigt, aber die Elemente einer Struktur können selbst
 * auch Strukturen oder andere zusammengesetzte Datentypen (Arrays, Vektoren, ...) sein.
 *     rgb start = {30, 140, 210};
 *     rgb end = {210, 240, 255};
 *
 * Mit start.r, start.g, start.b sowie end.r, end.g, end.b kann auf die einzelnen Farbanteile
 * zugegriffen werden. Dies benötigen wir für folgende Hilfsvariable:
 *
 *     rgb delta = {
 *         end.r - start.r,
 *         end.g - start.g,
 *         end.b - start.b
 *     };
 *
 * Der Farbverlauf kann dann mit folgenden Formeln berechnet werden:
 *
 *     int r = start.r + (1.0 * delta.r * y / height);
 *     int g = start.g + (1.0 * delta.g * y / height);
 *     int b = start.b + (1.0 * delta.b * y / height);
 *
 * HINWEIS: Hier wird es zwar nicht benötigt, aber die Elemente einer Struktur können selbst
 * auch Strukturen oder andere zusammengesetzte Datentypen (Arrays, Vektoren, ...) sein.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecision
#include <string>       // std::string, std::getline, ...
#include <cmath>        // pow, sin, ...
#include <cstdlib>      // rand
#include <fstream>      // std::ifstream, std::ofstream, ...
#include <vector>       // std::vector

using namespace std;

int main(int argc, char **argv) {
}