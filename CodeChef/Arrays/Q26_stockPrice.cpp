
#include <bits/stdc++.h>
using namespace std;

int findMaxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices) {
        if (price < minPrice) {
            minPrice = price; // update minimum seen so far
        } else if (price - minPrice > maxProfit) {
            maxProfit = price - minPrice; // update max profit
        }
    }
    return maxProfit;
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
    cout << findMaxProfit(a);
}
