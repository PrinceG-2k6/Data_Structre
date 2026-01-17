#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int c0 = 0;
    int c1 = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 0) c0++;
        if (x == 1) c1++;
    }

    if (c0 == 0) {
        cout << "NO" << "\n";
    } else if (c0 > 1 && c1 == 0) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
    }
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