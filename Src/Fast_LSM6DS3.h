/**
 * @file Fast_LSM6DS3.h
 * @author Jakub Kołton
 * @brief Główny plik nagłówkowy
 * @version 6.0
 * @date 2021-06-24
 * 
 * @copyright Copyright (c) Jakub Kołton 2021
 * 
 */

/*
    Author: Jakub Kolton

    Fast_LSM6DS3 - Library for LSM6DS3, IMU built-in Arduino Nano 33 IoT

    Latest version: https://github.com/jakubkolton/Arduino_Fast_LSM6DS3
*/

#ifndef _FAST_LSM6DS3_H_
#define _FAST_LSM6DS3_H_

#include <Arduino.h>
#include <Wire.h>

/**
 * @brief Domyślny adres I2C akcelerometru
 * 
 */
#define LSM6DS3_I2C_ADDRESS_DEFAULT 0x6A // domyslny adres I2C akcelerometru

// Rejestry czujnika
#define LSM6DS3_FUNC_CFG_ACCESS 0x01
#define LSM6DS3_SENSOR_SYNC_TIME_FRAME 0x04
#define LSM6DS3_FIFO_CTRL1 0x06
#define LSM6DS3_FIFO_CTRL2 0x07
#define LSM6DS3_FIFO_CTRL3 0x08
#define LSM6DS3_FIFO_CTRL4 0x09
#define LSM6DS3_FIFO_CTRL5 0x0A
#define LSM6DS3_ORIENT_CFG_G 0x0B
#define LSM6DS3_INT1_CTRL 0x0D
#define LSM6DS3_INT2_CTRL 0x0E
#define LSM6DS3_WHO_AM_I 0x0F
#define LSM6DS3_CTRL1_XL 0x10
#define LSM6DS3_CTRL2_G 0x11
#define LSM6DS3_CTRL3_C 0x12
#define LSM6DS3_CTRL4_C 0x13
#define LSM6DS3_CTRL5_C 0x14
#define LSM6DS3_CTRL6_C 0x15
#define LSM6DS3_CTRL7_G 0x16
#define LSM6DS3_CTRL8_XL 0x17
#define LSM6DS3_CTRL9_XL 0x18
#define LSM6DS3_CTRL10_C 0x19
#define LSM6DS3_MASTER_CONFIG 0x1A
#define LSM6DS3_WAKE_UP_SRC 0x1B
#define LSM6DS3_TAP_SRC 0x1C
#define LSM6DS3_D6D_SRC 0x1D
#define LSM6DS3_STATUS_REG 0x1E
#define LSM6DS3_OUT_TEMP_L 0x20
#define LSM6DS3_OUT_TEMP_H 0x21
#define LSM6DS3_OUTX_L_G 0x22
#define LSM6DS3_OUTX_H_G 0x23
#define LSM6DS3_OUTY_L_G 0x24
#define LSM6DS3_OUTY_H_G 0x25
#define LSM6DS3_OUTZ_L_G 0x26
#define LSM6DS3_OUTZ_H_G 0x27
#define LSM6DS3_OUTX_L_XL 0x28
#define LSM6DS3_OUTX_H_XL 0x29
#define LSM6DS3_OUTY_L_XL 0x2A
#define LSM6DS3_OUTY_H_XL 0x2B
#define LSM6DS3_OUTZ_L_XL 0x2C
#define LSM6DS3_OUTZ_H_XL 0x2D
#define LSM6DS3_SENSORHUB1_REG 0x2E
#define LSM6DS3_SENSORHUB2_REG 0x2F
#define LSM6DS3_SENSORHUB3_REG 0x30
#define LSM6DS3_SENSORHUB4_REG 0x31
#define LSM6DS3_SENSORHUB5_REG 0x32
#define LSM6DS3_SENSORHUB6_REG 0x33
#define LSM6DS3_SENSORHUB7_REG 0x34
#define LSM6DS3_SENSORHUB8_REG 0x35
#define LSM6DS3_SENSORHUB9_REG 0x36
#define LSM6DS3_SENSORHUB10_REG 0x37
#define LSM6DS3_SENSORHUB11_REG 0x38
#define LSM6DS3_SENSORHUB12_REG 0x39
#define LSM6DS3_FIFO_STATUS1 0x3A
#define LSM6DS3_FIFO_STATUS2 0x4B
#define LSM6DS3_FIFO_STATUS3 0x3C
#define LSM6DS3_FIFO_STATUS4 0x3D
#define LSM6DS3_FIFO_DATA_OUT_L 0x3E
#define LSM6DS3_FIFO_DATA_OUT_H 0x3F
#define LSM6DS3_TIMESTAMP0_REG 0x40
#define LSM6DS3_TIMESTAMP1_REG 0x41
#define LSM6DS3_TIMESTAMP2_REG 0x42
#define LSM6DS3_STEP_TIMESTAMP_L 0x49
#define LSM6DS3_STEP_TIMESTAMP_H 0x4A
#define LSM6DS3_STEP_COUNTER_L 0x4B
#define LSM6DS3_STEP_COUNTER_H 0x4C
#define LSM6DS3_SENSORHUB13_REG 0x4D
#define LSM6DS3_SENSORHUB14_REG 0x4E
#define LSM6DS3_SENSORHUB15_REG 0x4F
#define LSM6DS3_SENSORHUB16_REG 0x50
#define LSM6DS3_SENSORHUB17_REG 0x51
#define LSM6DS3_SENSORHUB18_REG 0x52
#define LSM6DS3_FUNC_SRC 0x53
#define LSM6DS3_TAP_CFG 0x58
#define LSM6DS3_TAP_THS_6D 0x59
#define LSM6DS3_INT_DUR2 0x5A
#define LSM6DS3_WAKE_UP_THS 0x5B
#define LSM6DS3_WAKE_UP_DUR 0x5C
#define LSM6DS3_FREE_FALL 0x5D
#define LSM6DS3_MD1_CFG 0x5E
#define LSM6DS3_MD2_CFG 0x5F
#define LSM6DS3_OUT_MAG_RAW_X_L 0x66
#define LSM6DS3_OUT_MAG_RAW_X_H 0x67
#define LSM6DS3_OUT_MAG_RAW_Y_L 0x68
#define LSM6DS3_OUT_MAG_RAW_Y_H 0x69
#define LSM6DS3_OUT_MAG_RAW_Z_L 0x6A
#define LSM6DS3_OUT_MAG_RAW_Z_H 0x6B

// Rejestry wbudowanych funkcji
#define LSM6DS3_SLV0_ADD 0x02
#define LSM6DS3_SLV0_SUBADD 0x03
#define LSM6DS3_SLAVE0_CONFIG 0x04
#define LSM6DS3_SLV1_ADD 0x05
#define LSM6DS3_SLV1_SUBADD 0x06
#define LSM6DS3_SLAVE1_CONFIG 0x07
#define LSM6DS3_SLV2_ADD 0x08
#define LSM6DS3_SLV2_SUBADD 0x09
#define LSM6DS3_SLAVE2_CONFIG 0x0A
#define LSM6DS3_SLV3_ADD 0x0B
#define LSM6DS3_SLV3_SUBADD 0x0C
#define LSM6DS3_SLAVE3_CONFIG 0x0D
#define LSM6DS3_DATAWRITE_SRC_ MODE_SUB_SLV0 0x0E
#define LSM6DS3_PEDO_THS_REG 0x0F
#define LSM6DS3_SM_THS 0x13
#define LSM6DS3_PEDO_DEB_REG 0x14
#define LSM6DS3_STEP_COUNT_DELTA 0x15
#define LSM6DS3_MAG_SI_XX 0x24
#define LSM6DS3_MAG_SI_XY 0x25
#define LSM6DS3_MAG_SI_XZ 0x26
#define LSM6DS3_MAG_SI_YX 0x27
#define LSM6DS3_MAG_SI_YY 0x28
#define LSM6DS3_MAG_SI_YZ 0x29
#define LSM6DS3_MAG_SI_ZX 0x2A
#define LSM6DS3_MAG_SI_ZY 0x2B
#define LSM6DS3_MAG_SI_ZZ 0x2C
#define LSM6DS3_MAG_OFFX_L 0x2D
#define LSM6DS3_MAG_OFFX_H 0x2E
#define LSM6DS3_MAG_OFFY_L 0x2F
#define LSM6DS3_MAG_OFFY_H 0x30
#define LSM6DS3_MAG_OFFZ_L 0x31
#define LSM6DS3_MAG_OFFZ_H 0x32

/**
 * @brief Adresy rejestrów zarezerwowanych
 * 
 */
// Rejestry zarezerwowane - nie wpisywac do nich
const uint8_t LSM6DS3_RESERVED[] = {0x00, 0x02, 0x03, 0x05, 0xDC, 0x1F};
// Dodatkowo: 0x43-48, 0x54-57, 0x60-65


// Ustawienia czujnikow

//      CTRL1_XL - ODR
#define LSM6DS3_ODR_XL_0 0 // Power-down
#define LSM6DS3_ODR_XL_12_5 1// 12.5 Hz
#define LSM6DS3_ODR_XL_26 2 // 26 Hz
#define LSM6DS3_ODR_XL_52 3 // 52 Hz
#define LSM6DS3_ODR_XL_104 4
#define LSM6DS3_ODR_XL_208 5
#define LSM6DS3_ODR_XL_416 6
#define LSM6DS3_ODR_XL_833 7
#define LSM6DS3_ODR_XL_1660 8
#define LSM6DS3_ODR_XL_3300 9
#define LSM6DS3_ODR_XL_6660 10 // 6660 Hz
//      CTRL1_XL - FS
#define LSM6DS3_FS_XL_2 0 // 2g
#define LSM6DS3_FS_XL_4 2 // 4g
#define LSM6DS3_FS_XL_8 3 // 8g
#define LSM6DS3_FS_XL_16 1 // 16g
//      CTRL1_XL - BW
#define LSM6DS3_BW_XL_50 3 // 50 Hz
#define LSM6DS3_BW_XL_100 2 // 100 Hz
#define LSM6DS3_BW_XL_200 1 // 200 Hz
#define LSM6DS3_BW_XL_400 0 // 400 Hz
//      CTRL8_XL - odgornie 0x09 => ODR/4

//      CTRL2_G - ODR
#define LSM6DS3_ODR_G_0 0 // Power-down
#define LSM6DS3_ODR_G_12_5 1// 12.5 Hz
#define LSM6DS3_ODR_G_26 2 // 26 Hz
#define LSM6DS3_ODR_G_52 3 // 52 Hz
#define LSM6DS3_ODR_G_104 4
#define LSM6DS3_ODR_G_208 5
#define LSM6DS3_ODR_G_416 6
#define LSM6DS3_ODR_G_833 7 // 833 MHz
#define LSM6DS3_ODR_G_1666 8 // 1666 MHz
//      CTRL2_G - FS
#define LSM6DS3_FS_G_250 0 // 250 dps
#define LSM6DS3_FS_G_500 1 // 500 dps
#define LSM6DS3_FS_G_1000 2 // 1000 dps
#define LSM6DS3_FS_G_2000 3 // 2000 dps
//      CTRL_7_G - odgornie 0x00 => High Performance, Bandwith = 16 MHz



class LSM6DS3
{
    public:    

        // Konstruktor obiektu akcelerometru
        LSM6DS3 (TwoWire& i2c, uint8_t i2c_addr);

        // Destruktor obiektu akcelerometru
        ~LSM6DS3();


        // Metoda zwracajaca wartosc rejestru
        int readRegister (uint8_t addr);

        // Metoda odczytu pomiaru z akcelerometru (dla dowolnych parametrow)
        int readAcceleration (float &x, float &y, float &z);

        // Metoda szybkiego odczytu pomiaru z akcelerometru - dla domyslnych ustawien
        int readAccelerationFast (float &x, float &y, float &z);

        // Metoda odczytu pomiaru z zyroskopu (dla dowolnych parametrow)
        int readAngular(float &x, float &y, float &z);
        
        // Metoda szybkiego odczytu pomiaru z zyroskopu - dla predefiniowanych ustawien (?jakich?)
        int readAngularFast(float &x, float &y, float &z);

        // Metoda (zawsze szybka) odczytu pomiaru z termometru
        int readTemperature(float &x);

        // Metoda zapisu do "bezpiecznego" rejestru
        int writeRegister (uint8_t addr, uint8_t value);

        // Ustawienie ODR (czestotliwosci wysylania pomiarow) akcelerometru
        // Parametr - od 0 do 10: patrz definicje "LSM6DS3_ODR_XL_????"
        int setFreq_XL(uint8_t value);

        // Ustawienie FS (zakresu pomiarowego) akcelerometru
        // Parametr - od 0 do 3: patrz definicje "LSM6DS3_DS_XL_??"
        int setScale_XL(uint8_t value);

        // Ustawienie BW (pasma filtru anty-aliasingowego) akcelerometru
        // Parametr - od 0 do 3: patrz definicje "LSM6DS3_BW_XL_???"
        int setBandwith_XL(uint8_t value);

        // Ustawienie ODR (czestotliwosci wysylania pomiarow) zyroskopu
        // Parametr - od 0 do 7: patrz definicje "LSM6DS3_ODR_G_???"
        int setFreq_G(uint8_t value);

        // Ustawienie FS (zakresu pomiarowego) zyroskopu
        // Parametr - od 0 do 3: patrz definicje "LSM6DS3_FS_G_??"
        int setScale_G(uint8_t value);


        // Inicjacja akcelerometru - z domyslnymi parametrami
        int beginFast();
        
        // Inicjalizacja akcelerometru - z wybranymi parametrami
        // Paramtery - jak w funkcjach ustawiajacych poszczegolne parametry
        int begin(uint8_t ODR_XL, uint8_t FS_XL, uint8_t BW_XL, uint8_t ODR_G, uint8_t FS_G);

        // Wylaczenie akcelerometru
        void end();


    private:

        TwoWire* I2C; // uchwyt do struktury I2C
        uint8_t I2C_Address; // adres (Slave) I2C akcelerometru

        // Metoda czytania rejestru 1-bajtowego do zmiennej
        int getRegister (uint8_t addr, uint8_t &data);

        // Metoda szybkiego zapisu do rejestru
        int writeRegisterFast (uint8_t addr, uint8_t value);

};


#endif