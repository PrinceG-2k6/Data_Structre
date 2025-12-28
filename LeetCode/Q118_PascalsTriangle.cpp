#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i =0;i<numRows;i++){
            vector<int> res;
            
            for(int j =0;j<i+1;j++){
            
                if(j==0){
                    res.push_back(1);
                }
                else if(j==i){
                    res.push_back(1);
                }
                else{
                    res.push_back(ans[i-1][j-1]+ans[i-1][j]);
                }


            }

            ans.push_back(res);
        }

        return ans;
    }
};


int main()
{
    Solution sol;
    
    vector<vector<int>> ans = sol.generate(5);
    for(vector<int> a : ans){
        for(int n : a){
            cout<< n << " ";
        }
        cout<<endl;
    }
    
}
