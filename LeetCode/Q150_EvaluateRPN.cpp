#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for(string c: tokens){
            if(c[0] == '+'){
                char a = stack.pop_back();
                char b = stack.pop_back();
            }
        }
    }
};

int main(){
    Solution sol;
    vector<string> tokens={"2","1","+","3","*"};
    cout<< sol.evalRPN(tokens);
}