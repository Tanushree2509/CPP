//Full Pyramid
#include<iostream>
using namespace std;
int main()
{
   int i,j,k,n=5;
   for (i =0; i< n; i++)
   {
      for (j = n - i - 1; j > 0; j--)
      {
         cout << " ";
      }
      for (k = 1; k <= 2 * i + 1; k++)
      {
         cout << "*";
      }
   
      cout << endl;
   }
}