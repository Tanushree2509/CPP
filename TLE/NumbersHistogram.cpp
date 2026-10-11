#include <iostream>
using namespace std;
int main()
{
   char ch;
   cin >> ch;

   int n;
   cin >> n;

   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
         cout << ch;
      }
      cout << endl;

   }
   return 0;

}