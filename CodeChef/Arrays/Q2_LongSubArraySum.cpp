#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<long long, int> prefixIndex; // prefix sum -> first index
        long long sum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            // case: subarray from 0 to i
            if (sum == k) {
                maxLen = i + 1;
            }

            // case: subarray ending at i, starting later
            if (prefixIndex.find(sum - k) != prefixIndex.end()) {
                maxLen = max(maxLen, i - prefixIndex[sum - k]);
            }

            // store only first occurrence
            if (prefixIndex.find(sum) == prefixIndex.end()) {
                prefixIndex[sum] = i;
            }
        }

        return maxLen;
    }
};

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int t, n, k;
    cout << "Enter No. of Test case : ";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Enter Size of array of case no. " << i + 1 << endl;
        cin >> n;

        cout << "Enter Sum to Find : ";
        cin >> k;

        vector<int> arr(n);
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }

        Solution sol;
        cout << sol.longestSubarraySum(arr, k) << endl;
    }

    return 0;
}