#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size();
        vector<int> a;
        int k =0;
        int i;
        int carry =0;
        for(i =n-1;i>=0;i--){
            // if(digits[i]!=0){
            //     break;
            // }
            if(digits[i] == 9){
                digits[i]=0;
                carry = 1;
            }else{
                digits[i]+=1;
                carry = 0;
                break;
            }

        }
        if(carry)a.push_back(1);

        for(int i=0;i<n;i++){
            a.push_back(digits[i]);
        }

        return a;

    }
};

int main()
{
    Solution sol;
    vector<int> digits = {9};
    vector<int> ans = sol.plusOne(digits);
    for(int a:ans){
        cout<<a<<" ";
    } 
}