#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ar[50];

    Solution() {
        for (int i = 3; i <= 50; i++) {
            ar[i] = -1;
        }
        ar[1] = 1;
        ar[2] = 2;
    }

    int climbStairs(int n) {
        if (n == 1) {
            return ar[n];
        }
        if (n == 2) {
            return ar[n];
        }
        if (ar[n] != -1) {
            return ar[n];
        }
        ar[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return ar[n];
    }
};

int main() {
    Solution a;
    cout << a.climbStairs(4);
    return 0;
}
