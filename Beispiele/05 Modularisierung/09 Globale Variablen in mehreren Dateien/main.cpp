/***********************************************************************************************
 * Beispiel: Globale Variablen in mehreren Dateien
 * ===============================================
 * 
 * Dies ist ein Sonderfall, der gelegentlich vorkommen kann. Man hat den Quellcode in mehrere
 * *.cpp-Dateien aufgeteilt und verwendet dabei globale Variablen, auf die in mehreren Dateien
 * zugegriffen werden soll. Beispiele hierfür können sein:
 * 
 *  - Zentrale Logging-Objekte zur Protokollierung des Programmlaufs
 *  - Zentrale Konfigurations-Objekte mit Programmeinstellungen
 *  - Singleton-Objekte, von denen es nur eines geben kann (z.B. std::cout)
 *  - Globale Zählvariablen
 *  - …
 * 
 * Dieses Beispiel zeigt das Prinzip anhand einer globalen Programmkonfiguration. Es soll also
 * eine globale Variable geben, die alle Konfigurationswerte des Programms enthält. Das Problem
 * dabei ist, dass globale Variablen immer nur innerhalb der *.cpp-Datei nutzbar sind, in der
 * sie definiert wurden. Anders als bei Funktionen kann man für eine Variable nicht einfach eine
 * zusätzliche Deklaration in die Header-Datei schreiben. Folgende Zeilen in der Header-Datei
 * config.hpp wären daher falsch:
 * 
 *     config_t config; 
 *     config_t config = {};
 *     …
 * 
 * Der Grund dafür ist, dass hierdurch jede *.cpp-Datei, die den Header inkludiert, ihre eigene
 * Variable "config" deklarieren würde. Statt einer Variable im gesamten Programm gäbe es viele
 * verschiedene mit dem gleichen Namen. Stattdessen muss die Variable in der Header-Datei mit dem
 * Schlüsselwort "extern" angekündigt aber noch nicht initialisiert werden:
 * 
 *     extern config_t config;      // Deklaration in config.hpp (Header)
 * 
 * Dadurch wissen Compiler und Linker, dass es eine Variable mit dem Namen "config" geben soll.
 * Erzeugt wird sie tatsächlich aber erst in der Datei config.cpp mit:
 * 
 *     config_t config = {};         // Definition in config.cpp (Implementierung)
 * 
 * In der main.cpp kann die Variable dann tatsächlich verwendet werden, wenn die Header-Datei
 * eingebunden wurde. Technisch gesehen geschieht dies, indem der Compiler einen Verweis in der
 * Datei main.o platziert, den der Linker später auflösen kann. Als Eselsbrücke kann man sich
 * aber einfach merken, dass mit dem Schlüsselwort "extern" externe Zugriffe ermöglicht werden.
 ***********************************************************************************************/

#include "config.hpp"   // Deklarationen zur Objektdatei config.o
#include <iostream>     // std::cout, std::cin, ...

using namespace std;

int main(int argc, char **argv) {
    cout << endl;

    config::init_config();

    cout << "Konfigurationswerte" << endl;
    cout << "===================" << endl;
    cout << endl;
    cout << "username....: " << config::config.username  << endl;
    cout << "homedir.....: " << config::config.homedir   << endl;
    cout << "webserver...: " << config::config.webserver << endl;

    cout << endl;
}