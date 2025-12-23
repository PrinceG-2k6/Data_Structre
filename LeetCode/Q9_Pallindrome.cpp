#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        if(x==0){
            return true;
        }

        int n = x;
        int res=0;
        while(n>0){
            int t =n%10;

            // Overflow check
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && t > 7))
                return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && t < -8))
                return 0;

            res=(res*10)+t;
            n=n/10;
        }

        return (res==x)?true:false;
    }
};

int main(){
    Solution sol;
    cout<<sol.isPalindrome(1921)<<endl;
}