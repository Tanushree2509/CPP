#include <iostream>
#include <vector>
using namespace std;

int main()
{
   vector<int> nums = {1 ,2, 3, 4};
   int l = nums.size();
   int sum = 0;
   
   for (int i = 0; i < l; i++)
   {
      if ((l % (i+1)) == 0)
      {
         sum += (nums[i]*nums[i]);
      }
      
   }
   return 0;
}