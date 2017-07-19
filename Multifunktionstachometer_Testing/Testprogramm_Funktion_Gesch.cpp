#include <iostream>
#include "Klasse_Gesch.h"

using namespace std;


double dauer = 3000;                                                            //fiktiver Wert für die Umdrehungszeit
double umfang = 3.1415*0.6;                                                     //fiktiver Wert für den Reifenumfang
double testergebnis = 0;                                                        //Speicherplatz für das Testergebnis
double sollwert = 2.26188;                                                      //Vorgabe eines Sollwertes für die Testbedingung

int main()
{
    cout << "Start des Tests" << endl;
    cout << endl;
    
    Gesch Test1;                                                                //Erschaffen eines Objektes zum testen
    
    Test1.setdauer(dauer);                                                      //übermitlung der fiktiven Werte an das Objekt Test1
    Test1.setumfang(umfang);
    
    testergebnis = Test1.getgesch();                                            //Aufruf der zu testenden Funktion getgesch
    
    if (testergebnis <= (sollwert+0.1) && testergebnis > (sollwert-0.1))        //Bedingung für den Erfolg des Testes 
    {                                                                           //Wenn das Testergebnis inerhalb eines bestimmten 
        cout << "Test erfolgreich" << endl;                                     //Tolleranzbereiches von 0.1 um den sollwert liegt ist 
        cout << endl;                                                           //der Test erfolgreich.
        cout << "Testergebnis ist" << testergebnis;                             //Testergebnis wird ausgegeben
        cout << endl;
    }
    
    else                                                                        //Wenn das Testergebnis nicht stimmt führt 
    {                                                                           //dies zum fehlschlag des Tests
        cout << "Test fehlgeschlagen" << endl;
        cout << "Testergebnis ist" << testergebnis;                             //Testergebnis wird ausgeben 
        cout << endl;
    }
    
    return 0;
}