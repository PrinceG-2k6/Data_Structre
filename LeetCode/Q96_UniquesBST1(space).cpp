#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int count = 0;
        for(int i =0;i<n;i++){
            count+= helperfactorial(i)*helperfactorial(n-i-1);
        }

        return count;
    };
    int helperfactorial(int n){
        if(n==0 || n==1){
            return 1;
        }

        return numTrees(n);
    }
};
int main(){
    Solution sol;
    int n;
    cin>>n;
    cout<<sol.numTrees(n);
return 0;
}