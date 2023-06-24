#include <cctype>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

// Prints board (set maskVisible to !maskVisible for debugging)
void printBoard(vector<vector<int>> board, vector<vector<bool>> maskVisible)
{
    for (int i = 0; i < board.size(); i++) {
        cout << "-";
        for (int k = 0; k < board[i].size(); k++) {
            cout << "----";
        }
        cout << endl
             << "|";
        for (int j = 0; j < board[i].size(); j++) {

            // DEBUG: Always print the full board
            // if (maskVisible[i][j]) {
            if (true) {
                // dash from negative number would mess up board
                if (board[i][j] < 0) {
                    cout << " " << board[i][j] << "|";
                } else {
                    cout << " " << board[i][j] << " |";
                }
            } else {
                cout << "   |";
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

// Checks if coordinate is on board
bool isValid(vector<int> toCheck, vector<vector<int>> board)
{
    bool isValid;
    if (toCheck[0] <= board.size()) {
        if (toCheck[0] > 0) {
            isValid = true;
            if (toCheck[1] <= board[1].size()) {
                if (toCheck[1] > 0) {
                    isValid = true;
                }
            } else {
                isValid = false;
            }
        }
    } else {
        isValid = false;
    }
    return isValid;
}

// Takes user input
vector<int> userInput(vector<vector<int>> board)
{
    vector<int> userInput = { 0, 0 };
    int input;
    while (!isValid(userInput, board)) {
        cout << "Please enter a coordinate \nEnter X:";
        cin >> input;
        userInput.at(0) = input;
        cout << "Enter Y:";
        cin >> input;
        userInput.at(1) = input;
    }
    return userInput;
}

// Generates random coordinate using <random>
vector<int> randomCoordinate(vector<vector<int>> board)
{
    vector<int> random;
    random_device rand;
    mt19937 gen(rand());
    uniform_int_distribution<> dis(1, board.size());
    random.push_back(dis(gen));
    uniform_int_distribution<> cis(1, board[1].size());
    random.push_back(cis(gen));
    return random;
}

//Used for 'countAdjacentMines"
vector<vector<int>> checkAndIncrease(vector<vector<int>> board, int i, int j)
{
    // Check if input is on the board
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
        return board;
    }

    if (board[i][j] >= 0) {
        board[i][j]++;
    }

    return board;
}

// Takes an empty game board and fills in mines
vector<vector<int>> generateMines(vector<vector<int>> board, int numMines)
{
    cout << "Make first move \n";

    vector<int> firstMove = userInput(board);
    for (int i = 0; i < numMines; i++) {
        vector<int> coordinateMine = randomCoordinate(board);
        // cout << coordinateMine[0] << " " << coordinateMine[1] << endl;
        int i1 = --coordinateMine[0], i2 = --coordinateMine[1];
        if (board[i1][i2] < 0) {
            i--;
        } else {
            board[coordinateMine[0]][coordinateMine[1]] = -1;
            // cout << "mine placed successfully\n";
        }
    }

    return board;
}

//Goes to every mine and increases the fields around it
vector<vector<int>> countAdjacentMines(vector<vector<int>> board)
{
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            // Take all mines and add 1 to adjacent coordinates
            if (board[i][j] < 0) {
                board = checkAndIncrease(board, i - 1, j + 1);
                board = checkAndIncrease(board, i, j + 1);
                board = checkAndIncrease(board, i + 1, j + 1);
                board = checkAndIncrease(board, i - 1, j);
                board = checkAndIncrease(board, i + 1, j);
                board = checkAndIncrease(board, i - 1, j - 1);
                board = checkAndIncrease(board, i, j - 1);
                board = checkAndIncrease(board, i + 1, j - 1);
            }
        }
    }

    return board;
}

vector<vector<bool>> recursiveOpening(vector<vector<int>> board, vector<vector<bool>> maskVisible, vector<vector<bool>> checkedByFunction) {
    
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

    // Sets boardSizeX, boardSizeY and numMines according to player input
    while (numMines == -1) {
        cin >> userDifficulty;
        userDifficulty = tolower(userDifficulty);
        switch (userDifficulty) {
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
            cout << "Enter a valid answer!\n";
            break;
        }
    }

    // Creates board
    vector<vector<int>> board;
    vector<vector<bool>> maskVisible;

    // Zero the board vector
    board.resize(boardSizeX);
    maskVisible.resize(boardSizeX);
    for (int i = 0; i < boardSizeX; i++) {
        board[i].resize(boardSizeY);
        maskVisible[i].resize(boardSizeY);
        for (int j = 0; j < boardSizeY; j++) {
            board[i][j] = 0;
            maskVisible[i][j] = false;
        }
    }

    // First move
    int moves = 1;
    board = generateMines(board, numMines);
    board = countAdjacentMines(board);
    printBoard(board, maskVisible);

    bool move = true;
    while (move) {
        vector<int> userCoordinate = userInput(board);
        if (board[userCoordinate[0]][userCoordinate[1]] >= 0) {
            //recursive function
            vector<vector<bool>> checkedByFunction = maskVisible;


        } else {
            cout << "Game Over!\n";
            move = false;
        }
    }

    /*
        // Quits/Restarts gameloop
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
