#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;

    for (int n = 2; n <= x; n++)
    {
        bool prime = true;

        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
               prime = false;
               break;
            }
        }

        if (prime)
        {
            cout << n << " ";
        }
    }

    return 0;
}