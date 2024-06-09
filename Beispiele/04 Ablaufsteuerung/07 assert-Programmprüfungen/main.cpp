/***********************************************************************************************
 * Beispiel: assert-Programmprüfungen
 * ==================================
 * 
 * Guter Quellcode sollte robust sein und bei Fehlern nicht gleich zum Programmabsturz führen.
 * Dennoch lautet eine anerkannte Strategie zum Schreiben von robustem Code: "Let it crash and
 * crash loudly!" Was ist damit gemeint und wie kann das sein?
 * 
 * Der Widerspruch löst sich auf, wenn man die jeweiligen Fehlersituationen auseinander hält.
 * Laufzeitfehler, die vergleichsweise häufig auftreten können und die sich mit vertretbarem
 * Aufwand nicht ausschließen lassen, dürfen nicht zum Absturz führen. Falsche Benutzereingaben
 * sind ein Beispiel hierfür. Erwartet ein Programm die Eingabe einer Zahl, der oder die
 * Benutzer*in gibt aber ungültige Zeichen ein, wäre ein Crash sehr frustrierend. Besser wäre
 * es, auf den Fehler hinzuweisen und die Eingabe zu wiederholen.
 * 
 * Demgegenüber stehen Laufzeitfehler, die extrem selten auftreten, dann ein Weiterarbeiten aber
 * unmöglich machen. Zum Beispiel, wenn die Anforderung eines Speicherbereichs nicht erfüllt
 * werden kann, weil kein weiterer Hauptspeicher zur Verfügung steht. Moderne Computer nutzen
 * virtualisierten Speicher, der viele Gigabyte groß werden kann – weit mehr als physikalischer
 * Speicher tatsächlich vorhanden ist. Eine Speicheranforderung sollte daher immer funktionieren.
 * Funktioniert sie tatsächlich einmal nicht, darf das Programm ruhig abstürzen. Denn der Fall
 * sollte nicht vorkommen. Und immerhin wird der Speicherplatz ja für die Ausführung benötigt.
 * Wie sollte das Programm also ohne den Speicher weiterlaufen können? (Bei eingebetteten
 * Microcontrollern ist das anders. Diese haben oft nur wenig Speicher und keine Virtualisierung
 * dessen. Doch sollte man das beim Programmieren wissen und somit keine Dinge programmieren, die
 * mit dem knappen Speicher ohnehin nicht realisierbar sind.)
 * 
 * Viel häufiger sind hingegen simple Programmierfehler. Man verlässt sich zum Beispiel darauf,
 * dass eine Variable korrekt initialisiert wurde. Tatsächlich wurde die Initialisierung aber
 * vergessen, so dass die Variable zufälligen Datenschrott beinhaltet. In diesem Fall lässt
 * C/C++ das Programm gerne auch mal von alleine abstürzen, wenn dadurch bestimmte Fehler,
 * ausgelöst werden. Beispiele hierfür sind eine Division durch Null bei Integer-Variablen oder
 * Zugriffe auf nicht erlaubte Speicherbereiche. Das ist für Anwender frustrierend. Man sollte
 * ein Programm aber ohnehin sehr ausgiebig testen, so dass das Problem schon beim Testen
 * auffallen sollte. Der Programmabsturz stellt sicher, dass der Fehler nicht kaschiert und
 * dadurch leicht übersehen wird. Deshalb: "Let it crash and crash loudly!"
 * 
 * Eine weitere Klasse von Programmierfehlern ist allerdings nicht so leicht zu finden: Logische
 * Fehler, die zu keinem Absturz aber dennoch zu fehlerhaften Abläufen führen. Oft fallen sie
 * lange Zeit gar nicht auf. Manchmal wundert man sich aber einfach, warum sich das Programm
 * komisch verhält. Die Fehlersuche fällt dann oft schwer, weil man erst einmal die Ursache für
 * das Fehlverhalten eingrenzen und den Fehler zuverlässig nachstellen muss. Ein ironischer
 * Spruch in Entwicklerkreisen lautet daher: "Debugging a program is like solving a crime where
 * you are also the murderer".
 * 
 * Um sich hier das Leben etwas leichter zu machen, kann man so genannte Assertions in den
 * Quellcode einbauen und dadurch quasi "Zusicherungen" machen, dass bestimmte Bedingungen
 * immer erfüllt sein müssen. Im Beispiel unten ist dies die Zusicherung, dass der
 * Zufallszahlengenerator nur Zahlen von 0 bis 9 liefert:
 * 
 *     int random_number = rand() % 10;
 *     assert(random_number >= 0 && random_number <= 9);
 * 
 * Das Beispiel ist natürlich trivial, da der Modulo-Operator in der ersten Zeile genau das
 * sicherstellt. Echte Beispiele sind allerdings weniger offensichtlich und Ursache und Wirkung
 * liegen nicht so nahe beieinander im Quellcode. Man stelle sich hierfür vor, dass zwischen
 * den beiden Zeilen 100 andere Zeilen stehen, was man auch "Action at a Distance" nennt.
 * Hier kann die Assertion tatsächlich helfen, Programmierfehler frühzeitig zu finden. Zum
 * Beispiel könnte man die erste Zeile später einmal ändern, um größere Zahlen zu erhalten:
 * 
 *     int random_number = rand() % 255;
 * 
 * Vergisst man dann aber, eine der nachfolgenden Stellen, an denen die Zahlen verwendet werden,
 * anzupassen, wird die Assertion früher oder später verletzt werden. Das Programm stürzt dann
 * möglichst laut ab und gibt praktischerweise auch noch den Namen der Quellcode-Datei und die
 * Zeilennummer dabei aus:
 * 
 *     main.cpp:77: int main(int, char**): Assertion `random_number >= 0 && random_number <= 9' failed.
 * 
 * Beim Testen sollte das schnell auffallen. Doch selbst, wenn der Fall erst im produktiven
 * Einsatz auftritt, ist der Absturz zwar nervig. Die Fehlermeldung hilft aber dabei, sowohl
 * die Codestelle als auch einen Hinweis auf die Ursache zu finden. Man sieht natürlich nicht,
 * warum die Zahl außerhalb des erwarteten Bereichs liegt. Aber man hat eine Spur, der man
 * nachgehen kann. Und oft ist die Lösung dann doch ziemlich offensichtlich.
 ***********************************************************************************************/

#include <cstdlib>      // rand
#include <ctime>        // time
#include <cassert>      // assert

int main(int argc, char **argv) {
    int random_number = rand() % 10;

    // Sicherstellen, dass die Nummer zwischen 0...9 liegt.
    // Falls nein, stürzt das Programm unter Angabe der Zeilennummer ab.
    assert(random_number >= 0 && random_number <= 9);

    // Zur Verdeutlichung, wie der Programmabsturz aussieht: Hier ein assert(),
    // der nicht zutrifft.
    assert(random_number > 42);
}