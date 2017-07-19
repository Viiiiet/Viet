#include <iostream>
#include "Klasse_Gesch.h"

using namespace std;


double dauer = 3000;                                                            //fiktiver Wert f�r die Umdrehungszeit
double gesch1 = 2;								//fiktiver Wert f�r eine zwischengespeicherte Geschwindigkeit gesch1 in m/s
double gesch2 = 0; 								//Initialisierung f�r Geschwindigkeit gesch2 in m/s
double gesch = 18;								//fiktiver Wert f�r die momentane Geschwindigkeit in km/h
int n = 2;                                                    			//fiktiver Wert f�r die Anzahl der Umdrehungen n
double testergebnis = 0;                                                        //Speicherplatz f�r das Testergebnis
double sollwert = 1.0;                                                      	//Vorgabe eines Sollwertes f�r die Testbedingung

int main()
{
    cout << "Start des Tests" << endl;
    cout << endl;
    
    Gesch Be; 									//Erschaffen eines Objektes zum testen
                                                               
    Be.setn(n);    								//�bermitlung der fiktiven Werte an das Objekt Be
    Be.setgesch1(gesch1);
    Be.setgesch2(gesch2);                                                      
    Be.setgesch(gesch);
    
    testergebnis = Be.getbeschl();                                            	//Aufruf der zu testenden Funktion getbeschl
    
    if (testergebnis <= (sollwert+0.1) && testergebnis > (sollwert-0.1))        //Bedingung f�r den Erfolg des Testes 
    {                                                                           //Wenn das Testergebnis inerhalb eines bestimmten 
        cout << "Test erfolgreich" << endl;                                     //Tolleranzbereiches von 0.1 um den sollwert liegt ist 
        cout << endl;                                                           //der Test erfolgreich.
        cout << "Testergebnis ist" << testergebnis;                             //Testergebnis wird ausgegeben
        cout << endl;
    }
    
    else                                                                        //Wenn das Testergebnis nicht stimmt f�hrt 
    {                                                                           //dies zum Fehlschlag des Tests
        cout << "Test fehlgeschlagen" << endl;
        cout << "Testergebnis ist" << testergebnis;                             //Testergebnis wird ausgegeben 
        cout << endl;
    }
    
    return 0;
}