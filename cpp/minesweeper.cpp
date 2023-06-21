#include <iostream>
#include <cctype>
#include <vector>

using namespace std;

void printBoard(vector<vector<int>> board, vector<vector<bool>> maskVisible)
{
    for (int i = 0; i < board.size(); i++)
    {
        cout << "-";
        for (int k = 0; k < board[i].size(); k++) {
            cout << "----";
        }
        cout << endl << "|";
        for (int j = 0; j < board[i].size(); j++)
        {
            if (!maskVisible[i][j]) {
                cout << " " << board[i][j] << " |";
            } else {
                cout << "  |";
            }
        }
        cout << "\n";
    }
    cout << "-";
    for (int k = 0; k < board[0].size(); k++) {
        cout << "----";
    }
    cout << endl;
}

int main()
{

    /*
    // main gameloop
    bool gameloop = true;
    while (gameloop)
    {
    */

    // Introduction
    cout << "Welcome to MINESWEEPER \n\nPlease select a difficulty: \n\t Normal [N] \n\t Hard [H] \n\t Expert [E]\n";

    // Set up variables + Evil hack to check whether difficulty is set
    char userDifficulty;
    int boardSizeX, boardSizeY, numMines = -1;

    // Sets boardSizeX, boardSizeY and numMines acording to player input
    while (numMines == -1)
    {
        cin >> userDifficulty;
        userDifficulty = tolower(userDifficulty);
        switch (userDifficulty)
        {
        case 'n':
            boardSizeX = boardSizeY = 8;
            numMines = 10;
            break;
        case 'h':
            boardSizeX = boardSizeY = 16;
            numMines = 40;
            break;
        case 'e':
            boardSizeX = 16;
            boardSizeY = 30;
            numMines = 99;
            break;
        default:
            cout << "Enter valid answer!\n";
            break;
        }
    }

    // Creates board
    vector<vector<int>> board;
    vector<vector<bool>> maskVisible;

    // Zero the board vector
    board.resize(boardSizeX);
    maskVisible.resize(boardSizeX);
    for (int i = 0; i < boardSizeX; i++)
    {
        board[i].resize(boardSizeY);
        maskVisible[i].resize(boardSizeY);
        for (int j = 0; j < boardSizeY; j++)
        {
            board[i][j] = 0;
            maskVisible[i][j] = false;
        }
    }

    // Debug board output
    printBoard(board, maskVisible);

    /*
        // Quits/Restarts Gameloop
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
