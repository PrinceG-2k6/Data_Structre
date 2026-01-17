#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ="()[][{}]({[[]]})";
    stack<char> st;
    int i =0;
    for(int i =0;i<s.length();i++){
        char c = s[i];
        if(s[i] == '('  ||  s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
        }else{
            if(s[i]==')'){
                if(st.top()=='(') st.pop();
                else return 0;
            }
            if(s[i]=='}'){
                if(st.top()=='{') st.pop();
                else return 0;
            }
            if(s[i]==']'){
                if(st.top()=='[') st.pop();
                else return 0;
            }
        }
    }

    if(!st.empty()){
        return 0;
    }
    else{
        cout<<"Parenthesis Matched";
    }
}