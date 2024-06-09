/***********************************************************************************************
 * Beispiel: CPU-Simulator in mehreren Dateien
 * ===========================================
 * 
 * Dies ist eine Variation des vorherigen Beispiels. Es handelt sich um dasselbe Programm, das
 * genau den gleichen fiktiven 16-Bit Computer emuliert. Der Quellcode wurde hier aber, wie in
 * einem der vorherigen Beispiele gezeigt, in mehrere Quellcode-Dateien gegliedert, um sowohl
 * die Übersichtlichkeit zu erhöhen, als auch die Compilierzeit zu optimieren. Denn durch die
 * Verwendung mehrerer *.cpp-Dateien muss immer nur die Datei neu compiliert werden, die sich
 * tatsächlich verändert hat.
 * 
 * Wichtig zu verstehen ist, dass jede *.cpp-Datei eine eigene "Übersetzungseinheit" darstellt
 * und deshalb vom Compiler zu einem Objektmodul (Objektcode-Datei) mit der Endung *.o übersetzt
 * wird. Dabei muss der Compiler nur die Deklarationen der anderen Module kennen, auf die hier
 * zugegriffen werden soll, wozu die jeweilige Header-Datei inkludiert werden muss. Der Linker
 * fügt die Objektdateien dann zum fertigen Programm zusammen und löst dabei die gegenseitigen
 * Verweise auf.
 * 
 * HINWEIS:
 * #include "xyz.hpp" bezieht sich auf das eigene Quellcode-Verzeichnis.
 * #include <xyz> bezieht sich auf installierte Bibliotheken und die Standardbibliothek.
 ***********************************************************************************************/

#include "computer.hpp" // Deklarationen zur Objektdatei computer.o, die aus computer.cpp erzeugt wird
#include <iostream>     // std::cout, std::cin, ...

using namespace std;

int main(int argc, char **argv) {
    struct computer_t computer = {};

    computer.ram = {
        // Programmcode
        op(MOVE, REG_A, VAL), 12,           // Lade in Register A den Wert 12 (Speicheradresse mit Textdaten)
        op(MOVE, REG_B, PTR_A),             // Lade in Register B den Wert an der Speicheradresse aus Register A
        op(JZR, VAL), 11,                   // Springe zur HLT-Anweisung in Speicherstelle 11, wenn der gelesene Wert null ist
        op(WRITE, VAL, REG_B), IO_TTY,      // Gebe das Zeichen in Register B auf dem Bildschirm aus
        op(ADD, REG_A, VAL), 1,             // Erhöhe den Wert in Register A (Speicheradresse mit Textdaten) um eins
        op(JMP, VAL), 2,                    // Springe zurück zur zweiten Anweisung (Speicherstelle 2)
        op(HALT),                           // Halte das Programm an

        // Daten
        '\n',
        'M', 'e', 'i', 'n', ' ',
        'v', 'i', 'r', 't', 'u', 'e', 'l', 'l', 'e', 'r', ' ',
        'C', 'o', 'm', 'p', 'u', 't', 'e', 'r', ' ',
        's', 'a', 'g', 't', ' ',
        'H', 'a', 'l', 'l', 'o', '!', '\n', 0,
    };

    computer.ram.resize(128);
    computer.cpu.sp = computer.ram.size() - 1;

    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    while ((computer.cpu.flags & FLAG_HLT) == 0) {
        execute(computer);
    }

    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl << "Virtuelle CPU angehalten." << endl;
    cout << endl;
    cout << status(computer);
    cout << endl;
}