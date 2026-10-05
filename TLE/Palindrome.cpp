#include <iostream>

using namespace std;

int main() {
    // Fast I/O for competitive programming
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;

   int original = n;
   int reversed = 0;

    // Mathematically reverse the number
   while (n > 0) 
   {
      int lastDigit = n % 10;
      reversed = (reversed * 10) + lastDigit;
      n /= 10;
   }

    // Line 1: Print the reversed number (automatically removes leading zeros)
   cout << reversed << "\n";

    // Line 2: Check if it is a palindrome
   if (original == reversed) 
   {
      cout << "YES\n";
   } 
   else 
   {
      cout << "NO\n";
   }

   return 0;
}
