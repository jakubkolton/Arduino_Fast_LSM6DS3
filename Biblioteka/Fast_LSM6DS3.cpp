#include "Fast_LSM6DS3.h"

// Konstruktor obiektu akcelerometru
LSM6DS3 ::LSM6DS3(TwoWire &i2c, uint8_t i2c_addr)
{
    I2C = &i2c,
    I2C_Address = i2c_addr;
}

// Destruktor obiektu akcelerometru
LSM6DS3 ::~LSM6DS3()
{
    // C++ sam niszczy obiekt
}

// Metoda czytania rejestru 1-bajtowego do zmiennej
int LSM6DS3 ::getRegister(uint8_t addr, uint8_t &data)
{
    I2C->beginTransmission(I2C_Address); // rozpoczecie transmisji w kierunku Slave - wyslanie jego adresu + bitu Read
    I2C->write(addr);                    // wyslanie adresu rejestru

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
    data = I2C->read();

    return 1; // kod poprawnego wykonania
}

// Metoda zwracajaca wartosc rejestru
int LSM6DS3 ::readRegister(uint8_t addr)
{
    uint8_t value; // wartosc zwracana z rejestru

    // Obsluga odczytu i ewentualnego bledu
    if (1 != getRegister(addr, value))
    {
        return -1; // kod bledu - nie otrzymano zadnego bajtu danych
    }

    return value;
}

// Metoda szybkiego odczytu pomiaru z akcelerometru - dla predefiniowanych ustawien (?jakich?)
int LSM6DS3 ::readAccelerationFast(float &x, float &y, float &z)
{
    int16_t dataReg;  // bufor na odczytywany rejestr
    uint8_t MSB, LSB; // bufor na MSB i LSB

    // Oś X
    if ((1 != getRegister(LSM6DS3_OUTX_L_XL, LSB)) ||
        (1 != getRegister(LSM6DS3_OUTX_H_XL, MSB)))
        x = NAN; // blad - not a number
    else
    {
        dataReg = (MSB << 8) | LSB;
        x = dataReg * 4.0 / 32768.0; // ze wzoru na przyspieszenie
    }

    // Oś Y
    if ((1 != getRegister(LSM6DS3_OUTY_L_XL, LSB)) ||
        (1 != getRegister(LSM6DS3_OUTY_H_XL, MSB)))
        y = NAN; // blad - not a number
    else
    {
        dataReg = (MSB << 8) | LSB;
        y = dataReg * 4.0 / 32768.0; // ze wzoru na przyspieszenie
    }

    // Oś X
    if ((1 != getRegister(LSM6DS3_OUTZ_L_XL, LSB)) ||
        (1 != getRegister(LSM6DS3_OUTZ_H_XL, MSB)))
        z = NAN; // blad - not a number
    else
    {
        dataReg = (MSB << 8) | LSB;
        z = dataReg * 4.0 / 32768.0; // ze wzoru na przyspieszenie
    }

    return 1;
}

// Metoda szybkiego odczytu pomiaru z zyroskopu - dla predefiniowanych ustawien (?jakich?)
int LSM6DS3 ::readAngularFast(float &x, float &y, float &z)
{
    int16_t dataReg;  // bufor na odczytywany rejestr
    uint8_t MSB, LSB; // bufor na MSB i LSB

    // Oś X
    if ((1 != getRegister(LSM6DS3_OUTX_L_G, LSB)) ||
        (1 != getRegister(LSM6DS3_OUTX_H_G, MSB)))
        x = NAN; // blad - not a number
    else
    {
        dataReg = (MSB << 8) | LSB;
        x = dataReg * 2000.0 / 32768.0; // ze wzoru na przyspieszenie katowe
    }

    // Oś Y
    if ((1 != getRegister(LSM6DS3_OUTY_L_G, LSB)) ||
        (1 != getRegister(LSM6DS3_OUTY_H_G, MSB)))
        y = NAN; // blad - not a number
    else
    {
        dataReg = (MSB << 8) | LSB;
        y = dataReg * 2000.0 / 32768.0; // ze wzoru na przyspieszenie katowe
    }

    // Oś X
    if ((1 != getRegister(LSM6DS3_OUTZ_L_G, LSB)) ||
        (1 != getRegister(LSM6DS3_OUTZ_H_G, MSB)))
        z = NAN; // blad - not a number
    else
    {
        dataReg = (MSB << 8) | LSB;
        z = dataReg * 2000.0 / 32768.0; // ze wzoru na przyspieszenie katowe
    }

    return 1;
}

// Metoda odczytu pomiaru z termometru
int LSM6DS3 ::readTemperature(float &x)
{
    int16_t dataReg;  // bufor na odczytywany rejestr
    uint8_t MSB, LSB; // bufor na MSB i LSB

    if ((1 != getRegister(LSM6DS3_OUT_TEMP_L, LSB)) ||
        (1 != getRegister(LSM6DS3_OUT_TEMP_H, MSB)))
        x = NAN; // blad - not a number
    else
    {
        dataReg = (MSB << 8) | LSB;
        x = 25.0 + (dataReg * 126.0 / 2048.0); // ze wzoru na temperature
        // T = offset (25) + [odczyt * zakres pomiaru (-40 do 125) / zakres ADC (12b, w tym jeden na znak)]
    }

    return 1;
}

// Funkcja szybkiego zapisu do rejestru (wpisywane jest chyba tylko do 1-bajtowych)
int LSM6DS3 ::writeRegisterFast(uint8_t addr, uint8_t value)
{
    I2C->beginTransmission(I2C_Address); // rozpoczecie transmisji w kierunku Slave - wyslanie jego adresu + bitu Write
    I2C->write(addr);                    // wyslanie adresu rejestru
    I2C->write(value);                   // wyslanie wartosci w ramce

    // Obsluga bledu transmisji
    if (0 != I2C->endTransmission())
    {
        return -1; // kod bledu
    }

    return 1; // kod poprawnego wykonania
}

// // Funkcja zapisu do "bezpiecznego" rejestru (wpisywane jest chyba tylko do 1-bajtowych)
int LSM6DS3 ::writeRegister(uint8_t addr, uint8_t value)
{
    // Sprawdzenie rejestrow zarezerwowanych
    for (int i = 0; i < 7; i++)
    {
        if (addr == LSM6DS3_RESERVED[i])
        {
            return -2; // kod bledu - adres zarezerwowany
        }
    }
    if (((addr >= 0x43) && (addr <= 0x48)) || ((addr >= 0x54) && (addr <= 0x57)) ||
        ((addr >= 0x60) && (addr <= 0x65)) || (addr > 0x6B))
    {
        return -2; // kod bledu - adres zarezerwowany
    }

    I2C->beginTransmission(I2C_Address); // rozpoczecie transmisji w kierunku Slave - wyslanie jego adresu + bitu Write
    I2C->write(addr);                    // wyslanie adresu rejestru
    I2C->write(value);                   // wyslanie wartosci w ramce

    // Obsluga bledu transmisji
    if (0 != I2C->endTransmission())
    {
        return -1; // kod bledu
    }

    return 1; // kod poprawnego wykonania
}

// Ustawienie ODR (czestotliwosci wysylania pomiarow) akcelerometru
// Parametr - od 0 do 10: patrz definicje "LSM6DS3_ODR_XL_????"
int LSM6DS3 ::setFreq_XL(uint8_t value)
{
    if ((10 < value))
    {
        return -2; // kod bledu - zly parametr funkcji
    }

    uint8_t reg = readRegister(LSM6DS3_CTRL1_XL);

    reg = (reg & 0x0F) | (value << 4); // wpisanie value na 4 bity MSB
    if (-1 == writeRegisterFast(LSM6DS3_CTRL1_XL, reg))
    {
        return -1; // kod bledu
    }

    return 1; // kod poprawnego wykonania
}

// Ustawienie FS (zakresu pomiarowego) akcelerometru
// Parametr - od 0 do 3: patrz definicje "LSM6DS3_FS_XL_??"
int LSM6DS3 ::setScale_XL(uint8_t value)
{
    if ((3 < value))
    {
        return -2; // kod bledu - zly parametr funkcji
    }

    uint8_t reg = readRegister(LSM6DS3_CTRL1_XL);

    reg = (reg & 0xF3) | (value << 2);
    if (-1 == writeRegisterFast(LSM6DS3_CTRL1_XL, reg))
    {
        return -1; // kod bledu
    }

    return 1; // kod poprawnego wykonania
}

// Ustawienie BW (pasma filtru anty-aliasingowego) akcelerometru
// Parametr - od 0 do 3: patrz definicje "LSM6DS3_BW_XL_???"
int LSM6DS3 ::setBandwith_XL(uint8_t value)
{
    if ((3 < value))
    {
        return -2; // kod bledu - zly parametr funkcji
    }

    uint8_t reg = readRegister(LSM6DS3_CTRL1_XL);

    reg = (reg & 0xFC) | value;
    if (-1 == writeRegisterFast(LSM6DS3_CTRL1_XL, reg))
    {
        return -1; // kod bledu
    }

    return 1; // kod poprawnego wykonania
}

// Ustawienie ODR (czestotliwosci wysylania pomiarow) zyroskopu
// Parametr - od 0 do 7: patrz definicje "LSM6DS3_ODR_G_???"
int LSM6DS3 ::setFreq_G(uint8_t value)
{
    if ((8 < value))
    {
        return -2; // kod bledu - zly parametr funkcji
    }

    uint8_t reg = readRegister(LSM6DS3_CTRL2_G);

    reg = (reg & 0x0F) | (value << 4); // wpisanie value na 4 bity MSB
    if (-1 == writeRegisterFast(LSM6DS3_CTRL2_G, reg))
    {
        return -1; // kod bledu
    }

    return 1; // kod poprawnego wykonania
}

// Ustawienie FS (zakresu pomiarowego) zyroskopu
// Parametr - od 0 do 3: patrz definicje "LSM6DS3_FS_G_??"
int LSM6DS3 ::setScale_G(uint8_t value)
{
    if ((3 < value))
    {
        return -2; // kod bledu - zly parametr funkcji
    }

    uint8_t reg = readRegister(LSM6DS3_CTRL2_G);

    reg = (reg & 0xF3) | (value << 2);
    if (-1 == writeRegisterFast(LSM6DS3_CTRL2_G, reg))
    {
        return -1; // kod bledu
    }

    return 1; // kod poprawnego wykonania
}

// Inicjacja akcelerometru - domyslna, najprostsza
int LSM6DS3 ::beginFast()
{
    I2C->begin(); // dolaczenie sie do magistrali I2C

    // Sprawdzenie obecnosci akcelerometru na magistrali
    if (0x69 != readRegister(LSM6DS3_WHO_AM_I))
    {
        // end();     // zakonczenie akcelerometru
        return -1; // przerwanie procedury
    }

    // Sztywne ustawienie parametrow zyroskopu - 104 Hz, 2000 dps, tryb Bypass
    if (-1 == writeRegisterFast(LSM6DS3_CTRL2_G, 0x4C))
        

    // Sztywne ustawienie parametrow akcelerometru - 104 Hz, 4g, tryb Bypass, ODR/4 (filtr dolnoprz.)
    writeRegisterFast(LSM6DS3_CTRL1_XL, 0x4A);

    // Sztywne ustawienie parametrow zyroskopu - tryb High Performance, pasmo 16 MHz
    writeRegisterFast(LSM6DS3_CTRL7_G, 0x00);

    // Sztywne ustawienie parametrow akcelerometru - ODR/4
    writeRegisterFast(LSM6DS3_CTRL8_XL, 0x09);

    return 1;
}

// Inicjalizacja akcelerometru - z wybranymi parametrami
// Paramtery - jak w funkcjach ustawiajacych poszczegolne parametry
int LSM6DS3 ::begin(uint8_t ODR_XL, uint8_t FS_XL, uint8_t BW_XL, uint8_t ODR_G, uint8_t FS_G)
{
    if ((10 < ODR_XL) || (3 < FS_XL) || (3 < BW_XL) || (8 < ODR_G) || (3 < FS_G))
    {
        return -2; // kod bledu - zly parametr funkcji
    }

    I2C->begin(); // dolaczenie sie do magistrali I2C

    // Sprawdzenie obecnosci akcelerometru na magistrali
    if (0x69 != readRegister(LSM6DS3_WHO_AM_I))
    {
        // end();     // zakonczenie akcelerometru
        return -1; // przerwanie procedury
    }

    // Przygotowanie parametrow zyroskopu
    uint8_t CTRL2_G;
    CTRL2_G = (ODR_G << 4) | (FS_G << 2);

    // Przygotowanie parametrow akcelerometru
    uint8_t CTRL1_XL;
    CTRL1_XL = (ODR_XL << 4) | (FS_XL << 2) | (BW_XL);


    // ustawienie parametrow zyroskopu
    writeRegisterFast(LSM6DS3_CTRL2_G, CTRL2_G);

    // ustawienie parametrow akcelerometru
    writeRegisterFast(LSM6DS3_CTRL1_XL, CTRL1_XL);

    // Sztywne ustawienie parametrow zyroskopu - tryb High Performance, pasmo 16 MHz
    writeRegisterFast(LSM6DS3_CTRL7_G, 0x00);

    // Sztywne ustawienie parametrow akcelerometru - ODR/4
    writeRegisterFast(LSM6DS3_CTRL8_XL, 0x09);

    return 1;
}

// Wylaczenie akcelerometru
void LSM6DS3 ::end()
{
    writeRegisterFast(LSM6DS3_CTRL2_G, 0x00);  // Wylacza zyroskop
    writeRegisterFast(LSM6DS3_CTRL1_XL, 0x00); // Wylacza akcelerometr

    I2C->end(); // konczy obiekt SPI
}
