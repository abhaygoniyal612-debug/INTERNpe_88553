#include <iostream>
using namespace std;

char b[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void show() {
    cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        cout << " " << b[i] << " | " << b[i + 1] << " | " << b[i + 2] << "\n";
        if (i < 6) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool won(char c) {
    int w[8][3] = {{0,1,2},{3,4,5},{6,7,8},   // rows
                   {0,3,6},{1,4,7},{2,5,8},   // columns
                   {0,4,8},{2,4,6}};          // diagonals
    for (auto &l : w)
        if (b[l[0]] == c && b[l[1]] == c && b[l[2]] == c) return true;
    return false;
}

int main() {
    char turn = 'X';

    for (int move = 0; move < 9; move++) {
        show();
        int pos;
        cout << "Player " << turn << ", choose a square (1-9): ";

        // keep asking until the input is a free square
        while (!(cin >> pos) || pos < 1 || pos > 9 || b[pos - 1] == 'X' || b[pos - 1] == 'O') {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid! Try again: ";
        }

        b[pos - 1] = turn;

        if (won(turn)) {
            show();
            cout << "Player " << turn << " wins!\n";
            return 0;
        }
        turn = (turn == 'X') ? 'O' : 'X';
    }

    show();
    cout << "It's a draw!\n";
}