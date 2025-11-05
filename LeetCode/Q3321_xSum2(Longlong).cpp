#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    long long freq;
};

// custom comparator: higher freq first, then higher val
struct Cmp {
    bool operator()(const Node& a, const Node& b) const {
        if (a.freq == b.freq) return a.val > b.val;
        return a.freq > b.freq;
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> ans;
        unordered_map<long long, long long> freq;
        multiset<Node, Cmp> ms;

        auto update = [&](long long num, int delta) {
            // remove old frequency if present
            if (freq[num] > 0) ms.erase(ms.find(Node{num, freq[num]}));
            freq[num] += delta;
            if (freq[num] > 0) ms.insert(Node{num, freq[num]});
            else freq.erase(num);
        };

        // initialize first window
        for (int i = 0; i < k; i++) update(nums[i], +1);

        auto getXSum = [&](const multiset<Node, Cmp>& ms, int x) {
            long long sum = 0;
            int c = 0;
            for (auto it = ms.begin(); it != ms.end() && c < x; ++it, ++c)
                sum += it->freq * it->val;
            return sum;
        };

        ans.push_back(getXSum(ms, x));

        // slide the window
        for (int i = k; i < n; i++) {
            update(nums[i - k], -1); // remove outgoing
            update(nums[i], +1);     // add incoming
            ans.push_back(getXSum(ms, x));
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 8, 7, 8, 7, 5};
    int k = 2, x = 2;
    vector<long long> ans = sol.findXSum(nums, k, x);
    for (auto v : ans) cout << v << " ";
}
