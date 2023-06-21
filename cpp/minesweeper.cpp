#include <iostream>
#include <cctype>
#include <vector>

int main()
{

    /*
    // main gameloop
    bool gameloop = true;
    while (gameloop)
    {
    */

    // Introduction
    std::cout << "Welcome to MINESWEEPER \n\nPlease select a difficulty: \n\t Normal [N] \n\t Hard [H] \n\t Expert [E]\n";

    // Set up variables
    char userDifficulty;
    int boardSizeX, boardSizeY, numMines;

    // Evil hack to check whether difficulty is set
    int difficulty = -1;

    // sets boardSizeX, boardSizeY and numMines acording to player input
    while (difficulty == -1)
    {
        std::cin >> userDifficulty;
        userDifficulty = tolower(userDifficulty);
        switch (userDifficulty)
        {
        case 'n':
            difficulty = 0;
            boardSizeX = boardSizeY = 8;
            numMines = 10;
            break;
        case 'h':
            difficulty = 1;
            boardSizeX = boardSizeY = 16;
            numMines = 40;
            break;
        case 'e':
            difficulty = 2;
            boardSizeX = 16;
            boardSizeY = 30;
            numMines = 99;
            break;
        default:
            std::cout << "Enter valid answer!\n";
            break;
        }
    }

    // creates board
    std::vector<std::vector<int>> board;
    std::vector<std::vector<bool>> maskVisible;

    // Zero the board vector
    board.resize(boardSizeX);
    maskVisible.resize(boardSizeX);
    for (int i = 0; i < boardSizeX; i++)
    {
        for (int j = 0; j < boardSizeY; j++)
        {
            board[i].resize(boardSizeY);
            board[i][j] = 0;

            maskVisible[i].resize(boardSizeY);
            maskVisible[i][j] = false;
        }
    }

    // debug board output
    for (int i = 0; i < boardSizeX; i++)
    {
        for (int j = 0; j < boardSizeY; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n\n";

    // debug visible maskVisible output
    for (int i = 0; i < boardSizeX; i++)
    {
        for (int j = 0; j < boardSizeY; j++)
        {
            std::cout << maskVisible[i][j] << " ";
        }
        std::cout << "\n";
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
