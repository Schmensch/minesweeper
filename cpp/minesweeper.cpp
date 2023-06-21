#include <iostream>
#include <cctype>

using namespace std;

int main()
{

    // main gameloop
    bool gameloop = true;
    while (gameloop)
    {

        // anounces game
        cout << "Welcome to MINESWEEPER \n\nPlease selekt a difficulty: \n\t Normal [N] \n\t Hard [H] \n\t Expert [E]" << endl;
        char difin;
        int boardX, boardY, nmins, dif = -1;

        // sets boardX, boardY and nmins acording to player input
        while (dif == -1)
        {
            cin >> difin;
            difin = tolower(difin);
            switch (difin)
            {
            case 'n':
                dif = 0;
                boardX = boardY = 8;
                nmins = 10;
                break;
            case 'h':
                dif = 1;
                boardX = boardY = 16;
                nmins = 40;
                break;
            case 'e':
                dif = 2;
                boardX = 16;
                boardY = 30;
                nmins = 99;
                break;
            default:
                cout << "Enter valid answer!" << endl;
                break;
            }
        }

        // creats board
        int board[boardX][boardY] = {0};
        bool maskVisible[boardX][boardY] = {0};

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
    return 0;
}

/*
for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
        if (maskVisible [i] [j] == false ) {
            cout << "true" << endl;
        }
    }
}
*/
