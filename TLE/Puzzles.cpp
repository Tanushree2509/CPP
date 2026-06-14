#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<long long> nums = {a, b, c};
    vector<char> ops = {'+', '-', '*'};

    do {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;

                char op1 = ops[i];
                char op2 = ops[j];

                long long x = nums[0], y = nums[1], z = nums[2];

                // Case 1: (x op1 y) op2 z
                long long res1;
                if (op1 == '+') res1 = x + y;
                else if (op1 == '-') res1 = x - y;
                else res1 = x * y;

                if (op2 == '+') res1 = res1 + z;
                else if (op2 == '-') res1 = res1 - z;
                else res1 = res1 * z;

                // Case 2: x op1 (y op2 z)
                long long res2;
                if (op2 == '+') res2 = y + z;
                else if (op2 == '-') res2 = y - z;
                else res2 = y * z;

                if (op1 == '+') res2 = x + res2;
                else if (op1 == '-') res2 = x - res2;
                else res2 = x * res2;

                if (res1 == d || res2 == d) {
                    cout << "YES";
                    return 0;
                }
            }
        }
    } while (next_permutation(nums.begin(), nums.end()));

    cout << "NO";
    return 0;
}