#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st; // stores indices
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prev = st.top();
                st.pop();   
                answer[prev] = i - prev;
            }
            st.push(i);
        }
        return answer;
    }
};
int main(){
    Solution sol;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> ans = sol.dailyTemperatures(temperatures);
    for(int n: ans){
        cout<<n<<" ";
    }
}