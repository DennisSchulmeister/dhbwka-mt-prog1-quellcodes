/***********************************************************************************************
 * Header: message.hpp
 * ===================
 * 
 ***********************************************************************************************/
#pragma once            // Ignorieren, wenn die Datei mehrfach eingebunden wird
#include <string>       // std::string, std::getline, ...

using namespace std;

namespace message {
    // Vorwärtsdeklarationen aller öffentlichen Funktionen
    string get_random_message();
}