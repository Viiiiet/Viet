#include<iostream>
#include<fstream>
#include"Klasse_Gesch.h"

using namespace std;

int main(void)
{
	Gesch Test;
	double Ergebnis = 13.1943;																//richtiges Ergebnis
	Test.setD(0.7);																			//setzen der relevanten Parameter zur Berechnung der Durchschnittsgeschwindigkeit
	Test.setn(1000);
	Test.setgesdauer(600000);

	ofstream Test_dgesch;
	Test_dgesch.open("Testdatei_dgesch.txt");
	
	if (Test.getd_gesch() >= (Ergebnis - 0.01) && Test.getd_gesch() <= (Ergebnis + 0.01))	//Abfrage, ob das, vom Programm berechnete Ergebnis innerhalb des Toleranzbereiches liegt
	{
		Test_dgesch << "Sollwert: " << Ergebnis << " km/h\n";
		Test_dgesch << "Berechnet: " << Test.getd_gesch() << " km/h\n"						//Ausgabe des Sollwertes, berechneten Wertes und ob der Test erfolgreich war in der Datei "Testdatei_dgesch.txt"
		Test_dgesch << "Test war erfolgreich!\n";
	}
	else
	{
		Test_dgesch << "Sollwert: " << Ergebnis << " km/h\n";
		Test_dgesch << "Berechnet: " << Test.getd_gesch() << " km/h\n";						//Ausgabe des Sollwertes, berechneten Wertes und ob der Test erfolgreich war in der Datei "Testdatei_dgesch.txt"
		Test_dgesch << "Test war nicht erfolgreich!\n";
	}
	Test_dgesch.close();
	return 0;
}
