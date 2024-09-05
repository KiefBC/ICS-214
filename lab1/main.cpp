#include <iostream>
#include <limits>

using namespace std; // I hate typing std:: before everything

bool userGuess() {
    cout << "*** Welcome to the Myster Number Game!" << endl;
    cout << "Guess a number between 0 and 10: " << endl;

    int userGuess;
    int mysteryNumber;
    int numGuesses = 0;

    // Generate a random number between 0 and 10
    mysteryNumber = rand() % 11;
    cout << "The mystery number is: " << mysteryNumber << endl;

    while (userGuess != mysteryNumber) {

        while (!(std::cin >> userGuess)) {
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

    cout << "Congratulations! You guessed the mystery number!\n" << std::endl;
    cout << "It took you " << numGuesses << " guesses to find the mystery number." << std::endl;

    return true;
}

int main() {
    while (userGuess()) {
        char response;

        cout << "Do you want to play again? (y/n)" << std::endl;
        std::cin >> response;
        if (response == 'n') {
            cout << "\nThank you for playing! Goodbye!" << std::endl;
            return 0;
        } else {
            cout << "Great! Let's play again!\n" << std::endl;
        }
    }
}
