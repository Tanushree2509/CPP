#include <iostream>
using namespace std;

int main()
{
    int n, k = 1;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int temp = k;

        // move k forward for next row
        k += i;

        if (i % 2 == 1)   // odd row → increasing
        {
            for (int j = 0; j < i; j++)
            {
                cout << temp + j << " ";
            }
        }
        else   // even row → decreasing
        {
            for (int j = i - 1; j >= 0; j--)
            {
                cout << temp + j << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
///////////////or


#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int end = i * (i + 1) / 2;
        int start = end - i + 1;

        if (i % 2 == 1)  // odd row → increasing
        {
            for (int j = start; j <= end; j++)
                cout << j << " ";
        }
        else  // even row → decreasing
        {
            for (int j = end; j >= start; j--)
                cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}

///final
#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        int end = i * (i + 1) / 2;
        int start = end - i + 1;

        if (i == 1 || i % 2 == 0)  // row 1 and even rows → increasing
        {
            for (int j = start; j <= end; j++)
                cout << j << " ";
        }
        else  // odd rows except 1 → decreasing
        {
            for (int j = end; j >= start; j--)
                cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}
