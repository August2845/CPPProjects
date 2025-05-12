#include "gameLogic.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

void playGame() {
    setlocale(LC_ALL, "Russian"); 
#ifdef _WIN32
    SetConsoleOutputCP(1251); 
    SetConsoleCP(1251);       
#endif

    srand(time(0));
    char playAgain;
    do {
        int secretNumber = rand() % 100 + 1;
        int guess, attempts = 7;
        bool hasWon = false;
        cout << "Добро пожаловать в игру 'Угадай число'!\n";
        cout << "Я загадал число от 1 до 100. У тебя " << attempts << " попыток.\n";
        while (attempts > 0) {
            cout << "Введите ваше число: ";
            cin >> guess;
            attempts--;
            if (guess == secretNumber) {
                cout << "Поздравляю! Ты угадал число!\n";
                hasWon = true;
                break;
            }
            else if (guess > secretNumber) {
                cout << "Слишком большое! Осталось попыток: " << attempts << "\n";
            }
            else {
                cout << "Слишком маленькое! Осталось попыток: " << attempts << "\n";
            }
        }
        if (!hasWon) {
            cout << "Увы, ты проиграл! Загаданное число было: " << secretNumber << "\n";
        }
        cout << "Хочешь сыграть еще раз? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    cout << "Спасибо за игру! До встречи!\n";
}