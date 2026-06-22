#include <iostream>
#include<vector>
using namespace std;

int main()
{
   int t,i;
   cin >> t;

   for (int j = 0; j<t; j++)
   {
      int evenMismatch = 0;
      int oddMismatch = 0;

      int s;
      cin >> s;
      
      vector<int> a(s);

      for( int i = 0 ; i < s ; i++)
      {
         cin >> a[i];
      }

      for(int i = 0; i < s; i++)
      {  
         if((i % 2) != (a[i] % 2))
         {
            if(i % 2 == 0)
               evenMismatch++;
            else
               oddMismatch++;
         }
      }

      if(evenMismatch != oddMismatch)
      {
         cout << -1 << endl;
      }
      else
      {
         cout << evenMismatch << endl;
      }

      
   }
}



#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int evenMismatch = 0;
        int oddMismatch = 0;

        for (int i = 0; i < n; i++)
        {
            if ((i % 2) != (a[i] % 2))
            {
                if (i % 2 == 0)
                    evenMismatch++;
                else
                    oddMismatch++;
            }
        }

        if (evenMismatch == oddMismatch)
            cout << evenMismatch << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}