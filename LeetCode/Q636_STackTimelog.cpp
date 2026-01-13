#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
    }
};

int main(){
    Solution sol;
    vector<string> logs = {"0:start:0","1:start:2","1:end:5","0:end:6"};
    vector<int> ans = sol.exclusiveTime(2,logs);
    for(int n : ans ){
        cout<< n << " ";
    }
}