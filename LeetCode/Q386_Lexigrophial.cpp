#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int count =1;
        for(int i =0;i<n;i++){
            ans.push_back(count);
            if(count*10<=n){
                count *=10;// Going deeper 1,10,100,1000,.....
            }else{
                if(count>=n) count/=10;//Go up level as limits
                count++;
                while(count%10==0)count/=10;// Removing trailing Zeroes
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int x = 2;
    vector<int> ans = sol.lexicalOrder(x);
    for (int x : ans)
    {
        cout << x << " ";
    }
    
}