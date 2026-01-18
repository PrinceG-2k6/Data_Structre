#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

bool isMagicSquare(vector<vector<int>>& grid, int r, int c,int s) {
          
    }

    int findMagicSquare(vector<vector<int>>& grid,int a,int b,int m){
        int hsum =0;
        int vsum =0;
        int k =0;
        int size =1;
        for(int i=a,j=b;i<m && j<m;i++,j++){
            hsum += grid[k][j];
            vsum += grid[j][k];

            if(hsum == vsum){
                int s = a-i+1;
                if(isMagicSquare(grid,a,b,s)){
                    size = max(size,s);
                }
            }
        }

    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int size =1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                size = max(size,findMagicSquare(grid,i,j,min(m,n)));
            }
        }
        return size;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{7,1,4,5,6},{2,5,1,6,4},{1,5,4,3,2},{1,2,7,3,4}};
    cout <<sol.largestMagicSquare(grid);
}