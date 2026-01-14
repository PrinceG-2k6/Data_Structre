#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    string a, b, c;
    cin >> a >> b >> c;

    int K = 0;
    int S_start = 0;
    int base_local_cost = 0;

    for (int i = 0; i < n; ++i) {
        int val_b = b[i] - '0';
        int val_c = c[i] - '0';
        int diff = val_b - val_c;
        K += diff;

        if (a[i] == '1') {
            S_start += diff;
        }
    }

    int p1 = 0;
    int p2 = K;
    int p3 = S_start;

    if (p1 > p2) swap(p1, p2);
    if (p2 > p3) swap(p2, p3);
    if (p1 > p2) swap(p1, p2);

    int S_final = p2;

    int total_cost = base_local_cost
                   + abs(S_final - S_start)
                   + abs(S_final)
                   + abs(K - S_final);

    cout << total_cost << "\n";
}

int main() {
    // your code goes here

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}