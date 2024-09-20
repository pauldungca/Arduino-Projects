//for DHT11
#include <dht.h>        
#define outPin 2       
dht DHT;

//for sound sensor
int soundPin = 10;
int sensor = 0;

// for water level sensor
const int read = A0; //Sensor AO pin to Arduino pin A0
int value; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  

  /*sensor = digitalRead(soundPin);

  if (sensor == 1){ 

    Serial.println("Sound Detected!");

    delay(1000);

  }

  else{ 

    Serial.println("No Sound");
    Serial.println("Detected!");

    delay(1000);

  }*/



  /*int readData = DHT.read11(outPin);

	float t = DHT.temperature;        // Read temperature
	float h = DHT.humidity;           // Read humidity

	Serial.print("Temperature = ");
	Serial.print(t);
	Serial.print("°C | ");
	Serial.print((t*9.0)/5.0+32.0);        // Convert celsius to fahrenheit
	Serial.println("°F ");
	Serial.print("Humidity = ");
	Serial.print(h);
	Serial.println("% ");
	Serial.println("");

	delay(100); // wait two seconds*/

  

  value = analogRead(read); //Read data from analog pin and store it to value variable
	
	if (value<=480){ 
		Serial.println("Water level: 0mm - Empty!"); 
	}
	else if (value>480 && value<=530){ 
		Serial.println("Water level: 0mm to 5mm"); 
	}
	else if (value>530 && value<=615){ 
		Serial.println("Water level: 5mm to 10mm"); 
	}
	else if (value>615 && value<=660){ 
		Serial.println("Water level: 10mm to 15mm"); 
	}	
	else if (value>660 && value<=680){ 
		Serial.println("Water level: 15mm to 20mm"); 
	}
	else if (value>680 && value<=690){ 
		Serial.println("Water level: 20mm to 25mm"); 
	}
	else if (value>690 && value<=700){ 
		Serial.println("Water level: 25mm to 30mm"); 
	}
	else if (value>700 && value<=705){ 
		Serial.println("Water level: 30mm to 35mm"); 
	}
	else if (value>705){ 
		Serial.println("Water level: 35mm to 40mm"); 
	}
	
	delay(5000); // Check for new value every 5 sec

  

}
