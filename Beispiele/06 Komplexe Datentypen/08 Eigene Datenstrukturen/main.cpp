/***********************************************************************************************
 * Beispiel: Eigene Datenstrukturen
 * ================================
 * 
 * In den vorherigen Beispielen haben wir sequentielle und assoziative Container kennen gelernt,
 * um damit Datenreihen sowie benannte Datenpunkte effektiv verwalten zu können. Abschließend
 * schauen wir uns an, wie wir zusammengesetzte Datentypen definieren können, bei denen eine
 * Variable mehrere Werte zusammenfasst, die unterschiedliche Eigenschaften desselben Datums
 * darstellen. Als Beispiel betrachten wir hierfür ein simples Adressbuch, das Kontaktdaten zu
 * Freunden und Bekannten speichert.
 * 
 * Wie für ein Adressbuch typisch, beinhaltet jeder Eintrag mehrere Werte, besitzt insgesamt
 * aber einen festen Aufbau. In unserem Fall bestehend aus Vorname, Nachname, E-Mailadresse
 * und einem Kennzeichen für besonders wichtige VIP-Kontakte. Mit unserem bisherigen Wissen
 * könnten wir diese bereits als Arrays oder Vektoren definieren:
 * 
 *     vector<string> contacts_first_name  = {};
 *     vector<string> contacts_last_name   = {};
 *     vector<string> contacts_email       = {};
 *     vector<bool>   contacts_vip_contact = {};
 * 
 * Um einen Eintrag anzulegen müssten wir dann aber mit vier verschiedenen Vektoren arbeiten.
 * In etwa so:
 * 
 *     contacts_first_name.push_back("Max");
 *     contacts_last_name.push_back("Mustermann");
 *     contacts_email.push_back("max.mustermann@example.com");
 *     contacts_vip_contact.push_back(false);
 * 
 * Dementsprechend müssten wir auch vier verschiedene Variablen definieren, um einen einzelnen
 * Eintrag auszulesen:
 * 
 *     string first_name  = contacts_first_name.at(0);
 *     string last_name   = contacts_last_name.at(0);
 *     string email       = contacts_email.at(0);
 *     bool   vip_contact = contacts_vip_contact.at(0);
 * 
 * Das würde im Grunde zwar funktionieren, ist aber sehr fehleranfällig und wohl kaum elegant.
 * Besser wäre es, wenn wir die vier Vektoren irgendwie zu einem zusammenfassen könnten.
 * Und tatsächlich: Das geht. Alles, was wir dafür tun müssen, ist eine sogenannte Struktur
 * zu definieren, die den Aufbau eines Adressbucheintrags vorgibt. Die Syntax hierfür lautet
 * wie folgt:
 * 
 *     struct Contact {
 *         string first_name;
 *         string last_name;
 *         string email;
 *         bool   vip_contact;
 *     };
 * 
 * Dadurch haben wir nun einen neuen Datentyp namens "Contact", den wir zur Deklaration von
 * Variablen verwenden können. Zum Beispiel für einen einzelnen Adressbucheintrag:
 * 
 *     Contact c1 = {};
 * 
 * Wahlweise können wir die Felder bei der Deklaration gleich mit Werten belegen. Wie immer
 * werden diese hierbei in die geschweiften Klammern, in der Reihenfolge ihrer Definition in
 * der Struktur, geschrieben.
 * 
 *     Contact c1 = {"Max", "Mustermann", "max.mustermann@example.com", false};
 * 
 * Derselbe Datentyp lässt sich natürlich auch für die Deklaration eines Arrays oder Vektors
 * benutzen. Aus den vier einzelnen Vektoren wird dann einfach:
 * 
 *     vector<Contact> contacts = {};
 * 
 * Und auch hier können wir den Vektor wahlweise bereits bei der Deklaration mit Inhalten füllen.
 * Hierzu schreiben wir in die geschweiften Klammern Adressbucheinträge, die ihrerseits selbst
 * in geschweiften Klammern stehen müssen:
 * 
 *     vector<Contact> contacts = {
 *         {"Karl", "Klammer",    "k.klammer@office97.com",     true},
 *         {"Max",  "Mustermann", "max.mustermann@example.com", false},
 *     };
 * 
 * Natürlich lassen sich anstelle eines Vektors auch alle anderen Containertypen verwenden.
 * Und Strukturen können selbst auch Container oder weitere Strukturen beinhalten. Im Programm
 * unten werden die Adressbucheinträge daher in einer Map abgelegt, die als Schlüsselwert einen
 * String mit Vor- und Nachnamen des Eintrags verwendet.
 * 
 * Das letzte Puzzlestück, dass uns jetzt noch fehlt, ist, wie wir auf die einzelnen Werte,
 * wie den Vornamen oder die E-Mailadresse, zugreifen können. Tatsächlich kennen wir den hierfür
 * benötigten Operator schon. Es handelt sich um denselben Punkt-Operator, den wir bereits bei
 * den Containertypen kennengelernt haben. Nur, dass unsere Strukturen (noch) keine Methoden,
 * sondern bisher nur Datenfelder besitzen. Folgende Schreibweise können wir somit verwenden,
 * um die Felder (korrekt eigentlich Attribute oder Eigenschaften genannt) anzusprechen:
 * 
 *     for (const Contact &contact : contacts) {
 *         cout << "Vorname....: " << contact.first_name << endl;
 *         cout << "Nachname...: " << contact.last_name << endl;
 *         cout << "E-Mail.....: " << contact.email << endl;
 *         cout << "Wichtig....: " << (contact.vip_contact ? "Ja" : "Nein)" << endl;
 *         cout << endl;
 *     }
 * 
 * Später, wenn wir uns mit Klassen und Objekt-Orientierung auseinander setzen, werden wir
 * sehen, dass wir hier schon unsere ersten objekt-orientierten Gehversuche unternehmen. Denn
 * Strukturen sind in C++ nur eine andere Schreibweise für Klassen, bei denen alle Attribute
 * und Methoden öffentlich (public) sind. Dazu aber ein andermal mehr.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setw
#include <string>       // std::string, std::getline, ...
#include <map>          // std::map

using namespace std;

struct Contact {
    string first_name;
    string last_name;
    string email;

    bool vip_contact;
};

int main(int argc, char **argv) {
    cout << endl;

    map<string, Contact> address_book = {
        {"Karl Klammer",   {"Karl", "Klammer",    "k.klammer@office97.com",     true}},
        {"Max Mustermann", {"Max",  "Mustermann", "max.mustermann@example.com", false}},
    };

    address_book.insert({
        "Leonie Musterfrau", 
        {"Leonie", "Musterfrau", "leonie85.1@gmail.com", false}
    });

    for (const auto& [full_name, contact_card] : address_book) {
        cout << setw(20) << full_name << ": " << contact_card.email;
        cout << (contact_card.vip_contact ? " (VIP)" : "");
        cout << endl;
    }

    cout << endl;
}