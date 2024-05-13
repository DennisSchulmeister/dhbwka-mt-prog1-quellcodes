/***********************************************************************************************
 * Beispiel: do/while-Schleifen
 * ============================
 * 
 * Die while-Schleife hat eine kleine Schwester: Die seltener verwendete do/while-Schleife
 * mit folgender Syntax:
 *
 *    do ANWEISUNG while (AUSDRUCK);
 *
 * Meistens mit einem Codeblock geschrieben:
 *
 *    do {
 *        ANWEISUNG;
 *        ANWEISUNG;
 *        ...
 *    } (AUSDRUCK);
 *
 * Im Gegensatz zur while-Schleife werden hier erst die Anweisungen im Schleifenkörper
 * ausgeführt und dann der Ausdruck ausgewertet. Dadurch wird sichergestellt, dass die
 * Anweisungen mindestens einmal ausgeführt werden.
 *
 * Dies wollen wir uns anhand der Leibniz-Reihe zur Näherung der Kreiszahl π anschauen.
 * In den vorherigen Beispielen haben wir bereits gesehen (Wikipedia sei Dank), dass wir
 * die Zahl π mit dem Bruch 104348/ 33215 näherungsweise berechnen können. Die Genauigkeit
 * ist dabei so hoch, dass wir einen Kreis von der Erde bis zum Polarstern berechnen könnten
 * und sein Durchmesser nur einen Millimeter zu kurz wäre. Eine alternative, rechenintensivere
 * Möglichkeit bietet hingegen die Leibniz-Reihe.
 * 
 *     ∞
 *     ⎲ (-1)ᵏ    π
 *     | ------ = -
 *     ⎳ 2k + 1   4
 *     k=0
 *
 * Das Summenzeichen verrät uns hier, dass wir eine Schleife brauchen, um den Algorithmus
 * auszuführen. Hierfür verwenden wir hier eine do/while-Schleife und wenden auch noch zwei
 * Optimierungen an, um die Berechnung der Teilausdrücke (-1)ᵏ und 2k + 1 zu vereinfachen.
 * Die Schleife soll dabei die ersten 25 Iterationen berechnen.
 ***********************************************************************************************/

#include <iostream>     // std::cout, std::cin, ...
#include <iomanip>      // std::setprecision

using namespace std;

constexpr double pi    = 104348.0 / 33215.0;
constexpr int    k_max = 24;

int main(int argc, char **argv) {
    cout << setprecision(20);
    
    cout << endl;
    cout << "π ≈ 104348 / 33215 ≈ " << pi << endl;
    cout << endl;
    cout << "k   Leibniz-Reihe          Abweichung zu π" << endl;
    cout << "==  =====================  =====================" << endl;
    cout << endl;

    int k = 0;
    double sign = 1, divisor = 1, total = 0;

    do {
        total   += sign / divisor;
        sign    *= -1;
        divisor += 2;
        k++;

        double leibniz = total * 4;
        double diff    = pi - leibniz;

        cout << setw(2)  << left << k << "  ";
        cout << setw(22) << left << leibniz << " ";
        if (diff > 0) cout << " ";
        cout << diff << endl;
    } while (k <= k_max);

    cout << endl;
}