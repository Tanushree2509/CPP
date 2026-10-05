#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
//f1 should be in zero, and f2 should be in 1 so that the summation will of these and the corresponding series will give you the sequence...
    int f1 = 0, f2 = 1;

    if (n == 0)
    {
        cout << 0;
    }
    else if (n == 1)
    {
        cout << 1;
    }
    else
    {
        int f;

        for (int i = 2; i <= n; i++)
        {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
        }

        cout << f;
    }

    return 0;
}