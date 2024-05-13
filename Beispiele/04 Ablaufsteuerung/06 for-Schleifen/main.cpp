/***********************************************************************************************
 * Beispiel: for-Schleifen
 * =======================
 * 
 * Innerhalb einer Schleife muss häufig eine Zahl hoch- oder runtergezählt werden. Entweder,
 * weil die Schleife eine bestimmte Anzahl oft ausgeführt werden soll, oder weil die Zahl für
 * eine Berechnung benötigt wird. Für diesen Fall gibt es mit der for-Schleife eine besonders
 * kompakte Kurzschreibweise. Ihre Syntax lautet wie folgt:
 *
 *    for (AUSDRUCK1; AUSDRUCK2; AUSDRUCK3) ANWEISUNG
 *
 * Die Anweisung wird wie immer meistens als Codeblock geschrieben:
 *
 *    for (AUSDRUCK1; AUSDRUCK2; AUSDRUCK3) {
 *        ANWEISUNG;
 *        ANWEISUNG;
 *        ....
 *    }
 *
 * Die Besonderheit liegt darin, zu welchen Zeitpunkten die Ausdrücke ausgewertet werden und
 * was damit gemacht wird:
 *
 *    - AUSDRUCK1: Einmalig, bevor die Schleife das erste mal ausgeführt wird
 *    - AUSDRUCK2: Vor jedem Durchlauf zur Prüfung, ob die Schleife weiterlaufen soll
 *    - AUSDRUCK3: Nach jedem Schleifendurchlauf
 *
 * Wichtig ist, dass AUSDRUCK2 true ergeben muss, damit die Schleife weiterläuft. Die anderen
 * Ausdrücke werden nur wegen ihrer Seiteneffekte ausgeführt, sonder aber nicht betrachtet.
 *
 * Hier ein paar häufig anzutreffenden Beispiele:
 *
 *    // 25 Durchläufe, gibt die Zahlen von 0 bis 24 aus
 *    for (int i = 0; i < 25; i++) {
 *        cout << i << " ;
 *    }
 *
 *    // Dasselbe nur rückwärts
 *    for (int i = 24; i >= 0; i--) {
 *        cout << i << " ";
 *    }
 *
 *    // Anzeige aller geraden Zahlen von 2 bis 10
 *    for (int i = 2; i <= 10; i += 2) {
 *        cout << i << " ";
 *    }
 *
 * Dieses Programm nutzt eine for-Schleife, um damit folgende Zahlenfolge zu berechnen:
 *
 *              ⎛      1  ⎞n
 *    	ⅇ = lim ⎜ 1 + --- ⎟
 *          n→∞ ⎝      n  ⎠
 *
 * Hier ist es der Limes, der uns verrät, dass wir eine Schleife benötigen. Das Programm soll
 * dabei die ersten 25 Iterationen berechnen.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecision
#include <cmath>        // pow (Potenz, englisch: power)

using namespace std;

constexpr double e     = exp(1);
constexpr int    n_max = 24;

int main(int argc, char **argv) {
    cout << setprecision(20);

    cout << endl;
    cout << "ⅇ = exp(1) ≈ " << e << endl;
    cout << endl;
    cout << "n   Zahlenfolge             Abweichung von ⅇ" << endl;
    cout << "==  ======================  ======================" << endl;
    cout << endl;

    for (int n = 0; n <= n_max; n++) {
        double lim_e = pow(1 + (1.0 / n), n);
        double diff  = e - lim_e;

        cout << setw(2)  << left << n << "  ";
        cout << setw(22) << left << lim_e << "  ";
        cout << diff << endl;
    }

    cout << endl;
}