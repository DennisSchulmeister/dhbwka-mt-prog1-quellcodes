/***********************************************************************************************
 * Header: message.hpp
 * ===================
 * 
 * Header-Datei zum Module message.o, das der Compiler aus der message.cpp generiert. Hier finden
 * sich die öffentlichen (auch für andere Module nutzbaren) Deklarationen. Zur Vermeidung von
 * Namenskonflikten befinden sich die Deklarationen in einem eigenen Namensraum (namespace).
 ***********************************************************************************************/
#pragma once            // Ignorieren, wenn die Datei mehrfach eingebunden wird
#include <string>       // std::string, std::getline, ...

using namespace std;

namespace message {
    // Vorwärtsdeklarationen aller öffentlichen Funktionen
    string get_random_message();
}