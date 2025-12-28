#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& A, vector<int>& B) {

        map<int,int> map1;
        int min_value=INT_MAX;
        for(int n: A){
            map1[n]++;
            min_value = min(min_value,n);
        }
        for(int n: B){
            map1[n]--;
            min_value = min(min_value,n);
        }
        long long ans=0;
        vector<int> extra;
        for(auto& p:map1){
            if(p.second %2!=0) return -1;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> A={4,2,2,2};
    vector<int> B={1,4,1,2};

    cout<<sol.minCost(A,B)<<endl;
    
}
