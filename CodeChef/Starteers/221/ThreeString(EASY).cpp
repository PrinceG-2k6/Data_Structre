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
    int sStar = 0;
    int base_local_cost = 0;

    for (int i = 0; i < n; ++i) {
        int x = b[i] - '0';
        int y = c[i] - '0';
        int diff = x - y;
        K += diff;

        if (a[i] == '1') {
            sStar += diff;
        }
    }

    int p1 = 0;
    int p2 = K;
    int p3 = sStar;

    if (p1 > p2) swap(p1, p2);
    if (p2 > p3) swap(p2, p3);
    if (p1 > p2) swap(p1, p2);

    int sfin = p2;

    int totalCost = base_local_cost
                   + abs(sfin - sStar)
                   + abs(sfin)
                   + abs(K - sfin);

    cout << totalCost << "\n";
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