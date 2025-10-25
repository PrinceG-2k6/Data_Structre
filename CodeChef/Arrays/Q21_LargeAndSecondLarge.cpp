#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MaxSum(vector<int> &nums)
    {
        set<int> s;
        for (int num : nums)
        {
            s.insert(num);
        }
        auto it = s.rbegin();
        int largest = *it;

        ++it;
        int sLargest = *it;
        return largest + sLargest;
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
        cout << sol.MaxSum(a) << endl;
    }
}
