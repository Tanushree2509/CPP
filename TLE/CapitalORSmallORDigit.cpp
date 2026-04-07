#include <iostream>
using namespace std;
int main()
{
   char x;
   int n;
   cin >> x;
   n= int (x);

   if (n<='9' && n>= '0')
   {
      cout << "IS DIGIT";
   }

   else if (n<=90 && n>= 65)
   {
      cout << "ALPHA\nIS CAPITAL";
   }

   else if (n<=122 && n>= 97)
   {
      cout << "ALPHA\nIS SMALL";
   }

   return 0;
   
}