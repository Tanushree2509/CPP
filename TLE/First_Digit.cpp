#include<iostream>
using namespace std;
int main ()
{
   int x;
   cin >> x;

   int first = x/1000;

   if (first % 2==0)
   {
      cout << "EVEN";
   }
   else 
   {
      cout << "ODD";
   }
   
   return 0;
}