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

  // Ustawienie zadanych parametrow akcelerometru
  LSM.setFreq_XL(LSM6DS3_ODR_XL_208); // ODR (czestotliwosc wysylania pomiarow) - 208 Hz
  LSM.setScale_XL(LSM6DS3_FS_XL_16); // FS (zakres pomiarowy) - 16g
  LSM.setBandwith_XL(LSM6DS3_BW_XL_200); // BW (pasmo filtru anty-aliasingowego) - 200 Hz

  // Formatowanie wynikow pomiaru przyspieszenia
  Serial.println("Przyspieszenie w jednostkach g = 9,81 m/s^2:\r\nX: \t Y: \t Z:");
}

void loop()
{
  float X, Y, Z; // przyszpieszenia w 3 osiach
  
  // Pomiary przyspieszenia liniowego
  LSM.readAcceleration(X, Y, Z);
  Serial.print(X);
  Serial.print("g \t");
  Serial.print(Y);
  Serial.print("g \t");
  Serial.print(Z);
  Serial.print("g\n\r");

  delay(500);
}