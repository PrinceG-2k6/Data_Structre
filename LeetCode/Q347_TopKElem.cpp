#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(auto& num : nums){
            mpp[num]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto& p : mpp) {
            pq.push({p.second, p.first}); // {frequency, number}
        }
        
        vector<int> ans;
        while(k-- && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    // Function call
    vector<int> result = sol.topKFrequent(nums, k);

    // Print result
    cout << "Top " << k << " frequent elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}