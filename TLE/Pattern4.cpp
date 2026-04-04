#include<iostream>
using namespace std;
int main()
{
   int i,j,k;
   for (i =0; i< 5; i++)
   {
      for (j=0; j<5-i; j++)
      {
         cout<<" ";
      }
      for(k=0;k<=i;k++){
         cout<<"*";
      }
   
      cout<<endl;
   }
}