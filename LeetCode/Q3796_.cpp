#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> ans(n);
        unordered_map<int,int>rest;
        for(vector<int> r: restrictions){
            rest[r[0]] = r[1];
        }
        int maxans=0;
        int j=1;    
        ans[0] = 0;
        while(j<n){
            ans[j] = ans[j-1]+diff[j-1];
            if(rest[j]){
                if(ans[j]>rest[j]){
                    ans[j] = rest[j];
                    int k = j;
                    while(abs(ans[k]-ans[k-1])>diff[k-1]){
                        ans[k-1] = ans[k]+diff[k-1];
                        k--;
                    }
                    
                }
            }
            j++;
        }      
        for(int n : ans){
            maxans = max(maxans,n);
        }
        return maxans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> restrictions={{3,1},{8,1}};
    vector<int> diff  ={2,2,3,1,4,5,1,1,2};
    cout<<sol.findMaxVal(10,restrictions,diff);
}