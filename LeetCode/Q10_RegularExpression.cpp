#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        unordered_map<char,int> mpp;
        for(int i =0;i<s.length();i++){
            mpp[s[i]]++;
        }
    }
};


int main(){
    Solution sol;
    cout<<sol.isMatch("aa","a")<<endl;
}