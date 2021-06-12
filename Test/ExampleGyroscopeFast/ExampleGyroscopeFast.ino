#include "Fast_LSM6DS3.h"

LSM6DS3 LSM(Wire, LSM6DS3_I2C_ADDRESS_DEFAULT); // obiekt akcelerometru

void setup() {
  // Konfiguracja akcelerometru i przesylania pomiarow przez UART
  Serial.begin(9600);
  while (!Serial); // czeka az bedzie polaczenie przez UART


  // Inicjalizacja akcelerometru
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
  // Pomiary przyspieszenia
  float X, Y, Z; // przyszpieszenia w 3 osiach

  LSM.readAngularFast(X, Y, Z);
  Serial.print(X);
  Serial.print(" \t");
  Serial.print(Y);
  Serial.print(" \t");
  Serial.print(Z);
  Serial.print("\n\r");

  delay(500); // Pomyslec o liczniku programowym albo przerwaniu
}