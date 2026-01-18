#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

bool isMagicSquare(vector<vector<int>>& grid, int r, int c,int s) {
        if (grid[r+1][c+1] != 5) return false;// centre must be 5

        int a = grid[r][c],b = grid[r][c+1],d = grid[r][c+2]; // grid ele except centre
        int e = grid[r+1][c],f = grid[r+1][c+2];
        int h = grid[r+2][c],i = grid[r+2][c+1],j = grid[r+2][c+2];

        bool seen[10] = {false};
        int arr[9] = {a,b,d,e,f,h,i,j,5};// 1 - 9 checking
        for (int x : arr) {
            if (x < 1 || x > 9 || seen[x]) return false;
            seen[x] = true;
        }

        if (a + j != 10) return false; //opposite cells must sum to 10
        if (b + i != 10) return false;
        if (d + h != 10) return false;
        if (e + f != 10) return false;

         // Check all rows, columns, and diagonals sum to 15
        if (a + b + d != 15) return false;
        if (h + i + j != 15) return false;
        if (a + e + h != 15) return false;
        if (d + f + j != 15) return false;
        if (a + 5 + j != 15) return false;// centre is 5
        if (d + 5 + h != 15) return false;

        return true;
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