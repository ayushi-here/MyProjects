#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void show_board();
void get_X_player_choice();
void get_O_player_choice();
void get_computer_choice();
int count_board(char symbol);
char check_winner();
void comp_vs_player();
void player_vs_player();

int main()
{
    int mode;
    while (true)
    {
        cout << "1. Comp vs player." << endl << "2. Player vs player." << endl << "3. End." << endl;
        cout << "Select an option: ";
        cin >> mode;

        switch (mode)
        {
            case 1:
                comp_vs_player();
                break;
            case 2:
                player_vs_player();
                break;
            case 3:
                exit(1);
            default:
                cout << "Please select a valid choice." << endl;
        }
    }

    return 0;
}

void comp_vs_player()
{
    string player_name;
    cout << "Enter your name: ";
    cin >> player_name;

    while (true)
    {
        show_board();

        if (count_board('X') == count_board('O'))
        {
            cout << player_name << "'s Turn." << endl;
            get_X_player_choice();
        }
        else
        {
            get_computer_choice();
        }

        char winner = check_winner();
        if (winner == 'X')
        {
            show_board();
            cout << player_name << " has won the game!!" << endl;
            break;
        }
        else if (winner == 'O')
        {
            show_board();
            cout << "Computer won!!" << endl;
            break;
        }
        else if (winner == 'D')
        {
            cout << "Game Draw." << endl;
            break;
        }
    }
}

void get_computer_choice()
{
    srand(time(0));
    int choice;

    do
    {
        choice = rand() % 9;
    } while (board[choice] != ' ');

    board[choice] = 'O';
}

void get_X_player_choice()
{
    while (true)
    {
        cout << "Select your position (1 to 9): ";
        int choice;
        cin >> choice;
        choice--;

        if (choice < 0 || choice > 8)
        {
            cout << "Invalid choice." << endl;
        }
        else if (board[choice] != ' ')
        {
            cout << "Please select an empty choice." << endl;
        }
        else
        {
            board[choice] = 'X';
            break;
        }
    }
}

void get_O_player_choice()
{
    while (true)
    {
        cout << "Select your position (1 to 9): ";
        int choice;
        cin >> choice;
        choice--;

        if (choice < 0 || choice > 8)
        {
            cout << "Invalid choice." << endl;
        }
        else if (board[choice] != ' ')
        {
            cout << "Please select an empty choice." << endl;
        }
        else
        {
            board[choice] = 'O';
            break;
        }
    }
}

void player_vs_player()
{
    string X_player_name, O_player_name;

    cout << "Enter X player name: ";
    cin >> X_player_name;

    cout << "Enter O player name: ";
    cin >> O_player_name;

    while (true)
    {
        show_board();

        if (count_board('X') == count_board('O'))
        {
            cout << X_player_name << "'s turn." << endl;
            get_X_player_choice();
        }
        else
        {
            cout << O_player_name << "'s turn." << endl;
            get_O_player_choice();
        }

        char winner = check_winner();
        if (winner == 'X')
        {
            show_board();
            cout << X_player_name << " won the game!!" << endl;
            break;
        }
        else if (winner == 'O')
        {
            show_board();
            cout << O_player_name << " won the game!!" << endl;
            break;
        }
        else if (winner == 'D')
        {
            cout << "Game Draw." << endl;
            break;
        }
    }
}

int count_board(char symbol)
{
    int total = 0;

    for (int i = 0; i < 9; i++)
    {
        if (board[i] == symbol)
            total += 1;
    }

    return total;
}

char check_winner()
{
    // horizontally
    if ((board[0] == board[1] && board[1] == board[2] && board[0] != ' ') ||
        (board[3] == board[4] && board[4] == board[5] && board[3] != ' ') ||
        (board[6] == board[7] && board[7] == board[8] && board[6] != ' '))
    {
        return board[0];
    }

    // vertically
    if ((board[0] == board[3] && board[3] == board[6] && board[0] != ' ') ||
        (board[1] == board[4] && board[4] == board[7] && board[1] != ' ') ||
        (board[2] == board[5] && board[5] == board[8] && board[2] != ' '))
    {
        return board[0];
    }

    // diagonally
    if ((board[0] == board[4] && board[4] == board[8] && board[0] != ' ') ||
        (board[2] == board[4] && board[4] == board[6] && board[2] != ' '))
    {
        return board[0];
    }

    if (count_board('X') + count_board('O') < 9)
        return 'C';
    else
        return 'D';
}

void show_board()
{
    cout<<endl<<endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << endl;
    cout << "-----------------------" << endl;

    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << endl;
    cout << "-----------------------" << endl;

    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << endl<<endl<<endl;
}
