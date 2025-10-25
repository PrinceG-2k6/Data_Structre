#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHappy(vector<int>& a,vector<int>& b) {
        int happy =0;
       for(int i =0;i<a.size();i++){
            if(a[i]<=2*b[i] && b[i]<=2*a[i]){
                happy++;
            }
       }

       return happy;
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
        vector<int> b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        cout<< sol.countHappy(a,b)<<endl;
    }

}
 