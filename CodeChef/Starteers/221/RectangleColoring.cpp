#include <bits/stdc++.h>
using namespace std;

int best;
long long len, wid, r0, g0, b0;
vector<long long> edge;

int cntColor(long long r, long long g, long long b) {
    return (r > 0) + (g > 0) + (b > 0);
}

void dfsPure(int idx, const vector<long long>& pure,
             long long r, long long g, long long b,
             int mixCnt) {

    if (idx == pure.size()) {
        int cost = pure.size();

        if (mixCnt == 0) {
            best = min(best, cost);
        } 
        else if (mixCnt == 1) {
            int c = cntColor(r, g, b);
            if (c >= 2)
                best = min(best, cost + c);
        } 
        else {
            best = min(best, cost + 2 * mixCnt);
        }
        return;
    }

    long long s = pure[idx];

    if (r >= s) dfsPure(idx + 1, pure, r - s, g, b, mixCnt);
    if (g >= s) dfsPure(idx + 1, pure, r, g - s, b, mixCnt);
    if (b >= s) dfsPure(idx + 1, pure, r, g, b - s, mixCnt);
}

void solveCase() {
    cin >> len >> wid >> r0 >> g0 >> b0;
    edge = {len, wid, len, wid};
    best = 13;

    for (int mask = 15; mask >= 0; --mask) {
        vector<long long> pure;
        int mixCnt = 0;

        for (int i = 0; i < 4; i++) {
            if (mask & (1 << i))
                pure.push_back(edge[i]);
            else
                mixCnt++;
        }

        int est = pure.size() + (mixCnt ? 2 * mixCnt : 0);
        if (est >= best) continue;

        dfsPure(0, pure, r0, g0, b0, mixCnt);
    }

    cout << best << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solveCase();
}
