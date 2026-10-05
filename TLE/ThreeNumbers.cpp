#include <iostream>
using namespace std;

int main() 
{
   int K, S;
   cin >> K >> S;

   int count = 0;

   for (int X = 0; X <= K; X++) 
   {
      for (int Y = 0; Y <= K; Y++) 
      {
         // Calculate what Z must be
         int Z = S - X - Y;

         // Check if Z is valid (between 0 and K)
         if (Z >= 0 && Z <= K) 
         {
            count++;
         }
      }
   }

   cout << count << endl;
   return 0;
}
