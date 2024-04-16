/***********************************************************************************************
 * Beispiel: Grundlegende Syntax von C und C++
 * ===========================================
 * 
 ***********************************************************************************************/
#include <iostream>
using namespace std;

/**
 * Anzeige des Menüs mit Abfrage der Benutzereingabe. Gibt den eingegebenen
 * Buchstaben als char-Wert zurück.
 */
char print_menu() {
		cout << "Robotersteuerung" << endl;
		cout << "================" << endl;
		cout << endl;
		cout << "Wohin soll der Roboter fahren?" << endl;
		cout << endl;
		cout << "[L] Links" << endl;
		cout << "[R] Rechts" << endl;
		cout << endl;
		cout << "[E] Programm beenden" << endl;
		cout << endl;
		cout << "Ihre Eingabe: ";

		char key;
		cin >> key;

		return key;
}

/**
 * Hauptfunktion des Programms.
 */
int main(int argc, char **argv) {
	bool running = true;

	while (running) {
		char key = print_menu();

		switch (key) {
			case 'l':
			case 'L':
				cout << "Der Roboert fährt nach LINKS!" << endl;
				break;
			
			case 'r':
			case 'R':
				cout << "Der Roboert fährt nach RECHTS!" << endl;
				break;
			
			case 'e':
			case 'E':
				cout << "Auf Wiedersehen!" << endl;
				running = false;
				break;
			
			default:
				cout << "Unerlaubte Eingabe. Bitte wiederholen." << endl;
		}

		cout << endl;
	}
}
