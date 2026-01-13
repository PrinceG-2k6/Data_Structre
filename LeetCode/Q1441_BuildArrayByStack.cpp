#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m = target.size();
        int idx = 0;
        vector<string>res;

        for(int i=1;i<=n && idx<m;i++){
             res.push_back("Push");
           if (target[idx]==i) {
            idx++;
           }
            else{
               
                 res.push_back("Pop");
            }
        
        }
        return res;
    }
};


int main(){
    Solution sol;
    vector<int> target = {1,3};
    vector<string> ans = sol.buildArray(target,3);
    for(string s:ans){
        cout<<s<<" ";
    }
}