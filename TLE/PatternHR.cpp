#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

    // Top row
    for (int i = 0; i < num; i++)
        cout << "*";
    cout << endl;

    // Middle (diagonal)
    for (int i = 1; i < num - 1; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (j == num - i - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    // Bottom row
    for (int i = 0; i < num; i++)
        cout << "*";

    return 0;
}