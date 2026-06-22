#include<iostream>
using namespace std;

// Function to calculate factorial
long long factorial(int n)
{
    long long fact = 1;
    for(int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int main ()
{
    int t;
    cin >> t;

    int a[t];

    // Input
    for (int i = 0; i < t; i++)
    {
        cin >> a[i];
    }

    // Output factorial for each element
    for (int i = 0; i < t; i++)
    {
        cout << factorial(a[i]) << endl;
    }
}