#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        long long s, k, m;
        cin >> s >> k >> m;

        long long lastFlip = (m / k) * k;   
        long long elapsed = m - lastFlip;   
        long long remaining = s - elapsed;  

        cout << max(0LL, remaining) << "\n";
    }
    return 0;
}
