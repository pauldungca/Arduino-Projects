#include <dht.h>        
#define tempPin 10    
dht DHT;

int greenlight = 6;
int yellowlight = 4;
int redlight = 2;

int potPin = A2;
int waterPin = A1;
int soundPin = A0;

void GreenLight(){
  digitalWrite(redlight, LOW);
  digitalWrite(yellowlight, LOW);
  digitalWrite(greenlight, HIGH);
}

void YellowLight(){
  digitalWrite(redlight, LOW);
  digitalWrite(greenlight, LOW);
  digitalWrite(yellowlight, HIGH);
}

void RedLight(){
  digitalWrite(yellowlight, LOW);
  digitalWrite(greenlight, LOW);
  digitalWrite(redlight, HIGH);  
}

void NoLight(){
  digitalWrite(greenlight, LOW);
  digitalWrite(yellowlight, LOW);
  digitalWrite(redlight, LOW);
}

void WaterLevelSensor(){

  int waterLevel = analogRead(waterPin);  

  int low = 350;
  int med = 380;

  if (waterLevel == 0){
    NoLight();
  }
  else if (waterLevel > 0 && waterLevel <= low){
    GreenLight();
  }
  else if (waterLevel > low && waterLevel <= med){
    YellowLight();
  }
  else {
    RedLight();
  }

  Serial.print("Water Level: ");
  Serial.print(waterLevel);
  Serial.println(" ");

  delay(500);
}

void DHT11Sensor(){

  int readData = DHT.read11(tempPin);

	float temp = DHT.temperature;  // Read temperature

  if (temp < 20){
    GreenLight();
  }
  else if (temp >= 20 && temp <= 30) {
    YellowLight();
  }
  else if (temp > 30) {
    RedLight();
  }

  Serial.print("Temparature: ");
  Serial.print(temp);
  Serial.print("°C");
  Serial.println(" ");

  delay(500);
}

void SoundSensor(){

  int sound = analogRead(soundPin);

  int low = 300;
  int med = 600;

  if (sound <= low){ 
    GreenLight();
  }
  else if (sound > low && sound <= med){ 
    YellowLight();
  }
  else{
     RedLight();
  }

  Serial.print("Sound Level: ");
  Serial.print(sound);
  Serial.println(" ");

  delay(500);
}

void setup() {

  pinMode(greenlight, OUTPUT);
  pinMode(yellowlight, OUTPUT);
  pinMode(redlight, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  int value = analogRead(potPin);

  if (value >= 0 && value <=300) {
    DHT11Sensor();     
  } else if (value >= 301 && value <= 700) {
    WaterLevelSensor();   
  } else {
    SoundSensor();   
  } 

}