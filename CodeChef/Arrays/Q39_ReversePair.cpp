#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>

class Solution {
public:
    int merge(std::vector<int>& nums, int low, int mid, int high) {
        int ans = 0;
        int j = mid + 1;
        
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            ans += (j - (mid + 1));
        }
        
        std::vector<int> temp;
        int i = low;
        j = mid + 1;
        
        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
        
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= high) temp.push_back(nums[j++]);
        
        for (int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }
        
        return ans;
    }

    int mergeSort(std::vector<int>& nums, int low, int high) {
        if (low >= high) return 0;
        
        int mid = low + (high - low) / 2;
        int ans = 0;
        
        ans += mergeSort(nums, low, mid);
        ans += mergeSort(nums, mid + 1, high);
        ans += merge(nums, low, mid, high);
        
        return ans;
    }

    int reversePairs(std::vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
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
        cout << sol.reversePairs(a) << endl;
    }
}
