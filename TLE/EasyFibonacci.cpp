#include<iostream>
using namespace std;

//Finonacci
int main()
{
   int f1 = 0, f2 = 1, n, fi;
   cin >> n;
   
   if (n == 1) 
      {
      cout << f1 << " " << endl;
      return 0;
      }

   cout << f1 << " ";
   cout << f2 << " ";
   
   for (int i = 1; i < n-1; i++)
   {
      fi = f1 + f2;
      cout << fi << " ";
      f1 = f2;
      f2 = fi;
   }

   return 0;
}