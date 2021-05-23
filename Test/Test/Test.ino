#include "Fast_LSM6DS3.h"

LSM6DS3 LSM(Wire, LSM6DS3_I2C_ADDRESS_DEFAULT); // obiekt klasy

void setup() {
  // Konfiguracja akcelerometru i przesylania pomiarow przez UART
  Serial.begin(9600);
  while (!Serial); // czeka az bedzie polaczenie przez UART


  // Inicjalizacja akcelerometru
  while (-1 == LSM.begin())
  {
    Serial.println("Blad inicjalizacji akcelerometru!");

    delay(1000); // Pomyslec o liczniku programowym
  }

  // Formatowanie wynikow pomiaru
  Serial.println("Przyspieszenie w jednostkach g = 9,81 m/s^2:\nX: \t Y: \t Z:");
}

void loop()
{
  float X, Y, Z; // przyszpieszenia w 3 osiach
  LSM.readAcceleration(X, Y, Z);
  // Serial.println("Delay");
  Serial.print(X);
  Serial.print(" \t");
  Serial.print(Y);
  Serial.print(" \t");
  Serial.print(Z);
  Serial.print("\n");

  delay(1000); // Pomyslec o liczniku programowym albo przerwaniu
}





// ZWALONE SETUP I LOOP, HATFU
/*
#include "Fast_LSM6DS3.h"

// Konfiguracja akcelerometru i przesylania pomiarow przez UART
void setup()
{
  Serial.begin(9600);
  while(!Serial); // czeka az bedzie polaczenie przez UART

  // Inicjalizacja akcelerometru
  LSM6DS3 LSM(Wire, LSM6DS3_I2C_ADDRESS_DEFAULT); // obiekt klasy
  while (-1 == LSM.begin())
  {
    Serial.println("Blad inicjalizacji akcelerometru!");

    delay(1000); // Pomyslec o liczniku programowym
  }
  
  // Formatowanie wynikow pomiaru
  Serial.println("Przyspieszenie w jednostkach g = 9,81 m/s^2:\nX: \t Y: \t Z:");
  float X, Y, Z; // przyszpieszenia w 3 osiach 
}

void loop()
{
  LSM.readAcceleration(X, Y, Z);
  Serial.print(X);
  Serial.print(" \t");
  Serial.print(Y);
  Serial.print(" \t");
  Serial.print(Z);
  Serial.print("\n");

  delay(1000); // Pomyslec o liczniku programowym albo przerwaniu
}
*/


// NA BAZIE CUDZEJ BIBLIOTEKI
/*
#include <Arduino_LSM6DS3.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");

    while (1);
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in g's");
  Serial.println("X\tY\tZ");
}

void loop() {
  float x, y, z;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);

    delay(1000);
  }
}
*/