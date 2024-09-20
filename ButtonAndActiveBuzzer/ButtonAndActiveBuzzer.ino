int buttonPin[] = {8, 9, 10};
int ledPin[] = {2, 3, 4};
int buzzerPin = 7;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 3; i++) {
    pinMode(buttonPin[i], INPUT_PULLUP);
    pinMode(ledPin[i], OUTPUT);
  }
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 3; i++) {
    if (digitalRead(buttonPin[i]) == HIGH) { // Button pressed
      digitalWrite(ledPin[i], HIGH); // Turn on the corresponding LED  
      tone(buzzerPin, 1000);   
      //digitalWrite(buzzerPin,HIGH);
      delay(5000); 
      digitalWrite(ledPin[i], LOW);   
      //digitalWrite(buzzerPin,LOW);   
      noTone(buzzerPin);
      break; 
    }
  }
}