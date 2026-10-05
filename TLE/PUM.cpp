#include <iostream>
using namespace std;

int main ()
{
   int N;
   cin >> N;

   int row = N*4;

   for (int i = 1; i <= row; i++)
   {
      if ( i % 4 == 0)
      {
         cout << "PUM";
         cout << endl;
      }

      else 
      {
         cout << i << " ";
      }
   }
   return 0;
}