#include <bits/stdc++.h>
using namespace std;

int largestSubarrayWithSumZero(vector<int>& arr) {
    unordered_map<int, int> prefixMap;
    int prefixSum = 0, maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        if (prefixMap.find(prefixSum) != prefixMap.end()) {
            maxLen = max(maxLen, i - prefixMap[prefixSum]);
        } else {
            prefixMap[prefixSum] = i; 
        }
    }

    return maxLen;
}


int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout<<largestSubarrayWithSumZero(a);
    
    return 0;
}