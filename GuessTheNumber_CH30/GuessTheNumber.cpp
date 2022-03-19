#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int main()
{
    mt19937 gen32;
    gen32.seed(std::chrono::system_clock::now().time_since_epoch().count());
    auto randomNumber = gen32() % 101;
    cout << "(Hint) " << randomNumber << "\n";
    int guessedNumber{0U};

    bool isGuessCorrect{false};
    while (!isGuessCorrect)
    {
        cout << "Enter a guess: ";
        cin >> guessedNumber;

        if (randomNumber == guessedNumber)
        {
            isGuessCorrect = true;
            cout << "You guessed it right!\n";
        }
        else if (guessedNumber > 100)
        {
            cout << "Too high. Wasted guess...\n";
        }
        else
        {
            if (randomNumber > guessedNumber)
            {
                cout << "Too low. Guess again...\n";
            }
            else
            {
                cout << "Too high. Guess again...\n";
            }
        }
    }
}