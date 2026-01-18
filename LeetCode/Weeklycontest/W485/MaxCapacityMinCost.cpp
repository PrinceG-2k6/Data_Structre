#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();

        auto temp = make_pair(costs, capacity);

        vector<pair<int,int>> machines;
        for (int i = 0; i < n; i++) {
            machines.push_back({costs[i], capacity[i]});
        }

        sort(machines.begin(), machines.end()); 

        vector<int> bestCap(n);
        bestCap[0] = machines[0].second;
        for (int i = 1; i < n; i++) {
            bestCap[i] = max(bestCap[i-1], machines[i].second);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (machines[i].first < budget) {
                ans = max(ans, machines[i].second);
            }
        }

        for (int i = 1; i < n; i++) {
            int remaining = budget - machines[i].first - 1;
            if (remaining < 0) continue;

            int l = 0, r = i - 1, pos = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (machines[mid].first <= remaining) {
                    pos = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (pos != -1) {
                ans = max(ans, machines[i].second + bestCap[pos]);
            }
        }

        return ans;
    }
};


int main()
{
    Solution sol;
    vector<int> cost = {2,3,6,9};
    vector<int> capacity = {7,5,1,7};
    cout << sol.maxCapacity(cost, capacity, 10);
}