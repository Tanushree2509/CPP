#include <iostream>
using namespace std;

int main()
{
   int ans = 1;
   int M = 1e9 + 7;

   for (int i = 1; i <= 100; i++)
   {
      ans  = ((ans % M) * (i % M)) % M;
   }
   cout << ans << endl;
   return 0;

}