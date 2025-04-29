// CHATGPT
#include <Wire.h>
#include "Adafruit_VL6180X.h"

Adafruit_VL6180X vl = Adafruit_VL6180X();
// SLUT HJÄLP

int val = 0;
int distanceThreshold = 100;

void setup() {
  Serial.begin(9600);

  pinMode(8, OUTPUT);  // Grön lampa
  pinMode(9, OUTPUT);  // Röd lampa
  pinMode(10, OUTPUT); // Relä
  digitalWrite(10, LOW); // Reläet initialt avstängt
}

void loop() {
  val = vl.readRange();

  delay(100);

  if (val < distanceThreshold) {
    digitalWrite(8, HIGH);   // Grön lampa på
    digitalWrite(9, LOW);    // Röd lampa av
    digitalWrite(10, HIGH);  // Relä på
  } else {
    digitalWrite(8, LOW);    // Grön lampa av
    digitalWrite(9, HIGH);   // Röd lampa på
    digitalWrite(10, LOW);   // Relä av
  }
}
