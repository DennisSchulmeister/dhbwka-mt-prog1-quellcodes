/***********************************************************************************************
 * Aufgabe: RAW-Sounddateien erzeugen
 * ==================================
 *
 * c) Abschließend wollen wir unser kleines Soundprogramm so abändern, dass es eine kleine
 * Melodie berechnet. Diese speichern wir hierfür ein folgender Datenstruktur (außerhalb der
 * main()-Methode):
 *
 *    struct tone {
 *        double frequency_hz;
 *        double duration_s;
 *    };
 *    
 *    vector<tone> melody = {
 *        {660, 0.0750}, {0, 0.1120},
 *        {660, 0.0563}, {0, 0.2625},
 *        {660, 0.0750}, {0, 0.3375},
 *        {510, 0.0750}, {0, 0.0750},
 *        {660, 0.0563}, {0, 0.2625},
 *        {770, 0.0750}, {0, 0.4300},
 *        {380, 0.0750}, {0, 0.4300},
 *    };
 *
 * Entfernen Sie alle Konstanten außer pi und sr und fügen Sie stattdessen die obigen Zeilen
 * in das Programm ein. Innerhalb der main()-Methode holen Sie sich dann die einzelnen Noten
 * mit einer einfachen for/each-Schleife:
 *
 *     for (tone note : melody) {
 *         ...
 *     }
 *
 * Innerhalb dieser Schleife muss dann die bisherige for-Schleife stehen, wobei Sie die Frequenz
 * und die Datei aus den beiden Variablen note.frequency_hz und note.duration_s erhalten.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecision
#include <string>       // std::string, std::getline, ...
#include <cmath>        // pow, sin, ...
#include <cstdlib>      // rand
#include <fstream>      // std::ifstream, std::ofstream, ...
#include <vector>       // std::vector

using namespace std;

constexpr double pi = 104348.0 / 33215.0;
constexpr int    sr = 44100;

struct tone {
    double frequency_hz;
    double duration_s;
};

vector<tone> melody = {
    {660, 0.0750}, {0, 0.1120},
    {660, 0.0563}, {0, 0.2625},
    {660, 0.0750}, {0, 0.3375},
    {510, 0.0750}, {0, 0.0750},
    {660, 0.0563}, {0, 0.2625},
    {770, 0.0750}, {0, 0.4300},
    {380, 0.0750}, {0, 0.4300},
};

double osc(double f, double t) {
    double sample = 0.0;

    for (int i = 1; i < 16; i += 2) {
        if ((i * f) > (sr / 2)) break;
        sample += sin(i * 2 * pi * f * t / sr) / i;
    }

    return sample;
}

int main(int argc, char **argv) {
    ofstream file;
    file.open("mario.raw", ios::binary);

    for (tone note : melody) {
        for (int t = 0; t < note.duration_s * sr; t++) {
            double sample = osc(note.frequency_hz, t) * 0.5;
            file.write((const char*) &sample, sizeof(sample));
        }
    }

    file.close();
}