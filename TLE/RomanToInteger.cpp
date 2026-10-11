#include <iostream>
#include <string>
using namespace std;

int charnum(char a)
{
   switch (a)
   {
      case 'I': return 1;
      case 'V': return 5;
      case 'X': return 10;
      case 'L': return 50;
      case 'C': return 100;
      case 'D': return 500;
      case 'M': return 1000;
      default: return 0;
   }
}

int main()
{
   string s;
   cin >> s;

   int total = 0;
   for (int i = 0; i < s.length(); ++i)
   {
      if (i + 1 < s.length() && charnum(s[i]) < charnum(s[i + 1]))
      {
         total -= charnum(s[i]);
      }
      else
      {
         total += charnum(s[i]);
      }
   }

   cout << total << endl;
   return 0;
}
/*
Does it behave differently than i++ here?

No. Inside a loop update step, ++i and i++ achieve the exact same goal—they both increment i by 1 before the next cycle starts.
Programmers often write ++i (prefix) out of habit because it updates the variable directly in memory without making a temporary 
copy of the old value first, making it a clean and efficient choice for loops.*/