#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> uniqTree(n + 1, 1);

        for (int nodes = 2; nodes <= n; nodes++) {
            int total = 0;
            for (int root = 1; root <= nodes; root++) {
                total += uniqTree[root - 1] * uniqTree[nodes - root];
            }
            uniqTree[nodes] = total;
        }

        return uniqTree[n];        
    }
};
int main(){
    Solution sol;
    int n;
    cin>>n;
    cout<<sol.numTrees(n);
return 0;
}