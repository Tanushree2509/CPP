#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int years = N / 365;
    int rem = N % 365;

    int months = rem / 30;
    int days = rem % 30;

    cout << years << " years\n";
    cout << months << " months\n";
    cout << days << " days\n";

    return 0;
}