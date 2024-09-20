
int led1 = 1;
int led2 = 2;
int led3 = 3;
int led4 = 4;
int led5 = 5;
int led6 = 6;

void setup() {
  // put your setup code here, to run once:

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(led1, HIGH);
  digitalWrite(led4, HIGH);
  delay(3000);

  digitalWrite(led1, LOW); 
  digitalWrite(led4, LOW); 
  
  digitalWrite(led2, HIGH);
  digitalWrite(led5, HIGH);
  delay(2000);

  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW); 
  
  digitalWrite(led3, HIGH); 
  digitalWrite(led6, HIGH); 
  delay(3000);

  digitalWrite(led3, LOW); 
  digitalWrite(led6, LOW); 
  
  digitalWrite(led2, HIGH);
  digitalWrite(led5, HIGH);
  delay(2000);

  digitalWrite(led2, LOW); 
  digitalWrite(led5, LOW); 

}




