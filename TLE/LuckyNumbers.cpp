#include <iostream>
using namespace std;

int main()
{
   int a, b;
   cin >> a >> b;

   int found = 0;

   for (int i = a; i <= b; i++)
   {
      int n = i;
      int flag = 1;

      while (n > 0)
      {
         int digit = n % 10;

         if (digit != 4 && digit != 7)
         {
            flag = 0;
            break;
         }

            n /= 10;
      }

      if (flag == 1)
      {
         cout << i << " ";
         found = 1;
      }
   }

   if (found == 0)
      cout << -1;

   return 0;
}