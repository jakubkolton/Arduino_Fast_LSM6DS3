#include "Fast_LSM6DS3.h"



// Konstruktor obiektu akcelerometru
LSM6DS3 :: LSM6DS3 (TwoWire& i2c, uint8_t i2c_addr);
{
    I2C = &i2c,
    I2C_Adress = i2c_addr;
}

// Destruktor obiektu akcelerometru
LSM6DS3 :: ~LSM6DS3()
{
    // C++ sam niszczy obiekt
}

// Metoda czytania rejestru bytes-bajtowego
int LSM6DS3 :: readRegister (uint8_t addr, uint8_t *data, uint8_t bytes)
{
    I2C->beginTransmission(I2C_Address); // rozpoczecie transmisji w kierunku Slave - wyslanie jego adresu + bitu R
    I2C->write(addr); // wyslanie adresu rejestu

    // Obsluga bledu transmisji
    if (I2C->endTransmission(false) != 0)
    {
        return -1; // kod bledu
    }

    // Obsluga zbyt malej liczby odebranych bajtow
    if (I2C->requestFrom(I2C_Address) != bytes) 
    {
        return 0; // kod bledu
    }

    // Obsluga poprawnej liczby odebranych bajtow
    for (uint8_t i = 0; i < bytes; i++) // kolejne bajty
    {
        *data = I2C->read(); // odczyt jednego bajtu
        ++data; // kolejny bajt
    }

    return 1; // kod poprawnego wykonania
}












/*
// Funkcje czytania jednego rejestru
int readRegister (uint8_t addr)
{
    uint8_t value; // wartosc zwracana z rejestru

    // Obsluga odczytu i ewentualnego bledu
    if (readMultipleRegisters(addr, &value, sizeof(value)) != 1)
    {
        return -1; // kod bledu - nie otrzymano zadnego bajtu danych
    }

    return value;
}

// Funkcja czytania kilku rejestrow
int LSM6DS3 :: readMultipleRegisters (uint8_t addr, uint8_t *data, uint8_t bytes)
{
    I2C->beginTransmission(I2C_Address); // rozpoczecie transmisji w kierunku Slave - wyslanie jego adresu + bitu R
    I2C->write(addr); // wyslanie adresu rejestu

    // Obsluga bledu transmisji
    if (I2C->endTransmission(false) != 0)
    {
        return -1; // kod bledu
    }

    // Obsluga zbyt malej liczby odebranych bajtow
    if (I2C->requestFrom(I2C_Address) != bytes) 
    {
        return 0; // kod bledu
    }

    // Obsluga poprawnej liczby odebranych bajtow
    for (uint8_t i = 0; i < bytes; i++) // kolejne bajty
    {
        *data = I2C->read(); // odczyt jednego bajtu
        ++data; // kolejny bajt
    }

    return 1; // kod poprawnego wykonania
}
*/