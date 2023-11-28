#define Sensor1_PIN_TRIG 3
#define Sensor2_PIN_ECHO 2
#define Sensor3_PIN_TRIG 5
#define Sensor4_PIN_ECHO 4
#define Sensor5_PIN_TRIG 7
#define Sensor6_PIN_ECHO 6
#define Led_Red 8
#define Led_Green 9
#define Led_Blue 10
#define Buzzer_pin 11

void setup() {
  Serial.begin(115200);
  pinMode(Sensor1_PIN_TRIG, OUTPUT);
  pinMode(Sensor2_PIN_ECHO, INPUT);
  pinMode(Sensor3_PIN_TRIG, OUTPUT);
  pinMode(Sensor4_PIN_ECHO, INPUT);
  pinMode(Sensor5_PIN_TRIG, OUTPUT);
  pinMode(Sensor6_PIN_ECHO, INPUT);
  pinMode(Led_Red, OUTPUT);
  pinMode(Led_Green, OUTPUT);
  pinMode(Led_Blue, OUTPUT);
}

void loop() {

  digitalWrite(Sensor1_PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor1_PIN_TRIG, LOW);

  int duration1 = pulseIn(Sensor2_PIN_ECHO, HIGH);
  Serial.print("Distância 1 em CM: ");
  int distance1 = duration1 / 58;
  Serial.println(distance1);

  digitalWrite(Sensor3_PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor3_PIN_TRIG, LOW);

  int duration2 = pulseIn(Sensor4_PIN_ECHO, HIGH);
  Serial.print("Distância 2 em CM: ");
  int distance2 = duration2 / 58;
  Serial.println(distance2);

  digitalWrite(Sensor5_PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor5_PIN_TRIG, LOW);

  int duration3 = pulseIn(Sensor6_PIN_ECHO, HIGH);
  Serial.print("Distância 3 em CM: ");
  int distance3 = duration3 / 58;
  Serial.println(distance3);

  if(distance1 < 30 || distance2 < 30 || distance3 < 30){
    digitalWrite(Led_Red, HIGH);
    digitalWrite(Led_Green, LOW);
    digitalWrite(Led_Blue, LOW);
    tone(Buzzer_pin, 1000 + (90 - (distance1 + distance2 + distance3)), 5000);

  }

  else{
    digitalWrite(Led_Red, LOW);
    digitalWrite(Led_Green, HIGH);
    digitalWrite(Led_Blue, LOW);
  }
  
  Serial.println("------------------------------");



  delay(1000);
}
