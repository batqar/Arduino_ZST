//Konkurs na najlepsze wydarzenia w ramach Dnia Nowych Technologii w Edukacji,

long cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds *0.01723
  return (pulseIn(echoPin, HIGH)*0.01723);
  
}

void setup()
{
  Serial.begin(9600);

  pinMode(2, OUTPUT);
 // pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  cm =readUltrasonicDistance(7, 6);

  Serial.print(cm);
  Serial.println("cm");
  
  // Dystans bezpiecznej odległści społecznej  COVID-19
  if (cm > 150) {
    digitalWrite(2, LOW);
   // digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    // Dystans nie bezpiecznej odległości społecznej COVID-19
  }
  if (cm <= 150 && cm > 100) {
    digitalWrite(2, HIGH);
   // digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  if (cm <= 100) {
    digitalWrite(2, HIGH);
    //digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  delay(100); // Wait for 100 millisecond(s)
}
