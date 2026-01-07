#include <bits/stdc++.h>
using namespace std;

const long long LIM = 1000000007LL;
const long long NGLIM = -1000000007LL;

void solve_case() {
    int w;
    cin >> w;

    vector<long long> a(w), b(w);
    for (int i = 0; i < w; i++) cin >> a[i];
    for (int i = 0; i < w; i++) cin >> b[i];

    vector<long long> l(w, LIM), r(w, NGLIM);

    // Left DP
    l[0] = min(a[0], b[0]);
    for (int i = 1; i < w; i++) {
        long long prev = l[i - 1];
        if (prev == LIM) {
            l[i] = LIM;
            continue;
        }
        long long best = LIM;
        if (a[i] >= prev) best = min(best, a[i]);
        if (b[i] >= prev) best = min(best, b[i]);
        l[i] = best;
    }

    // Right DP
    r[w - 1] = max(a[w - 1], b[w - 1]);
    for (int i = w - 2; i >= 0; i--) {
        long long nxt = r[i + 1];
        if (nxt == NGLIM) {
            r[i] = NGLIM;
            continue;
        }
        long long best = NGLIM;
        if (b[i] <= nxt) best = max(best, b[i]);
        if (a[i] <= nxt) best = max(best, a[i]);
        r[i] = best;
    }

    bool ok = false;
    for (int i = 0; i < w; i++) {
        long long left_need = (i == 0) ? NGLIM : l[i - 1];
        long long right_need = (i == w - 1) ? LIM : r[i + 1];

        if (left_need == LIM || right_need == NGLIM) continue;

        if (a[i] >= left_need && b[i] <= right_need && a[i] <= b[i]) {
            ok = true;
            break;
        }

        if (b[i] >= left_need && a[i] <= right_need && b[i] <= a[i]) {
            ok = true;
            break;
        }
    }

    cout << (ok ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve_case();
    }
    return 0;
}
