#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string st;
        
        reverse(s.begin(), s.end());

        for (char c : s) {
            freq[c - 'a']--;

            while (!st.empty() &&
                   st.back() > c &&
                   freq[st.back() - 'a'] > 0) {
                st.pop_back();
            }

            st.push_back(c);
        }

        return st;
    }
};

int main(){
    Solution sol;
    cout<<sol.lexSmallestAfterDeletion("ccbab");
}