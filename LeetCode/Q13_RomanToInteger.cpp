#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int values(char letter) {
        if (letter == 'I')
            return 1;
        if (letter == 'V')
            return 5;
        if (letter == 'X')
            return 10;
        if (letter == 'L')
            return 50;
        if (letter == 'C')
            return 100;
        if (letter == 'D')
            return 500;
        if (letter == 'M')
            return 1000;
        return 0;
    };

    int romanToInt(string s) {
        int resp = 0;
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == 'I') {
                if (s[i + 1] == 'V') {
                    resp -= 2;
                }
                if (s[i + 1] == 'X') {
                    resp -= 2;
                }
            }
            if (s[i] == 'X') {
                if (s[i + 1] == 'L') {
                    resp -= 20;
                }
                if (s[i + 1] == 'C') {
                    resp -= 20;
                }
            }
            if (s[i] == 'C') {
                if (s[i + 1] == 'M') {
                    resp -= 200;
                }
                if (s[i + 1] == 'D') {
                    resp -= 200;
                }
            }

            resp += values(s[i]);
        }

        return resp;
    }
};

int main(){
    Solution sol;
    string s ="MCMXCIV";
    cout<<sol.romanToInt(s);

    return 0;
}