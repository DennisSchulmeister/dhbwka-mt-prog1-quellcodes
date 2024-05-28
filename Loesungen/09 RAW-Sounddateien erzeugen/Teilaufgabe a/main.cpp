/***********************************************************************************************
 * Aufgabe: RAW-Sounddateien erzeugen
 * ==================================
 *
 * a) Das "Hallo Welt" der Audioprogrammierung ist ein Sinus mit der Kammertonfrequenz 440Hz.
 * Diesen wollen wir in eine Audiodatei im RAW-Format schreiben, wobei dieses Format besonders
 * einfach ist: Es handelt sich lediglich um die Samplewerte in einem selbst festgelegten
 * Binärformat. Wir legen folgende Parameter hierfür fest:
 *
 *   * Sampleformat: double ("64-bit float" in Audacity)
 *   * Abtastrate: 44100 Hz (CD-Qualität)
 *   * Audiokanäle: 1 (Mono)
 *
 * Jetzt müssen wir nur noch eine Binärdatei öffnen und Werte hineinschreiben:
 *
 *     double sample = 0.0;
 *
 *     ofstream file;
 *     file.open("sin440.raw", ios::binary);
 *     file.write((const char*) &sample, sizeof(sample));
 *     file.close();
 *
 * Welche Werte? Die Formel hierfür lautet: sin(2π * f * t / sr). Die Variablen sind dabei wie
 * folgt definiert:
 *
 *    constexpr double pi = 104348.0 / 33215.0;
 *    constexpr double f  = 440.0;
 *    constexpr int    sr = 44100;
 *
 * Achten Sie darauf, die Konstanten vor der main()-Funktion zu deklarieren. Für die nächste
 * Teilaufgabe benötigen wir das so.
 *
 * Nutzen Sie diese Informationen, um einen zwei Sekunden andauernden Sinuston mit 440 Hz
 * in die Datei zu schreiben. TIPP: Sie benötigen eine for-Schleife, mit (Länge * Abtastrate)
 * Durchläufen.
 *
 * Öffnen Sie die Datei in Audacity, indem Sie dort "File → Import → Raw Data…" auswählen.
 * In dem daraufhin erscheinenden Popup-Fenster wählen Sie folgende Werte aus:
 *
 *     Encoding:          64-bit float
 *     Byte order:        Default endianess
 *     Channels:          1 Channel (Mono)
 *     Start offset:      0 Bytes
 *     Amount to import:  100%
 *     Sample rate:       44100 Hz
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecision
#include <string>       // std::string, std::getline, ...
#include <cmath>        // pow, sin, ...
#include <cstdlib>      // rand
#include <fstream>      // std::ifstream, std::ofstream, ...
#include <vector>       // std::vector

using namespace std;

constexpr double pi       = 104348.0 / 33215.0;
constexpr double length_s = 2.0;
constexpr double f        = 440.0;
constexpr int    sr       = 44100;

int main(int argc, char **argv) {
    ofstream file;
    file.open("sin440.raw", ios::binary);

    for (int t = 0; t < length_s * sr; t++) {
        double sample = sin(2 * pi * f * t / sr);
        file.write((const char*) &sample, sizeof(sample));
    }

    file.close();
}