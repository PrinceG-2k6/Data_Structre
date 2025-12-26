#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int e_hour = 0;
        int cur_penalty = 0;
        for (char c : customers)
        {
            if (c == 'Y')
            {
                cur_penalty++;
            }
        }

        int min_penalty = cur_penalty;

        for (int i = 0; i < customers.size(); i++)
        {
            (customers[i] == 'Y') ? cur_penalty-- : cur_penalty++;

            if (cur_penalty < min_penalty)
            {
                e_hour = i + 1;
                min_penalty = cur_penalty;
            }
        }

        return e_hour;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-1, 2, 1, -4};
    cout << sol.bestClosingTime("YNYY") << endl;
}
