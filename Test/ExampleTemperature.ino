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

  // Formatowanie wynikow pomiaru temperatury
  Serial.println("Temperatura w jednostkach *C:");
}

void loop()
{
  // Pomiary temperatury
  float T;

  LSM.readTemperature(T);
  Serial.print(T);
  Serial.print("*C");
  Serial.print("\n\r");

  delay(500);
}