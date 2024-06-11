/***********************************************************************************************
 * Beispiel: Intelligente Arrays, Vektoren, Listen
 * ===============================================
 * 
 * Aufgrund der zuvor beschriebenen Einschränkungen und potentiellen Fehlerquellen im Umgang mit
 * klassischen C-Arrays besitzt die C++-Standardbibliothek eine Vielzahl intelligenterer Typen,
 * welche die direkte Nutzung von C-Arrays in den allermeisten Fällen obsolet machen. Sie werden
 * Container genannt, da ihre einzige Aufgabe darin besteht, ähnlich wie ein Array, eine Sammlung
 * gleichartiger Daten beliebiger Anzahl zu verwalten. Die Standardbibliothek liefert dabei
 * unterschiedliche Containertypen, die für unterschiedliche Anwendungen optimiert sind. Die
 * wichtigsten hierbei sind:
 * 
 *  - std::array:  Container mit fester Größe. Daten liegen auf dem Stack.
 *  - std::vector: Container mit variabler Größe. Daten liegen auf dem Heap.
 *  - std::list:   Doppelt-verkettete Liste variabler Länge. Daten liegen auf dem Heap.
 * 
 * Sie werden prinzipiell alle auf dieselbe Weise verwendet, unterscheiden sich jedoch im Detail
 * in ihrer Implementierung und den Fähigkeiten. Beispielsweise kann ein std::array nur eine
 * feste zur Compilierzeit bekannte Größe besitzen, während die Größe des Containers bei den
 * anderen beiden Typen zur Laufzeit wachsen und schrumpfen kann. Vektoren und Listen kümmern
 * sich intern um die komplette Speicherverwaltung, so dass man sich darüber eigentlich nie
 * Gedanken machen muss. Jedoch sollte man wissen, wie die Container intern arbeiten, um
 * den richtigen Containertyp für einen Anwendungsfall auswählen zu können:
 * 
 * Vektoren nutzen intern ein C-Array, das alle Werte dicht gepackt im Speicher anordnet. Dies
 * bringt gerade bei kleinen Datentypen wie Zahlen enorme Geschwindigkeitsvorteile beim Zugriff.
 * Auch verursacht das Anhängen neuer Elemente am Ende keine nennenswerten Kosten. Dafür können
 * keine Werte in der Mitte eingefügt werden, ohne größere Teile des Vektors im Speicher hin
 * und her zu kopieren.
 * 
 * Listen arbeiten stattdessen mit einer Datenstruktur, die doppelt verkettete Liste genannt
 * wird. Die Elemente liegen dabei als einzelne Elemente verstreut im Speichern, verweisen aber
 * mit Zeigern auf das jeweils vorherige und nachfolgende Element. Dadurch können billig an jeder
 * Position neue Elemente eingefügt oder alte Elemente entfernt werden. Die Zugriffe sind jedoch
 * weniger performant und man kann nicht einfach mit einem Index beispielsweise auf das dritte
 * Element zugreifen. Für kleine Datentypen wie Integer ist die Verwendung einer verketteten
 * Liste ein enormer Speicher-Overhead im Vergleich zu Vektoren.
 * 
 * Das nachfolgende Programm zeigt, wie die unterschiedlichen Container definiert, initialisiert
 * und verwendet werden. Es zeigt dabei auch, welche typischen Operationen die Container jeweils
 * unterstützen und wie ungültige Indexzugriffe ohne Programmabsturz abgefangen werden können.
 * Die wichtigsten Methoden hierbei sind:
 * 
 *  - at(index):                  Indexzugriff auf einen einzelnen Wert, mit Range-Prüfung
 *  - Operator [index]:           Array-Schreibweise für Indexzugriffe, allerdings ohne Range-Prüfung!
 *  - push_front(element):        Einfügen neuer Elemente am Anfang des Containers
 *  - push_back(element):         Einfügen neuer Elemente am Ende des Containers
 *  - insert(position, element):  Einfügen neuer Elemente mitten im Container
 *  - size():                     Aktuelle Größe des Containers abfragen
 * 
 * Methoden? Haben wir bisher nicht immer von Funktionen oder Unterprogrammen gesprochen?
 * Ja richtig. Hier erhalten wir jedoch einen kleinen Vorgeschmack auf die objekt-orientierte
 * Programmierung, bei der ein Objekt (hier zum Beispiel ein Array) nicht nur Daten, sondern
 * auch so genannte Methoden besitzen kann, die im Grunde genommen spezielle Funktionen nur
 * für das Objekt sind. Nehmen wir zum Beispiel folgenden Container an:
 * 
 *     vector<int> vec = {11, 22, 33};
 * 
 * Dann können wir mit vec.xxx auf die Daten und Methoden des Vectors zugreifen. Dabei kann
 * es sich um zum Objekt gehörige Variablen oder um zum Objekt gehörige Funktionen handeln,
 * die wir wie gewohnt mit runden Klammern aufrufen. Um die Anzahl der Vektorelemente zu
 * erhalten schreiben wir daher:
 * 
 *     cout << "Anzahl: " << vec.count() << endl;
 * 
 * Dies würde die Zahl "3" ausgeben, da drei Elemente in dem Vektor enthalten sind.
 * 
 * Alle Container unterstützen darüber hinaus das Iterator-Protokoll, so dass mit for-each
 * über ihre Elemente iteriert werden kann:
 * 
 *     for (const auto &element : container) {
 *         // Tue irgendwas mit element aus container
 *     }
 ***********************************************************************************************/

#include <iostream>     // cout, cin, ...
#include <array>        // array
#include <vector>       // vector
#include <list>         // list

using namespace std;


// Hilfsfunktion zur Anzeige der Container-Elemente
template<class T>
void print_container(string type, const T &container);


int main(int argc, char **argv) {
    cout << endl;

    array<int, 5> arr = {1, 2, 3, 4, 5};            // array  - Container fester Größe
    vector<int>   vec = {1, 2, 3, 4, 5};            // vector - Container mit dynamischer Größe
    list<int>     lst = {1, 2, 3, 4, 5};            // list   - Doppelt-verkettete Liste

    arr[0] = 11;
    arr[1] = 22;
    arr[2] = 33;
    arr[3] = 44;
    arr[4] = 55;
    
    try {
        // arr[1000] = 66                            // Undefined Behaviour! Programm könnte abstürzen!
        arr.at(1000) = 66;                           // Besser: Wirft den Laufzeitfehler std::out_of_range
    } catch (std::out_of_range const &exception) {
        cout << "Fehler: " << exception.what() << endl << endl;
    }

    vec[0] = 11;
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    // vec[1000] = 99;                              // Undefined Behaviour! Programm könnte abstürzen!
    // vec.at(1000) = 66;                           // Besser: Wirft den Laufzeitfehler std::out_of_range

    lst.push_front(0);
    lst.insert(lst.begin(), -1);
    lst.insert(lst.end(), 6);
    lst.push_back(7);

    print_container("array<int, 5>", arr);
    print_container("vector<int>", vec);
    print_container("list<int>", lst);
}


template<class T>
void print_container(string type, const T &container) {
    cout << type << " (Größe " << container.size() << ")" << endl;

    for (const auto &element : container) {
        cout << element << " ";
    }

    cout << endl << endl;
}