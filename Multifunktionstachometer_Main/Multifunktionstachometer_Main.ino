
//Bibliotheken und Klassen importieren
#include <LiquidCrystal.h>
#include "Klasse_Gesch.h"

//Variablen des Typs double       
double geschw;                    // momentane Geschwindigkeit           
double dgeschw;                   // Durchschnittsgeschwindigkeit
double strecke;                   // gefahrene Stecke
double Beschl;                    // Beschleunigung
double wert = 0;                  // auszugebener Wert auf dem Display
double Maxgesch;                  // Maximalgeschwindigkeit
double Maxbeschl;                 // Maximalbeschleunigung
double durchmesser;               // Durchmesser

// Variablen des Typs char
char* Name[18];                                  
char* einheit[5];

//Variablen des Typs integer
const int PotentiometerPin = A1;
int maxfinal_pace[2];
unsigned long int final_pace[2];
unsigned long int fahrzeit[4] = {0,0,0,0};
int p;                                              //Potentiometer Messwert
int DPin = 10;                                      //Pin des Buttons für die Auswahl des Durchmessers
int Dauer;                                          // Dauer zwischen zwei Durchläufen 

//Variablen des Typs Bool
bool a = HIGH;
          
//Display wird initialisiert 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Funkionsprototypen
void setausgabe(char* Name, char* einheit, double wert, int unten, int oben, int pot);
void setausgabe(char* Name, char* einheit,unsigned long int wert1,unsigned long int wert2, int unten, int oben, int pot);

//Objekte werden erstellt
Gesch GO1;

void setup() {
  
//Serieller Monitor
Serial.begin(9600);

//Display set up 
lcd.begin(16,2);

// initialisiere PotentiometerPin
pinMode(PotentiometerPin, INPUT);

//Abfrage des Durchmessers
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Durchmesser");              
lcd.setCursor(0,1);
lcd.print("auswaehlen bitte"); 
delay(2000);            



// Ab hier bis zum Hauptprogramm wurde der Code von Tobias Ohnimus/ Le-To erstellt

                                                      //while-Schleife, die darauf wartet, dass der Button gedrückt wird
do
{
  p = analogRead(PotentiometerPin);
  setausgabe("Durchmesser:","Zoll",16,0,127,p);
  setausgabe("Durchmesser:","Zoll",18,127,254,p);
  setausgabe("Durchmesser:","Zoll",20,254,381,p);
  setausgabe("Durchmesser:","Zoll",24,381,508,p);
  setausgabe("Durchmesser:","Zoll",26,508,635,p);
  setausgabe("Durchmesser:","Zoll",27,635,762,p);
  setausgabe("Durchmesser:","Zoll",28,762,889,p);
  setausgabe("Durchmesser:","Zoll",29,889,1016,p);

  delay(100);
  
}
while(!digitalRead(DPin));


if(p >= 0 && p <127){                               //Abfrage auf welchem Stand sich das Potentiometer befunden hat und dementsprechende Zuweisung des Durchmessers
  durchmesser = 0.4064;}
else if(p >= 127 && p < 254){
  durchmesser = 0.4572;}
else if(p >= 254 && p < 381){
  durchmesser = 0.508;}
else if(p >= 381 && p < 508){
  durchmesser = 0.6096;}
else if(p >= 508 && p < 635){
  durchmesser = 0.6604;}
else if(p >= 635 && p < 762){
  durchmesser = 0.6858;}
else if(p >= 762 && p < 889){
  durchmesser = 0.7112;}
else if(p >= 889 && p < 1016){
  durchmesser = 0.7366;}

lcd.clear();
lcd.setCursor(2,0);
lcd.print("Gute Fahrt =)");


}

//H A U P T P R O G R A M M 
void loop() {


  //Methoden des Geschwindigkeitsobjektes aufrufen
   Dauer = GO1.getdauer();
  geschw = GO1.getgesch();
 strecke = GO1.getstrecke();
 dgeschw = GO1.getd_gesch();
           GO1.getpace(fahrzeit[0],strecke,final_pace);
           GO1.getmaxpace(final_pace,maxfinal_pace);
           GO1.getfahrzeit(fahrzeit);
Maxbeschl= GO1.getmaxbeschl();
  Beschl = GO1.getbeschl();
Maxgesch = GO1.getmaxgesch();

//Ausgabe auf dem serial monitor
//Serial.println(fahrzeit[0]);

// Auslesen des Drehpotentiometers           
p = analogRead(PotentiometerPin);

// Aufruf der Funktionen zur Ausgabe auf dem Display 
setausgabe("Geschwindigkeit:","km/h",geschw,0,102,p);                                      // Anzeige der Geschwindigkeit 
setausgabe("Dauer:","ms",Dauer,102,204,p);                                                 // Anzeige der Umdrehungszeit des Reifens 
setausgabe("D-Geschw:","km/h",dgeschw,204,306,p);                                          // Anzeige der Durchschnittsgeschwindigkit 
setausgabe("Strecke:","km",strecke,306,408,p);                                             // Anzeige der gefahrenen Strecke
setausgabe("Pace:","min/km",final_pace[0],final_pace[1],408,510,p);                        // Anzeige des Paces 

                if( fahrzeit[3] < 1)
                {
                setausgabe("Fahrzeit:","min",fahrzeit[2],fahrzeit[1],510,612,p);           // Anzeige der Fahrzeit in Minuten und Sekunden 
                }
                else if(fahrzeit[3] >= 1)
                {
                setausgabe("Fahrzeit:","h",fahrzeit[3],fahrzeit[2],510,612,p);             // Anzeige der Fahrzeit in Stunden und Minuten 
                }

setausgabe("Beschleunigung:","m/s^2",Beschl,612,714,p);                                    // Anzeige der Momentanbeschleunigung  
setausgabe("Max-Geschw:","km/h",Maxgesch,714,816,p);                                       // Anzeige der Maximalgeschwindigkeit 
setausgabe("Max-Pace:","min/km",maxfinal_pace[0],maxfinal_pace[1],816,918,p);
setausgabe("Max-Beschl:","m/s^2",Maxbeschl,918,1020,p);

//setausgabe("Testfahrzeit:","ms",fahrzeit[0],1020,1023,p);


  delay(100);
}


//F U K T I O N E N

// Programmiert von David Lohuis / Le-Div

// Funktionsdeklaration der Display-Ausgabefunktion für normale Werte 
void setausgabe(char* Name, char* einheit, double wert, int unten, int oben,int pot) // Fuktionswerte die für die Anzeige auf dem Display und die Menüführung notwendig sind
{     
   if (pot >= unten && pot < oben)// Bedingung für die Menüführung 
   { 
    // Ausgabe auf dem Display 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(Name);              // Ausgabe des Namens des angezeigten Wertes 
    lcd.setCursor(2,1);
    lcd.print(wert);              // Ausgabe das Wertes in Zahlen
    lcd.setCursor(11,1);  
    lcd.print(einheit);           // Ausgabe der Einheit die zu dem Wert gehört 
   }
}


// Funktionsüberladung der Funktion Display-Ausgabefunktion für die Ausgabe von Zeiten
void setausgabe(char* Name, char* einheit, unsigned long int wert1, unsigned long int wert2, int unten, int oben, int pot)
{   
    if (pot >= unten && pot < oben)
    {
    // Ausgabe auf dem Display 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(Name);                 // Ausgabe des Namens des angezeigten Wertes 
    lcd.setCursor(2,1);
    lcd.print(wert1);                // Ausgabe der Minuten (wert1)
    lcd.setCursor(4,1);
    lcd.print(":");
    lcd.setCursor(5,1);
    lcd.print(wert2);                // und der Sekunden(wert2)
    lcd.setCursor(10,1);
    lcd.print(einheit);              // Ausgabe der Einheit die zu dem Wert gehört
    }
}


