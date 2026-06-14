#include <iostream>
#include <cmath>
using namespace std;
int main()
{
   int x;
   cin >> x;
    if (x <= 1)
    {
        cout << "NO";
        return 0;
    }

    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}