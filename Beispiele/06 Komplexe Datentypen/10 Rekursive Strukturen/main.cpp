/***********************************************************************************************
 * Beispiel: Rekursive Strukturen
 * ==============================
 * 
 * Dieses Beispiel zeigt mehrere der zuvor vorgestellten Konzepte in Kombination. Wir haben
 * hier eine Struktur, die beispielsweise in einem produzierenden Unternehmen die Stückliste
 * (englisch Bill of Material, kurz BOM) eines herzustellenden Gegenstands speichern könnte.
 * Diese zeichnet sich durch eine rekursive Definition aus, bei der ein herzustellendens
 * Teil aus beliebig vielen, weiteren Teilen bestehen kann.
 * 
 * Um Stücklisten dieser Art verwalten zu können, wird am Anfang des Programm ein strukturierter
 * Datentyp mit dem Namen `bom_t` (das `_t` steht für Type) definiert. Die Rekursion wird durch
 * einen std::vector<bom_t> hergestellt.
 * 
 * Am Anfang der main-Funktion werden werden zwei Stücklisten für zwei Produkte definiert: Eine
 * Tastatur und ein Gaming-PC. Die Schreibweise mit den geschweiften Klammern ist etwas schwer
 * zu lesen. Es handelt sich dabei (von außen nach innen) um die Initialisierung der Variable
 * selbst, des darin enthaltenen Vektors und der Einträge innerhalb des Vektors, wobei sich beim
 * dritten Schritt die Reihenfolge wiederholt.
 * 
 * Zur Ausgabe der Stücklisten gibt es hier eine Hilfsfunktion, die einen Zeiger vom Typ bom_t*
 * auf die anzuzeigende Stückliste sowie einen String zur Einrückung erwartet. Innerhalb der
 * Funktion werden Einrückung und Name des Bauteils ausgeben, bevor sich die Funktion selbst
 * aufruft, um mit einer tiefen Einrückung dessen Unterkomponenten anzuzeigen.
 * 
 * Sowohl in der main-Funktion als auch der print_bom-Funktion wird mit einer Zählvariable i
 * gearbeitet. Da die Variablen einer Funktion aber unabhängig von den Variablen einer anderen
 * Funktion existieren, beeinflussen sie sich gegenseitig nicht. Auch ist es kein Problem, dass
 * sich die Funktion `print_bom()` rekursiv selbst aufruft. Die rufende Funktion ist dann zwar
 * noch im Speicher vorhanden, die aufgerufene Version erhält aber ihren einen "Call Frame"
 * (deutsch Funktionsrahmen) auf dem Stack, in dem ihre Variablen liegen. Das `i` der rekursiv
 * aufgerufenen Funktion `print_bom()` stört also das `i` der rufenden Funktion `print_bom()`
 * nicht. Alles klar? :-)
 ***********************************************************************************************/

#include <cstdint>      // Plattformunabhängige Ganzzahlen
#include <iostream>     // std::cout, std::cin, ...
#include <string>       // std::string, std::getline, ...
#include <vector>       // std::vector

using namespace std;

struct bom_t {
    string name;
    vector<bom_t> children;
};

void print_bom(bom_t* bom, string indent);

int main(int argc, char **argv) {
    cout << endl;

    bom_t keyboard = {"Tastatur", {
        {"Gehäuse", {}},
        {"Tastenkappen", {}},
        {"Cherry Key Switch MX", {}},
        {"Platine", {}}
    }};

    bom_t computer = {"Gaming PC Ultimate Pro 2000X", {
        {"Chasis", {
            {"Mini-Tower Gehäuse", {}},
            {"Netzteil 250 Watt", {}},
        }},
        {"Laufwerke", {
            {"Festplatte SDD 2 TB", {}},
            {"Blueray-Brenner", {}},
        }},
        {"Hauptplatine", {
            {"Asus Motherboard", {}},
            {"CPU Intel i7", {}},
            {"RAM 24 GB", {}},
            {"Grafikkarte NVIDIA", {}}
        }},
    }};

    bom_t products[] = {keyboard, computer};
    constexpr int SIZE = sizeof(products) / sizeof(bom_t);

    for (int i = 0; i < SIZE; i++) {
        print_bom(&products[i], " - ");
        cout << endl;
    }

    cout << endl;
}

void print_bom(bom_t* bom, string indent) {
    cout << indent << bom->name << endl;

    for (int i = 0; i < bom->children.size(); i++) {
        print_bom(&bom->children[i], "   " + indent);
    }
}