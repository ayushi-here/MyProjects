#include <iostream>
#include <cstdlib>
#include <ctime>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(NULL))); // Random number generation. For each time the program runs, it gives a different value. We use the current time. srand expects and only in unsigned int, so we typecast.

    int player_throw = 0;
    int ai_throw = 0;
    bool draw = false;
while(1){
    do {
        cout << "Select your throw." << endl;
        cout << "1). ROCK" << endl;
        cout << "2). PAPER" << endl;
        cout << "3). SCISSORS" << endl;
        cout << "4). End" <<endl;
        cout << "Selection: ";
        cin >> player_throw;
        cout << endl;

        
        if (player_throw < 1 || player_throw > 4) {
            cout << "Invalid input. Please enter 1, 2, or 3." << endl;
            continue;  // Skip the rest of the loop and ask for input again
        }
        if(player_throw==4) exit(1);

        ai_throw = (rand() % 3) + 1; // rand() -> 0.... 9999 % 3 -> 0-2

        if (ai_throw == ROCK)
            cout << "AI throws ROCK." << endl;
        else if (ai_throw == PAPER)
            cout << "AI throws PAPER." << endl;
        else if (ai_throw == SCISSORS)
            cout << "AI throws SCISSORS." << endl;

        draw = false;

        // Rock beats scissors
        // Scissors beats paper
        // Paper beats rock
        if (player_throw == ai_throw) {
            draw = true;
            cout << "Draw! Play again!" << endl;
        } else if (player_throw == ROCK && ai_throw == SCISSORS)
            cout << "ROCK beats SCISSORS! YOU WIN." << endl;
        else if (player_throw == ROCK && ai_throw == PAPER)
            cout << "PAPER beats ROCK! YOU LOSE." << endl;
        else if (player_throw == PAPER && ai_throw == ROCK)
            cout << "PAPER beats ROCK! YOU WIN." << endl;
        else if (player_throw == PAPER && ai_throw == SCISSORS)
            cout << "SCISSORS beats PAPER! YOU LOSE." << endl;
        else if (player_throw == SCISSORS && ai_throw == PAPER)
            cout << "SCISSORS beats PAPER! YOU WIN." << endl;
        else if (player_throw == SCISSORS && ai_throw == ROCK)
            cout << "ROCK beats SCISSORS! YOU LOSE." << endl;

        cout << endl;

    } while (draw);
}
    return 0;
}
