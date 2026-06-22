#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
   int a, b;
   cin >> a >> b;

   list <int> nums;
   
   for (int i = 1; i <= min(a,b); i++)
   {
      if ((a % i == 0) && (b % i == 0))
      {
         nums.push_back(i); 
      }
   }
   cout << *max_element(nums.begin(), nums.end());

   return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int gcd = 1;

    for (int i = 1; i <= min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }

    cout << gcd;

    return 0;
}