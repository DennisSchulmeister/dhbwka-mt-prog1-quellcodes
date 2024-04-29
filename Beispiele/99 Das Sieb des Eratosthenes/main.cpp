/***********************************************************************************************
 * Beispiel: Das Sieb des Erastothenes
 * ===================================
 * 
 * Das Sieb des Erastothenes ist ein einfacher Lehrbuchalgorithmus zum Finden aller Primzahlen
 * kleiner gleich einer Zahl N. Das Verfahren ist ganz einfach:
 *
 *   1. Man notiert alle Ganzzahlen von 2 bis N in einer Liste.
 *   2. Man durchläuft die Liste eine Zahl nach der anderen und ...
 *   3. Streicht alle Vielfachen der aktuellen Zahl.
 *   4. Bereits gestrichene Zahlen werden übersprungen.
 *
 * Übrig bleiben die Primzahlen, da alle Vielfachen der Primzahlen "ausgesiebt" wurden.
 *
 * Dieses Verfahren kann man auf unterschiedliche Weise in C++ implementieren. Eine Möglichkeit
 * wäre, ein Array (oder einen Vektor) mit N Elementen zu verwenden, die für die jeweilige Zahl
 * an ihrem Index stehen. Also Index 2 für die Zahl 2, Index 3 für die Zahl 3 usw., wobei man
 * nicht die Zahl sondern ein Boolean speichert, dass mit true/false kodiert, ob an die Zahl
 * eine Primzahl ist. Dieses Verfahren habt aber eine Laufzeit von O(n²).
 *
 * Hier wird deshalb eine andere Version gezeigt, die stattdessen die gefundenen Primzahlen
 * in einem Vektor abgelegt, wobei der Index hierbei keine Bedeutung hat.
 ***********************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

constexpr int n = 50;
vector<int> prime_numbers = {};

/**
 * Hauptfunktion des Programms.
 */
int main(int argc, char **argv) {
	cout << "Das Sieb des Erastothenes" << endl;
	cout << "=========================" << endl;
	cout << endl;

	for (int i = 2; i < n; i++) {
		bool is_prime = true;

		for (int n : prime_numbers) {
			if (i % n == 0) {
				is_prime = false;
				break;
			}
		}

		if (is_prime) {
			prime_numbers.push_back(i);
			cout << to_string(i) << " ";
		}
	}

	cout << endl;
}
