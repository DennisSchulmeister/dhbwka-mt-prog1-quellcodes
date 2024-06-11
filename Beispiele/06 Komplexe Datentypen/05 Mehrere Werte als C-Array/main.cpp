/***********************************************************************************************
 * Beispiel: Mehrere Werte als C-Array
 * ===================================
 * 
 * Stellen Sie sich vor, Sie hätten ein Arduino Microcontroller-Board, das tatsächlich in C++
 * programmiert wird (die so genannte "Arduino Language" ist in Wirklichkeit C++ mit einer
 * Arduino-spezifischen Standardbibliothek) und wollten damit die Temperatur vor Ihrer Haustür
 * messen. Alle fünf Minuten sollte die Temperatur gemessen und so gespeichert werden, dass
 * sowohl der Tagesverlauf nachvollzogen als auch ein gleitender Durchschnitt über die letzten
 * zwei Stunden gebildet werden kann. Wie würden Sie hierfür vorgehen?
 * 
 * Mit dem aktuellen Wissen wohl sehr umständlich. Sie bräuchten allein 288 Variablen für die
 * Messwerte eines Tages (12 Werte je Stunde mal 24). Nicht nur, dass Sie diese am Anfang des
 * Programms in meterlangem Quellcode deklarieren müssten:
 * 
 *     double temperature1 = {};
 *     double temperature2 = {};
 *     double temperature3 = {};
 *     double temperature4 = {};
 *     ...
 * 
 * Irgendwie müssten Sie es schaffen, die richtige Variable für jede Messung zu verwenden.
 * Vielleicht so etwa?
 * 
 *     int i = 0;
 * 
 *     void loop() {                                            // Arduino: Ständig wiederholte Programmlogik
 *         delay(5 * 60 * 1000);                                // Arduino: Programm fünf Minuten unterbrechen
 *         double temperature = read_temperature_sensor();      // Dummy für Sensorzugriff
 * 
 *         i = i + 1 % 288;
 * 
 *         switch (i) {
 *             case 1:  temperature1 = temperature;  break;
 *             case 2:  temperature2 = temperature;  break;
 *             case 3:  temperature3 = temperature;  break;
 *             case 4:  temperature4 = temperature;  break;
 *             ...
 *         }
 *     }
 * 
 * Irgendwas stimmt hier nicht. Kann das wirklich alles so kompliziert sein? Und wie würden
 * man in so einem Programm den Tagesverlauf auswerten oder den Durchschnitt der letzten
 * zwei Stunden berechnen? Ganz klar: So nicht.
 * 
 * Sie haben Glück! Tatsächlich ist das Problem, eine beliebige Anzahl gleichartiger Werte
 * verarbeiten zu können, mindestens so alt wie C und C++ selbst. Dementsprechend gibt es auch
 * eine einfache Lösung: Arrays (deutsch Felder). Statt 288 Variablen können Sie somit eine
 * einzige Variable, die wie eine Art Liste funktioniert, deklarieren und 288 Einträge in
 * dieser Liste direkt ansprechen. Die Syntax hierfür lautet wie folgt:
 * 
 *     double temperatures[288] = {};
 *     int i = 0;
 * 
 *     void loop() {
 *         delay(5 * 60 * 1000);
 *         temperatures[i] = read_temperature_sensor();
 *         i = i + 1 % 288;
 * 
 *         // Sonstige Berechnungen z.B. für den gleitenden Durchschnitt
 *     }
 * 
 * Schauen wir uns die wichtigsten Zeilen hiervon genauer an:
 * 
 *     double temperatures[288] = {};
 * 
 * Diese Zeile definiert eine Array-Variable mit dem Namen "temperatures", die 288 double-Werte
 * verwalten kann. Die Werte liegen hintereinander im Hauptspeicher und werden durch die Zuweisung
 * von {} mit Nullwerten initialisiert. Kleine Arrays mit wenigen vordefinierten Werten kann man
 * auch so deklarieren:
 * 
 *     double some_values[] = {95, 73, 33, 87};
 * 
 * Doch zurück zum Beispiel.
 * 
 *     temperatures[i] = read_temperature_sensor();
 * 
 * Diese Zeile nutzt den []-Operator, um einen Eintrag im Array zu adressieren und einen neuen
 * Messwert darin abzulegen. Der Wert zwischen den eckigen Klammern kann eine Literalkonstante
 * (also einfach eine Zahl) oder ein beliebig anderer Ausdruck sein, der einen int-Wert als
 * Ergebnis liefert. Man nennt die hier eingesetzte Zahl auch den "Index", mit dem auf die
 * Array-Elemente zugegriffen wird.
 * 
 * WICHTIG: Der Index wird in C/C++ immer von null an gezählt. Der erste Eintrag des Arrays
 * lautet daher temperatures[0] und der letzte Eintrag temperatures[287].
 * 
 *     i = i + 1 % 288;
 * 
 * Diese Zeile hat nur indirekt mit dem Array zu tun. Hier wird der Index für den nächsten
 * Messwert ausgerechnet, indem die Variable i um eins erhöht und dann der Rest (Modulo) einer
 * Division durch 288 gebildet wird. Als Folge daraus springt die Variable nach dem Wert 287
 * wieder auf null zurück.
 * 
 * Will man auf die Array-Elemente zugreifen, um beispielsweise den Durchschnitt aller Werte
 * zu berechnen, könnte man eine einfache for-Schleife dafür nutzen:
 * 
 *     double average = 0.0;
 *     for (int i = 0; i < 288; i++)  average += temperatures[i];
 *     average /= 288;
 * 
 * Damit ist eigentlich schon fast alles gesagt, was man über Arrays wissen muss. Allerdings
 * ist Ihnen vielleicht aufgefallen, dass die Länge des Arrays an mehreren Stellen in den
 * Beispielen als Zahl erscheint. Das offenbart ein großes Problem von klassischen C-Arrays:
 * Der Compiler kennt ihre Länge nicht! Dementsprechend kann man die Länge weder im Quellcode
 * abfragen, noch kann der Compiler erkennen, wenn man versucht, auf ein Element zuzugreifen,
 * das über die reservierte Länge des Arrays hinaus geht.
 * 
 * Eine einfache Strategie hiermit umzugehen, ist, eine Konstante für die Länge des Arrays
 * zu definieren. In etwa so:
 * 
 *     constexpr int temperature_size = 288;
 *     double temperatures[temperature_size] = {};
 * 
 *     for (int i = 0; i < temperature_size; i++) {
 *         ...
 *     }
 * 
 * Dadurch wird die Länge zumindest nur noch an einer Stelle im Quellcode definiert, so dass
 * man diese später leicht ändern kann, sollte dies notwendig werden. Ein Programmierfehler
 * kann aber immer noch dazu führen, dass man zum Beispiel versucht, auf Index 300 zuzugreifen,
 * obwohl das Array nur 288 Einträge besitzt. Doch es kommt noch kurrioser. Auch folgendes
 * ist Erlaubt:
 * 
 *     double temperatures[] = {};
 * 
 * Ein Array ohne Länge! Was passiert, wenn man versucht, darin einen Wert abzulegen?
 * Zum Beispiel so:
 * 
 *     temperatures[i] = read_temperature_sensor();
 * 
 * Wenn man Glück hat, nichts. Wenn man Pech hat, überschreibt man irgend eine andere Variable.
 * Wenn es doof läuft, überschreibt man einen Teil des Programmcodes. Wenn es ganz blöd kommt,
 * stürzt das Programm ab. Im C/C++-Sprachgebrauch ist das Programm "nicht korrekt" (englisch
 * ill-formed) und das Verhalten ist undefiniert. Denn tatsächlich zeigt die Array-Variable
 * auf eine Stelle im Speicher. Da das Array aber keine Länge besitzt, liegt an dieser Stelle
 * sehr wahrscheinlich irgend ein anderer Wert. Ups!
 * 
 * Genauso gefährlich ist es, über die Länge eines Array hinaus zu gehen. Bei unserem Array mit
 * exakt 288 Einträgen würde folgende Zeile einfach irgend einen Wert im Speicher überschreiben.
 * Sehr wahrscheinlich eine andere Variable:
 * 
 *     temperatures[300] = 3.686;
 * 
 * Denn der Compiler nimmt einfach die Startadresse des Arrays und addiert 300 mal die Größe
 * eines double-Werts hinzu, um die adressierte Speicherstelle zu berechnen. Da für das Array
 * aber weniger Speicher reserviert wurde, schießt er dabei, ohne es zu merken, über das Ziel
 * hinaus und schreibt fröhlich die double-Zahl 3.686 dorthin. Das liegt an einer zweiten,
 * besonderen Eigenschaft von Arrays in C:
 * 
 * Arrays sind überwiegend "syntaktischer Zucker" für Zeiger in C/C++. Eine Array-Variable
 * ist immer auch ein Zeiger. Und mit Zeigern kann man rechnen, was "Zeigerarithmetik" (englisch
 * Pointer Arithmetic) genannt wird. Hier zum Vergleich ein Zeiger auf einen double-Wert:
 * 
 *     double  val = 0.0;
 *     double *ptr_val = &val;
 * 
 * Damit haben wir natürlich nur Platz für einen einzelnen Wert reserviert. Wüssten wir aber,
 * dass an der Speicherstelle, auf die der Zeiger zeigt, tatsächlich Platz für zum Beispiel
 * zehn double-Werte ist, könnten wir sowohl mit der Array-Schreibweise als auch mit der
 * Zeigerschreibweise auf diese Einträge zugreifen:
 * 
 *     ptr_val[2] = 12.34;      // Dritten Wert ändern
 * 
 * Wäre gleichbedeutend zu:
 * 
 *     *(ptr_val + 2) = 12.34;
 * 
 * Die zweite Syntax ist weniger schön. Es passiert aber exakt dasselbe:
 * 
 *   1. Addiere zur Speicheradresse die Länge von zwei double Werten (nicht zwei Bytes!)
 *   2. Dereferenziere den Zeiger, um auf die errechnete Speicherstelle zuzugreifen (*-Operator)
 *   3. Schreibe an die Speicherstelle den neuen Wert 12.34
 * 
 * Dadurch erklärt sich, warum der Compiler die Länge eines Arrays nicht kennt: Streng genommen
 * gibt es gar keine Arrays in C, sondern nur Zeiger, die eine Speicheradresse beinhalten.
 * Und mit Speicheradressen kann man rechnen. Anfang der 1970er-Jahre war dies ausreichend,
 * um die erste Version von UNIX implementieren zu können. Die oben beschriebenen Probleme
 * plagen C-Programmierer*innen aber immer noch heute. 🤕 C++-Entwickler*innen eigentlich auch.
 * Dort hat man aber in der Standardbibliothek neue Typen definiert, die klassische C-Arrays
 * in den meisten Fällen obsolet machen. Siehe nächstes Beispiel.
 * 
 * Doch auch eine andere Sache lässt sich dadurch nun abschließend erklären: Die Funktionsweise
 * von C-Strings. Also Variablen, die wie folgt deklariert werden:
 * 
 *     char text[] = "Ich bin ein C-String!";
 * 
 * Beziehungsweise gleichbedeutend:
 * 
 *     char *text = "Ich bin ein C-String";
 * 
 * Die erste Variante deklariert ein char-Array, die zweite einen char-Zeiger. Wie wir nun
 * wissen, ist beides dasselbe. Es gibt wirklich keinen Unterschied, außer dass die erste
 * Variante die Absicht hinter der Variable besser erklärt: Eine Menge von Zeichen zu speichern.
 * Und da Arrays keine eingebaute Länge haben, muss der Compiler den String mit einem Null-Byte
 * abschließen, damit das Ende des Strings sicher erkannt werden kann.
 * 
 * Kommen wir mit dieser Erkenntnis auch nochmal abschließend zur main()-Funktion eines jeden
 * C/C++-Programms zurück. Diese ist wie folgt definiert:
 * 
 *     int main(int argc, char **argv) {
 *         ...
 *     }
 * 
 * An anderer Stelle haben wir gesehen, dass argc und argv die Argumente codieren, die dem
 * Programm bei seinem Aufruf mitgegeben werden. Meistens, indem man ein Terminalfenster
 * öffnet und dort die Argumente hinter den Programmnamen schreibt. Zum Beispiel unter Windows:
 * 
 *     main.exe --enable-feature-a --output-file data.csv
 * 
 * argc enthält in diesem Fall die Zahl 4 und argv ein Array mit C-Strings. Genau genommen
 * also ein zwei-dimensionales Array, da jeder C-String selbst ja auch ein Array ist.
 * Tatsächlich könnte man argv deshalb auch als argv[][] deklarieren. Der Folgende Quellcode
 * zeigt die darin gespeicherten Inhalte:
 * 
 *     for (int i = 0; i < argc; i++) {
 *         cout << argv[i] << endl;
 *     }
 * 
 * Dies würde in unserem Beispiel folgende Konsolenausgabe erzeugen:
 * 
 *     main.exe
 *     --enable-feature-a
 *     --output-file
 *     data.csv
 * 
 * Da argv[i] ebenfalls ein Array ist, kann man auch auf die einzelnen Zeichen zugreifen:
 * 
 *     for (int i = 0; i < argc; i++) {
 *         for (int j = 0; j < strlen(argv[i]); j++) {
 *             char c = argv[i][j];     // Einzelnes Zeichen
 *         }
 *     }
 * 
 * Alles klar? Dann haben Sie Zeiger, C-Arrays und C-Strings komplett verstanden. 👍
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecision
#include <thread>       // std::this_thread::sleep_for
#include <chrono>       // std::chrono::seconds
#include <cstdlib>      // rand
#include <ctime>        // time

using namespace std;


// Hilfsmethode zur Simulation eines Sensors
double get_measurement() {
    static double value = 1.0 * (1 + (rand() % 100)) / (1 + (rand() % 10));
    double change = 1.0 * (1 + (rand() % 20)) / (1 + (rand() % 10));
    change = (change / 2) - 1;
    value += change;
    
    return max(0.0, value);
}

int main(int argc, char **argv) {
    cout << endl;
    cout << "Programm beenden mit Strg+C" << endl;
    cout << endl;
   
    srand(time(nullptr));

    // Die Variable ring_buffer ist ein Array mit zehn double-Werten. Wie der Name andeutet,
    // wird es als Ringspeicher genutzt, der stets die letzten zehn Messwerte beinhaltet, damit
    // ein gleitender Durchschnitt über diese berechnet werden kann. Die Konsolenausgabe zeigt,
    // welcher Eintrag im Puffer nach einer Messung überschrieben wird.
    constexpr int buffer_size = 10;
    double ring_buffer[buffer_size] = {};                                       // Array-Definition
    int i = 0;

    while (true) {
        // Programm für eine Sekunde anhalten
        this_thread::sleep_for(chrono::seconds(1));

        // Nächsten Messwert im Puffer ablegen
        ring_buffer[i] = get_measurement();                                     // Array-Zugriff
        i = (i + 1) % buffer_size;

        // Gleitenden Durchschnitt berechnen
        double average = 0.0;
        for (int j = 0; j < buffer_size; j++)  average += ring_buffer[j];       // Array-Zugriff
        average = average / buffer_size;

        // Werte auf dem Bildschirm ausgeben
        cout << "[ ";

        for (int j = 0; j < buffer_size; j++) {;
            if (i - 1 == j || (i == 0 && j + 1 == buffer_size))  cout << " {";  else cout << "  ";
            cout << setprecision(3) << setw(4) << ring_buffer[j];               // Array-Zugriff
            if (i - 1 == j || (i == 0 && j + 1 == buffer_size))  cout << "} ";  else cout << "  ";
        }

        cout << "]   avg = " << setprecision(3) << setw(4) << average << endl;
    }
}