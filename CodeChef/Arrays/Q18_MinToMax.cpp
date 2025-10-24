#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNonMinimum(vector<int>& nums) {
        int min =1000;
        int count =0;
        for(int num:nums){
            if(num<min){
                min =num;
            }
        }
        for(int num:nums){
            if(num == min){
                count++;
            }
        }
        return nums.size()-count;
    }
};

int main() {
    int t;
    cin>>t;
    Solution sol;
    while(t--){
        int n,min;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<< sol.countNonMinimum(a)<<endl;
    }

}
 