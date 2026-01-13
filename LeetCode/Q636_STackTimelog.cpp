#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> freq(n,0);

        stack<tuple<string,int,int>> fxn;
        for(string& log:logs){
            string id,status,timestamp;
            int runtime,fee_init=0;
            stringstream ss(log);
            getline(ss,id,':');
            getline(ss,status,':');
            getline(ss,timestamp,':');
            if(status == "start"){
                fxn.push({id,stoi(timestamp),fee_init});
            }
            else{
                int starttime=get<1>(fxn.top());
                int fee = get<2>(fxn.top());
                int time = stoi(timestamp)-starttime+1;
                runtime = time - fee;
                
                freq[stoi(id)]+=runtime;
                fxn.pop();
                if(!fxn.empty())
                    get<2>(fxn.top())+=time;
            }
        }
        return freq;
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
