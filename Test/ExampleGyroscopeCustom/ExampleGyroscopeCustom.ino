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

    delay(1000); // Pomyslec o liczniku programowym
  }

  // Ustawienie zadanych parametrow zyroskopu
  LSM.setFreq_G(LSM6DS3_ODR_G_208); // ODR (czestotliwosc wysylania pomiarow) - 208 Hz
  LSM.setScale_G(LSM6DS3_FS_G_1000); // FS (zakres pomiarowy) - 1000 */sek

  // Formatowanie wynikow pomiaru przyspieszenia
  Serial.println("Przyspieszenie katowe w jednostkach */sekunde:\r\nX: \t\t Y: \t\t Z:");
}

void loop()
{
  float X, Y, Z; // przyszpieszenia w 3 osiach
  
  // Pomiary przyspieszenia katowego
  LSM.readAngular(X, Y, Z);
  Serial.print(X);
  Serial.print(" \t\t");
  Serial.print(Y);
  Serial.print(" \t\t");
  Serial.print(Z);
  Serial.print(" \n\r");

  delay(500);
}