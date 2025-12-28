#include <bits/stdc++.h>
using namespace std;

// O(m*n)

// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         int rows = grid.size();
//         int cols = grid[0].size();
//         int count = 0;

//         for (int i = rows - 1; i >= 0; i--) {
//             for (int j = cols - 1; j >= 0; j--) {
//                 if (grid[i][j] < 0)
//                     count++;
//                 else
//                     break; 
//             }
//         }
//         return count;
//     }
// };

// ====================================

// O(m+n)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int i = 0, j = n - 1;
    int count = 0;

    while (i < m && j >= 0) {
        if (grid[i][j] < 0) {
            count += (m - i);
            j--;
        } else {
            i++;
        }
    }
    return count;
}

};



int main()
{
    Solution sol;
    vector<vector<int>> grid = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    cout<<sol.countNegatives(grid);
    
}
