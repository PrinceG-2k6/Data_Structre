#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCapacity(vector<int> &costs, vector<int> &capacity, int budget)
    {
        int n = costs.size();

        vector<pair<int, int>> machines;
        for (int i = 0; i < n; i++)
        {
            machines.push_back({costs[i], capacity[i]});
        }

        sort(machines.begin(), machines.end());

        int maxCapacity = 0;

        for (int i = 0; i < n; i++)
        {
            if (machines[i].first < budget)
            {
                maxCapacity = max(maxCapacity, machines[i].second);
            }
        }

        int left = 0, right =n-1;
        while (left < right) {
            int totalCost = machines[left].first + machines[right].first;
        if (totalCost < budget) {
            for (int i = right; i > left; i--) {
                maxCapacity = max(maxCapacity,machines[left].second+machines[i].second);
            }
            left++;
        } else {
            right--;
        }
    }

        return maxCapacity;
    }
};

int main()
{
    Solution sol;
    vector<int> cost = {2,3,6,9};
    vector<int> capacity = {7,5,1,7};
    cout << sol.maxCapacity(cost, capacity, 10);
}