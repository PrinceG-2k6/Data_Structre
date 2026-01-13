#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for(char c: tokens){
            if(c == '+'){
                int a = stack
            }
        }
    }
};

int main(){
    Solution sol;
    vector<string> tokens={"2","1","+","3","*"};
    cout<< sol.evalRPN(tokens);
}