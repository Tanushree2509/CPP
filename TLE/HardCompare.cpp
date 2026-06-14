#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   long long A, B, C, D;
   cin >> A >> B >> C >> D;

   double x = B * log(A);
   double y = D * log(C);

   if (x > y)
      cout << "YES";
   else
      cout << "NO";

   return 0;
}