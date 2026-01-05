#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int minEle = INT_MAX;

        long long sum = 0;
        long long count =0;

        for(int i=0;i<n;i++){
            for(int j=0 ;j<n;j++){
                if(matrix[i][j]<0){
                    count++;
                }
                minEle = min(minEle,abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }

        if(count %2 ==0){
            return sum;
        }
        else{
            return (sum-2*minEle);
        }
                
    }
};

int main(){
    Solution sol;
    // vector<vector<int>> matrix={{1,-1},{-1,1}};
    
    vector<vector<int>> matrix={{1,2,3},{-1,-2,-3},{1,2,3}};
    cout<<sol.maxMatrixSum(matrix)<<endl;
}