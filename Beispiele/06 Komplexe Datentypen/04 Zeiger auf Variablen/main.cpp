/***********************************************************************************************
 * Beispiel: Zeiger auf Variablen
 * ==============================
 * 
 * Mit Referenzen haben wir im vorherigen Beispiel eine einfache Möglichkeit kennengelernt, den
 * Speicherbereich einer Variable zu teilen, so dass wir beispielsweise eine Variable an eine
 * Funktion übergeben und dort den Inhalt der exakt selben Variable ändern können. In etwa so:
 * 
 *     void change_number(int& xyz) {
 *         xyz = 24;
 *     }
 * 
 *     int number = 12;
 *     change_number(number);
 *     cout << number << endl;          // Gibt "24" aus
 * 
 * Dabei hilft es, sich den RAM-Speicher, in dem auch die Variablen eines Programms liegen, wie
 * einen großen Schrank mit Postfächern vorzustellen. Jedes Fach hat eine Postfachnummer, damit
 * man es von den anderen Fächern unterscheiden kann. In jedem Fach liegt genau ein Brief, der
 * einen einzelnen Wert speichert. Kennt man die Postfachnummer (und hat dan passenden Schlüssel),
 * kann man den darin liegenden Brief lesen oder gegen einen neuen Brief mit einem neuen Wert
 * austauschen. (Mein Dank geht an meinen früher Professor heute Kollegen Dietmar Ratz für diese
 * wirklich wunderbare Erklärung. Kaufen Sie sein Buch "Grundkurs Programmieren in Java", aus
 * dem dieses Beispiel stammt! Transparenzhinweis: Mein Name steht neuerdings auch auf dem Buch,
 * das Beispiel stammt aber noch von vor meiner Zeit. 😊)
 * 
 * Übertragen auf den Computer heißt das:
 * 
 *   1. Der RAM speichert eine Abfolge von Datenwerten (in C++ immer ein Byte, also 8 Bit, groß).
 * 
 *   2. Eine Speicherstelle im RAM wird über ihre Adresse (in C++ Zeiger oder Pointer genannt)
 *      angesprochen. Die Adresse ist eine fortlaufende Nummer, die von 0 bis RAM-Größte - 1
 *      gezählt wird.
 * 
 *   3. Da Variablen ihre Werte im RAM ablegen, besitzt jede Variable eine solche Adresse.
 * 
 *   4. Referenzen sind eine einfache Möglichkeit, die Speicheradresse einer Variable mit einer
 *      anderen Variable zu teilen, so dass beide Variablen dieselbe Stelle im RAM adressieren.
 * 
 *   5. Geht aus dem Beispiel mit den Postfächern nicht hervor: Die meisten Variablen belegen
 *      mehrere Speicheradressen, da die meisten Variablen länger als ein Byte sind.
 * 
 * Referenzen eignen sich jedoch nicht für alle Anwendungsfälle, in denen auf die Adresse einer
 * Variable zugegriffen werden soll. Denn, wie wir ja jetzt wissen, müssen Referenzen immer auf
 * eine Speicherstelle zeigen, die nachträglich nicht mehr verändert werden kann. Zeiger sind
 * deshalb der große Bruder von Referenzen, die diese Möglichkeiten bieten, dafür aber etwas
 * mehr Erfahrung im Umgang voraussetzen, um ungewollte Fehlern und Abstürze zu vermeiden.
 * 
 * Zunächst die graue Theorie dahinter. Haben wir eine Variable wie die folgende:
 * 
 *     int var1 = 32168;
 * 
 * Dann können wir mit folgender Schreibweise eine Zeiger-Variable definieren, und die Adresse
 * von var1 darin ablegen:
 * 
 *     int *ptr_var1 = &var1;
 * 
 * Ausschlaggebend ist hier das Sternchen links vom Variablennamen, das auch hier alternativ
 * am Datentyp hängen kann. Dieselbe Zeile bewirkt daher genau dasselbe:
 * 
 *     int* ptr_var1 = &var1;
 * 
 * Die haarspalterische Frage ist hier, ob man denkt, ptr_var1 ist eine "Zeigervariable" vom
 * Typ "int", oder ptr_var1 ist eine "Variable" vom Typ "Zeiger auf int". So oder so haben
 * diese Variablen aber eine besondere Eigenschaft: Sie speichern nicht einfach einen Wert
 * (hier ein int), sondern sie speichern "die Adresse, an der der Wert im Speicher liegt".
 * Also in etwa so:
 * 
 *     ╔══════════════════════════════════════════════════╗
 *     ║                 ┏━━━━━━━━┓                       ║
 *     ║                 ┃        ┃ (Adresse 0x000)       ║
 *     ║                 ┣━━━━━━━━┫    ·                  ║
 *     ║                 ┃        ┃    ·                  ║
 *     ║                 ┣━━━━━━━━┫    ·                  ║
 *     ║        var1 ══> ┃  32168 ┃ (Adresse 0xBABE) <─┐  ║
 *     ║                 ┣━━━━━━━━┫    ·               │  ║
 *     ║    ptr_var1 ══> ┃ 0xBABE ┃ (Adresse 0xCAFE) ──┘  ║
 *     ║                 ┣━━━━━━━━┫    ·                  ║
 *     ║                 ┃        ┃    ·                  ║
 *     ║                 ┣━━━━━━━━┫    ·                  ║
 *     ║                 ┃        ┃ (Adresse 0xFFFF)      ║
 *     ║                 ┗━━━━━━━━┛                       ║
 *     ╚══════════════════════════════════════════════════╝
 * 
 * Und dieser Wert kann sich ändern. Oder auf gar keine Variable zeigen, wobei man von einem
 * Null-Pointer spricht. Im Gegensatz zu Referenzen ist folgendes daher erlaubt:
 * 
 *     int* ptr_var1;
 * 
 * Ein Zeiger muss nicht sofort initialisiert werden. Sollte aber, damit er nicht auf irgend
 * eine zufällige Speicherstelle zeigt. Besser wäre daher:
 * 
 *     int *ptr_var1 = nullptr;     // Null-Pointer: Zeigt auf "nichts"
 *     int *ptr_var1 = {};          // Ebenfalls ein Null-Pointer
 *     int *ptr_var1 = &var1;       // Gültiger Pointer: Zeigt auf var1
 * 
 * Damit erklärt sich auch die Bedeutung des &-Operators: Richtig geraten! Er ermittelt die
 * Adresse einer Variable, die man beispielsweise auch auf der Konsole ausgeben kann:
 * 
 *     cout << " var1.......: " <<  var1     << " (Wert)"    << endl;
 *     cout << "&var1.......: " << &var1     << " (Adresse)" << endl;
 * 
 * Wenn man nun so einen Zeiger hat, wie kommt man wieder an den Wert, der an der Speicherstelle
 * gespeichert ist? Ganz einfach: Mit dem *-Operator. Man sagt, der Zeiger wird durch ihn
 * "dereferenziert", weil der Verweis auf den Speicherbereich dadurch wieder aufgelöst wird.
 * 
 *     cout << " ptr_var1...: " <<  ptr_var1 << " (Wert der Zeigervariable)"    << endl;
 *     cout << "*ptr_var1...: " << *ptr_var1 << " (Dereferenzierter Zeiger)"    << endl;
 *     cout << "&ptr_var1...: " << &ptr_var1 << " (Adresse der Zeigervariable)" << endl;
 * 
 * Die erste cout-Anweisung gibt deshalb die Adresse von var1 und die zweite Anweisung den
 * Wert von var1 aus. Die dritte Zeile gibt die Speicherstelle aus, an welcher der Zeiger im
 * im Speicher liegt.
 * 
 * HINWEIS: Bei den strukturierten Datentypen lernen wir mit -> noch einen weiteren Operator
 * zur Zeigerdereferenzierung kennen. Aktuell können wir ihn aber noch nicht einsetzen.
 * 
 * Nun die zweite Frage: Was macht man nun damit? In welchen Fällen braucht man Zeiger?
 * Zum Beispiel wenn …
 * 
 *  1) man Speicher auf dem Heap (deutsch: Halde) reservieren will, was wir später noch kennen
 *     lernen werden.
 * 
 *  2) eine Funktion mehr wie einen Wert zurückliefern soll.
 * 
 *  3) eine Funktion optionale (Quasi-)Referenzparameter besitzen soll.
 * 
 *  4) man mehrere Werte vom selben Typ hintereinander im Speicher ablegen will. Man nennt dies
 *     dann ein Array (deutsch: Feld), von denen wir mit den C-Strings bereits eine Sonderform
 *     kennengelernt haben: Mehrere zusammengehörige char-Werte als Zeichenkette im Speicher.
 * 
 *  5) man komplexere Datenstrukturen, deren Inhalte sich nachträglich ändern können sollen,
 *     implementieren will. Ein Klassiker ist zum Beispiel eine so genannte "Linked List"
 *     (deutsch: verknüpfte Liste), bei der man in der Mitte neue Werte einfügen oder alte
 *     Werte entfernen kann.
 * 
 * Kurz um: Zeiger finden sich überall in C/C++. In diesem Programm schauen wir uns neben den
 * oben erklärten Grundlagen ein Fallbeispiel für die Fälle zwei und drei an, die gerade in
 * älterem Code besonders häufig vorkommen: Funktionen mit optionalen Referenzparametern und
 * mehr als einem Rückgabewert.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <cstdlib>      // rand
#include <ctime>        // time

using namespace std;


// Mehrere Rückgabewerte
// ---------------------
//
// Diese Funktion soll zwei Zufallszahlen ermitteln und zurückliefern. Mit return geht
// das nicht solange, wir noch keine Strukturen kennen. Ein alter Trick ist daher, einfach
// zwei Parameter als Zeiger zu deklarieren und diese zur Rückgabe der beiden Werte zu
// nutzen. Der Aufrufe muss daher wissen, dass sich der Wert der hier referenzierten
// Variablen durch den Aufruf der Funktion ändern wird.
//
// Optionale Quasi-Referenzen
// --------------------------
//
// Zur Rückgabe mehrerer Werte hätte man random1 und random2 auch als Referenz deklarieren
// können. Jedoch müssen Referenzen immer an eine Variable gebunden werden. Diese Funktion
// soll es jedoch freistellen, ob man keine, oder oder zwei Zufallszahlen zurückgegeben
// bekommen will. Statt Referenzen müssen hier daher Zeiger verwendet und diese mit dem
// Wert nullptr als Default-Wert versehen werden.
void get_two_random_numbers(int range, int* random1 = nullptr, int* random2 = nullptr);


int main(int argc, char **argv) {
    cout << endl;
    
    // Deklaration und Verwendung von Zeigern
    int var1 = 32168;           // Ein ganz gewöhnlicher int-Wert
    int *ptr_var1 = &var1;      // Zeiger auf Int, mit Adresse von var1 initialisiert

    cout << " var1.......: " <<  var1     << " (Wert)"    << endl;
    cout << "&var1.......: " << &var1     << " (Adresse)" << endl;
    cout << endl;
    
    cout << " ptr_var1...: " <<  ptr_var1 << " (Wert der Zeigervariable)"    << endl;
    cout << "*ptr_var1...: " << *ptr_var1 << " (Dereferenzierter Zeiger)"    << endl;
    cout << "&ptr_var1...: " << &ptr_var1 << " (Adresse der Zeigervariable)" << endl;
    cout << endl;

    // Funktionen mit mehreren Rückgabewerten und optionalen Quasi-Referenzen
    int random1, random2 = {};

    get_two_random_numbers(100, &random1);
    cout << "random1.....: " << random1 << endl;
    cout << "random2.....: " << random2 << endl;
    cout << endl;

    get_two_random_numbers(25, &random1, &random2);
    cout << "random1.....: " << random1 << endl;
    cout << "random2.....: " << random2 << endl;
    cout << endl;
}


// Implementierung zur Funktion get_two_random_numbers(). Man beachte, dass hier die Default-Werte
// nicht wiederholt werden können. Dass random1 und random2 bei Nicht-Übergabe automatisch mit dem
// Wert nullptr initialisiert werden, sieht man nur bei der Funktionsdeklaration weiter oben.
// Allerdings muss man bei Zeigern sowieso IMMER damit rechnen, dass diese Null Pointer sein können.
// Deshalb: "Vertrauen ist gut. Kontrolle ist besser!"
void get_two_random_numbers(int range, int* random1, int* random2) {
    srand(time(nullptr));
    
    if (random1) *random1 = rand() % range;     // random1 optional: Nur ändern wenn kein Null Pointer!
    if (random2) *random2 = rand() % range;     // random2 optional: Nur ändern wenn kein Null Pointer!
}