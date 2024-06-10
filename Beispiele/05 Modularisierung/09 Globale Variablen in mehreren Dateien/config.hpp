/***********************************************************************************************
 * Header: config.hpp
 * ==================
 * 
 * Header-Datei mit den Deklarationen für ein einfaches, globales Konfigurationsobjekt mit den
 * Einstellungen des Programms. Enthalten sind:
 * 
 *  - Ein strukturierter Datentyp zur Definition der konfigurierbaren Werte
 *  - Deklaration einer globalen Variable mit exakt diesem Datentyp
 *  - Eine Initialisierungsfunktion zum Einlesen der Konfigurationswerte bei Programmstart
 * 
 * Durch das Schlüsselwort "extern" vor der Variable wird sichergestellt, dass es die Variable
 * tatsächlich nur einmal im gesamten Programm gibt und aus allen *.cpp-Dateien, die diese
 * Header-Datei einbinden, darauf zugegriffen werden kann.
 ***********************************************************************************************/
#pragma once            // Ignorieren, wenn die Datei mehrfach eingebunden wird
#include <string>       // std::string, std::getline, ...

using namespace std;

namespace config {
    // Strukturierter Datentyp mit Konfigurationswerten
    struct config_t {  
        string username;
        string homedir;
        string webserver;
    };

    // Vorwärtsdeklaration einer globalen Variable mit externer Sichtbarkeit. Die Variable wird dadurch
    // nicht angelegt, sondern nur dem Compiler und dem Linker bekannt gemacht. In der config.cpp befindet
    // sich die eigentliche Variablendefinition. In der main.cpp kann auf sie zugegriffen werden.
    extern config_t config;

    // Funktion zum
    void init_config();
}