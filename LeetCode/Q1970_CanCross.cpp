#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Row;
    int Col;
    vector<vector<int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};

    bool DFS(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=Row || j<0 || j>=Col || grid[i][j]==1){
            return false;
        }

        if(i==Row-1){
            return true;
        }

        grid[i][j]=1;

        for(auto & dir : direction){
            int new_i=i+dir[0];
            int new_j=j+dir[1];

            if(DFS(grid,new_i,new_j)){
                return true;
            }
        }

        return false;
    }

    bool canCross(vector<vector<int>>& cells, int mid){
        vector<vector<int>> grid(Row , vector<int>(Col));

        for(int i = 0 ;i<=mid;i++){
            int x  = cells[i][0]-1;
            int y  = cells[i][1]-1;

            grid[x][y]=1;
        }

        for(int j= 0;j<Col;j++){
            if(grid[0][j]==0 && DFS(grid,0,j)){
                return true;
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        Row = row;
        Col = col;
        
        int l = 0;
        int r = cells.size()-1;
        int lastday =0 ;

        while(l<=r){
            int mid = l + (r-l)/2;
            if(canCross(cells,mid)){
                lastday = mid +1;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }

        return lastday;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> cells = {{1,1},{2,1},{1,2},{2,2}};
    cout<<sol.latestDayToCross(3,3,cells)<<endl;
}   