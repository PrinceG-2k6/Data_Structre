#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        unordered_map<int, int> mpp;
        int n = secret.size();
        int cntb = 0;
        for (int i = 0; i < n; i++)
        {
            mpp[secret[i] - '0']++; // Storing Secrret data
        }
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
            {
                cntb++;
                mpp[secret[i] - '0']--; // Bull Counted
            }
        }
        int cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
                continue; // Bull already counted
            if (mpp[guess[i] - '0'] > 0)
            {
                cnt2++;
                mpp[guess[i] - '0']--;
            }
        }

        string ans = to_string(cntb) + "A" + to_string(cnt2) + "B";

        return ans;
    }
};

int main()
{
    Solution sol;
    string ans = sol.getHint("1123", "0111");
    cout << ans << endl;
}