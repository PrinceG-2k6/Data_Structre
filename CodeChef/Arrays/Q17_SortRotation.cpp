
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[(i + 1) % n])
            {
                count++;
            }
        }
        if (count <= 1)
            return true;
        return false;
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