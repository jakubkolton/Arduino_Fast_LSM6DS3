# Fast_LSM6DS3 - OPIS PROJEKTU

    Wersja projektu: v 6.0 

Projekt biblioteki do obsługi akcelerometru LSM6DS3 (wbudowanego w Arduino Nano 33) z pomocą interfejsu I2C.

## Funkcjonalności biblioteki:
- Biblioteka pozwala na wykonanie pomiarów z akcelerometru, żyroskopu i termometru
- Stałe predefiniujące adresy rejestrów i fragmenty ich wartości, ułatwiające konfigurację.
- Dostęp do rejestrów wbudowanych w LSM6DS3 - możliwość ich odczytu i zapisu.
- Inicjacja - domyślna lub z zadanymi parametrami. Wyłączanie IMU.
- Metody ułatwiające ustawianie wybranych parametrów LSM6DS3.
- Metody do odczytu pomiarów - przyspieszenia liniowego, kątowego i temperatury.
- Większość metod odczytu i zapisu posiada wersję standardową i szybką (z dopiskiem Fast) pozwalającą na szybkie prototypowanie oraz wykonanie kodu. Metod standardowych można używać w każdych warunkach, często pozwalają one np. na ustawianie konkretnych parametrów LSM6DS3. Natomiast użycie metod szybkich zalecane jest tylko, gdy użytkownikowi zależy na szybkich pomiarach - bez samodzielnej konfiguracji parametrów układu.

### Poprawna praca akcelerometru (na moim biurku):
- Płytka leży na stole: X =  0; Y =  0; Z =  1.
- Płytka z USB do góry: X =  1; Y =  0; Z =  0.
- Płytka z USB do dołu: X = -1; Y =  0; Z =  0;
- Płytka z pinami A(x) do góry: X = 0; Y =  1; Z =  0;
- Płytka z pinami A(x) do dołu: X = 0; Y = -1; Z =  0;

### Wymagane dodatkowe biblioteki:
- Arduino.h
- Wire.h

## HISTORIA ZMIAN:

#### v 6.0:
- Autorska obsługa akcelerometru:
    - Funkcja inicjująca akcelerometr z wybranymi parametrami.
    - Wyodrębnienie funkcji uniwersalnych i domyślnych funkcji szybkich (z małą kontrolą użytkownika, ale szybkim wykonaniem kodu).
    - Przygotowanie przykładowych programów wykorzystujących bibliotekę (folder Examples).
    - Instrukcja obsługi biblioteki.

- Planowane rozszerzenia:  
    - Usprawnienie działania I2C.
    - Dokumentacja z wykorzystaniem Doxygen.


#### v 5.0:
- Autorska obsługa akcelerometru:
    - Stałe predefiniujące różne parametry (częstotliwość, zakres pomiarowy itp).
    - Funkcje ustawiające parametry akcelerometru i żyroskopu (częstotliwość próbkowania, zakres pomiarowy itp.).

#### v 4.0:
- Autorska obsługa akcelerometru:
    - Szybka obsługa żyroskopu i termometru.

#### v 3.0:
- Autorska obsługa akcelerometru:
    - Publiczna funkcja zapisu do rejestrów (sprawdzająca, czy są na liście rejestrów "dozwolonych").
    - Częściowe wyodrębnienie funkcji uniwersalnych, funkcji domyślnych i funkcji szybkich (z małą kontrolą użytkownika, ale szybkim wykonaniem kodu).

#### v 2.0:
- Autorska obsługa akcelerometru:
    - Zdefiniowano stałe dla adresów rejestrów akcelerometru.
    - Domyślna inicjalizacja akcelerometru (predefiniowane ustawienia).
    - Funkcje wpisu i odczytu z rejestrów.
    - Zebranie pomiarów przyspieszenia.