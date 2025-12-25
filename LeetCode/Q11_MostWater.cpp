#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j= height.size()-1;
        int m = 0;

        while(i<j){
            m = max(m,min(height[i],height[j])*(j-i));
            (height[i]<=height[j])?i++:j--;
        }

        return m;
    }
};




int main(){
    Solution sol;
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout<<sol.maxArea(height)<<endl;
}