#include <iostream>
#include <vector>
using namespace std;
int main ()
{
   int n, E =0, P=0, O=0, N=0 ;
   cin >> n;

   vector<int> a(n);

   for (int i = 0; i < n; i++)
   {
      cin >> a[i];
      
      if (a[i] > 0) P++;
      else if (a[i] < 0) N++;

      if (a[i] % 2 == 0) E++;
      else O++;
   }

   cout << "Even: "<< E << endl;
   cout << "Odd: "<< O << endl;
   cout << "Positive: "<< P << endl;
   cout << "Negative: "<< N << endl;

   return 0;

}