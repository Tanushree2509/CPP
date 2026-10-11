#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>
using namespace std;

int main()
{
   int t;
   cin >> t;

   vector<int> a(t);
  // vector<int> b; // Starts empty
  // vector<int> c; // Starts empty

   for (int i = 0; i < t; i++)
   {
      cin >> a[i];
   }

   for (int j = 0; j < t; j++)
   {
      vector<int> b; // Starts empty
      vector<int> c; // Starts empty

      //converting decimal to binary
      while (a[j] != 0) 
      {
         b.push_back(a[j] % 2); // remainder
         a[j] /= 2;
      }

      //use can use for loop too
      // Reverses vector b in place
      reverse(b.begin(), b.end());//binary form

      //taking all the ones and converting back to decimal 
      for (int val : b) 
      {
         if (val == 1)
         {
            c.push_back(1);
         }
      }
      
      int sum = 0;
      int l = c.size();

      //while (l==0)
      //{
         for (int k = 0; k < c.size(); k++)
         {
            //pow(base, exponent);  
            sum = sum + (c[k] * (round(pow(2, k))));
           // l--;
         }

     // }
      cout << sum << endl;


   }
   return 0;
}
