#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // sort letters to form the anagram signature
            mp[key].push_back(s);         // group all anagrams with same key
        }

        vector<vector<string>> ans;
        for (auto& it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = sol.groupAnagrams(strs);
    for (vector<string> str : result)
    {
        for (string s : str)
        {
            cout << s << " ";
        }
        cout << endl;
    }
}