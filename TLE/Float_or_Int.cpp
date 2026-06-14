#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double n;
    cin >> n;

    double intPart;
    double fracPart = modf(n, &intPart);

    if (fracPart == 0)
    {
        cout << "int " << (long long)intPart;
    }
    else
    {
        cout << "float " << (long long)intPart << " " << fracPart;
    }

    return 0;
}