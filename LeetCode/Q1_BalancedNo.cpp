#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countBalanced(long long low, long long high) {
        long long difference = high - low;
        long long count =0;
        for(long long i = low;i<=high;i++){
            long long x =i;
            long long sum = 0;
            int choice = 1;
            while(x){
                int a = x%10;
                if(choice){
                    sum+=a;
                    choice = 0;
                }
                else{
                    sum-=a;
                    choice = 1;
                }
                x/=10;
            }
            sum = abs(sum);
            if(i%11==0 && (sum==0||sum%11!=0) ){
                count++;
            }
        }

        return count;
    }
};
int main()
{
    Solution sol;
    cout<<sol.countBalanced(238,329)<<endl;
    
}   