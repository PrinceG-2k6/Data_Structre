
#include <bits/stdc++.h>
using namespace std;  

class Solution {
public:
    int dp[1001][1001];
    
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    
    int func(string s1, string s2, int i, int j){
        int n = s1.size(),m =s2.size();
        if(i==n){
            int s=0;
            while(j<m){
                s+=s2[j];j++;
            }
            return s;
        }
        if(j==m){
            int s=0;
            while(i<n){
                s+=s1[i];i++;
            }
            return s;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            dp[i][j] = func(s1,s2,i+1,j+1);
            return dp[i][j];
        }

        int skip_s1 = s1[i] + func(s1,s2,i+1,j);
        int skip_s2 = s2[j] + func(s1,s2,i,j+1);

        dp[i][j]=min(skip_s1,skip_s2);
        return dp[i][j];
    }

    int minimumDeleteSum(string s1, string s2) {
        return func(s1,s2,0,0);

    }
};

int main(){
    Solution sol;
    cout<<sol.minimumDeleteSum("delete","leet")<<endl;
}