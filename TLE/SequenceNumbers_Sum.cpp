#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
   int n, m;

   while (cin >> n >> m)
   {
      if (n <= 0 || m <= 0)
         break;
      
      int mini = min(n, m);
      int sum =0;

      for (int i=mini; i <= max(n,m); i++)
      {
         cout << i << " ";
         sum = sum + i;
      }
      
      cout << "sum ="<< sum << endl;
   }

   return 0;
}