#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum =0;
        int m1 = 0,m2=0;
        int left[height.size()],right[height.size()];
        for(int i = 0;i<height.size();i++){
            if(m1<height[i]){
                m1 = height[i];
            }
            left[i]=m1;

            if(m2<height[height.size()-1-i]){
                m2 = height[height.size()-1-i];
            }
            right[height.size()-1-i]=m2;
        }

        for(int i = 1;i<height.size()-1;i++){
            if(height[i]<left[i] && height[i]<right[i]){
                sum += min(left[i],right[i]) - height[i];
            }
        }

          

        return sum; 
    }
};


int main(){
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<sol.trap(height)<<endl;
}