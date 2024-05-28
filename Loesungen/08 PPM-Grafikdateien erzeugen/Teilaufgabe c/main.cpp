/***********************************************************************************************
 * Aufgabe: PPM-Grafikdateien erzeugen
 * ===================================
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
    int width = 320, height = 240;

    ofstream file;
    file.open("sin_circles.ppm");

    file << "P3" << endl;
    file << width << " " << height << endl;
    file << "255" << endl;

    for (int y = 0; y < height; y++) {
        double sy = 0.5 + sin(3.14 * y / height * 3) / 2.0;

        for (int x = 0; x < width; x++) {
            double sx = 0.5 + sin(3.14 * x / width * 4) / 2.0;

            int r = 130 * sx * sy;
            int g = 0;
            int b = 50;

            file << r << " " << g << " " << b << endl;
        }
    }

    file.close();
}