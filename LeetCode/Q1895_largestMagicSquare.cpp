#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMagic(vector<vector<array<int,4>>> const & prefixSum, int r, int c, int sz) {
        int sum = prefixSum[r+sz][c+sz][2] - prefixSum[r][c][2];
        if (sum != prefixSum[r+sz][c+1][3] - prefixSum[r][c+sz+1][3]) {
            return false; 
        }

        for (int i = 0, j = r; i < sz; i++, j++) {
            if (sum != prefixSum[j+1][c+sz][0] - prefixSum[j+1][c][0]) {
                return false;
            }
        }
        for (int i = 0, j = c; i < sz; i++, j++) {
            if (sum != prefixSum[r+sz][j+1][1] - prefixSum[r][j+1][1]) return false;
        }
        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<array<int,4>>> prefixSum(m+1, vector<array<int,4>>(n+2));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int val = grid[i-1][j-1];
                prefixSum[i][j][0] = prefixSum[i][j-1][0] + val;
                prefixSum[i][j][1] = prefixSum[i-1][j][1] + val;
                prefixSum[i][j][2] = prefixSum[i-1][j-1][2] + val;
                prefixSum[i][j][3] = prefixSum[i-1][j+1][3] + val;
            }
        }

        int sz = min(m, n);
        for (int k = sz; k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    if (isMagic(prefixSum, i, j, k)) return k;
                }
            }
        }
        return 1;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{7,1,4,5,6},{2,5,1,6,4},{1,5,4,3,2},{1,2,7,3,4}};
    cout <<sol.largestMagicSquare(grid);
}