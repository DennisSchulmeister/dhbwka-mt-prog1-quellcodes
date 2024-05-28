/***********************************************************************************************
 * Aufgabe: PPM-Grafikdateien erzeugen
 * ===================================
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
 * Entfernen Sie anschließend die Zeilen, in welche die drei Testpixel geschrieben werden und
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
    file.open("colormap.ppm");

    file << "P3" << endl;
    file << width << " " << height << endl;
    file << "255" << endl;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = 255.0 * x / width;
            int g = 255.0 * y / height;
            int b = 50;

            file << r << " " << g << " " << b << endl;
        }
    }

    file.close();
}