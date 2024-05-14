/*
 * HINWEIS: Dieses Program lässt sich nicht kompilieren. Es handelt sich nur
 * um eine Sammlung typischer Syntaxelemente von C/C++ als Spickzettel.
 */



/***********************************************************************************************
 * NAME DES PROGRAMMS
 * ==================
 *
 * BESCHREIBUNG
 *
 * DATUM, EIGENER NAME, E-MAIL
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecision
#include <string>       // std::string, std::getline, ...
#include <vector>       // std::vector
#include <fstream>      // std::ifstream, std::ofstream, ...
#include <cmath>        // sin, ...

using namespace std;

int main(int argc, char **argv) {
    // Programmcode hier
    return 0;
}



// Einzeiliger Kommentar

/*
 * Mehrzeiliger Kommentar
 */

 /*
 Auskommentierter Quellcode:

 int i;
 cout "Wie oft? ";
 cin > i;
 */


// Variablendeklarationen
int       ganzzahl          = 42;
long long große_ganzzahl    = 456456163156156L;
float     kommazahl_ungenau = 47.11;
double    kommazahl_genau   = 8.15;
bool      wahr_falsch       = true;

char   zeichen    = 'a';
char*  cstring    = "Ich bin ein C-String.";
string cpp_string = {"Ich bin ein C++-String"};


// Konsolenausgabe
cout << "Hier kommt eine Zahl: " << kommazahl_genau << "." << endl;


// Tastatureingabe (fehleranfällig)
cout "Bitte eine ganze Zahl eingeben: ";
cin >> ganzzahl;


// Tastatureingabe (sicher)
string buffer;
double n;

try {
    cout "Bitte eine Kommazahl eingeben: ";
    getline(cin, buffer);
    n = stod(buffer);
} catch (...) {
    cerr << "Scherzkeks! Du hast keine Zahl eingegeben."
}


// Fallunterscheidung
if (ganzzahl < 10) {
    cout << "Die Zahl ist zu klein!" << endl;
} else if (ganzzahl > 30) {
    cout << "Die Zahl ist zu groß!" << endl;
} else {
    cout << "Die Zahl ist genau richtig." << endl;
}


switch (zeichen) {
    case "a":
        cout << "Buchstabe A" << endl;
        break;
    case "b":
        cout << "Buchstabe B" << endl;
        break;
    default:
        count << "Unbekanntes Zeichen!" << endl;
}


// Schleife
while (zahl < 100) {
    // Quellcode hier
    zahl++;
}

do {
    // Quellcode hier
    zahl++;
} while (zahl < 100);

// Initialisierung; Prüfung; Befehl vor nächstem Durchlauf
for (int i = 0; i < zahl; i++) {
    // Quellcode hier
}


/**
 * Definition einer neuen Funktion:
 * RÜCKGABETYPE NAME(TYPE PARAMETER, TYP PARAMETER, ...)
 */
void sag_hallo(char *name) {
    cout << "Hallo " < name "";
}

// Aufruf der Funktion
sag_hallo("C++");