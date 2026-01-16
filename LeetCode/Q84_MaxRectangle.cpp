#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element=st.top();
                st.pop();
                int nse=i;
                int pse=(st.empty() ? -1:st.top());
                maxi=max(maxi,(heights[element]*(nse-pse-1)));
            }
            st.push(i);
        }
        while(!st.empty()){
                int element=st.top();   
                st.pop();
                int nse=heights.size();
                int pse=(st.empty() ? -1:st.top());
                 maxi=max(maxi,(heights[element]*(nse-pse-1)));
            }
        return maxi;
    }
};

int main(){
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};
    cout<<sol.largestRectangleArea(heights);
}