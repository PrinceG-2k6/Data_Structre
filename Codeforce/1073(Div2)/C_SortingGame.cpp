#include <bits/stdc++.h>
using namespace std;

void solve() {
    int len;
    cin >> len;
    string str;
    cin >> str;

    if (is_sorted(str.begin(), str.end())) {
        cout << "Bob\n";
        return;
    }

    int cnt0 = 0;
    for (char ch : str) if (ch == '0') cnt0++;

    vector<int> pos;
    for (int i = 0; i < cnt0; i++) {
        if (str[i] == '1') pos.push_back(i + 1);
    }
    for (int i = cnt0; i < len; i++) {
        if (str[i] == '0') pos.push_back(i + 1);
    }

    cout << "Alice\n";
    cout << pos.size();
    for (int v : pos) cout << " " << v;
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) solve();
    return 0;
}