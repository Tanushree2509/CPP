#include <iostream>
using namespace std;

int main()
{
    int X;

    while (true)
    {
        cin >> X;

        if (X == 1999)
        {
            cout << "Correct" << endl;
            break;   // stop program
        }
        else
        {
            cout << "Wrong" << endl;
        }
    }

    return 0;
}