#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int number, guess;

    number = rand() % 100 + 1;

    cout << "===== GUESS THE NUMBER GAME =====" << endl;
    cout << "I have selected a number between 1 and 100." << endl;

    do
    {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > number)
        {
            cout << "Too high! Try again." << endl;
        }
        else if (guess < number)
        {
            cout << "Too low! Try again." << endl;
        }
        else
        {
            cout << "Congratulations! You guessed the correct number!" << endl;
        }

    } while (guess != number);

    return 0;
}