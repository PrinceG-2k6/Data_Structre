#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minNumberOperations(vector<int> &target)
    {
        int operations = target[0];
        for (int i = 1; i < target.size(); i++)
        {
            if (target[i] > target[i - 1])
            {
                operations += target[i] - target[i - 1];
            }
        }
        return operations;
    }
};

int main()
{
    Solution s;
    vector<int> target = {1, 2, 3, 2, 1};
    cout << "Operations: " << s.minNumberOperations(target) << endl;
    return 0;
}
