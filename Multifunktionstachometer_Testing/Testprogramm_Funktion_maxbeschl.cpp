#include <iostream>
#include "Klasse_Gesch.h"

using namespace std;

double maxbeschl = 5;				//fiktiver Wert f�r die Maximalbeschleunigung
double beschl = 10;					//fiktiver Wert f�r die Beschleunigung
double testergebnis = 0;			//Speicherplatz f�r das Testergebnis
double sollwert = 10;				//Sollwert

int main()
{
	cout << " Start des Tests" << endl;
	cout << endl;
	
	Gesch MB;								//Objekt erschaffen
	
	MB.setmaxbeschl(maxbeschl);					//�bermittlung der fiktiven Werte an das Objekt MB
	MB.setbeschl(beschl);
	
	testergebnis = MB.getmaxbeschl();
	
	if (testergebnis <= (sollwert+0.1) && testergebnis > (sollwert-0.1))  //Bedingung f�r Testerfolg
	{
		cout << "Test erfolgreich" << endl;
		cout << endl;
		cout << "Testergebnis ist" << testergebnis;
		cout << endl;
	}
	
	else																								//Testergebnis falsch, f�hrt zu der Ausgabe "Test fehlgeschlagen"
	{
		cout << "Test fehlgeschlagen" << endl;
		cout << "Testergebnis ist "<< testergebnis;
		cout << endl;
	}
	return 0;
}