
#include <SPI.h>
#include <SD.h>
#include <TFT.h>  

#define Sensor1_PIN_TRIG 3
#define Sensor1_PIN_ECHO 2
#define Sensor2_PIN_TRIG 5
#define Sensor2_PIN_ECHO 6
#define Sensor3_PIN_TRIG 7
#define Sensor3_PIN_ECHO 6


#define sd_cs  4
#define lcd_cs 10
#define dc     9
#define rst    8

int i= 0;

TFT TFTscreen = TFT(lcd_cs, dc, rst);

PImage BKG;
PImage img1;


void setup() {

  TFTscreen.begin();

  Serial.begin(9600);
  while (!Serial) {
    // wait for serial port to connect. Needed for native USB port only
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
  BKG = TFTscreen.loadImage("BKG.bmp");
  if (!BKG.isValid()) {
    Serial.println(F("error while loading BKG.bmp"));
  }
}

void loop() {
  digitalWrite(Sensor1_PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor1_PIN_TRIG, LOW);

  int duration1 = pulseIn(Sensor1_PIN_ECHO, HIGH);
  duration1 = duration1/58;

  Serial.print("Distância 1 em CM: ");
  Serial.println(duration1);

  digitalWrite(Sensor2_PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor2_PIN_TRIG, LOW);

  int duration2 = pulseIn(Sensor2_PIN_ECHO, HIGH);
  duration2 = duration2/58;

  Serial.print("Distância 2 em CM: ");
  Serial.println(duration2);

  digitalWrite(Sensor3_PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensor3_PIN_TRIG, LOW);

  int duration3 = pulseIn(Sensor3_PIN_ECHO, HIGH);
  duration3=duration3/58;
  Serial.print("Distância 3 em CM: ");
  Serial.println(duration3);
  //Serial.println("------------------------------");

if (i==0) {
  TFTscreen.image(BKG, 0, 0);
  Serial.println("Impressa imagem de fundo");
 }
  i=i+1;

  // draw the image to the screen
  //sensor1/ sensor da esquerda

  // fixa duration1
  duration1=150/i;
  Serial.println(duration1);
   if (duration1<34) i=1;
  // fixa duratio3


  if (duration1>=100){
    img1= TFTscreen.loadImage("esq1.bmp");
    TFTscreen.image(img1, 7, 38);}
  else if (duration1<100 && duration1>=80){ 
    img1= TFTscreen.loadImage("esq2.bmp");
    TFTscreen.image(img1, 7, 38);}
  else if (duration1<80 && duration1>=60){ 
    img1= TFTscreen.loadImage("esq3.bmp");
    TFTscreen.image(img1, 7, 38);}
  else if (duration1<60 && duration1>=40){
    img1= TFTscreen.loadImage("esq4.bmp");
    TFTscreen.image(img1, 7, 38);}
  else if (duration1<40){ 
    img1= TFTscreen.loadImage("esq5.bmp");
    TFTscreen.image(img1, 7, 38);}
 //sensor2/ sensor do meio

  // fixa duratio2
  duration2=150/i;
  Serial.println(duration2);
   if (duration2<34) i=1;
  // fixa duratio2


  if (duration2>=100) {
    img1= TFTscreen.loadImage("cent1.bmp");
    TFTscreen.image(img1, 56, 46);}
  else if (duration2<100 && duration2>=80){
    img1= TFTscreen.loadImage("cent2.bmp");
    TFTscreen.image(img1, 56, 46);}
  else if (duration2<80 && duration2>=60) {
    img1= TFTscreen.loadImage("cent3.bmp");
    TFTscreen.image(img1, 56, 46);}
  else if (duration2<60 && duration2>=40) {
    img1= TFTscreen.loadImage("cent4.bmp");
    TFTscreen.image(img1, 56, 46);}
  else if (duration2<40){ 
    img1= TFTscreen.loadImage("cent5.bmp");
    TFTscreen.image(img1, 56, 46);}

  //sensor3/ sensor da direita

  // fixa duratio3
  duration3=150/i;
  Serial.println(duration3);
   if (duration3<34) i=1;
  // fixa duratio3


  if (duration3>=100){
    img1= TFTscreen.loadImage("dir1.bmp"); 
  TFTscreen.image(img1, 102, 38);
  }
  else if (duration3<100 && duration3>=80) {
    img1= TFTscreen.loadImage("dir2.bmp");
  TFTscreen.image(img1, 102, 38);
  }
  else if (duration3<80 && duration3>=60) {
    img1= TFTscreen.loadImage("dir3.bmp");
  TFTscreen.image(img1, 102, 38);
  }
  else if (duration3<60 && duration3>=40) {
    img1= TFTscreen.loadImage("dir4.bmp");
  TFTscreen.image(img1, 102, 38);
  }
  else if (duration3<40) {
    img1= TFTscreen.loadImage("dir5.bmp");
  TFTscreen.image(img1, 102, 38);
  }

  // wait a little bit before drawing again
  delay(1000);

}
