#include <iostream>
#include "Klasse_Gesch.h"

using namespace std;

double maxbeschl = 5;				//fiktiver Wert für die Maximalbeschleunigung
double beschl = 10;					//fiktiver Wert für die Beschleunigung
double testergebnis = 0;			//Speicherplatz für das Testergebnis
double sollwert = 10;				//Sollwert

int main()
{
	cout << " Start des Tests" << endl;
	cout << endl;
	
	Gesch MB;								//Objekt erschaffen
	
	MB.setmaxbeschl(maxbeschl);					//Übermittlung der fiktiven Werte an das Objekt MB
	MB.setbeschl(beschl);
	
	testergebnis = MB.getmaxbeschl();
	
	if (testergebnis <= (sollwert+0.1) && testergebnis > (sollwert-0.1))  //Bedingung für Testerfolg
	{
		cout << "Test erfolgreich" << endl;
		cout << endl;
		cout << "Testergebnis ist" << testergebnis;
		cout << endl;
	}
	
	else																								//Testergebnis falsch, führt zu der Ausgabe "Test fehlgeschlagen"
	{
		cout << "Test fehlgeschlagen" << endl;
		cout << "Testergebnis ist "<< testergebnis;
		cout << endl;
	}
	return 0;
}