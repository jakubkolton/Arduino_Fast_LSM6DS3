#include "Fast_LSM6DS3.h"

LSM6DS3 LSM(Wire, LSM6DS3_I2C_ADDRESS_DEFAULT); // obiekt akcelerometru

void setup() {
  // Konfiguracja UART (do przesylania pomiarow i komunikatow)
  Serial.begin(9600);
  while (!Serial); // czeka az bedzie polaczenie przez UART


  // Inicjalizacja akcelerometru z zadanymi parametrami (104 Hz, 4g, filtr antyaliasingowy 100 Hz; 104 Hz, 2000 dps) 
  while (-1 == LSM.begin(LSM6DS3_ODR_XL_104, LSM6DS3_FS_XL_4, LSM6DS3_BW_XL_100, LSM6DS3_ODR_G_104, LSM6DS3_FS_G_2000))
  {
    Serial.println("Blad inicjalizacji akcelerometru!");

    delay(1000);
  }

  // Formatowanie wynikow pomiarow
  Serial.println("Przyspieszenie w jednostkach g = 9,81 m/s^2:\r\nX: \t Y: \t Z:");
  Serial.println("Przyspieszenie katowe w jednostkach */sekunde:\r\nX: \t Y: \t Z:");
  Serial.println("Temperatura w jednostkach *C:");
}

void loop()
{
  float X, Y, Z; // przyszpieszenia w 3 osiach
  float T; // temperatura
  
  // Pomiary przyspieszenia liniowego
  LSM.readAcceleration(X, Y, Z);
  Serial.print(X);
  Serial.print("g \t");
  Serial.print(Y);
  Serial.print("g \t");
  Serial.print(Z);
  Serial.print("g\n\r");

  delay(500);

  // Pomiary przyspieszenia katowego
  LSM.readAngular(X, Y, Z);
  Serial.print(X);
  Serial.print("*/sek \t");
  Serial.print(Y);
  Serial.print("*/sek \t");
  Serial.print(Z);
  Serial.print("*/sek\n\r");

  delay(500);
  
  // Pomiary temperatury
  LSM.readTemperature(T);
  Serial.print(T);
  Serial.print("*C\n\r\n\r");

  delay(1500); 
}