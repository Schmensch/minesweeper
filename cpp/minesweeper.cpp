#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    bool gameloop = true;
    while (gameloop) {
        cout << "test" << endl;


        //quits/restarts Gameloop
        while (true) {
            cout << "Play Again? \b Y/N" << endl;
            char input;
            cin >> input;
            input = toupper(input);
            if (input == 'Y') {
                break;
            } else if (input == 'N') {
                return 0;
            } else {
                cout << "Enter valid answer!" << endl;
            }
        }
    }
    return 0;
}