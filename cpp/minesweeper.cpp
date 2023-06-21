#include <iostream>
#include <cctype>

using namespace std;

int main()
{

    /*
    // main gameloop
    bool gameloop = true;
    while (gameloop)
    {
    */

    // anounces game
    cout << "Welcome to MINESWEEPER \n\nPlease select a difficulty: \n\t Normal [N] \n\t Hard [H] \n\t Expert [E]" << endl;
    char userDifficulty;
    int boardX, boardY, numMines;
    int difficulty = -1;

    // sets boardX, boardY and numMines acording to player input
    while (difficulty == -1)
    {
        cin >> userDifficulty;
        userDifficulty = tolower(userDifficulty);
        switch (userDifficulty)
        {
        case 'n':
            difficulty = 0;
            boardX = boardY = 8;
            numMines = 10;
            break;
        case 'h':
            difficulty = 1;
            boardX = boardY = 16;
            numMines = 40;
            break;
        case 'e':
            difficulty = 2;
            boardX = 16;
            boardY = 30;
            numMines = 99;
            break;
        default:
            cout << "Enter valid answer!" << endl;
            break;
        }
    }

    // creates board
    int board[boardX][boardY];
    bool maskVisible[boardX][boardY];

    // Zero the board
    for (int i = 0; i < boardX; i++)
    {
        for (int j = 0; j < boardY; j++)
        {
            board[i][j] = 0;
            maskVisible[i][j] = false;
        }
    }

    // debug board output
    for (int i = 0; i < boardX; i++)
    {
        for (int j = 0; j < boardY; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n\n\n";

    // debug visible maskVisible output
    for (int i = 0; i < boardX; i++)
    {
        for (int j = 0; j < boardY; j++)
        {
            cout << maskVisible[i][j] << " ";
        }
        cout << endl;
    }

    /*
        // quits/restarts Gameloop
        while (true)
        {
            cout << "Play Again? \nY/N" << endl;
            char input;
            cin >> input;
            input = tolower(input);
            if (input == 'y')
            {
                break;
            }
            else if (input == 'n')
            {
                return 0;
            }
            else
            {
                cout << "Enter valid answer!" << endl;
            }
        }
    }
    */
    return 0;
}
