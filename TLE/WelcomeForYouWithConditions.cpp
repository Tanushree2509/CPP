// Given two numbers A and B. Print "Yes" if A is greater than or equal to B. Otherwise print "No".

// Input
// Only one line containing two numbers A and B (0  ≤  A, B  ≤  100).

// Output
// Print "Yes" or "No" according to the statement.
#include <iostream>
using namespace std;
int main()
{
   int a,b;
   cout << "Enter the numbers: ";
   cin >> a >> b;
   while (a >= 0 && b <= 100) 
   {
      if (a >= b)
      {
         cout << "Yes";
         break;
      }
      else
         cout << "No";
         break;
   }
}