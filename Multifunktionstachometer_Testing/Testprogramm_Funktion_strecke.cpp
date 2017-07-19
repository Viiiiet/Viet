#include<iostream>
#include<fstream>
#include"Klasse_Gesch.h"

using namespace std;

int main()
{
	Gesch Test;
	double Ergebnis = 2.19905;																//richtiges Ergebnis
	Test.setD(0.7);																			//setzen der relevanten Parameter
	Test.setn(1000);
	ofstream Test_strecke;
	Test_strecke.open("Testdatei_strecke.txt");
	
	if (Test.getstrecke() >= (Ergebnis - 0.01) && Test.getstrecke() <= (Ergebnis + 0.01))	//Abfrage, ob das vom Programm berechnete Ergebnis innerhalb der Toleranz liegt
	{
		Test_strecke << "Sollwert: " << Ergebnis << " km\n";
		Test_strecke << "Berechnet: " << Test.getstrecke() << " km\n";						//Ausgabe des Sollwertes, berechneten Wertes und ob der Test erfolgreich war in der Datei "Testdatei_strecke.txt"
		Test_strecke << "Test war erfolgreich!\n";
	}
	else
	{
		Test_strecke << "Sollwert: " << Ergebnis << " km\n";
		Test_strecke << "Berechnet: " << Test.getstrecke() << " km\n";						//Ausgabe des Sollwertes, berechneten Wertes und ob der Test erfolgreich war in der Datei "Testdatei_strecke.txt"
		Test_strecke << "Test war nicht erfolgreich!\n";
	}
	Test_strecke.close();
	return 0;
}
