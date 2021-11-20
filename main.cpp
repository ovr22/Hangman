#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

string GetRandomWord();

int main() {
    //Greeting
    cout << "Welcome! We are going to play Hangman!" << endl;

    //Gets a random word from a 10 word bank and lets the user know how many letters are in the word.
    string guessWord = GetRandomWord();
    cout << "Your word has " << guessWord.size() << " letters." << endl;
    for (int i = 0; i < guessWord.size(); ++i) {
        cout << "_";
        if (i == guessWord.size() - 1){
            cout << endl;
        }
    }

    //Makes so that each letter is part of an array and is set throughout the program
    char wordArray[guessWord.size()];
    for (int i = 0; i < guessWord.size(); ++i) {
        wordArray[i] = guessWord.at(i);
    }

    //blank array to show progress as the guesses continue
    char progressArray[guessWord.size()];
    for (int i = 0; i < guessWord.size(); ++i) {
        progressArray[i] = '_';
    }

    //Guessing begins
    vector<char> incorrectV(0, '_');
    int correctGuesses = 0;
    int amountGuesses = 0;
    char guess;
    while (correctGuesses != guessWord.size()) {
        cout << "Enter a guess: ";
        cin >> guess;
        for (int i = 0; i < guessWord.size(); i++) {
            if (guess == wordArray[i]){
                progressArray[i] = wordArray[i];
                correctGuesses++;
                if (i == guessWord.size() - 1) {
                    break;
                }
            }
            else {
                if (guess != wordArray[i] && i == guessWord.size() - 1) {
                    char incorrectLetter = guess;
                    incorrectV.push_back(incorrectLetter);
                }
            }
        }
        for (int i = 0; i < guessWord.size(); ++i) {
            cout << progressArray[i];
        }
        amountGuesses++;
        cout << "\t\t\tNumber of incorrect guesses: " << amountGuesses - correctGuesses;

        cout << "\t\t\tNumber of correct guesses: " << correctGuesses;

        //displays incorrect letters.
        cout << "\t\t\tIncorrect letters: ";
        for (int i = 0; i < incorrectV.size(); ++i) {
            cout << incorrectV.at(i) << " ";
        }
        cout << endl;
    }
    cout << "Congratulations! You guessed the word!\nIt took you " << amountGuesses <<  " to figure it out.";
    cout << "Would you like to play again? (enter 'y' or 'n') ";
    bool play;
    char answer;
    cin >> answer;
    if (answer == 'y') {
        play = true;
        if (play) {
            return main();
        }
    }
    else if (answer == 'n') {
        play = false;
    }
    cout << "Thanks for playing!!" << endl;

    return 0;
}

string GetRandomWord(){
    string randWord;
    srand(time(0));
    int word = rand()%10;
    if (word == 0){
        randWord = "jazzy";
    }
    else if (word == 1) {
        randWord = "giraffe";
    }
    else if (word == 2) {
        randWord = "russia";
    }
    else if (word == 3) {
        randWord = "shoelace";
    }
    else if (word == 4) {
        randWord = "anklet";
    }
    else if (word == 5) {
        randWord = "azimuth";
    }else if (word == 6) {
        randWord = "controller";
    }
    else if (word == 7) {
        randWord = "logarithm";
    }else if (word == 8) {
        randWord = "glial";
    }
    else if (word == 9) {
        randWord = "popcorn";
    }



    return randWord;
}