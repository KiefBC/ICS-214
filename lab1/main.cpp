#include <iostream>
#include <limits>

using namespace std; // I hate typing std:: before everything

bool userGuess(int maxRange);
int promptUserForMaxRange();
int pickRanNumInRange(int minRange, int maxRange);
bool userPlayAgain();
int promptUserForGuess(int maxRange);
void welcomeMsg();
void playOneRound();

int main() {
    int minRange = 0;

    bool playAgain = true;
    // while (playAgain) {
    //     int maxRange = promptUserForMaxRange();
    //     int mysteryNumber = pickRanNumInRange(minRange, maxRange);
    //     int userGuess = promptUserForGuess(maxRange);
    //     playAgain = userPlayAgain();
    // }
    playOneRound();
}

void playOneRound() {
    welcomeMsg();

    int guessCount = 0;
    bool correct = false;

    while (!correct) {
        int maxRange = promptUserForMaxRange();
        int mysteryNumber = pickRanNumInRange(0, maxRange);
        int userGuess = promptUserForGuess(maxRange);

        if (userGuess < mysteryNumber) {
            cout << "Too low!" << endl;
        } else if (userGuess > mysteryNumber) {
            cout << "Too high!" << endl;
        } else {
            correct = true;
        }

        guessCount++;
    }

    std::cout << "Correct, it took you " << guessCount << " guesses!" << std::endl;
}

int promptUserForMaxRange() {
    int maxRange = 0;
    bool validInput = false;

    while (!validInput) {
        cout << "Enter the maximum range for the mystery number: ";
        cin >> maxRange;

        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input buffe
            cout << "Invalid input. Please enter a positive integer." << endl;
        } else if (maxRange < 0) {
            cout << "The maximum range must be a positive integer." << endl;
        } else {
            validInput = true;
        }
    }

    return maxRange;
}

int pickRanNumInRange(int minRange, int maxRange) {
    return rand() % (maxRange - minRange) + minRange;
}

int promptUserForGuess(int maxRange) {
    int userGuess = 0;
    cout << "Enter your guess: " << endl;
    cin >> userGuess;

    return userGuess;
}

bool userPlayAgain() {
    char response;
    cout << "Do you want to play again? (y/n)" << endl;
    cin >> response;

    try {
        if (response != 'y' || response != 'n') {
            throw invalid_argument("Invalid input. Please enter 'y' or 'n'.");
        }
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    return response == 'y';
}

void welcomeMsg() {
    cout << "Welcome to the Number Guessing Game!" << endl;
}
