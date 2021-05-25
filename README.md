# Fast_LSM6DS3 - OPIS PROJEKTU

    Wersja projektu: v 3.0

Projekt biblioteki do obsługi akcelerometru LSM6DS3 (wbudowanego w Arduino Nano 33) z pomocą interfejsu I2C.

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

#### v 3.0:
- Autorska obsługa akcelerometru:
    - Publiczna funkcja zapisu do rejestrów (sprawdzająca, czy są na liście rejestrów "dozwolonych").
    - Częściowe wyodrębnienie funkcji uniwersalnych, funkcji domyślnych i funkcji szybkich (z małą kontrolą użytkownika, ale szybkim wykonaniem kodu).
- Planowane rozszerzenia:
    - Stałe predefiniujące różne parametry (częstotliwość, zakres pomiarowy itp.).
    - Funkcja inicjująca akcelerometr z wybranymi parametrami.
    - Funkcja pobierająca zakres pomiarowy, potrzebny przy obliczaniu przyspieszenia.
    - Wyodrębnienie funkcji uniwersalnych, funkcji domyślnych i funkcji szybkich (z małą kontrolą użytkownika, ale szybkim wykonaniem kodu).
    - Dokumentacja z wykorzystaniem Doxygen.
    - Instrukcja obsługi biblioteki.
    - Porównanie szybkości biblioteki z "konkurencyjnymi" z GitHuba.
    - Dodatkowo obsługa żyroskopu, termometru.
    - Autorska obsługa interfejsu I2C.

#### v 2.0:
- Autorska obsługa akcelerometru:
    - Zdefiniowano stałe dla adresów rejestrów akcelerometru.
    - Domyślna inicjalizacja akcelerometru (predefiniowane ustawienia).
    - Funkcje wpisu i odczytu z rejestrów.
    - Zebranie pomiarów przyspieszenia.

#### v 1.0:
- Pierwsza wersja programu.
- Uruchomienie cudzej biblioteki w celu sprawdzenia poprawności pracy peryferiów, programatora itp.