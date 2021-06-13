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
  Serial.println("Przyspieszenie liniowe w jednostkach g = 9,81 m/s^2:\r\nX: \t Y: \t Z:");
}

void loop()
{
  float X, Y, Z; // przyszpieszenia w 3 osiach

  // Pomiary przyspieszenia liniowego
  LSM.readAccelerationFast(X, Y, Z);
  Serial.print(X);
  Serial.print("g \t");
  Serial.print(Y);
  Serial.print("g \t");
  Serial.print(Z);
  Serial.print("g\n\r");

  delay(500);
}