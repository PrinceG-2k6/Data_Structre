#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNum(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;  // XOR accumulates the unique number
        }
        return result;
    }
};

int main() {
    int t;
    cin>>t;
    Solution sol;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<< sol.singleNum(a)<<endl;
    }

}
 