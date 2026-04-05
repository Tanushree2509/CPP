#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;

    double x = (double)A / B;

    cout << "floor " << A << " / " << B << " = " << floor(x) << endl;
    cout << "ceil " << A << " / " << B << " = " << ceil(x) << endl;
    cout << "round " << A << " / " << B << " = " << round(x) << endl;

    return 0;
}