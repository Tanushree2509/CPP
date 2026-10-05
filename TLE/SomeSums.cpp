#include<iostream>
using namespace std;
 
int main()
{
   int N, A, B;
   cin >> N >> A >> B;
   int ans = 0;
 
   for (int i = 1; i <= N; i++)
   {
      int temp = i, sum = 0;
      while (temp > 0)
      {
         sum = sum + temp % 10;
         temp = temp /10;
      }
 
      if (sum >= A && sum <= B)
      {
         ans = ans + i;
      }
      
   }
   cout << ans;
}