#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int x, y;
        cin >> x >> y;

        if (y >= 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}