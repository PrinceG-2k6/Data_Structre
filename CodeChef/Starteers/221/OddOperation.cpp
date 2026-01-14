#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        if (n % 2 != 0) {
            cout << "0\n";
            continue;
        }

        if (n < 10) {
            cout << "-1\n";
            continue;
        }

        int count = 0;
        int t = n;

        while (t) {
            if (t % 2 != 0) {
                cout << count << "\n";
                break;
            }

            int maxDigit = 0;
            bool found = false;
            int y = t;

            while (y) {
                int x = y % 10;
                maxDigit = max(maxDigit, x);
                if (x % 2 != 0) {
                    found = true;
                    cout << count + 1 << "\n";
                    break;
                }
                y /= 10;
            }

            if (found) break;

            t -= maxDigit;
            count++;
        }
    }
}
