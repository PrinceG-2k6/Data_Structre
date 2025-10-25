#include <bits/stdc++.h>
using namespace std;
void rearrangeArray(vector<int>& arr, int n) {
    vector<int> pos, neg;

    for (int x : arr) {
        if (x > 0) pos.push_back(x);
        else neg.push_back(x);
    }

    for (int i = 0; i < n/2; i++) {
        cout << pos[i] << " " << neg[i] << " ";
    }
    cout << "\n";
}

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    rearrangeArray(a, n);
}
