// Geschwindigkeitsklasse 

class Gesch
{
    private:
        // Atribute des Typs Double 

        double gesch = 0;                 // Geschwindigkeit in "km/h"           
        double gesch1 = 0;                // zwischengespeicherte Geschwindigkeit für den letzten Durchlauf mit ungeradem n in "m/s"
        double gesch2 = 0;                // zwischengespeicherte Geschwindigkeit für den letzten Durchlauf mit geradem n in "m/s"
        double maxgesch = 0;              // Maximalgeschwindigkeit in "km/h"
        double beschl = 0;                // Beschleunigung in "m/(s^2)"
        double maxbeschl = 0;              // Maximale Beschleunigung in "m/(s^2)"
        double D = 0.3;                   // Durchmesser des Reifens in "m"
        double umfang = 3.141 * D ;       // Umfang des Reifens in "m"                      
        double start = 0;                 // Start der Zeitmessung in "ms"
        double pace;                      // Pace "min/km"
        double ende;                      // Ende der Zeitmessung in "ms"
        double sekunden = 0.0;            // Sekunden 
        double minuten = 0.0;             // Minuten
        double stunden = 0.0;             // Stunden
        
        //Atribute des Typs Integer
        int sensorValue = 0;      
        int sensorPin = A0;
        int n = 0;                        // Anzahl der Durchläufe
        int dauer = 0;                    // Dauer eines Durchlaufes in "ms"
        unsigned long int gesdauer = 0;   // Gesamtdauer in "ms"
       
        
    public:
       
        // Methoden des Typs Void
        void setD(double D);
        void getmaxpace(unsigned long int* final_pace, int* maxfinal_pace);           // Bestimmung des maximalen Pace
        void getpace(int fahrzeit, double strecke,unsigned long int* final_pace);     // Berechnung des Pace in "min/km"
        void getfahrzeit(unsigned long int* fahrzeit);                                // Berechnung der gesamten Fahrzeit in "h:min:s"
        
        //Methoden des Typs int
        int getdauer();                                                               // Berechnung der Dauer in "ms"
        
        // Methoden des Typs double  
        double getgesch();                                                            // Berechnung der Geschwindigkeit in "km/h"
        double getd_gesch();                                                          // Berechnung der Duchschnittsgeschwindigkeit in "km/h"
        double getstrecke();                                                          // Berechnung der gefahfenen Strecke in "m"     
        double getbeschl();                                                           // Berechnung der Beschleunigung "m/(s^2)"
        double getmaxgesch();                                                         // Bestimmung der Maximalgeschwindigkeit "km/h"
        double getmaxpace(int* final_pace, int* maxfinal_pace);                       // Bestimmung des maximalen Pace in "min/km"
        double getmaxbeschl();                                                        // Bestimmung der maximalen Beschleunigung in "m/(s^2)"
};


void Gesch::setD(double D)  
{
    this->D = D;
}


// Von David Lohuis/Le-Div
int Gesch::getdauer()                            // Ermittlung der Zeit einer Radumdrehung 
{
    
    sensorValue = analogRead(sensorPin);            //Sensor für die Hallsonde wird das erste mal ausgelesen 

   if (sensorValue > 2);                            //Bedingung die erfüllt werden muss damit die Zeitmessung startet 
   {
    start = millis();                               // Start der Zeitmessung 
 
       do                                           //Whileschleife um auf das 2. Sensorsignal zu warten
       {
            sensorValue = analogRead(sensorPin);    //2. Sensorauslesen der Hallsonde was bei einem Wert größer 2 zum Abbruch führt 
       }while( sensorValue < 2);
       
    n += 1;                                        //koninuierliche Berechnung der Anzahl der Messungen
   
   }

   delay(50);
   dauer = millis() - start;                       // stoppen der Zeitmessung und Zeitintervall bildung 

      
    return dauer;                                   //Rückgabewert Umdrehungszeit
}
 


//von Viet Le /Viiiiet
double Gesch::getgesch()                            // Methode für die Berechnung der momentan Geschwindigkeit
{
    if (dauer > 10)
    {
    gesch = (umfang / this->dauer * 1000)*3.6;      // Berechnung der momentan Geschwindigtkeit aus dem Umfang und der Dauer in km/h
    }
    return gesch;                                   //  Rückgabewert 
}

double Gesch::getd_gesch()                                            //Methode zur Berechnung der Durchschnittsgeschwindigkeit
{
     return this->n*umfang*1000*3.6/this->gesdauer;                   //Berechnung der Durchschnittsgeschwindigkeit aus Anzahl der Messungen und Gesamtdauer und Rückgabe
}                                                                     //in km/h




//von Tobias Ohnimus/Le-To
double Gesch::getstrecke()                                            //Methode zur Berechnung der Strecke
{
  return this->n*3.141*D;                                             //Berechnung der Strecke aus Anzahl der Messungen und 
}



//Von David Lohuis/Le-Div 
void Gesch::getpace(int fahrzeit, double strecke,unsigned long int* final_pace) // Methode zur Berechnung des Paces 
{
    
     this->pace = fahrzeit/strecke ;                                   // Berechnung des Paces 
    
    while(pace >= 1)                                                   // Aufteilen der Kommazahl in Nachkommastellen und Minuten
    {
        pace -= 1;                                                     // Nachkommastellen
        minuten += 1;                                                  // Minuten 
    }
            
    sekunden = pace * 60;                                               // Speicherung und Umrechnung der Nachkommastellen Sekunden     
    
    final_pace[0] = minuten;                                            // Speicherung der Minuten und Sekunden in einem Tuppel
    final_pace[1] = sekunden;
}



//Von Viet Le/ Viiiiet
void Gesch::getfahrzeit(unsigned long int* fahrzeit)                                 // Methode zur Ermittlung der Fahrzeit
{

    if (dauer>10)
    {                                                       //if-Schleife zur Vermeidung von Messfehlern und unnötiger Rechnung aufgrund von Teilung durch 0
      gesdauer +=  this->dauer + 100;                       //koninuerliche Berechnung der Dauer seit Start der Messungen
    
      for(int i=0;i<4;i++)                                    //Zurücksetzen des arrays fahrtzeit
      {
        fahrzeit[i] = 0;
      }
      
      fahrzeit[0] = gesdauer;
      
      while( fahrzeit[0] >= 3600000)                                 
      {
        fahrzeit[0] -= 3600000;                                      
        fahrzeit[3] += 1;
      }
                                  
      while(fahrzeit[0] >= 60000)                                   
      {
        fahrzeit[0] -= 60000;                                       
        fahrzeit[2] += 1;
      }

      while(fahrzeit[0] >= 1000)                                  
      {
        fahrzeit[0] -= 1000;
        fahrzeit[1] += 1;
      }
      fahrzeit[0] = gesdauer;
    }                                                       //Ende der if-Bedingung->wenn die Bedingung nicht erfüllt ist, tut diese Funktion gar nichts
}


//Von Dominik Mahlstedt/ Le-Do
double Gesch::getbeschl()                                       // Methode zur Berechnung der Beschleunigung
{

  if (dauer > 10) 
  {
  if (n % 2 == 1 )                                               // If-Bedingung für ungerades n/für ungerade Anzahl an Durchläufen
  {
    gesch1 = this->gesch/3.6;                                    // Bei ungeraden n wird momentane Geschwindigkeit als "gesch1" gespeichert
    beschl = (this->gesch1 - this->gesch2) / (this->dauer/1000); // Geschw. des vorh. Durchlaufs mit geradem n (gesch2) von gesch1 abziehen und durch Zeit teilen(Berechnung der Beschleunigung)    
  }
  else                                                           // If-Bedingung für gerades n/für gerade Nzahl an Durchläufen 
  {
    gesch2 = this->gesch/3.6;                                    // Bei jedem geraden n wird die momentane Geschwindigkeit als "gesch2" gespeichert
    beschl = (this->gesch2 - this->gesch1) / (this->dauer/1000); // Geschw. des vorh. Durchlaufs mit ungeradem n (gesch1) von gesch2 abziehen und durch Zeit teilen(Berechnung der Beschleunigung)
  }
  }
  return this->beschl;                                           // Beschleunigung zurückgeben
}



//Von Dominik Mahlstedt
double Gesch::getmaxgesch()                         // Klasse zur Bestimmung der Maximalgeschwindigkeit                              
{
  if (this->gesch >= this->maxgesch)                // Bedingung, um alte Maximalgeschwindigkeit zu überschreiben                 
  {
    this->maxgesch = this->gesch;                   // neue, höhere Geschwindigkeit als neue Maximalgeschwindigkeit speichern
  }
  return this->maxgesch;                            // Maximalgeschwindigkeit zurückgeben
}


// Von Viet Le/Viiiiet
void Gesch::getmaxpace(unsigned long int* final_pace, int* maxfinal_pace)     // Methode zur Bestimmung des maximalen Pace
{
  if ( final_pace[0] < maxfinal_pace[0])
  {
    maxfinal_pace[0] = final_pace[0];  
  }
  else if (  final_pace[1] <= maxfinal_pace[1] && final_pace[0] <= maxfinal_pace[0] )
  {
   maxfinal_pace[1] = final_pace[1];
  }
}

// Von Dominik Mahlstedt
double Gesch::getmaxbeschl()                  // Klasse zur Bestimmung der maximalen Beschleunigung
{
  if (this->beschl >= this->maxbeschl)        // Bedingung, um alte Maximalbeschleunigung zu überschreiben
  {
    this->maxbeschl = this->beschl;           // neue, höhere Beschleunigung als neue Maximalbeschleunigung speichern
  }
  return this->maxbeschl;                     // Maximalbeschleunigung zurückgeben
}










