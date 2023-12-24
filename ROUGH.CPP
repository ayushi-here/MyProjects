#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Choice { ROCK, PAPER, SCISSORS };

void printMenu() {
    cout << "1. Rock\n2. Paper\n3. Scissors\nEnter your choice (1-3): ";
}

Choice getUserChoice() {
    int choice;
    cin >> choice;
    return static_cast<Choice>(choice - 1);
}

Choice generateComputerChoice() {
    return static_cast<Choice>(rand() % 3);
}

void determineWinner(Choice user, Choice computer) {
    cout << "Computer: " << (computer == ROCK ? "Rock" : (computer == PAPER ? "Paper" : "Scissors")) << endl;
    cout << "You: " << (user == ROCK ? "Rock" : (user == PAPER ? "Paper" : "Scissors")) << endl;

    if (user == computer) cout << "It's a tie!";
    else if ((user == ROCK && computer == SCISSORS) || (user == PAPER && computer == ROCK) || (user == SCISSORS && computer == PAPER))
        cout << "You win!";
    else
        cout << "Computer wins!";
    cout << "\n-------------------------\n";
}

int main() {
    srand(time(0));

    do {
        printMenu();
        determineWinner(getUserChoice(), generateComputerChoice());
        cout << "Do you want to play again? (y/n): ";
    } while (char playAgain; cin >> playAgain && (playAgain == 'y' || playAgain == 'Y'));

    cout << "Thanks for playing! Goodbye.\n";

    return 0;
}
