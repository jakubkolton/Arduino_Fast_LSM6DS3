#ifndef _FAST_LSM6DS3_H_
#define _FAST_LSM6DS3_H_



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
#define LSM6DS3_CTRL7_C 0x16
#define LSM6DS3_CTRL8_XL 0x17
#define LSM6DS3_CTRL9_XL 0x18
#define LSM6DS3_CTRL10_C 0x19
#define LSM6DS3_MASTER_CONFIG 0x1A
#define LSM6DS3_WAKE_UP_SRC 0x1B
#define LSM6DS3_TAP_SRC 0x1C
#define LSM6DS3_D6D_SRC 0x1D
#define LSM6DS3_STATUS_REG 0x1E
#define LSM6DS3_RESERVED 0x1F
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
#define LSM6DS3_OUT_MAG_RAW_X_H 0x6B

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

// Rejestry zakazane
// Dopisac adresy sprawdzane w !pro funkcji! zapisujacej do rejestru

#include <Arduino.h>
#include <Wire.h>

class LSM6DS3
{
    public:    

        // Konstruktor obiektu akcelerometru
        LSM6DS3 (TwoWire& i2c, uint8_t i2c_addr);

        // Destruktor obiektu akcelerometru
        ~LSM6DS3();


        // Inicjacja akcelerometru - domyslna, najprostsza
        int begin();
        // Dopisac taka dla pro uzytkownikow

        // Zakonczenie akcelerometru
        void end();

        // Metoda czytania rejestru bytes-bajtowego
        int readRegister (uint8_t addr, uint8_t *data, uint8_t bytes);

        
        
        
        
        
        
        /*
        // Funkcje czytania rejestru/rejestrow
        int readRegister (uint8_t addr);
        int readMultipleRegisters (uint8_t addr, uint8_t *data, uint8_t bytes);
        */



    
    private:

        TwoWire* I2C; // uchwyt do struktury I2C
        uint8_t I2C_Address; // adres (Slave) I2C akcelerometru

        // Funkcja zapisu do rejestru
        int writeRegister (uint8_t addr, uint8_t value);



}




#endif
