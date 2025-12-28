#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> freq;
        for (int x : A) freq[x]++;
        for (int x : B) freq[x]--;

        vector<int> extra;
        int minVal = INT_MAX;
        for (auto& [k, v] : freq) {
            if (v % 2) return -1;
            for (int i = 0; i < abs(v) / 2; ++i)
                extra.push_back(k);
            minVal = min(minVal, k);
        }

        sort(extra.begin(), extra.end());
        long long cost = 0;
        for (int i = 0; i < extra.size() / 2; ++i)
            cost += min(extra[i], 2 * minVal);
        return cost;
    }
};

int main()
{
    Solution sol;
    vector<int> A={4,2,2,2};
    vector<int> B={1,4,1,2};

    cout<<sol.minCost(A,B)<<endl;
    
}
