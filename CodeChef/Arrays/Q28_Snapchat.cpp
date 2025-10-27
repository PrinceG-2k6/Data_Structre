#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int snapStreak(int *a, int *b,int n)
    {
        int count = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0 && b[i]> 0)
            {
                count++;
            }
            else
            {
                ans = max(ans,count);
                count =0;
            }
        }
        if (count > ans)
            ans = count;

        return ans;
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
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        cout << sol.snapStreak(a, b,n) << endl;
    }
}
