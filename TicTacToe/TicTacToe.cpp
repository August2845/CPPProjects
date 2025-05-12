#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentPlayer = 'X';

void drawBoard() {
    cout << "Текущее поле:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[2][i] == board[0][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
    return true;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
#endif

    int choice;
    bool gameWon = false;

    while (!gameWon && !isBoardFull()) {
        drawBoard();
        cout << "Игрок " << currentPlayer << ", выберите клетку (1-9): ";
        cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Неверный ход! Попробуй снова.\n";
            continue;
        }

        board[row][col] = currentPlayer;
        if (checkWin()) {
            drawBoard();
            cout << "Игрок " << currentPlayer << " победил!\n";
            gameWon = true;
        }
        else if (isBoardFull()) {
            drawBoard();
            cout << "Ничья!\n";
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}