#include <iostream>
#include "Klasse_Gesch.h"

using namespace std;

class Testing:public Gesch
{
    private:
    double Testwert_gesch = 0;
    double Testvariable = 0;
    
    public:
    void Test_gesch(Testing& T1);
    void Tets_pace();
};

void Testing::Test_gesch(Testing& T1)
{
    
    T1.dauer = 3000;
    T1.umfang = 3.1415*0,6;
    Testvariable = 2.26188;
    
    
   Testwert_gesch = T1.getgesch();
    
    if (Testwert_gesch <= (Testvariable+0.5) && Testwert_gesch > (Testvariable-0.5))
    {
        cout << "Test erfolgreich" << endl;
        cout << endl;
        cout << "Geschwindigkeit betraegt:" << Testwert_gesch << endl;
        cout << endl;
    }
    
    else 
    {
        cout << "Test fehlgeschlagen";
        cout << endl;
        cout << "Geschwindigkeit betraegt:" << Testwert_gesch << endl;
        cout << endl;
    }
}


