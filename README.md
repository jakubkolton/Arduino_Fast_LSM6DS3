# Fast_LSM6DS3 - OPIS PROJEKTU

    Wersja projektu: v 2.0

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
    - Domyślna inicjalizacja akcelerometru (predefiniowane ustawienia)
    - Funkcje wpisu i odczytu z rejestrów
    - Zebranie pomiarów przyspieszenia
- Planowane rozszerzenia:
    - Stałe predefiniujące różne parametry (częstotliwość, zakres pomiarowy itp.).
    - Funkcja inicjująca akcelerometr z wybranymi parametrami.
    - Publiczna funkcja zapisu do rejestrów (sprawdzająca, czy są na liście rejestrów "dozwolonych").
    - Funkcja pobierająca zakres pomiarowy, potrzebny przy obliczaniu przyspieszenia.
    - Wyodrębnienie funkcji uniwersalnych, funkcji domyślnych i funkcji szybkich (z małą kontrolą użytkownika, ale szybkim wykonaniem kodu).
    - Dokumentacja z wykorzystaniem Doxygen.
    - Instrukcja obsługi biblioteki.
    - Porównanie szybkości biblioteki z "konkurencyjnymi" z GitHuba.
    - Dodatkowo obsługa żyroskopu, termometru.
    - Autorska obsługa intefrejsu SPI/I2C.
    

#### v 1.0:
- Pierwsza wersja programu.
- Uruchomienie cudzej biblioteki w celu sprawdzenia poprawności pracy peryferiów, programatora itp.