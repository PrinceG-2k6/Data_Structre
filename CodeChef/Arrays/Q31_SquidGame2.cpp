#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Visible(vector<int>& nums, int h) {
        int ans=0;
        for(int num:nums){
            if(num>h){
                ans++;
            }
        }
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
        int n,h;
        cin >> n>>h;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << sol.Visible(a,h) << endl;
    }
}
