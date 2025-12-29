#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long dp[20][205][2][2];
    string s;

    long long f(int i, int d, int t, int st) {
        if (i == s.size()) return st && d == 100;
        if (dp[i][d][t][st] != -1) return dp[i][d][t][st];
        long long r = 0;
        int lim = t ? s[i] - '0' : 9;
        for (int x = 0; x <= lim; x++) {
            int nd = d;
            int ns = st || x;
            if (ns) nd += (i % 2 == 0 ? x : -x);
            r += f(i + 1, nd, t && x == lim, ns);
        }
        return dp[i][d][t][st] = r;
    }

    long long numberOfBalancedIntegers(long long x) {
        if (x <= 0) return 0;
        s = to_string(x);
        memset(dp, -1, sizeof(dp));
        return f(0, 100, 1, 0);
    }

    int countBalanced(long long low, long long high) {
        return numberOfBalancedIntegers(high) - numberOfBalancedIntegers(low - 1);
    }
};

int main()
{
    Solution sol;
    cout<<sol.countBalanced(218,329)<<endl;
    
}   