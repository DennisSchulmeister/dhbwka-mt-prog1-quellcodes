/***********************************************************************************************
 * Aufgabe: PPM-Grafikdateien erzeugen
 * ===================================
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
    ofstream file;
    file.open("test.ppm");

    file << "P3" << endl;
    file << "3 1" << endl;
    file << "255" << endl;
    file << "255 0 0" << endl;
    file << "0 255 0" << endl;
    file << "0 0 255" << endl;

    file.close();
}