#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        string s = logs[0];
            string part;
            int start, end;

            stringstream ss(s);

            getline(ss, part, ':'); // "0"
            start = stoi(part);

            getline(ss, part, ':'); // "end" (ignored)

            getline(ss, part, ':'); // "5"
            end = stoi(part);

            ans[start] += end;
        for (int i = 1; i < logs.size(); i++) {
            s = logs[i];
            int nextStart,nextEnd;

            stringstream ss(s);

            getline(ss, part, ':'); // "0"
            nextStart= stoi(part);

            getline(ss, part, ':'); // "end" (ignored)

            getline(ss, part, ':'); // "5"
            nextEnd = stoi(part);

            ans[start] += nextEnd - end;
            end = nextEnd;
        }

        return ans;
    } 
};

int main(){
    Solution sol;
    vector<string> logs = {"0:start:0","1:start:2","1:end:5","0:end:6"};
    vector<int> ans = sol.exclusiveTime(2,logs);
    for(int n : ans){
        cout<<n<<" ";
    }
}