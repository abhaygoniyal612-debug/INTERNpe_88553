#include <iostream>
#include <string>
using namespace std;

int main() {
    const int W = 30, H = 12, PH = 4;
    int p = 4, bx = 10, by = 5, dx = 1, dy = 1, score = 0;

    while (true) {
        // draw
        cout << "\n";
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++)
                cout << (x == bx && y == by ? 'O' : (x == 0 && y >= p && y < p + PH) ? '|' : '.');
            cout << "\n";
        }
        cout << "Score: " << score << "   Move (w = up, s = down, Enter = stay): ";

        // input (press key + Enter)
        string in;
        getline(cin, in);
        if (in == "w" && p > 0) p--;
        if (in == "s" && p < H - PH) p++;

        // ball
        bx += dx; by += dy;
        if (by <= 0 || by >= H - 1) dy = -dy;
        if (bx >= W - 1) dx = -1;
        if (bx <= 1) {
            if (by >= p && by < p + PH) { dx = 1; score++; }
            else break;
        }
    }
    cout << "\nGame Over! Score: " << score << endl;
}