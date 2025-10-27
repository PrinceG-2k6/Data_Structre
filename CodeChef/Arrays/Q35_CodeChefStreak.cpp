#include <bits/stdc++.h>
using namespace std;

int Streak(int arr[], int n) {
    int streak = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            streak++;
            ans = max(ans, streak);
        } else {
            streak = 0;
        }
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        int om = Streak(a, n);
        int addy = Streak(b, n);

        if (om > addy) {
            cout << "OM" << endl;
        } else if (om< addy) {
            cout << "ADDY" << endl;
        } else {
            cout << "DRAW" << endl;
        }
    }
    return 0;
}

