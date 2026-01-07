
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    vector<long long> X(N);
    for (int i = 0; i < N; ++i) cin >> X[i];

    vector<long long> Y(M);
    for (int i = 0; i < M; ++i) cin >> Y[i];

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    long long min_max_val = LLONG_MAX;

    for (int i = 0; i < N - 1; ++i) {
        long long xl_spread = X[i] - X[0];
        long long xl_max = X[i];
        long long xr_spread = X[N - 1] - X[i + 1];
        long long xr_max = X[N - 1];

        for (int j = 0; j < M - 1; ++j) {
            long long yl_spread = Y[j] - Y[0];
            long long yl_max = Y[j];
            long long yr_spread = Y[M - 1] - Y[j + 1];
            long long yr_max = Y[M - 1];

            long long cost1 = 0;
            cost1 = max(cost1, xl_spread * yr_max);
            cost1 = max(cost1, yr_spread * xl_max);
            cost1 = max(cost1, xr_spread * yl_max);
            cost1 = max(cost1, yl_spread * xr_max);

            if (cost1 < min_max_val)
                min_max_val = cost1;

            long long cost2 = 0;
            cost2 = max(cost2, xl_spread * yl_max);
            cost2 = max(cost2, yl_spread * xl_max);
            cost2 = max(cost2, xr_spread * yr_max);
            cost2 = max(cost2, yr_spread * xr_max);

            if (cost2 < min_max_val)
                min_max_val = cost2;
        }
    }

    cout << min_max_val << endl;
}

int main() {
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}