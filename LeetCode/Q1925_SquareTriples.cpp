#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int count =0;
        for(int i = 1;i<n;i++){
            for(int j =i;j<=n;j++){

                double sq = sqrt(pow(i,2)+pow(j,2));
                int x = sq;
                if(x==sq && 1<=x && x<=n){
                    count+=2;
                }
            }
        }

        return count;
    }
};
int main(){
    Solution sol;
    cout<<sol.countTriples(10)<<endl;
}