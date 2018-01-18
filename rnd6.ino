/*
Sketch uses 4430 bytes (13%) of program storage space. Maximum is 32256 bytes.

Global variables use 370 bytes (18%) of dynamic memory, leaving 1678 bytes for local variables. Maximum is 2048 bytes.

Dieses Programm soll über einen Taster einen Zufallsgenerator für 6 LED's auslösen, sodass diese darauffolgend die jeweilige Zahl
zwischen 1 und 6 darstellen. Eine siebte LED stellt den Status der Eingabe und des Zufallsgenerators dar.

Zum Schluss erfragt eine Schleife um herauszufinden, was gerade dargestellt oder verarbeitet wird.
// Variable Declaration */
int time = 1000; // 1 second to have animations waiting, might decrease for better UI
int buttonPin = 2;
int buttonState;
long rnd;

// Serial Interval
int Ai = 9600; //ms Ableseintervall
//      = 10000;

// Data Frequency f
int Af = 9600; // in Baud; Vin

// LED Pin Identification
int LEDpin_9 = 9;
int LEDpin_8 = 8;
int LEDpin_7 = 7;
int LEDpin_6 = 6;
int LEDpin_5 = 5;
int LEDpin_4 = 4;
int LEDpin_3 = 3;

// Initialisation
void setup()
{
  //Serial.available();
  Serial.begin(Ai);
  pinMode(LEDpin_9, OUTPUT);
  pinMode(LEDpin_8, OUTPUT);
  pinMode(LEDpin_7, OUTPUT);
  pinMode(LEDpin_6, OUTPUT);
  pinMode(LEDpin_5, OUTPUT);
  pinMode(LEDpin_4, OUTPUT);
  pinMode(LEDpin_3, OUTPUT);
  pinMode(buttonPin, INPUT);
  //pinMode(buttonPin, INPUT_PULLUP);
  
  Serial.println("Test LEDs");
  digitalWrite(LEDpin_3, HIGH); // Mitte 			| grau
  digitalWrite(LEDpin_4, HIGH); // Links unten 			| blau
  digitalWrite(LEDpin_5, HIGH); // Mitte unten			| türkis	
  digitalWrite(LEDpin_6, HIGH); // Rechts unten			| grün
  digitalWrite(LEDpin_7, HIGH); // Rechts oben			| gelb
  digitalWrite(LEDpin_8, HIGH); // Mitte oben			| orange
  digitalWrite(LEDpin_9, HIGH); // Links oben			| weiss
  delay(time/10); 			// Blink
  digitalWrite(LEDpin_9, LOW);
  digitalWrite(LEDpin_8, LOW);
  digitalWrite(LEDpin_7, LOW);
  digitalWrite(LEDpin_6, LOW);
  digitalWrite(LEDpin_5, LOW);
  digitalWrite(LEDpin_4, LOW);
  digitalWrite(LEDpin_3, LOW);
  
  Serial.println("Zähle 1.");
  digitalWrite(LEDpin_9, HIGH);
  delay(time);
  digitalWrite(LEDpin_9, LOW);
  delay(time);
  
  Serial.println("Zähle 2.");
  digitalWrite(LEDpin_4, HIGH);
  digitalWrite(LEDpin_9, HIGH);
  delay(time);
  digitalWrite(LEDpin_9, LOW);
  digitalWrite(LEDpin_4, LOW);
  delay(time);
  
  Serial.println("Zähle 3.");
  digitalWrite(LEDpin_3, HIGH);
  digitalWrite(LEDpin_4, HIGH);
  digitalWrite(LEDpin_7, HIGH);
  delay(time);
  digitalWrite(LEDpin_7, LOW);
  digitalWrite(LEDpin_4, LOW);
  digitalWrite(LEDpin_3, LOW);
  delay(time);
  
  Serial.println("Zähle 4.");
  digitalWrite(LEDpin_4, HIGH);
  digitalWrite(LEDpin_6, HIGH);
  digitalWrite(LEDpin_7, HIGH);
  digitalWrite(LEDpin_9, HIGH);
  delay(time);
  digitalWrite(LEDpin_9, LOW);
  digitalWrite(LEDpin_7, LOW);
  digitalWrite(LEDpin_6, LOW);
  digitalWrite(LEDpin_4, LOW);
  delay(time);
  
  Serial.println("Zähle 5.");
  digitalWrite(LEDpin_3, HIGH);
  digitalWrite(LEDpin_4, HIGH);
  digitalWrite(LEDpin_6, HIGH);
  digitalWrite(LEDpin_7, HIGH);
  digitalWrite(LEDpin_9, HIGH);
  delay(time);
  digitalWrite(LEDpin_9, LOW);
  digitalWrite(LEDpin_7, LOW);
  digitalWrite(LEDpin_6, LOW);
  digitalWrite(LEDpin_4, LOW);
  digitalWrite(LEDpin_3, LOW);
  delay(time);
  
  Serial.println("Zähle 6.");
  digitalWrite(LEDpin_4, HIGH);
  digitalWrite(LEDpin_5, HIGH);
  digitalWrite(LEDpin_6, HIGH);
  digitalWrite(LEDpin_7, HIGH);
  digitalWrite(LEDpin_8, HIGH);
  digitalWrite(LEDpin_9, HIGH);
  delay(time);
  digitalWrite(LEDpin_9, LOW); 
  digitalWrite(LEDpin_8, LOW);
  digitalWrite(LEDpin_7, LOW);
  digitalWrite(LEDpin_6, LOW);
  digitalWrite(LEDpin_5, LOW);
  digitalWrite(LEDpin_4, LOW);
  delay(time);
  
  Serial.println("Alle LEDs.");
  digitalWrite(LEDpin_3, HIGH); // Mitte
  digitalWrite(LEDpin_4, HIGH); // Links unten
  digitalWrite(LEDpin_5, HIGH); // Mitte unten
  digitalWrite(LEDpin_6, HIGH); // Rechts unten
  digitalWrite(LEDpin_7, HIGH); // Rechts oben
  digitalWrite(LEDpin_8, HIGH); // Mitte oben
  digitalWrite(LEDpin_9, HIGH); // Links oben
  delay(time);
  digitalWrite(LEDpin_9, LOW);
  digitalWrite(LEDpin_8, LOW);
  digitalWrite(LEDpin_7, LOW);
  digitalWrite(LEDpin_6, LOW);
  digitalWrite(LEDpin_5, LOW);
  digitalWrite(LEDpin_4, LOW);
  digitalWrite(LEDpin_3, LOW);

  delay(time); // Wait for specified millisecond(s)
  
  
  randomSeed(analogRead(0));
  Serial.begin(Ai);
  Serial.println("Initialisation abgeschlossen. Zufällige Wiedergabe ...");
}

// Default mode
/* 
    The loop uses the preinitialised pins & functions and runs over them continously.
    The random function uses as MINIMUM lowerBorder 1 && as MAXIMUM upperBorder 7 to target all 7 LEDs and can be changed manually.
    Later on a prompt could ask the user to type in the necessary number of lamps & the code could adapt flexibly.
    A switch statement is more undefined but quicker than 7 if statements to call the right number to be displayed
*/


void loop()
{
  Serial.println("Würfeln ...");
  buttonState = digitalRead(buttonPin);
  Serial.println("buttonState");
  Serial.println(buttonState);
  if (buttonState == LOW){
    rnd = random(1, 7); 
    switch (rnd) {
    case 1:
      digitalWrite(LEDpin_3, HIGH);
      Serial.println("Zähle 1.");
      delay (time);
      break;
    case 2:
      digitalWrite(LEDpin_4, HIGH);
      digitalWrite(LEDpin_9, HIGH);
      Serial.println("Zähle 2.");
      delay (time);
      break;
    case 3:
      digitalWrite(LEDpin_3, HIGH);
      digitalWrite(LEDpin_4, HIGH);
      digitalWrite(LEDpin_7, HIGH);
      Serial.println("Zähle 3.");
      delay (time);
      break;
    case 4:
      digitalWrite(LEDpin_4, HIGH);
      digitalWrite(LEDpin_6, HIGH);
      digitalWrite(LEDpin_7, HIGH);
      digitalWrite(LEDpin_9, HIGH);
      Serial.println("Zähle 4.");
      delay (time);
      break;
    case 5:  
	    digitalWrite(LEDpin_3, HIGH);
      digitalWrite(LEDpin_4, HIGH);
      digitalWrite(LEDpin_6, HIGH);
      digitalWrite(LEDpin_7, HIGH);
      digitalWrite(LEDpin_9, HIGH);
      Serial.println("Zähle 5.");
      delay (time);
      break;
   case 6: 
      digitalWrite(LEDpin_4, HIGH);
      digitalWrite(LEDpin_5, HIGH);
      digitalWrite(LEDpin_6, HIGH);
      digitalWrite(LEDpin_7, HIGH);
      digitalWrite(LEDpin_8, HIGH);
      digitalWrite(LEDpin_9, HIGH);
      Serial.println("Zähle 6.");
      delay (time);
      break;
   }
  }
  
  // Display error message after waiting for specified amount of seconds and shutting off all lamps.
  delay(time); // Wait for specified millisecond(s)
  digitalWrite(buttonPin, HIGH);
  digitalWrite(LEDpin_3, LOW);
  digitalWrite(LEDpin_4, LOW);
  digitalWrite(LEDpin_5, LOW);
  digitalWrite(LEDpin_6, LOW);
  digitalWrite(LEDpin_7, LOW);
  digitalWrite(LEDpin_8, LOW);
  digitalWrite(LEDpin_9, LOW);
  
  delay(time*2);
  Serial.println("Programm beendet.");
  Serial.flush();
}
