#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for(int i =0 ;i<row-2;i++){

            for(int j=0;j<col-2;j++){
                int a = grid[i][j]+grid[i][j+1]+grid[i][j+2];

                int b = grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];

                int c = grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];

                int d = grid[i][j]+grid[i+1][j]+grid[i+2][j];

                int e = grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];

                int f = grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];

                int g = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];

                int h = grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];


                if(a==b && c==d && e==f && g==h && b==c && f==g && c==f && f==15 
                    && grid[i][j]!=grid[i+1][j]
                    && grid[i+1][j]!=grid[i+2][j]
                    && grid[i+2][j]!=grid[i][j+1]
                    && grid[i][j+1]!=grid[i+1][j+1]
                    && grid[i+1][j+1]!=grid[i+2][j+1]
                    && grid[i+2][j+1]!=grid[i][j+2]
                    && grid[i][j+2]!=grid[i+1][j+2]
                    && grid[i+1][j+2]!=grid[i+2][j+2]
                ){
                    count++;
                }
            }
        }

        return count;
    }
};
int main()
{
    Solution sol;
    // vector<vector<int>> grid ={{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    
    vector<vector<int>> grid ={{5,5,5},{5,5,5},{5,5,5}};
    // 4 3 8 4
    // 9 5 1 9
    // 2 7 6 2
    cout<<sol.numMagicSquaresInside(grid)<<endl;
    
}   