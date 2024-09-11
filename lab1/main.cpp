#include <iostream>
#include <limits> // For numeric_limits

using namespace std; // I hate typing std:: before everything

bool userGuess(int maxRange);

int promptUserForMaxRange();

int pickRanNumInRange(int minRange, int maxRange);

bool userPlayAgain();

int promptUserForGuess(int minRange, int maxRange);

void welcomeMsg();

void playOneRound();

void goodbyeMsg();

int main() {
    bool playAgain = true;
    while (playAgain) {
        playOneRound();
        playAgain = userPlayAgain();
    }
}

// This will be the main function that will run the game
void playOneRound() {
    constexpr int minRange = 0; // Placeholder for now
    welcomeMsg();

    int guessCount = 0;
    bool correct = false;
    const int maxRange = promptUserForMaxRange();
    const int mysteryNumber = pickRanNumInRange(minRange, maxRange);

    while (!correct) {
        int userGuess = promptUserForGuess(minRange, maxRange);

        if (userGuess < mysteryNumber) {
            cout << "Too low!\n" << endl;
        } else if (userGuess > mysteryNumber) {
            cout << "Too high!\n" << endl;
        } else {
            correct = true;
        }

        guessCount++;
    }

    cout << "Correct! It took you " << guessCount << " guesses!\n" << endl;
}

// This function will prompt the user for the maximum range
int promptUserForMaxRange() {
    int maxRange;
    while (true) {
        cout << "Enter the Maximum Range: ";
        cin >> maxRange;

        // Can't assign a string to an int
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the buffer
            cout << "Invalid input. Please enter a number." << endl;
        } else {
            return maxRange;
        }
    }
}

// This function will generate a random number within the range
int pickRanNumInRange(int minRange, int maxRange) {
    srand(time(0)); // LSP gives me errors about this not being "random" enough

    const int mysteryNumber = minRange + rand() % (maxRange - minRange + 1);
    cout << "Mystery Number: " << mysteryNumber << endl;

    return mysteryNumber;
}

// This function will prompt the user for their guess
int promptUserForGuess(const int minRange, const int maxRange) {
    int userGuess = 0;

    while (true) {
        cout << "Enter your guess between " << minRange << " and " << maxRange << ": ";
        cin >> userGuess;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid integer.\n" << endl;
        } else if (userGuess < minRange || userGuess > maxRange) {
            cout << "Please enter a number between " << minRange << " and " << maxRange << ".\n";
        } else {
            return userGuess;
        }
    }
}

// This function will allow the user to play again
bool userPlayAgain() {
    char response;

    while (true) {
        cout << "Do you want to play again? (y/n): ";
        cin >> response;

        if (response == 'y' || response == 'n') {
            break;
        }

        cout << "Invalid input. Please enter 'y' for yes or 'n' for no.\n" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (response == 'y') {
        cout << "Great! Let's play again!\n" << endl;
        return true;
    }

    // Print out goodbye message
    goodbyeMsg();
    return false;
}

// This function will display the welcome message
void welcomeMsg() {
    cout << " Welcome to the Number Guessing Game!" << endl; // Leading space was intended
    cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;
}

// This function will display the goodbye message
void goodbyeMsg() {
    cout << "\n Goodbye!" << endl;
    cout << "*=*=*=*=*=*" << endl;
}
