#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        
        vector<int> A(N + 1);
        for (int i = 0; i <= N; i++) {
            cin >> A[i];
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < N; i++) {
            ans = min(ans, max(A[i], A[i + 1]));
        }
        
        cout << ans << endl;
    }
}
