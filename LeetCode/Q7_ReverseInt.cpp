#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int n = abs(x);
        int res=0;
        int multipier =1;
        while(n>0){
            int t =n%10;
            res=(res*10)+t;
            n=n/10;
        }

        if(x>0){
            return res;
        }
        else{
            return -res;
        }
    }
};

int main(){
    Solution sol;
    cout<<sol.reverse(-123)<<endl;
}