#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void peak(vector<int> &a) {
        int n = a.size();
        if (n <= 0) {
            cout << "-1" << endl;
            return;
        }

        vector<int> b; // Changed array to vector
        
        for (int i = 0; i < n; i++) {
            if (n == 1) {
                b.push_back(a[i]);
            }
            else if (i == 0) {
                if (a[i] > a[i + 1]) {
                    b.push_back(a[i]);
                }
            }
            else if (i == n - 1) {
                if (a[i] > a[i - 1]) {
                    b.push_back(a[i]);
                }
            }
            else {
                if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                    b.push_back(a[i]);
                }
            }
        }

        if (b.empty()) {
            cout << "-1" << endl;
        }
        else {
            for (int j = 0; j < b.size(); j++) {
                if (j > 0) cout << " ";
                cout << b[j];
            }
            cout << endl;
        }
    }
};

void printArray(vector<int>& a) {  // Modified to use vector
    for (int x : a) {
        cout << x << " ";
    }
}

int main() {
    int n;
    Solution sol;
    
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++) {
        cin >> a[j];
    }

    sol.peak(a);

    return 0;
}
