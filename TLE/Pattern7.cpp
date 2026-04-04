//Hourglass
#include<iostream>
using namespace std;
int main()
{
   int i, j, k, n = 5;

   // Top half of the hourglass
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < i; j++)
         cout << " ";

      for (k = 0; k < 2 * (n - i) - 1; k++)
         cout << "*";

      cout << endl;
   }

   // Bottom half of the hourglass
   for (i = 2; i <= n; i++)
   {
      for (j = 0; j < n - i; j++)
         cout << " ";

      for (k = 0; k < 2 * i - 1; k++)
         cout << "*";

      cout << endl;
   }
}



// #include<iostream>
// using namespace std;
// int main()
// {
//    int i,j,k=1;
//    for (i =0; i< 5; i++)
//    {
//       for (j=0; j<5-i; j++)
//       {
//          cout<<"*";
//       }
   
//       cout<<endl;
//    }
// }