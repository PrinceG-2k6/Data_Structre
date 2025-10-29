#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        if (n == 0 || n == 1) return n;

        int bits = ceil(log2(n + 1)); // number of bits required
        return pow(2, bits) - 1;      // smallest (2^bits - 1) ≥ n
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.smallestNumber(n);
    return 0;
}
