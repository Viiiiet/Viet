#include <iostream>
#include "Klasse_Gesch.h"

using namespace std;

double maxgesch = 25;								//fiktiver Wert für die Maximalgeschwindigkeit
double gesch = 30;								//fiktiver Wert für Geschwindigkeit
double testergebnis = 0;                                                        //Speicherplatz für das Testergebnis
double sollwert = 30;                                                      	//Vorgabe eines Sollwertes für die Testbedingung

int main()
{
    cout << "Start des Tests" << endl;
    cout << endl;
    
    Gesch MG; 									//Erschaffen eines Objektes zum testen
                                                                 
    MG.setmaxgesch(maxgesch);                                                   //Übermitlung der fiktiven Werte an das Objekt MG
    MG.setgesch(gesch);
    
    testergebnis = MG.getmaxgesch();                                            //Aufruf der zu testenden Funktion getmaxgesch
    
    if (testergebnis <= (sollwert+0.1) && testergebnis > (sollwert-0.1))        //Bedingung für den Erfolg des Testes 
    {                                                                           //Wenn das Testergebnis inerhalb eines bestimmten 
        cout << "Test erfolgreich" << endl;                                     //Tolleranzbereiches von 0.1 um den sollwert liegt ist 
        cout << endl;                                                           //der Test erfolgreich.
        cout << "Testergebnis ist" << testergebnis;                             //Testergebnis wird ausgegeben
        cout << endl;
    }
    
    else                                                                        //Wenn das Testergebnis nicht stimmt führt 
    {                                                                           //dies zum Fehlschlag des Tests
        cout << "Test fehlgeschlagen" << endl;
        cout << "Testergebnis ist" << testergebnis;                             //Testergebnis wird ausgegeben 
        cout << endl;
    }
    
    return 0;
}