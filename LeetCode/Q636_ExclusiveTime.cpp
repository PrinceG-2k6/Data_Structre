#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> freq(n,0);

        stack<int> ID;
        stack<int> start;
        stack<int> Fee;
        for(string& log:logs){
            string id,status,timestamp;
            stringstream ss(log);
            getline(ss,id,':');
            getline(ss,status,':');
            getline(ss,timestamp,':');
            if(status == "start"){
                ID.push(stoi(id));
                start.push(stoi(timestamp));
                Fee.push(0);
            }
            else{
                int startTime = start.top();
                int id = ID.top();
                int time = stoi(timestamp)-startTime+1;
                int fee = Fee.top();
                int runtime = time - fee;
                freq[id]+=runtime;
                fee+=time;
                start.pop();
                ID.pop();
                Fee.pop();
                if(!Fee.empty()){
                    Fee.top()+=time;
                }

            }
        }
        return freq;
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