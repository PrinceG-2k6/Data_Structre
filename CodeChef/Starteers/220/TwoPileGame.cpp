#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        long long count = 0;

        if (y > x) {
            long long k1 = (y - x + 1) / 2;
            x += k1;
            y -= k1;
            count += k1;
        }

        count += y;
        x -= y;
        y = 0;

        count += x;
        x = 0;

        if (count % 2 == 0)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }
    return 0;
}
