
#include <SPI.h>
#include <SD.h>
#include <TFT.h>  

#define sd_cs  4
#define lcd_cs 10
#define dc     9
#define rst    8


TFT TFTscreen = TFT(lcd_cs, dc, rst);

PImage logo;


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
  logo = TFTscreen.loadImage("DisplayClear.bmp");
  if (!logo.isValid()) {
    Serial.println(F("error while loading DisplayClear.bmp"));
  }
}

void loop() {
  // don't do anything if the image wasn't loaded correctly.
   if (logo.isValid() == false) {
    return;
  }

  Serial.println(F("drawing image"));

  // draw the image to the screen
  TFTscreen.image(logo, 0, 0);

  // wait a little bit before drawing again
  delay(1500);
}
