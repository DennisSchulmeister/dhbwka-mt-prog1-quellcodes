/***********************************************************************************************
 * Implementierung: config.cpp
 * ===========================
 * 
 * Implementierungsdatei passend zur Header-Datei config.hpp. Hier wird die globale Variable
 * mit den Konfigurationswerten tatsächlich angelegt und initialisiert. Ebenso gibt es hier
 * die Implementierung zur Funktion init_config(), die bei Programmstart aufgerufen werden
 * muss, um die Konfigurationswerte zu ermitteln und in die globale Variable zu schreiben.
 * 
 * Die globale Variable kann daraufhin überall im Programm verwendet werden, um die einzelnen
 * Konfigurationswerte zu erhalten.
 ***********************************************************************************************/
#include "config.hpp"   // Eigene Header-Datei

#include <cstdlib>      // std::getenv
#include <string>       // std::string, std::getline, ...

using namespace std;

namespace config {
    // Deklaration der globalen Variable mit den Konfigurationswerten. Durch die extern-Anweisung
    // im Header-File wird die Variable auch außerhalb dieser Quelldatei nutzbar.
    config_t config = {};

    // Funktion zum Einlesen der Konfigurationswerte. Muss beim Programmstart aufgerufen werden.
    // Hier werden einfach irgendwelche Fantasiewerte aus den Umgebungsvariablen des Betriebssystems
    // ermittelt. Ein echtes Programm würde natürlich intelligentere Dinge machen. :-)
    void init_config() {
        const char *username = getenv("USERNAME");                      // Windows
        if (username == nullptr) username = getenv("USER");             // Linux, macOS, Unix
        if (username == nullptr) username = "anonymous";                // Fallback
        config.username = string(username);

        const char *homedir = getenv("USERPROFILE");                    // Windows
        if (homedir == nullptr) homedir = getenv("HOME");               // Linux, macOS, Unix
        if (homedir == nullptr) homedir = ".";                          // Fallback
        config.homedir = string(homedir);

        const char *webserver = getenv("WEBSERVER");                    // Eigene Umgebungsvariable
        if (webserver == nullptr) webserver = "https://www.wpvs.de";    // Fallback
        config.webserver = string(webserver);
    }
}