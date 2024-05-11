/***********************************************************************************************
 * Beispiel: Hallo Welt in C++
 * ===========================
 * 
 * Seit dem Buch "The C Programming Language" der Spracherfinder Dennis Richie und
 * Brian Kernighan gehört "Hallo Welt" zur Popkultur der heutigen Zeit. Jede*r angehende
 * Programmierer*in fängt mit diesem freundlichen, kleinen Programm an, das nichts weiter
 * macht, außer den Text "Hallo Welt" auf der Konsole auszugeben.
 * 
 * Hier handelt es sich um die Variante für C++, die im Gegensatz zu C das Objekt
 * `std::cout` anstelle der `printf`-Funktion verwendet.
 ***********************************************************************************************/
#include <iostream>

/**
 * Hauptfunktion des Programms.
 */
int main(int argc, char **argv) {
	std::cout << "Hallo Welt" << std::endl;
	return 0;
}
