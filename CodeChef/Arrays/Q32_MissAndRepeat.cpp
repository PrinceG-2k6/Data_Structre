#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRepeatingAndMissing(const vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;

        for (int num : arr) {
            freq[num]++;
        }

        int repeating = -1, missing = -1;

        // Find the repeating and missing numbers
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2) {
                repeating = i;
            } else if (freq[i] == 0) {
                missing = i;
            }
        }

        return {repeating, missing};
    }
};


int main()
{
    int t;
    cin >> t;

    Solution sol;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> ans = sol.findRepeatingAndMissing(a);
        for(int x:ans){
            cout<< x<<" ";
        }
    }
}
