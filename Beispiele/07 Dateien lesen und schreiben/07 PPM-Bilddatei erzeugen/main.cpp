/***********************************************************************************************
 * Beispiel: PPM-Bilddatei erzeugen
 * ================================
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
 * Aufbauend auf diesem Wissen generiert dieses Programm eine simple Farbverlaufsgrafik, die
 * entlang der Y-Achse zwischen mehreren Farben überblendet. Die auskommentierten Zeilen in
 * der Mitte liefern eine simplere, alternative Form, bei der anstelle des Farbverlaufs fette
 * Farbbalken generiert werden.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::string, std::getline, ...
#include <fstream>      // std::ifstream, std::ofstream, ...
#include <array>        // std::array
#include <cmath>        // std::modf, std::round, ...

using namespace std;

struct rgb {
    int r;
    int g;
    int b;
};

array<rgb, 6> colors = {
    rgb{255, 0,   0},
    rgb{255, 255, 0},
    rgb{0,   255, 0},
    rgb{0,   255, 255},
    rgb{0,   0,   255},
    rgb{255, 0,   255},
};

int main(int argc, char **argv) {

    constexpr int width = 320, height = 240;
    int lines = height / colors.size();

    ofstream file;
    file.open("colorbars.ppm");

    file << "P3" << endl;
    file << width << " " << height << endl;
    file << "255" << endl;

    for (int y = 0; y < height; y++) {
        ////// Einfache Streifen
        // int i = y / lines;
        // rgb color = colors.at(i);
        //////

        ////// Farbverlauf
        double d = 1.0 * y / lines;
        double i;
        double f = modf(d, &i);

        rgb color1 = colors.at((int) i);
        rgb color2 = colors.at(((int) i + 1) % colors.size());

        rgb color = {
            (int) round(color1.r + (1.0 * (color2.r - color1.r) * f)),
            (int) round(color1.g + (1.0 * (color2.g - color1.g) * f)),
            (int) round(color1.b + (1.0 * (color2.b - color1.b) * f)),
        };
        //////

        for (int x = 0; x < width; x++) {
            file << color.r << " " << color.g << " " << color.b << endl;
        }
    }

    file.close();
}