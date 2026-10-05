#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

const string NAMES[] = {"Rock", "Paper", "Scissors"};

// 0 = draw, 1 = player wins, -1 = computer wins
int getResult(int you, int pc) {
    if (you == pc) return 0;
    return (you + 1) % 3 == pc ? -1 : 1;
}

int readMove() {
    int m;
    while (true) {
        cout << "Your move (0 = Rock, 1 = Paper, 2 = Scissors): ";
        if (cin >> m && m >= 0 && m <= 2) return m;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid! Enter 0, 1 or 2.\n";
    }
}

int main() {
    srand(time(0));
    int rounds;
    cout << "How many rounds do you want to play? ";
    cin >> rounds;

    int win = 0, lose = 0, draw = 0;

    for (int i = 1; i <= rounds; i++) {
        cout << "\n--- Round " << i << "/" << rounds << " ---\n";
        int you = readMove();
        int pc = rand() % 3;

        cout << "You: " << NAMES[you] << " | PC: " << NAMES[pc] << endl;

        int r = getResult(you, pc);
        if (r == 0)      { cout << "Draw!\n";     draw++; }
        else if (r == 1) { cout << "You win!\n";  win++;  }
        else             { cout << "You lose!\n"; lose++; }

        cout << "Score -> Win: " << win << " | Lose: " << lose << " | Draw: " << draw << endl;
    }

    cout << "\n===== FINAL RESULT =====\n";
    if (win > lose)      cout << "You are the champion!\n";
    else if (lose > win) cout << "Computer wins the match!\n";
    else                 cout << "Match tied!\n";
}