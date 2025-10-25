#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string difficultyCheck(vector<int> &nums)
    {

        {
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i] > nums[i + 1])
                {
                    return "No";
                }
            }
        }
        return "Yes";
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
        cout << sol.difficultyCheck(a) << endl;
    }
}
