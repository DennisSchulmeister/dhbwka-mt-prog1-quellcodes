/***********************************************************************************************
 * Beispiel: Hallo Welt (C)
 * ========================
 * 
 * Seit dem Buch "The C Programming Language" der Spracherfinder Dennis Richie und
 * Brian Kernighan gehört "Hallo Welt" zur Popkultur der heutigen Zeit. Jede*r angehende
 * Programmierer*in fängt mit diesem freundlichen, kleinen Prorgamm an, das nichts weiter
 * macht, außer den Text "Hallo Welt" auf der Konsole auszugeben.
 * 
 * Hier handelt es sich um die Variante für C, die im Gegensatz zu C++ die Funktion
 * `printf` anstelle des `std::cout`-Objekts verwendet.
 ***********************************************************************************************/
#include <stdio.h>

/**
 * Hauptfunktion des Programms.
 */
int main(int argc, char **argv) {
	printf("Hallo Welt\n");
	return 0;
}
