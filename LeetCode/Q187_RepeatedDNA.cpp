#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int length = s.size();
        if (length < 10) return {};

        unordered_map<string, int> count;
        vector<string> answer;

        for (int i = 0; i <= length - 10; i++) {
            string temp = s.substr(i, 10); // Take substring of length 10
            count[temp]++;
        }

        for (auto &p : count) {
            if (p.second > 1) {
                answer.push_back(p.first);
            }
        }

        return answer;
    }
};

int main() {
    
    Solution sol;

    vector<string> res = sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT") ;
    for(string s:res){
        cout<<s<<endl;
    }
    
    return 0;
}