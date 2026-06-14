#include<iostream>
using namespace std;
int main()
{
   int t;
   cin>> t;
   for (int i = 1; i <= t; i++)
   {
      int x, y;
      cin >> x >> y;

      int sum = 0;
      int start = min (x,y);
      int end = max(x,y);

      for (int i = start +1; i < end; i++)
      {
         if (i % 2 != 0)
         {
            sum = sum + i;
         }
      }
      cout << sum << endl;
   }
   return 0;
   
}
