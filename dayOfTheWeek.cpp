

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <string>

using namespace std;

string weekDaysNames[]{ "Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota", "Niedziela" };    //tablica z nazwami dni tygodnia

int amountOfDaysInWeek[]= { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 335 }; // liczba dni w calym nieprzestepnym roku (dla miesiecy)


//sprawdzamy czy rok jest przestepny, jesli 
// wynik tej funkcji to - 1, wtedy jest przestepny, a jesli 0, nie jest.
int ifYearIsLeap(int year) {
    return (year % 4 == 0);
}

int calculateWeekDay(int year, int month, int day) {     
    int FirstDay;
    FirstDay = day + amountOfDaysInWeek[month - 1];
    if ((month > 2) && (ifYearIsLeap(year) == 1)) {
        FirstDay++;
    }
    int result;
    year = (year - 1) % 100;
    month = (year - 1) - year;
    day = year + year / 4;
    result = (((((month / 100) % 4) * 5) + day) + 7);
    result += FirstDay - 1;
    result %= 7;
    return result;
}

int gettingInput() { //funkcja sprawdzajaca, czy uzytkownik nie popelnil bledu
    int input; 
    while (true) {
    if (!(cin >> input)) {
            cerr << "Podano bledne dane, prosze podac je ponownie!" << endl;
            cerr << "Prosze nacisnac dowolny przycisk." << endl;
            getchar(); getchar();
            cin.clear();
            cin.ignore();
            system("cls");
            cout << "Prosze podac dane na nowo." << endl;
            continue;
    }
    else {
        break;
    }
    }
    return input;

}


int main()
{  
    int year, month, day;
    int result;
    while (true) {
        cout << "Witaj w programie, ktory po podaniu daty, wypisuje Ci ktory jest dzien tygodnia!" << endl;     //menu
        cout << "Prosze podac konkretna date w takim formacie: " << endl;
        cout << "RRRR (rok)" << endl;
        cout << "MM (miesiac)" << endl;
        cout << "DD (dzien)" << endl;
        while (true) {
            cout << "Prosze podac rok" << endl;
            year = gettingInput();
            if (year <= 0) {               //upewniamy sie czy uzytkownik podal rok poprawnie
                cout << "Przy podawaniu roku, wystapil blad, prosze podac rok ponownie!" << endl;
                cout << "Prosze nacisnac dowolny przycisk." << endl;
                getchar(); getchar();
                system("cls");
                continue;
            }
            else {
                break;
            }
        }
        while (true) {
            cout << "Prosze podac miesiac" << endl;
            month = gettingInput();
            if ((month <= 0) || (month > 13)) {               //program upewnia sie czy uzytkownik podal miesiac zgodnie z oficjalna liczba miesiecy w kalendarzu
                cout << "Przy podawaniu miesiaca, wystapil blad, prosze podac miesiac ponownie!" << endl;
                cout << "Prosze nacisnac dowolny przycisk." << endl;
                getchar(); getchar();
                system("cls");
                continue;
            }
            else {
                break;
            }
        }
            while (true) {
                cout << "Prosze podac dzien" << endl;
                day = gettingInput();                              //sprawdzamy czy dzien podany przez uzytkownika jest podany w poprawny sposob, zgodnie z kalendarzem
                if ((((month == 1, 3, 5, 7, 8, 10, 12) && (day > 32 || day <= 0)) || ((month == 4, 6, 9, 11) && (day > 31 || day <= 0))) || ((((month = 2) && (day>29 || day<=0)) || ((ifYearIsLeap(year) == 1) && (day > 30 || day <=0)))) ) {
                    cout << "Przy podawaniu dni, wystapil blad, prosze podac dni ponownie!" << endl;
                    cout << "Prosze nacisnac dowolny przycisk." << endl;
                    getchar(); getchar();
                    system("cls");
                    continue;
                }
                else {
                    break;
                }

            }
            result = calculateWeekDay(year, month, day); //
            cout << "Dana data wypada w: " << weekDaysNames[result] << endl;
            cout << "Prosze nacisnac dowolny przycisk." << endl;
            getchar(); getchar();
            system("cls");
        }
    }




