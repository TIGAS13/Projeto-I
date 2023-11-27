#define Sensor1_PIN_TRIG 3
#define Sensor2_PIN_ECHO 2
#define Sensor3_PIN_TRIG 5
#define Sensor4_PIN_ECHO 4
#define Sensor5_PIN_TRIG 7
#define Sensor6_PIN_ECHO 6

void setup() {
  Serial.begin(115200);
  pinMode(Sensor1_PIN_TRIG, OUTPUT);
  pinMode(Sensor2_PIN_ECHO, INPUT);
  pinMode(Sensor3_PIN_TRIG, OUTPUT);
  pinMode(Sensor4_PIN_ECHO, INPUT);
  pinMode(Sensor5_PIN_TRIG, OUTPUT);
  pinMode(Sensor6_PIN_ECHO, INPUT);
}

void loop() {

  digitalWrite(Sensor1_PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor1_PIN_TRIG, LOW);

  int duration1 = pulseIn(Sensor2_PIN_ECHO, HIGH);
  Serial.print("Distância 1 em CM: ");
  Serial.println(duration1 / 58);

  digitalWrite(Sensor3_PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor3_PIN_TRIG, LOW);

  int duration2 = pulseIn(Sensor4_PIN_ECHO, HIGH);
  Serial.print("Distância 2 em CM: ");
  Serial.println(duration2 / 58);

  digitalWrite(Sensor5_PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor5_PIN_TRIG, LOW);

  int duration3 = pulseIn(Sensor6_PIN_ECHO, HIGH);
  Serial.print("Distância 3 em CM: ");
  Serial.println(duration3 / 58);
  Serial.println("------------------------------");



  delay(1000);
}
