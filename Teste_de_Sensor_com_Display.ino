#include <SPI.h>
#include <SD.h>
#include <TFT.h>

#define Sensor1_PIN_TRIG 3
#define Sensor2_PIN_ECHO 2
#define Sensor3_PIN_TRIG 5
#define Sensor4_PIN_ECHO 4
#define Sensor5_PIN_TRIG 7
#define Sensor6_PIN_ECHO 6

#define sd_cs  1
#define lcd_cs 10
#define dc     9
#define rst    8

TFT TFTscreen = TFT(lcd_cs, dc, rst);

PImage OOR,Far,Medium,Close,TC; //OOR- Out Of Range, TC- Too Close

void setup() {
  Serial.begin(9600);
  pinMode(Sensor1_PIN_TRIG, OUTPUT);
  pinMode(Sensor2_PIN_ECHO, INPUT);
  pinMode(Sensor3_PIN_TRIG, OUTPUT);
  pinMode(Sensor4_PIN_ECHO, INPUT);
  pinMode(Sensor5_PIN_TRIG, OUTPUT);
  pinMode(Sensor6_PIN_ECHO, INPUT);
  
  while (!Serial) {
    // wait for serial port to connect.
  }

  // clear the GLCD screen before starting
  TFTscreen.background(255, 255, 255);

  // try to access the SD card. If that fails (e.g.
  // no card present), the setup process will stop.
  Serial.print(F("Initializing SD card..."));
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
  OOR = TFTscreen.loadImage("DisplayClear.bmp");
  if (!OOR.isValid()) {
    Serial.println(F("error while loading DisplayClear.bmp"));
  }
    Far = TFTscreen.loadImage("Nivel1.bmp");
  if (!Far.isValid()) {
    Serial.println(F("error while loading Nivel1.bmp"));
  }
    Medium = TFTscreen.loadImage("Nivel2.bmp");
  if (!Medium.isValid()) {
    Serial.println(F("error while loading Nivel2.bmp"));
  }
    Close = TFTscreen.loadImage("Nivel3.bmp");
  if (!Close.isValid()) {
    Serial.println(F("error while loading Nivel3.bmp"));
  }
  TC = TFTscreen.loadImage("Dis_Full.bmp");
  if (!TC.isValid()) {
    Serial.println(F("error while loading Dis_Full.bmp"));
  }
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

 
  // draw the image to the screen
  if (duration2>=100) TFTscreen.image(OOR, 0, 0);
  else if (duration2<100 && duration2>=66) TFTscreen.image(Far, 0, 0);
  else if (duration2<66 && duration2>=33) TFTscreen.image(Medium, 0, 0);
  else if (duration2<33) TFTscreen.image(Close, 0, 0);

  // wait a little bit before drawing again
  delay(1500);



  
}