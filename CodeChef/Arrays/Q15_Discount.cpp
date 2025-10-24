
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string checkCoupon(int n, int x, int y, vector<int>& prices) {
        int sum1 = 0, sum2 = 0;
        int i = 0;
        while(i < n) {
            sum1 += prices[i];
            if(prices[i] > y) {
                sum2 += prices[i]-y;
            }
            i++;
        }

        if(sum1<=(sum2+x)){
            return "NO COUPON";
        }
        else{
            return "COUPON";
        }
        
    }
};

int main() {
    int t;
    cin>>t;
    Solution sol;
    while(t--){
        int n,x,y;
        cin >> n >> x >> y;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        cout << sol.checkCoupon(n,x,y,arr)<<endl;
        
    }

    return 0;
}