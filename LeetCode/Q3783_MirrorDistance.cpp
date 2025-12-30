#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        int x = n;
        int reverse = 0;
        while(x){
            int t = x%10;
            reverse =(reverse*10)+t;
            x/=10;
        }
        
        return abs(n-reverse);
        
    }
};
int main()
{
    Solution sol;
    cout<<sol.mirrorDistance(25)<<endl;
    
}    