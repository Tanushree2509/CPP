#include<iostream>
#include <set>
using namespace std;

int main ()
{
   set<int> s;
   s.insert(2);
   s.insert(5);
   s.insert(8);
   s.insert(2);

   if (s.find(5) != s.end())
      cout << "5 is present" << endl;
   s.erase(2);
   
   for (int x: s)
      cout << x << " ";
   return 0;
}