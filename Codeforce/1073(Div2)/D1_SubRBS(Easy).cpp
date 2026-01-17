#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int r_par = 0;
    int ans = -1;

    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '(') {
            r_par++;
        } else {
            if (r_par >= 2) {
                ans = n - 2;
                break;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}