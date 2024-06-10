/***********************************************************************************************
 * Beispiel: Aufzählungen mit enum
 * ===============================
 * 
 * In bestimmten Fällen kommt es immer mal wieder vor, dass man für eine Reihe zusammengehöriger
 * Werte sprechende Konstanten benötigt. Für den Computer ist es meist am Besten, wenn die Werte
 * numerisch codiert werden, weil ganzzahlige Nummern wenig Speicherplatz beanspruchen und sehr
 * schnell verarbeitet werden können. Wollte man beispielsweise in einer Kalenderanwendung mit
 * Wochentagen umgehen, läge es deshalb nahe, statt den Zeichenketten "Montag", "Dienstag",
 * "Mittwoch" usw. die Tage durchzunummerieren:
 * 
 *  0 = Montag
 *  1 = Dienstag
 *  2 = Mittwoch
 *  ...
 * 
 * Will man zusätzlich codieren können, ob ein Kalendereintrag überhaupt mit einem Wochentag
 * verknüpft ist, könnte man die Zahl null hierfür verwenden und die eigentlichen Tage von eins
 * beginnend zählen:
 * 
 *   0 = Kein Tag
 *   1 = Montag
 *   2 = Dienstag
 *   ...
 * 
 * Doch hieran zeigt sich auch schon ein Problem. Wie sieht man einer Zahl im Quellcode an,
 * wofür sie steht? Dass es sich um Wochentage handelt, ergibt sich meist aus dem Kontext.
 * Aber hat der erste Tag der Woche nun die Zahl null oder eins? Und ist der erste Tag ein
 * Montag, so wie in Mitteleuropa üblich, oder ein Sonntag, wie zum Beispiel in den USA?
 * Klar kann und sollte man diese Dinge in einem Kommentar festhalten. Doch was macht man in
 * sehr großen Programmen mit hunderten oder gar tausenden Quellcodezeilen, wo an vielen Stellen
 * mit Wochentagen gerechnet wird? Eine Möglichkeit wäre, Konstanten zu definieren:
 * 
 *     constexpr int NO_DAY  = 0;
 *     constexpr int MONDAY  = 1;
 *     constexpr int TUESDAY = 2;
 *     ...
 * 
 * Überall, wo man einen Wochentag benötigt, kann man dann statt der Zahl eine der Konstanten
 * verwenden. Der Quellcode wird dadurch sehr viel lesbarer und weniger fehleranfällig, da man
 * nie mehr über die Interpretation der Zahlen nachdenken muss. Doch es geht noch besser. Zum
 * einen ist die häufige Wiederholung von "constexpr int" etwas lästig zu tippen. Doch viel
 * Wichtiger: Die Konstanten haben alle den Typ "int", der ja bekanntlich für alle möglichen
 * Ganzzahlen stehen kann. Dadurch könnten wir auch viele "dumme" Sachen machen, die überhaupt
 * keinen Sinn ergeben, zum Beispiel:
 * 
 *  - Einen Wochentag neun, zehn oder 12 erfinden (manchmal könnte man den gebrauchen)
 *  - Wochentage und Geldbeträge addieren
 *  - Eine Anzahl Termine verwenden, wo Wochentage erwartet werden
 *  - Und vieles mehr
 * 
 * Muss man eben aufpassen, könnten man jetzt sagen. Jedoch kann uns der Compiler sehr leicht
 * unter die Arme greifen, um derartige Fehler zu vermeiden. Wir müssen die Konstanten lediglich
 * nicht als Konstanten sondern als Aufzählungstyp deklarieren. Die Syntax hiefür lautet:
 * 
 *     enum TYP {
 *         KONSTANTE1, KONSTANTE2, KONSTANTE3, ...
 *     };
 * 
 * Wochentage könnte man zum Beispiel so definieren:
 * 
 *     enum weekday_t {
 *         MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
 *     }
 * 
 * Hierdurch definiert man einen neuen Datentyp mit dem Namen "weekday_t", den man für die
 * Deklaration von Variablen oder in Funktionssignaturen verwenden kann:
 * 
 *     weekday_t day = MONDAY;
 *     weekday_t get_day_of_week(std::time_point t) { ... }
 *     ...
 * 
 * Und wieder wird der Quellcode ein Stück leserlicher, weil einer Variable jetzt auch an
 * ihrem Typ ansieht, wofür sie gedacht ist. Der exakte Wert der Konstanten ist dabei oft
 * nebensächlich und wird deshalb im Quellcode gar nicht angegeben. Die Konstanten werden
 * dann einfach in der Reihenfolge ihrer Definition von null an gezählt. Montag entspricht
 * also der Zahl null, Dienstag der eins usw. Will man dies ändern, kann man für einen oder
 * mehrere Konstanten den Wert fest vorgeben. Im Beispiel unten wird dies für die Monate
 * gemacht, damit diese immer von eins gezählt werden:
 * 
 *     enum month_d {
 *         JANUARY = 1,
 *         FEBRUARY, MARCH, ...
 *     };
 * 
 * In jedem Fall kann der Compiler nun prüfen, ob eine Zahl zulässig ist und bei folgender
 * Zeile beispielsweise eine Fehlermeldung produzieren:
 * 
 *     weekday_t day = 23;
 * 
 * Doch es gibt auch Nachteile, zumindest bei mit "enum" definierten Aufzählungen wie hier:
 * 
 *   1. Die Namen der Konstanten müssen eindeutig sein. Mann kann zum Beispiel keine Variable
 *      oder anderswie definierte Konstante mit dem Namen MONDAY haben. Auch andere Aufzählungen
 *      dürfen die schon definierten Namen nicht verwenden.
 * 
 *   2. Die Konstanten werden automatisch in einen int-Wert umgewandelt, wenn an einer Stelle
 *      eine Ganzzahl erwartet wird. Dadurch klopft uns der Compiler nicht auf die Finger,
 *      wenn wir Wochentage und Geldbeträge addieren. Der Wochentag wird klammheimlich einfach
 *      als Datentyp "int" re-interpretiert (der Fachbegriff lautet static cast). Schöner wäre,
 *      wenn der Compiler einen Fehler melden würde.
 * 
 * Beide Nachteile lassen sich mit dem neueren "enum class" lösen. Zum Vergleich folgt unten
 * aber erst die Variante nur mit "enum", die wir im nächsten Beispiel auf "enum class" ändern.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
using namespace std;

enum weekday_t {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};

enum month_t {
    JANUARY = 1,
    FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

int main(int argc, char **argv) {
    weekday_t day = MONDAY;
    month_t month = JUNE;

    cout << endl;
    cout << "Montag...: " << day << endl;
    cout << "Juni.....: " << month << endl;
    cout << endl;
}