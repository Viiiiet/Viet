#include<iostream>
#include"Klasse_Gesch.h"

using namespace std;


int maxfinal_pace[2];
int final_pace[2];
int sek_max_erg =0;				
int sek_min_erg = 0;				
int min_max_erg =4;				//richtiges Testergebnis (Minuten)
int min_min_erg = 5;			//falsches Testergebnis  (Minuten)

int main()
{
	Gesch MPace;
	
	MPace.getmaxpace(final_pace,maxfinal_pace);			
	
	cout << maxfinal_pace[1] << ":" << maxfinal_pace[0] << "min/km"<< endl;

	if (maxfinal_pace[1] <= min_max_erg && maxfinal_pace[0] == sek_max_erg) // Bedingung für erfolgreichen Test und die Aussgabe
	{
		cout << "Test erfolgreich" << endl;
		cout << endl;
		cout << "Ergebnis ist " << maxfinal_pace[1] << " : " << maxfinal_pace[0] << "min/km"<< endl;
	}
	
	else if (final_pace[1] >= min_min_erg && final_pace[0] == sek_min_erg )  // Bedingung für fehlgeschlagenen Test und Ausgabe
	{
		cout << "Test fehlgeschlagen" << endl;
		cout << endl;
	}
}
