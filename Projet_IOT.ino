//Include the servo motor library
#include <Servo.h>
//Define the LDR sensor pins
#define LDR1 A5
#define LDR2 A4
#define LED 5
//Define the error value. You can change it as you like
#define error 50
//Starting point of the servo motor
int Spoint =  90;
//Create an object for the servo motor
Servo servo;
int ldr1,ldr2,value1;

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);
//Include servo motor PWM pin
  servo.attach(10);
//Set the starting point of the servo
  servo.write(Spoint);
  delay(1000);
}

void loop() {
//Get the LDR sensor value
   ldr1 = analogRead(LDR1);
//Get the LDR sensor value
   ldr2 = analogRead(LDR2);

//Get the difference of these values
   value1 = abs(ldr1 - ldr2);
  int value2 = abs(ldr2 - ldr1);

//Check these values using a IF condition
  if ((value1 <= error) || (value2 <= error)) {

  } else {
    if (ldr1 > ldr2) {
      Spoint = --Spoint;
      
    }
    if (ldr1 < ldr2) {
      Spoint = ++Spoint;
    
    }
  }
//Write values on the servo motor
  servo.write(Spoint);

   if ((value1 <= error)&&(ldr1 < 300)&&(ldr2 < 300)){ 
  digitalWrite(LED,HIGH);
}else
{
digitalWrite(LED,LOW);
}
PRINT();
  delay(200);
}



void PRINT(){
  Serial.print("ldr1 : ");
  Serial.println(ldr1);

  Serial.print("ldr2 : ");
  Serial.println(ldr2);
 
  Serial.print("value1 : ");
  Serial.println(value1);  
  
  Serial.print("Spoint : ");
  Serial.println(Spoint);
  
}