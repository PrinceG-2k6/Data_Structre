#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int candidate = arr[0];
        int count = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == candidate) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    candidate = arr[i];
                    count = 1;
                }
            }
        }
        return candidate;  // Guaranteed to exist
    }
};



int main()
{
    int n;
    Solution sol;

    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++)
    {
        cin >> a[j];
    }

    cout << sol.majorityElement(a);
    return 0;
}
