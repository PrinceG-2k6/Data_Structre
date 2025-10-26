#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int BombCheck(vector<int> &nums, int bomb)
    {
        int count = 0;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] - bomb < 0)
            {
                count = i + 1;
                break;
            }
        }

        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    Solution sol;
    while (t--)
    {
        int n, bomb;
        cin >> n >> bomb;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << sol.BombCheck(a, bomb) << endl;
    }
}