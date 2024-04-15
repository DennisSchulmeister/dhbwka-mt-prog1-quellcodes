Mechatronik - Programmieren I (Quellcodes)
==========================================

1. [Kurzbeschreibung](#kurzbeschreibung)
1. [Benötigte Software](#benötigte-software)
1. [Kompilieren und Ausführen der Quellcodes](#kompileren-und-ausführen-der-quellcodes)
1. [Experiment: Die Elisa AI-Tutorin](#experiment-die-elisa-ai-tutorin)
1. [Copyright](#copyright)

Kurzbeschreibung
----------------

Dieses Repository beinhaltet sämtliche zur Verfügung gestellten Quellcodes,
Aufgaben und Praxisbeispiele der Vorlesung „Programmeiren I (Schulmeister-Zimolong)”
im Studiengang Mechatronik an der DHBW Karlsruhe.

Benötigte Software
------------------

Folgende Software wird benötigt, um die Beispiele und Aufgaben bearbeiten zu können:

* Code-Editor oder IDE: [Visual Studio Code](https://code.visualstudio.com/)
* Build-Werkzeuge: GNU Compiler Collection -
  [Windows](https://jmeubank.github.io/tdm-gcc/download/),
  [Mac OS](https://osxdaily.com/2023/05/02/how-install-gcc-mac/)

Falls Sie keine Software auf Ihrem Rechner installieren können, dafür aber einen GitHub-Benutzer
haben, können Sie die Quellcodes unter folgender Adresse auch in der Gitpod Online-IDE bearbeiten:
[https://gitpod.io/#https://github.com/DennisSchulmeister/dhbwka-mt-prog1-quellcodes](https://gitpod.io/#https://github.com/DennisSchulmeister/dhbwka-mt-prog1-quellcodes)

Kompileren und Ausführen der Quellcodes
---------------------------------------

Zwar bieten viele Editoren (und IDEs sowieso) eine eingebaute Möglichkeit, um in C oder C++
geschrieben Programme zu kompilieren. Bei größeren Projekten müssen hierfür jedoch verschiedene
Einstellungen vorgenommen werden, die dann nur mit der einen IDE bzw. dem einen Editor funktionieren.
Die Aufgaben und Beispiele beinhalten daher stattdessen ein `Makefile`, das mit dem Konsolenprogramm
`make` ausgeführt werden kann und somit unabhängig von der IDE oder dem Code-Editor funktioniert.

Zunächst muss die Datei `Makefile` im Hauptverzeichnis des Respositories angepasst werden, je nachdem,
welches Betriebssystem Sie verwenden:

* **Windows:** Keine Anpassung erforderlich
* **Linux, Unix oder Mac OS:** Siehe Kommentare in der Date [Makefile](Makefile)

Die Gitpod Online-IDE läuft unter Linux. Anschließend kann man in der Kommandozeile einfach in das
jeweilige Beispiel- oder Aufgabenverzeichnis wechseln und dort folgende Befehle ausführen:

| **Befehl**   | **Funktion**                                                 |
|--------------|--------------------------------------------------------------|
| `make run`   | Kompilieren, Linken und Ausführen des Programms              |
| `make all`   | Kompilieren und Linken in einem Schritt                      |
| `make'       | Dasselbe wie `make all`                                      |
| `make clean` | Vom Compiler erzeugte Dateien wieder löschen                 |
| `make xyz.o` | Kompilieren der Quelldatei `xyz.cpp` zur Objektdatei `xyz.o` |


Experiment: Die Elisa AI-Tutorin
--------------------------------

Viele Hochschulen bieten parallel zu den Vorlesungen sog. Tutorien an, in denen die Studierenden die
Vorlesungsinhalte üben und sich dabei von Studierenden der höheren Semester, den Tutor*innen, Hilfe
holen können. An der Dualen Hochschule haben wir das leider nicht. Als Experiment wird daher parallel
zur Vorlesung im Forschungsprojekt KoLLI des Studiengangs Wirtschaftsinformatik die virtuelle KI-Tutorin
`Elisa` entwickelt. Sie soll Ihnen dabei helfen, die Aufgaben zu bearbeiten, Fragen zu beantworten sowie
Tipps zu geben und Hilfestellung zu leisten. Nähere Informationen folgen in Kürze.

Copyright
---------

Sämtliche Quellcodes sind lizenziert unter
[_Creative Commons Namensnennung 4.0 International_](http://creativecommons.org/licenses/by/4.0/)

© 2024 Dennis Schulmeister-Zimolong <br/>

E-Mail: [dhbw@windows3.de](mailto:dhbw@windows3.de) <br/>
Webseite: https://www.wpvs.de
