#include <iostream>
#include <string>
using namespace std;

int main()
{
   string s;
   cin >> s;

   //eg: (()())(())
   int opened = 0;
   string result = "";

   for (int i = 0; i < s.size(); i++)
   {
      if (s[i] == '(')
      {
         if (opened > 0)
         {
            result += s[i];
         }
         opened ++;
      }

      else if (s[i] == ')')
      {
         opened --;

         if (opened > 0)
         {
            result += s[i];
         }
      }
   }
   return result;
   
}