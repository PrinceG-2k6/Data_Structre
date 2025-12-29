
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (cost1 + cost2 < costBoth) {
            return 1LL * cost1 * need1 + 1LL * cost2 * need2;
        }

        long long ans = 0;

        int both = min(need1, need2);
        ans += 1LL * both * costBoth;

        need1 -= both;
        need2 -= both;

        ans += 1LL * need1 * min(cost1, costBoth);
        ans += 1LL * need2 * min(cost2, costBoth);

        return ans;
    }
};