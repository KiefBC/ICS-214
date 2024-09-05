#include <iostream>
#include <limits>

using namespace std; // I hate typing std:: before everything

bool userGuess(int maxRange);
int promptUserForMaxRange();

int main() {

    int maxRange = promptUserForMaxRange();
    cout << "Max range: " << maxRange << endl;

    while (userGuess(maxRange)) {
        char response;

        cout << "Do you want to play again? (y/n)" << endl;
        cin >> response;
        // TODO: Add input validation, only Y and N should be accepted
        if (response == 'n') {
            cout << "\nThank you for playing! Goodbye!" << endl;
            return 0;
        } else {
            cout << "Great! Let's play again!\n" << endl;
        }
    }
}

int promptUserForMaxRange() {
    int maxRange = 0;
    cout << "Enter the maximum range for the mystery number: " << endl;
    try {
        cin >> maxRange;
        if (maxRange < 0) {
            throw invalid_argument("The maximum range must be a positive integer.");
        }
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    return maxRange;
}

bool userGuess(int maxRange) {
    cout << "*** Welcome to the Myster Number Game!" << endl;
    cout << "Guess a number between 0 and " << maxRange << endl;

    // TODO: Let user choose the range of numbers
    int userGuess = 0;
    int mysteryNumber = 0;
    int numGuesses = 0;

    // Generate a random number between -1 and 10
    mysteryNumber = rand() % 10;
    cout << "The mystery number is: " << mysteryNumber << endl;

    while (userGuess != mysteryNumber) {

        while (!(cin >> userGuess)) {
            cin.clear(); // This clears the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This discards the input buffer
            cout << "\nInvalid input. Please enter an integer between 0 and 10: " << std::endl;
        }

        if (userGuess < mysteryNumber) {
            cout << "\nYour guess is too low. Try again!" << endl;
        } else if (userGuess > mysteryNumber) {
            cout << "\nYour guess is too high. Try again!" << endl;
        }

        numGuesses++;
    }

    cout << "Congratulations! You guessed the mystery number!\n" << endl;
    cout << "It took you " << numGuesses << " guesses to find the mystery number." << std::endl;

    return true;
}
