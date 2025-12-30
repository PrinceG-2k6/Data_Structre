#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long ans=0;
        int n=s.size();
        long long map[26]={0};
        long long maxi=0;
        
            for(int i=0;i<n;i++){
                ans+=cost[i];
                map[s[i]-'a']+=cost[i];
                
            }
            for(int i=0;i<26;i++){
                maxi=max(maxi, map[i]);
            }
            
        
        return ans-maxi;
    }
};
int main()
{
    Solution sol;
    vector<int> cost={1,2,3,4,1,10};
    cout<<sol.minCost("aabaac",cost)<<endl;
    
}    