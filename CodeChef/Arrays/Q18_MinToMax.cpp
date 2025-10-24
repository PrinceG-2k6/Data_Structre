
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countNonMinimum(vector<int>& nums) {
        // write your code here 
        
    }
};


int main()
{

    Solution sol;

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sol.check(arr);

    return 0;
}