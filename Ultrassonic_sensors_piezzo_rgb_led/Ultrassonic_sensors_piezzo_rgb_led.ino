#include <SoftwareSerial.h>
#define Sensor1_PIN_TRIG 3
#define Sensor2_PIN_ECHO 2
#define Sensor3_PIN_TRIG 5
#define Sensor4_PIN_ECHO 4
#define Sensor5_PIN_TRIG 7
#define Sensor6_PIN_ECHO 24
#define Led_Red 8
#define Led_Green 9
#define Led_Blue 6
#define Buzzer_pin 12

SoftwareSerial B(10,11);

void setup() {
  Serial.begin(115200);
  B.begin(115200);
  pinMode(Sensor1_PIN_TRIG, OUTPUT);
  pinMode(Sensor2_PIN_ECHO, INPUT);
  pinMode(Sensor3_PIN_TRIG, OUTPUT);
  pinMode(Sensor4_PIN_ECHO, INPUT);
  pinMode(Sensor5_PIN_TRIG, OUTPUT);
  pinMode(Sensor6_PIN_ECHO, INPUT);
  pinMode(Led_Red, OUTPUT);
  pinMode(Led_Green, OUTPUT);
  pinMode(Led_Blue, OUTPUT);
  pinMode(Buzzer_pin, OUTPUT);
}

void loop() {
   unsigned long duration = 5000;
  digitalWrite(Sensor1_PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor1_PIN_TRIG, LOW);

  int duration1 = pulseIn(Sensor2_PIN_ECHO, HIGH);
  Serial.print("Distância 1 em CM: ");
  unsigned int distance1 = duration1 / 58;
  Serial.println(distance1);

  digitalWrite(Sensor3_PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor3_PIN_TRIG, LOW);

  int duration2 = pulseIn(Sensor4_PIN_ECHO, HIGH);
  Serial.print("Distância 2 em CM: ");
  unsigned int distance2 = duration2 / 58;
  Serial.println(distance2);

  digitalWrite(Sensor5_PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor5_PIN_TRIG, LOW);

  int duration3 = pulseIn(Sensor6_PIN_ECHO, HIGH);
  Serial.print("Distância 3 em CM: ");
  unsigned int distance3 = duration3 / 58;
  Serial.println(distance3);
  int delayTime1 = map(distance1,0,100,50,500);
  int delayTime2 = map(distance2,0,100,50,500);
  int delayTime3 = map(distance3,0,100,50,500);
  int delayTime = delayTime1 + delayTime2 + delayTime3;

  B.print(distance1);
  B.print(";");
  B.print(distance2);
  B.print(";");
  B.print(distance3);
  B.print(";");
  delay(100);

  if((distance1 < 33 && distance1 != 0) || (distance2 < 33 && distance2 != 0) || (distance3 < 33 && distance3 != 0)){
    digitalWrite(Led_Red, HIGH);
    digitalWrite(Led_Green, LOW);
    digitalWrite(Led_Blue, LOW);
    tone(Buzzer_pin,1000);
    delay(delayTime);
    noTone(Buzzer_pin);

  }
  if(distance1 == 0 || distance2 == 0 || distance3 == 0){
     while (true) {
    tone(Buzzer_pin, 1000);
    delay(100);

  } }
    if((distance1 >= 33 && distance1 < 66)  || (distance2 >= 33 && distance2 < 66) || (distance3 >= 33 && distance3 < 66)){
      digitalWrite(Led_Red, HIGH);
      digitalWrite(Led_Green, HIGH);
    }

  if(distance1 >= 66 || distance2 >= 66 || distance3 >= 66){
    digitalWrite(Led_Red, LOW);
    digitalWrite(Led_Green, HIGH);
    digitalWrite(Led_Blue, LOW);
  }
  
    
  
  
  
  
  Serial.println("------------------------------");






  delay(300);
}