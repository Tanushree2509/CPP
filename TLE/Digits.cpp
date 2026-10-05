#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            cout << 0;
        }
        else
        {
            while (x > 0)
            {
                int a = x % 10;
                cout << a << " ";
                x = x / 10;
            }
        }

        cout << endl;
    }

    return 0;
}
