// Geschwindigkeitsklasse 

class Gesch
{
    private:
        // Atribute des Typs Double 
        double gesch = 0;                 // Geschwindigkeit           
        double gesch1 = 0;                // zwischengespeicherte Geschwindigkeit für den letzten Durchlauf mit ungeradem n
        double gesch2 = 0;                // zwischengespeicherte Geschwindigkeit für den letzten Durchlauf mit geradem n
        double maxgesch = 0;              // Maximalgeschwindigkeit
        double beschl = 0;                // Beschleunigung
        double maxbeschl = 0              // Maximale Beschleunigung
        double D = 0.3;                   // Durchmesser des Reifens in Metern
        double umfang = 3.141 * D ;       // Umfang des Reifens in Metern                      
        double start = 0;                 // Start der Zeitmessung
        double pace;                      // Pace
        double ende;                      // Ende der Zeitmessung
        double sekunden = 0.0;            // Sekunden
        double minuten = 0.0;             // Minuten
        double stunden = 0.0;             // Stunden
        
        //Atribute des Typs Integer
        int sensorValue = 0;      
        int sensorPin = A0;
        int n = 0;                        // Anzahl der Durchläufe
        int dauer = 0;                    // Dauer eines Durchlaufes
        unsigned long int gesdauer = 0;   // Gesamtdauer in Millisekunden
       
        
    public:
       
        // Methoden des Typs Void
        void setD(double D);

        //Methoden des Typs int
        int getdauer();                                                               // Berechnung der Dauer
        
        // Methoden des Typs double  
        double getgesch();                                                            // Berechnung der Geschwindigkeit
        double getd_gesch();                                                          // Berechnung der Duchschnittsgeschwindigkeit
        double getstrecke();                                                          // Berechnung der gefahfenen Strecke
        double getpace(int fahrzeit, double strecke,unsigned long int* final_pace);   // Berechnung des Pace
        double getfahrzeit(unsigned long int* fahrzeit);                              // Berechnung der gesamten Fahrzeit
        double getbeschl(double geschw,int Dauer);                                    // Berechnung der Beschleunigung
        double getmaxgesch(double geschw);                                            // Bestimmung der Maximalgeschwindigkeit
        double getmaxpace(int* final_pace, int* maxfinal_pace);                       // Bestimmung des maximalen Pace
        double getmaxbeschl();                                                        // Bestimmung der maximalen Beschleunigung

		//Methoden für das Testing
		void setdauer(double dauer);
		void setgesdauer(int gesdauer);
		void setumfang(double umfang);
		void setn(int n);
		void setgesch1(double gesch1);
		void setgesch2(double gesch2);
		void setgesch(double gesch);
		void setmaxgesch(double maxgesch);
};

void Gesch::setD(double D)
{
    this->D = D;
}



/*int Gesch::getdauer()                            // Ermittlung der Zeit einer Radumdrehung 
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
}*/
 



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





double Gesch::getstrecke()                                            //Methode zur Berechnung der Strecke
{
  return this->n*3.141*D;                                             //Berechnung der Strecke aus Anzahl der Messungen und 
}




double Gesch::getpace(int fahrzeit, double strecke,unsigned long int* final_pace) // Methode zur Berechnung des Paces 
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




double Gesch::getfahrzeit(unsigned long int* fahrzeit)                                 // Methode zur Ermittlung der Fahrzeit
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



double Gesch::getbeschl(double geschw,int Dauer)    // Methode zur Berechnung der Beschleunigung
{

  if (Dauer > 10) 
  {
  if (n % 2 == 1 )                                  // If-Bedingung für ungerades n/für ungerade Anzahl an Durchläufen
  {
    gesch1 = geschw;                                // Bei ungeraden n wird momentane Geschwindigkeit als "gesch1" gespeichert
    beschl = (gesch1 - gesch2) / Dauer;             // Geschw. des vorh. Durchlaufs mit geradem n (gesch2) von gesch1 abziehen und durch Zeit teilen(Berechnung der Beschleunigung)    
  }
  else                                              // If-Bedingung für gerades n/für gerade Nzahl an Durchläufen 
  {
    gesch2 = geschw;                                // Bei jedem geraden n wird die momentane Geschwindigkeit als "gesch2" gespeichert
    beschl = (gesch2 - gesch1) / Dauer;             // Geschw. des vorh. Durchlaufs mit ungeradem n (gesch1) von gesch2 abziehen und durch Zeit teilen(Berechnung der Beschleunigung)
  }
  }
  return beschl;                                    // Beschleunigung zurückgeben
}




double Gesch::getmaxgesch(double geschw)            // Klasse zur Bestimmung der Maximalgeschwindigkeit                              
{
  if (geschw >= this->maxgesch)                     // Bedingung, um alte Maximalgeschwindigkeit zu überschreiben                 
  {
    this->maxgesch = geschw;                        // neue, höhere Geschwindigkeit als neue Maximalgeschwindigkeit speichern
  }
  return this->maxgesch;                            // Maximalgeschwindigkeit zurückgeben
}


void Gesch::getmaxpace(int* final_pace, int* maxfinal_pace)     // Klasse zur Bestimmung des maximalen Pace
{
  if ( this->final_pace[0] < this->maxfinal_pace[0])
  {
    this->maxfinal_pace[0] = this->final_pace[0];  
  }
  else if (  this->final_pace[1] <= this->maxfinal_pace[1] && this->final_pace[0] <= this->maxfinal_pace[0] )
  {
    this->maxfinal_pace[1] = this->final_pace[1];
  }
  return void;
}


double Gesch::getmaxbeschl()                  // Klasse zur Bestimmung der maximalen Beschleunigung
{
  if (this->beschl >= this->maxbeschl)        // Bedingung, um alte Maximalbeschleunigung zu überschreiben
  {
    this->maxbeschl = this->beschl;           // neue, höhere Beschleunigung als neue Maximalbeschleunigung speichern
  }
  return this->maxbeschl;                     // Maximalbeschleunigung zurückgeben
}


//Funktionen für das Testing
void Gesch::setdauer(double dauer)               // Methode um einen fiktiven Wert für die dauer in ein Objekt ein zu lesen
{
	this->dauer = dauer;
}

void Gesch::setumfang(double umfang)            // Methode um einen fiktiven Wert für den umfang in ein Objekt ein zu lesen 
{
	this->umfang = umfang;
}

void Gesch::setn(int n)
{
	this->n = n;
}

void Gesch::setD(double D)
{
	this->D = D;
}

void Gesch::setgesch(double gesch)
{
	this->gesch = gesch;
}

void Gesch::setgesch1(double gesch1)
{
	this->gesch1 = gesch1;
}

void Gesch::setgesch2(double gesch2)
{
	this->gesch2 = gesch2;
}

void Gesch::setmaxgesch(double maxgesch)
{
	this->maxgesch = maxgesch;
}

void Gesch::setgesdauer(int gesdauer)
{
	this->gesdauer = gesdauer;
}

void Gesch::setmaxbeschl(double maxbeschl)
{
	this->maxbeschl = maxbeschl;
}

void Gesch::setbeschl(double beschl)
{
	this->beschl = beschl;
}



