#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector < int > alphabet(26, 0);
        for (char c: s) {
            alphabet[c - 'a']++;
        }
        bool check = true;
        int pairs = 0;

        for (int a: alphabet) {
            if (a >= 3) {
                check = false;
                break;
            }
            if (a == 2) pairs++;
        }
        if (!check || pairs > n / 2) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}