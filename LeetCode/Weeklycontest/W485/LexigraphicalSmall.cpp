#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string lexSmallestAfterDeletion(string s) {

        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<char> suffixMin(n);
        suffixMin[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(s[i], suffixMin[i + 1]);
        }

        string result;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (freq[c - 'a'] > 1 && i + 1 < n && c > suffixMin[i + 1]) {
                freq[c - 'a']--;
                continue;
            }

            result.push_back(c);
            freq[c - 'a']--;
        }

        return result;
    }
};

int main(){
    Solution sol;
    cout<<sol.lexSmallestAfterDeletion("ccbab");
}