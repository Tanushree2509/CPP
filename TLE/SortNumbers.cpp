#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   int a, b, c;
   cin >> a >> b >> c;

   int x = a, y = b, z = c;

    
   if (x > y) swap(x, y);
   if (x > z) swap(x, z);
   if (y > z) swap(y, z);

   cout << x << endl;
   cout << y << endl;
   cout << z << endl;

   cout << endl;

   cout << a << endl;
   cout << b << endl;
   cout << c << endl;

   return 0;
}