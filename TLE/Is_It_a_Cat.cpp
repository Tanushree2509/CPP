#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        // Convert to lowercase
        for (char &c : s) {
            c = tolower(c);   
        }

        // Compress string (remove consecutive duplicates)
        string compressed = "";
        compressed += s[0];

        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                compressed += s[i];
            }
        }

        if (compressed == "meow"){
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}