#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    bool gameloop = true;
    while (gameloop) {
        cout << "Welcome to MINESWEEPER \n\nPlease selekt a difficulty: \n\t Normal [N] \n\t Hard [H] \n\t Expert [E]" << endl;
        char difin;
        int x;
        int y;
        int nmins;
        int dif = -11;

        //sets x,z and nmins acording to player input
        while (dif == -11){
            cin >> difin;
            difin = tolower(difin);
            switch (difin){
                case 'n':
                    dif = 0;
                    x = y = 7;
                    nmins = 9;
                    break;
                case 'h':
                    dif = 1;
                    x = y = 15;
                    nmins = 39;
                    break;
                case 'e':
                    dif = 2;
                    x = 15;
                    y = 29;
                    nmins = 98;
                    break;
                default:
                    cout << "Enter valid answer!" << endl;
                    break;
            }
        }


        /*
        still figuring shit out

        int board [y][x] = {
            {1,0,0,0},
            {0,0,0,0}
        };

        for (int i=0; i>7; i++) {
            cout << board [0][0];
        }
        */
        


        //quits/restarts Gameloop
        while (true) {
            cout << "Play Again? \nY/N" << endl;
            char input;
            cin >> input;
            input = tolower(input);
            if (input == 'y') {
                break;
            } else if (input == 'n') {
                return 0;
            } else {
                cout << "Enter valid answer!" << endl;
            }
        }
    }
    return 0;
}