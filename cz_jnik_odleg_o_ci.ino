    int Trig = 2;   // Numer pinu wyzwolenia
    int Echo = 3;   // Numer pinu odpowiedzi
    int Red = 4;    // Numer pinu - dioda czerwona
     
    long EchoTime;  // Czas trwania sygnału ECHO
    int  Distance;  // Odległość w centymetrach
    int  MaximumRange = 200; // Maksymalna odległość
    int  MinimumRange = 2;   // Minimalna odległość
     
    void setup()
    {
      // Inicjalizacja portu szeregowego
      Serial.begin(9600);
     
      // Konfiguracja pinów
      pinMode(Trig, OUTPUT);
      pinMode(Echo, INPUT);
      pinMode(Red, OUTPUT);
     
    }
     
    void loop()
    {
      // Ustawiamy TRIG w stan niski na 2us
      digitalWrite(Trig, LOW);
      delayMicroseconds(2);
     
      // Ustawiamy TRIG w stan wysoki na 10us
      digitalWrite(Trig, HIGH);
      delayMicroseconds(10);
     
      // Ustawiamy TRIG w stan niski - rozpoczynamy pomiar
      digitalWrite(Trig, LOW);
     
      // Odczytujamy czas trwania stanu wysokiego na pinie ECHO
      EchoTime = pulseIn(Echo, HIGH);
     
      // Obliczamy odległość
      Distance = EchoTime / 58;
     
      // Sprawdzamy zakres pomiarowy
      if (Distance >= MaximumRange || Distance <= MinimumRange)
      {
        Serial.println("Poza zakresem");  
      } else  
      {
        if (Distance < 50
       )
        {
          digitalWrite(Red, LOW);  
          delay(5000);    
        } else
        {
          digitalWrite(Red, HIGH);      
        }    
          
        Serial.print("Odleglosc: ");
        Serial.println(Distance);
      }
     
      // Opóźnienie kolejnego pomiaru
      delay(100);
    }

