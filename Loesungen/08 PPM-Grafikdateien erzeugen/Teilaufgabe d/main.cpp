/***********************************************************************************************
 * Aufgabe: PPM-Grafikdateien erzeugen
 * ===================================
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
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecision
#include <string>       // std::string, std::getline, ...
#include <cmath>        // pow, sin, ...
#include <cstdlib>      // rand
#include <fstream>      // std::ifstream, std::ofstream, ...
#include <vector>       // std::vector

using namespace std;

struct rgb {
    int r;
    int g;
    int b;
};

int main(int argc, char **argv) {
    int width = 320, height = 240;
    rgb start = {30, 140, 210}, end = {210, 240, 255};

    rgb delta = {
        end.r - start.r,
        end.g - start.g,
        end.b - start.b
    };

    ofstream file;
    file.open("linear_gradient.ppm");

    file << "P3" << endl;
    file << width << " " << height << endl;
    file << "255" << endl;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = start.r + (1.0 * delta.r * y / height);
            int g = start.g + (1.0 * delta.g * y / height);
            int b = start.b + (1.0 * delta.b * y / height);

            file << r << " " << g << " " << b << endl;
        }
    }

    file.close();
}