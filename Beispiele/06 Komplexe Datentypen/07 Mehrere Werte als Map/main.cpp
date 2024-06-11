/***********************************************************************************************
 * Beispiel: Mehrere Werte als Map
 * ===============================
 * 
 * Arrays, Vektoren und Listen sind so genannte sequentielle Container, weil die darin abgelegten
 * Daten eine Reihenfolge besitzen, die sich meist aus der Reihenfolge ergibt, in der die Daten
 * in den Container geschrieben wurden. Die Container besitzen aber auch eine sort()-Methode, um
 * ihre Inhalte zu sortieren und einige von ihnen erlauben es, an bestimmten Stellen Elemente
 * einzufügen oder zu löschen.
 * 
 * Manchmal hat man aber zwar mehrere Daten vom selben Typ. Die Daten haben aber keine inhärente
 * Reihenfolge sondern eher einen Namen (oder einen anderen Schlüsselwert), anhand dessen sie
 * auseinander gehalten werden können. Zum Beispiel in einem Smart Home, bei dem an verschiedenen
 * Orten Temperatursensoren installiert wurden. Hier gibt es keine Reihenfolge, aus der man
 * sinnvolle Rückschlüsse ziehen könnte. Jeder Sensor kann aber mit einem Raum verknüpft werden,
 * so dass man ablesen kann, wie die Temperatur im Wohnzimmer, Schlafzimmer oder in der Küche
 * gerade ist.
 * 
 * Der Container der Wahl ist hier eine Map (auf deutsch etwas irreführend auch assoziatives
 * Array genannt). Eine Map speichert beliebig viele Einträge, ordnet den Einträgen dabei meist
 * aber keine Reihenfolge zu (manche Implementierungen merken sich die Reihenfolge, in der die
 * Einträge hinzugefügt wurden und können diese rekonstruieren). Stattdessen wird jedem Eintrag
 * ein Schlüsselwert zugewiesen, um ihn später wieder auffinden zu können. Man spricht hier
 * auch von Key und Value.
 * 
 * Maps haben dabei die besondere Eigenschaft, dass alle Keys vom selben Datentyp sein müssen,
 * sowie alle Values einen einheitlichen Datentyp besitzen müssen. Bei der Deklaration einer
 * Map müssen die beiden Datentypen daher in spitzen Klammern (als sog. Template Parameter)
 * mitgegeben werden:
 * 
 *     map<string, double> temperature_sensors = {};
 * 
 * Wahlweise kann die Map bei der Deklaration gleich mit Einträgen initialisiert werden:
 * 
 *     map<string, double> temperature_sensors = {
 *         {"Wohnzimmer":   22.3},
 *         {"Schlafzimmer": 22.6},
 *     };
 * 
 * Neue Einträge werden mit insert() hinzugefügt:
 * 
 *     temperature_sensors.insert({"Arbeitszimmer", 22.4});
 * 
 * Und mit dem []-Operator kann auf einzelne Elemente zugegriffen werden:
 * 
 *     temperature_sensors["Wohnzimmer"] = 22.7;
 * 
 * Eine besondere Form der for-each-Schleife bieten abschließend noch die Möglichkeit, ob alle
 * Einträge einer Map in einer unbestimmten Reihenfolge zu iterieren:
 * 
 *     for (const auto &[key, value] : temperature_sensors) {
 *         // Tue irgendwas mit dem in key stehenden Namen
 *         // Tue irgendwas mit der in value stehenden Temperatur
 *     }
 * 
 * Das untenstehende Programm zeigt einen vollständigen Quellcode hierzu.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setw
#include <string>       // std::string, std::getline, ...
#include <map>          // std::map

using namespace std;

int main(int argc, char **argv) {
    cout << endl;

    map<string, double> temperature_sensors = {
        {"Vor dem Haus", 28.4},
        {"Im Garten",    27.1},
        {"Wohnzimmer",   22.3},
        {"Schlafzimmer", 22.6},
    };

    temperature_sensors.insert({"Arbeitszimmer", 22.4});    // Achtung: Geschweifte Klammern!
    temperature_sensors["Wohnzimmer"] = 22.7;

    for (const auto &[key, value] : temperature_sensors) {
        cout << setw(15) << key << ": " << value << "° C" << endl;
    }

    cout << endl;
}