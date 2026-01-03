#include<bits/stdc++.h>
using namespace std;

void subsequence(string s, int idx, string curr) {
    if (idx == s.size()) {
        cout << curr << endl;
        return;
    }

    subsequence(s, idx + 1, curr + "_ ");

    subsequence(s, idx + 1, curr + s[idx] + " ");
}


int main(){
    string s = "abc";
}