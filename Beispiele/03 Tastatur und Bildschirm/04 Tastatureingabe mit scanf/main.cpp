/***********************************************************************************************
 * Beispiel: Tastatureingabe mit scanf
 * ===================================
 * 
 * Tastatureingaben werden in C häufig mit der scanf()-Funktion realisiert, die allerdings nicht
 * ganz einfach zu nutzen ist. Sie erstartet zwei Parameter:
 *
 *   1) Einen Formatstring
 *   2) Speicheradresse einer Variable
 *
 * Der Formatstring definiert, was für eine Eingabe erwartet wird. Der eingegebene Wert wird,
 * sofern er dem Format entspricht, in die Variable geschrieben. Allerdings gibt es hier viele
 * Stolpersteine:
 *
 *   - Die Formatstrings können schnell kompliziert werden.
 *
 *   - Bei C-Strings muss die max. Anzahl Zeichen angeben werden, damit Leerzeichen korrekt
 *     eingelesen werden und die Eingabe nicht beim ersten Leerzeichen abbricht. Außerdem
 *     werden so Pufferüberläufe verhindert!
 *
 *   - Die Eingabe endet nicht bei ENTER, sondern beim ersten ungültigen Zeichen. Die
 *     restlichen Zeichen werden einfach vom nächsten scanf()-Aufruf interpretiert, was oft
 *     zu unerwarteten Ergebnissen führt.
 *
 * Probieren Sie es aus! Geben Sie erst lauter korrekte Werte ein und dann lauter inkorrekte
 * Werte. Beispielsweise eine Kommazahl, wo eine Ganzzahl erwartet wird, oder ein Text ...
 * Hätten Sie jeweils gedacht, dass sich das Programm so verhält, wie es tut?
 ***********************************************************************************************/

#include <cstdio>       // printf, scanf, ...

using namespace std;

int main(int argc, char **argv) {
    char   text[100];
    int    i_nr;
    double d_nr;

    printf("\n");

    printf("Bitte einen Text eingeben.......: ");
    scanf("%99[^\n]", text);
    // %99[^n] --> Maximal 99 Zeichen ohne den durch ENTER ausgelösten Zeilenumbruch

    printf("Bitte eine Ganzzahl eingeben....: ");
    scanf("%i", &i_nr);

    printf("Bitte eine Kommazahl eingeben...: ");
    scanf("%lf", &d_nr);

    printf("\n");
    printf("Folgendes haben Sie eingeben:\n");
    printf("\n");
    printf("C-String....: %s\n", text);
    printf("Ganzzahl....: %i\n", i_nr);
    printf("Kommazahl...: %f\n", d_nr);
    printf("\n");
}