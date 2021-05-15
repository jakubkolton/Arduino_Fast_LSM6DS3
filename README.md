# Fast_LSM6DS3 - OPIS PROJEKTU

    Wersja projektu: v 2.0 (niepełna)

Projekt biblioteki do obsługi akcelerometru LSM6DS3 wbudowanego w Arduino Nano 33.

### Poprawna praca akcelerometru (na moim biurku):
- Płytka leży na stole: X =  0; Y =  0; Z =  1.
- Płytka z USB do góry: X =  1; Y =  0; Z =  0.
- Płytka z USB do dołu: X = -1; Y =  0; Z =  0;
- Płytka z pinami A(x) do góry: X = 0; Y =  1; Z =  0;
- Płytka z pinami A(x) do dołu: X = 0; Y = -1; Z =  0;

## HISTORIA ZMIAN:

#### v 2.0:
- Autorska obsługa akcelerometru z wykorzystaniem cudzej biblioteki do interfejsu SPI/I2C:
    - Zdefiniowano stałe dla adresów rejestrów akcelerometru
    - ? Inicjalizacja akcelerometru ?
    - ? Zebranie pomiarów ?
- Planowane rozszerzenia:
    - Dokończyć w/w.
    - Rozszerzenie biblioteki o szereg szybszych funkcji, m.in :
        - Odczyt rejestrów 1- i 2-bajtowych
        - Inicjalizacja domyślna
        - + Stałe predefiniujące różne rzeczy
    - Autorska obsługa intefrejsu SPI/I2C.
    - Dokumentacja z wykorzystaniem Doxygen.
    - Instrukcja obsługi biblioteki.
    - Dodatkowo obsługa żyroskopu.
    

#### v 1.0:
- Pierwsza wersja programu.
- Uruchomienie cudzej biblioteki w celu sprawdzenia poprawności pracy peryferiów, programatora itp.
- Planowane rozszerzenia:
    - Autorska obsługa akcelerometru z wykorzystaniem cudzej biblioteki do interfejsu SPI/I2C
    - Autorska obsługa intefrejsu SPI/I2C.
    - Dokumentacja z wykorzystaniem Doxygen.
    - Instrukcja obsługi biblioteki.
    - Dodatkowo obsługa żyroskopu.