#include <iostream>
using namespace std;
int main()
{
   int l1, l2;
   long long n, m;
   cin >> n >> m;
   l1 = n % 10;
   l2 = m % 10;
   int add = l1 + l2;
   cout << add;
}