#include <iostream>
#include "Klasse_Gesch.h"

using namespace std;

double fahrzeit = 67;                                                       // Testwert für eine fiktive Fahrzeit 
double strecke = 15;                                                        // Testwert für eine fiktive Strecke
int final_pace[2];                                                          // Array für die Ergebnis speicherung      
int m_ergebnis = 4;                                                         // sollwert für das Ergebnis der Minuten 
int s_ergebnis = 28;                                                        // sollwert für das Ergebnis der Sekunden 

int main()
{
    cout << "Start des Tests" << endl;
    cout << endl;
    
    Gesch GO1;                                                               //Erschaffen eines Objektes für den Test 
    
    GO1.getpace(fahrzeit,strecke,final_pace);                                //Aufruf der Methode die getestet werden soll 
    
    cout << final_pace[0] << ":" << final_pace[1] << " min/km" << endl;      //Ausgabe der Ergebnise zum überprüfen 
    cout << endl;
    
    if (final_pace[0] == m_ergebnis && final_pace[1] == s_ergebnis)          //Wenn das Ergebnis im Array mit dem sollwert 
    {                                                                        //übereinstimmt, dann führt dies zum Erfolg des
        cout << "Test erfolgreich" << endl;                                  //Tests.
        cout << endl;
    }
    
    else                                                                     //Bei Nichterfüllung wird ein Fehlschlag ausgegeben 
    {
        cout << "Test fehlgeschlagen" << endl;
        cout << endl;
    }
}