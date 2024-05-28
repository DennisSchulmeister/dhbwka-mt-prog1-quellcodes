/***********************************************************************************************
 * Aufgabe: RAW-Sounddateien erzeugen
 * ==================================
 *
 * b) Auf dieser Grundlage können wir nun etwas spielen. Zunächst erstellen wir eine neue
 * Funktion osc(double f, double t), in welche wir die Berechnung des nächsten Samples
 * auslagern. Der Name deutet darauf hin, dass es sich um einen Oszillator (Signalgenerator)
 * mit periodischer Schwingungsform handelt. Um den Sound etwas interessanter zu machen,
 * synthetisieren wir dabei eine Rechteckfunktion:
 *
 *    double osc(double f, double t) {
 *        double sample = 0.0;
 *    
 *        for (int i = 1; i < 32; i += 2) {
 *            if ((i * f) > (sr / 2)) break;
 *            sample += sin(i * 2 * pi * f * t / sr) / i;
 *        }
 *    
 *        return sample;
 *    }
 *
 * Tauschen Sie die Formel in der for-Schleife gegen einen Aufruf der neuen Funktion aus und
 * hören Sie sich das Ergebnis in Audacity an.
 *
 * ACHTUNG: Ton leiste stellen! Vor allem, wenn Sie Kopfhörer aufhaben!
 *
 * Passen Sie das Programm anschließend so an, dass ein Frequenzdurchlauf (englisch: sweep)
 * generiert wird, indem Sie die Frequenz mit der Zeit multiplizieren:
 *
 *     double progress = t / length_s / sr;
 *     double sample = osc(f * progress, t) * 0.5;
 *
 * Kopieren Sie anschließend die for-Schleife und lassen Sie den Sweep wieder rückwärts auf
 * 0 Hz zulaufen. TIPP: Der Inhalt der Schleife muss nicht geändert werden, nur ihre drei
 * Ausdrücke in den runden Klammern.
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
constexpr double f        = 2050;
constexpr int    sr       = 44100;

double osc(double f, double t) {
    double sample = 0.0;

    for (int i = 1; i < 32; i += 2) {
        if ((i * f) > (sr / 2)) break;
        sample += sin(i * 2 * pi * f * t / sr) / i;
    }

    return sample;
}

int main(int argc, char **argv) {
    ofstream file;
    file.open("square-sweep.raw", ios::binary);

    for (int t = 0; t < length_s * sr; t++) {
        double progress = t / length_s / sr;
        double sample = osc(f * progress, t) * 0.5;
        file.write((const char*) &sample, sizeof(sample));
    }

    for (int t = length_s * sr; t > 0; t--) {
        double progress = t / length_s / sr;
        double sample = osc(f * progress, t) * 0.5;
        file.write((const char*) &sample, sizeof(sample));
    }

    file.close();
}