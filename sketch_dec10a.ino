#include <SPI.h>
#include <SD.h>
#include <TFT.h>
#include <SoftwareSerial.h>

#define Sensor1_PIN_TRIG 3
#define Sensor1_PIN_ECHO 2
#define Sensor2_PIN_TRIG 5
#define Sensor2_PIN_ECHO 4
#define Sensor3_PIN_TRIG 7
#define Sensor3_PIN_ECHO 13
#define Led_Red 8
#define Led_Green 9
#define Led_Blue 6
#define Buzzer_pin 12

#define sd_cs  53
#define lcd_cs 46
#define dc     45
#define rst    47

TFT TFTscreen = TFT(lcd_cs, dc, rst);
SoftwareSerial B(10,11);

PImage BKG;
PImage esq1;
PImage esq2;
PImage esq3;
PImage esq4;
PImage esq5;
PImage dir1;
PImage dir2;
PImage dir3;
PImage dir4;
PImage dir5;
PImage cent1;
PImage cent2;
PImage cent3;
PImage cent4;
PImage cent5;

void setup() {
  Serial.begin(115200);
  B.begin(115200);
  while (!Serial) {
    // wait for serial port to connect.
  }

  Serial.print(F("Initializing SD card..."));

  pinMode(Sensor1_PIN_TRIG, OUTPUT);
  pinMode(Sensor1_PIN_ECHO, INPUT);
  pinMode(Sensor2_PIN_TRIG, OUTPUT);
  pinMode(Sensor2_PIN_ECHO, INPUT);
  pinMode(Sensor3_PIN_TRIG, OUTPUT);
  pinMode(Sensor3_PIN_ECHO, INPUT);
  pinMode(Led_Red, OUTPUT);
  pinMode(Led_Green, OUTPUT);
  pinMode(Led_Blue, OUTPUT);
  pinMode(Buzzer_pin, OUTPUT);
  
  Serial.print(F("Initializing SD card..."));

  // clear the GLCD screen before starting
  TFTscreen.background(255, 255, 255);

  // try to access the SD card. If that fails (e.g.
  // no card present), the setup process will stop.
-  Serial.print(F("Initializing SD card..."));
  if (!SD.begin(sd_cs)) {
    Serial.println(F("failed!"));
    return;
  }
  Serial.println(F("OK!"));

  // initialize and clear the GLCD screen
  TFTscreen.begin();
  TFTscreen.background(255, 255, 255);

  // now that the SD card can be access, try to load the
  // image file.
  BKG = TFTscreen.loadImage("BKG.bmp");
  if (!BKG.isValid()) {
    Serial.println(F("error while loading BKG.bmp"));
  }
  esq1= TFTscreen.loadImage("esq1.bmp");
  if (!esq1.isValid()) {
    Serial.println(F("error while loading esq1.bmp"));
  }
  esq2= TFTscreen.loadImage("esq2.bmp");
  if (!esq2.isValid()) {
    Serial.println(F("error while loading esq2.bmp"));
  }
  esq3= TFTscreen.loadImage("esq3.bmp");
  if (!esq3.isValid()) {
    Serial.println(F("error while loading esq3.bmp"));
  }
  esq4= TFTscreen.loadImage("esq4.bmp");
  if (!esq4.isValid()) {
    Serial.println(F("error while loading esq4.bmp"));
  }
  esq5= TFTscreen.loadImage("esq5.bmp");
  if (!esq5.isValid()) {
    Serial.println(F("error while loading esq5.bmp"));
  }
  dir1= TFTscreen.loadImage("dir1.bmp");
  if (!dir1.isValid()) {
    Serial.println(F("error while loading dir1.bmp"));
  }
  dir2= TFTscreen.loadImage("dir2.bmp");
  if (!dir2.isValid()) {
    Serial.println(F("error while loading dir2.bmp"));
  }
  dir3= TFTscreen.loadImage("dir3.bmp");
  if (!dir3.isValid()) {
    Serial.println(F("error while loading dir3.bmp"));
  }
  dir4= TFTscreen.loadImage("dir4.bmp");
  if (!dir4.isValid()) {
    Serial.println(F("error while loading dir4.bmp"));
  }
  dir5= TFTscreen.loadImage("dir5.bmp");
  if (!dir5.isValid()) {
    Serial.println(F("error while loading dir5.bmp"));
  }
  cent1= TFTscreen.loadImage("cent1.bmp");
  if (!cent1.isValid()) {
    Serial.println(F("error while loading cent1.bmp"));
  }
  cent2= TFTscreen.loadImage("cent2.bmp");
  if (!cent2.isValid()) {
    Serial.println(F("error while loading cent2.bmp"));
  }
  cent3= TFTscreen.loadImage("cent3.bmp");
  if (!cent3.isValid()) {
    Serial.println(F("error while loading cent3.bmp"));
  }
  cent4= TFTscreen.loadImage("cent4.bmp");
  if (!cent4.isValid()) {
    Serial.println(F("error while loading cent4.bmp"));
  }
  cent5= TFTscreen.loadImage("cent5.bmp");
  if (!cent5.isValid()) {
    Serial.println(F("error while loading cent5.bmp"));
  }



}

void loop() {

  TFTscreen.image(BKG, 0, 0);
  
  unsigned long duration = 5000;
  digitalWrite(Sensor1_PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor1_PIN_TRIG, LOW);

  int duration1 = pulseIn(Sensor1_PIN_ECHO, HIGH);
  unsigned int distance1 = duration1/58;
  Serial.print("Distância 1 em CM: ");
  Serial.println(distance1);

  digitalWrite(Sensor2_PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor2_PIN_TRIG, LOW);

  int duration2 = pulseIn(Sensor2_PIN_ECHO, HIGH);
  unsigned int distance2 = duration2/58;
  Serial.print("Distância 2 em CM: ");
  Serial.println(distance2);

  digitalWrite(Sensor3_PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor3_PIN_TRIG, LOW);

  int duration3 = pulseIn(Sensor3_PIN_ECHO, HIGH);
  unsigned int distance3 = duration3/58;
  Serial.print("Distância 3 em CM: ");
  Serial.println(distance3);
  
  //tempo do buzzer
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

  if((distance1 < 40) || (distance2 < 40) || (distance3 < 40)){
    digitalWrite(Led_Red, HIGH);
    digitalWrite(Led_Green, LOW);
    digitalWrite(Led_Blue, LOW);
    while (true) {
    tone(Buzzer_pin, 1000);
    delay(100);

  }
  }
    if((distance1 >= 40 && distance1 < 60)  || (distance2 >= 40 && distance2 < 60) || (distance3 >= 40 && distance3 < 60)){
      digitalWrite(Led_Red, HIGH);
      digitalWrite(Led_Green, HIGH);
      tone(Buzzer_pin,1000);
      delay(delayTime);
      noTone(Buzzer_pin);

    }

  if(distance1 >= 60 || distance2 >= 60 || distance3 >= 60){
    digitalWrite(Led_Red, LOW);
    digitalWrite(Led_Green, HIGH);
    digitalWrite(Led_Blue, LOW);
    tone(Buzzer_pin,1000);
    delay(delayTime);
    noTone(Buzzer_pin);
  }

  // draw the image to the screen
  //sensor1/ sensor da esquerda
  if (duration1>=100) TFTscreen.image(esq1, 7, 38);
  else if (duration1<100 && duration1>=80) TFTscreen.image(esq2, 7, 38);
  else if (duration1<80 && duration1>=60) TFTscreen.image(esq3, 7, 38);
  else if (duration1<60 && duration1>=40) TFTscreen.image(esq4, 7, 38);
  else if (duration1<40) TFTscreen.image(esq5, 7, 38);
 //sensor2/ sensor do meio
  if (duration2>=100) TFTscreen.image(cent1, 56, 46);
  else if (duration2<100 && duration2>=80) TFTscreen.image(cent2, 56, 46);
  else if (duration2<80 && duration2>=60) TFTscreen.image(cent3, 56, 46);
  else if (duration2<60 && duration2>=40) TFTscreen.image(cent4, 56, 46);
  else if (duration2<40) TFTscreen.image(cent5, 56, 46);
 //sensor3/ sensor da direita
  if (duration3>=100) TFTscreen.image(dir1, 102, 38);
  else if (duration3<100 && duration3>=80) TFTscreen.image(dir2, 102, 38);
  else if (duration3<80 && duration3>=60) TFTscreen.image(dir3, 102, 38);
  else if (duration3<60 && duration3>=40) TFTscreen.image(dir4, 102, 38);
  else if (duration3<40) TFTscreen.image(dir5, 102, 38);



  Serial.println("------------------------------");
  // wait a little bit before drawing again
  delay(300);



  
}