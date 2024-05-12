/***********************************************************************************************
 * Beispiel: Konsolenausgaben mit C
 * ================================
 * 
 * Computerprogramme kommunizieren traditionell über die sogenannte Konsole, um Daten anzuzeigen
 * oder von der Tastatur einzulesen. Dies stammt aus den Anfängen der Computertechnik, als die
 * ersten interaktiven Programme möglich wurden, die über eine Art "elektrische Schreibmaschine"
 * Text ausdrucken und Eingaben entgegen nehmen konnten. Der Begriff "Konsole" spielt hier auf
 * das sperrige Möbelstück an, an dem man hierzu saß. Später kamen dann Videoterminals mit
 * Bildschirm und Tastatur und wieder später grafische Oberflächen, wie wir sie heute kennen.
 * Die Konsole bleibt aber immer noch die einfachste und gerade für Werkzeugprogramme bevorzugte
 * Art und Weise, mit den Benutzer*innen zu kommunizieren.
 *
 * In C kommt hier häufig die printf()-Funktion zum Einsatz. Sie erwartet im ersten Parameter
 * einen String mit dem anzuzeigenden Text, sowie beliebig viele weitere Parameter mit in den
 * Text zu integrierten Variablen. Im Text müssen hierfür mit dem Prozenzeichen eingeleitete
 * Platzhalter definiert werden, so später die Werte stehen sollen. Die Platzhalter definieren
 * dabei, wie die Wert formatiert werden sollen.
 *
 * Vgl. https://cplusplus.com/reference/cstdio/printf/
 ***********************************************************************************************/

#include <cstdio>       // printf, scanf, ...

using namespace std;

int main(int argc, char **argv) {
    printf("\n");
    printf("Wahnsinn! Eine Textausgabe auf der Konsole. Das muss man gesehen haben. :-)\n\n");

    char   text[] = "Hallo Konsole!";
    int    i_nr   = 4711;
    double d_nr   = 8.15;

    printf("C-String....: %s\n", text);
    printf("Ganzzahl....: %i\n", i_nr);
    printf("Kommazahl...: %f\n", d_nr);
    printf("\n");
}