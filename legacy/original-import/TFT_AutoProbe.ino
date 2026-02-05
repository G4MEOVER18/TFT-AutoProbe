#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft; // nutzt die Konfiguration aus tft_setup.h

static void backlight_on() {
#ifdef TFT_BL
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, TFT_BACKLIGHT_ON);
#endif
}

void setup() {
  Serial.begin(115200);
  delay(300);

  Serial.println();
  Serial.println("TFT_AutoProbe boot");

  backlight_on();

  tft.init();
  tft.setRotation(1);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("TFT_eSPI OK (init)");
  tft.println();
  tft.println("Look for:");
  tft.println("- Backlight");
  tft.println("- Text visible");

  Serial.println("TFT_AutoProbe: init done");
}

void loop() {
  delay(1000);
}
