/***********************************************************************************************
 * Aufgabe: RAW-Sounddateien erzeugen
 * ==================================
 *
 * Nicht nur Zahlenkolonnen und Bilder lassen sich mit C/C++ berechnen. Auch Geräusche sind
 * problemlos möglich, wenn man Zahlen in eine Datei schreiben kann. Allerdings müssen wir die
 * Zahlen hierfür nicht als Text sondern in ihrer Binärform in die Datei schreiben.
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
 * Im daraufhin erscheinenden Popup-Fenster wählen Sie folgende Werte aus:
 *
 *     Encoding:          64-bit float
 *     Byte order:        Default endianess
 *     Channels:          1 Channel (Mono)
 *     Start offset:      0 Bytes
 *     Amount to import:  100%
 *     Sample rate:       44100 Hz
 *
 * b) Auf dieser Grundlage können wir nun etwas spielen. Zunächst erstellen wir eine neue
 * Funktion double osc(double f, double t), in welche wir die Berechnung des nächsten Samples
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
 * ACHTUNG: Ton leise stellen! Vor allem, wenn Sie Kopfhörer aufhaben!
 *
 * Passen Sie das Programm anschließend so an, dass ein Frequenzdurchlauf (englisch: sweep)
 * generiert wird, indem Sie die Frequenz mit der Zeit multiplizieren:
 *
 *     double progress = t / length_s / sr;
 *     double sample = osc(f * progress, t) * 0.5;
 *
 * Kopieren Sie anschließend die for-Schleife und lassen Sie den Sweep wieder rückwärts auf
 * 0 Hz zulaufen. TIPP: Der Inhalt der Schleife muss nicht geändert werden, nur die drei
 * Ausdrücke in den runden Klammern.
 *
 * c) Abschließend wollen wir unser kleines Soundprogramm so abändern, dass es eine kleine
 * Melodie berechnet. Diese speichern wir hierfür ein folgender Datenstruktur außerhalb der
 * main()-Methode:
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
 * und Dauer aus den beiden Variablen note.frequency_hz und note.duration_s erhalten.
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