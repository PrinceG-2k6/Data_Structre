#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        long long x = n;
        long long reverse = 0;
        while(x){
            int t = x%10;
            reverse =(reverse*10)+t;
            x/=10;
        }
        
        long long ans = abs(n-reverse);
        return ans;
    }
};
int main()
{
    Solution sol;
    cout<<sol.mirrorDistance(25)<<endl;
    
}    