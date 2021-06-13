/*
    Author: Jakub Kolton

    Fast_LSM6DS3 - Library for LSM6DS3, IMU built-in Arduino Nano 33 IoT

    Latest version: https://github.com/jakubkolton/Arduino_Fast_LSM6DS3
*/

#include "Fast_LSM6DS3.h"

LSM6DS3 LSM(Wire, LSM6DS3_I2C_ADDRESS_DEFAULT); // obiekt akcelerometru

void setup() {
  // Konfiguracja UART (do przesylania pomiarow i komunikatow)
  Serial.begin(9600);
  while (!Serial); // czeka az bedzie polaczenie przez UART


  // Inicjalizacja akcelerometru z domyslnymi parametrami
  while (-1 == LSM.beginFast())
  {
    Serial.println("Blad inicjalizacji akcelerometru!");

    delay(1000);
  }

  // Formatowanie wynikow pomiaru przyspieszenia
  Serial.println("Przyspieszenie katowe w jednostkach */sekunde:\r\nX: \t Y: \t Z:");
}

void loop()
{
  float X, Y, Z; // przyszpieszenia w 3 osiach

  // Pomiary przyspieszenia katowego
  LSM.readAngularFast(X, Y, Z);
  Serial.print(X);
  Serial.print(" \t");
  Serial.print(Y);
  Serial.print(" \t");
  Serial.print(Z);
  Serial.print("\n\r");

  delay(500); // Pomyslec o liczniku programowym albo przerwaniu
}