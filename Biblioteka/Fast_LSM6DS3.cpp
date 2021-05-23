#include "Fast_LSM6DS3.h"
#include <Arduino.h> // wywalic potem, ale Visual szaleje z typami uint8_t bez tego




// Konstruktor obiektu akcelerometru
LSM6DS3 :: LSM6DS3 (TwoWire& i2c, uint8_t i2c_addr)
{
    I2C = &i2c,
    I2C_Address = i2c_addr;
}

// Destruktor obiektu akcelerometru
LSM6DS3 :: ~LSM6DS3()
{
    // C++ sam niszczy obiekt
}

// Metoda czytania rejestru 1-bajtowego do zmiennej
int LSM6DS3 :: getRegister (uint8_t addr, uint8_t *data)
{
    I2C->beginTransmission(I2C_Address); // rozpoczecie transmisji w kierunku Slave - wyslanie jego adresu + bitu Read
    I2C->write(addr); // wyslanie adresu rejestru

    // Obsluga bledu transmisji
    if (0 != I2C->endTransmission(false))
    {
        return -1; // kod bledu
    }

    // Obsluga zbyt malej liczby odebranych bajtow
    if (1 != I2C->requestFrom(I2C_Address, 1)) 
    {
        return 0; // kod bledu
    }

    // Odczyty rejestru - jednego bajtu
    *data = I2C->read();
    
    return 1; // kod poprawnego wykonania
}

// Metoda zwracajaca wartosc rejestru do zmiennej
int LSM6DS3 :: readRegister (uint8_t addr)
{
    uint8_t value; // wartosc zwracana z rejestru

    // Obsluga odczytu i ewentualnego bledu
    if (1 != getRegister(addr, &value))
    {
        return -1; // kod bledu - nie otrzymano zadnego bajtu danych
    }

    return value;
}

// Metoda odczytu pomiaru z akcelerometru
int LSM6DS3 :: readAcceleration(float &x, float &y, float &z)
{
    // ???czy nie wystarczy uint8_t???
    int16_t dataReg; // bufor na odczytywany rejestr

    // Oś X
    if (1 != getRegister(LSM6DS3_OUTX_L_XL, (uint8_t *)dataReg))
        x = NAN; // blad - not a number
    else
        x = dataReg * 4.0 / 32768.0; // ze wzoru na przyspieszenie

    // Oś Y
    if (1 != getRegister(LSM6DS3_OUTY_L_XL, (uint8_t *)dataReg))
        y = NAN; // blad - not a number
    else
        y = dataReg * 4.0 / 32768.0; // ze wzoru na przyspieszenie

    // Oś Z
    if (1 != getRegister(LSM6DS3_OUTZ_L_XL, (uint8_t *)dataReg))
        z = NAN; // blad - not a number
    else
        z = dataReg * 4.0 / 32768.0; // ze wzoru na przyspieszenie

    return 1;
}

// Funkcja zapisu do rejestru (wpisywane jest chyba tylko do 1-bajtowych)
int LSM6DS3 :: writeRegister (uint8_t addr, uint8_t value)
{
    I2C->beginTransmission(I2C_Address); // rozpoczecie transmisji w kierunku Slave - wyslanie jego adresu + bitu Write
    I2C->write(addr); // wyslanie adresu rejestru

    // Obsluga bledu transmisji
    if (0 != I2C->endTransmission())
    {
        return -1; // kod bledu
    }

    return 1; // kod poprawnego wykonania
}

// Inicjacja akcelerometru - domyslna, najprostsza
int LSM6DS3 :: begin()
{
    I2C->begin(); // dolaczenie sie do magistrali I2C

    // Sprawdzenie obecnosci akcelerometru na magistrali
    if (0x69 != readRegister(LSM6DS3_WHO_AM_I)) 
    {
        end(); // co to robi?
        return -1; // przerwanie procedury
    }

    
    // Sztywne ustawienie parametrow
    // Jak w cudzej bibliotece
    //set the gyroscope control register to work at 104 Hz, 2000 dps and in bypass mode
    writeRegister(LSM6DS3_CTRL2_G, 0x4C);

    // Set the Accelerometer control register to work at 104 Hz, 4 g,and in bypass mode and enable ODR/4
    // low pass filter (check figure9 of LSM6DS3's datasheet)
    writeRegister(LSM6DS3_CTRL1_XL, 0x4A);

    // set gyroscope power mode to high performance and bandwidth to 16 MHz
    writeRegister(LSM6DS3_CTRL7_G, 0x00);

    // Set the ODR config register to ODR/4
    writeRegister(LSM6DS3_CTRL8_XL, 0x09);
    

    return 1;
}

// Zakonczenie akcelerometru
void LSM6DS3 :: end()
{
    writeRegister(LSM6DS3_CTRL2_G, 0x00); // co to robi?
    writeRegister(LSM6DS3_CTRL1_XL, 0x00); // co to robi?

    I2C->end(); // konczy obiekt SPI
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

// Metoda czytania rejestru bytes-bajtowego do tablicy (chocby 1-elementowej)
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