#include <iostream>
using namespace std;

int main() {
    long long a,b,c,d;
    cin >> a >> b >> c >> d;

    int res = 1;
    for(long long x : {a,b,c,d})
        res = (res * (x % 100)) % 100;

    if(res < 10) cout << "0";
    cout << res;
}