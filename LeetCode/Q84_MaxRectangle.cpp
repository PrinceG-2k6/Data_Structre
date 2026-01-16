#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nsl(n);
        vector<int> nsr(n);
        stack<int> s;
        //next smaller left
        nsl[0]=-1;
        s.push(0);
        for(int i=1;i<heights.size();i++){
            int curr=heights[i];
            while(!s.empty() && heights[s.top()]>=curr){
                s.pop();
            }
            if(s.empty()){
                nsl[i]=-1;
            }
            else{
                 nsl[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        //next smaller right
        
        s.push(n-1);
        nsr[n-1]=n;
        for(int i=n-2;i>=0;i--){
            int curr=heights[i];
            while(!s.empty() && heights[s.top()]>=curr){
                s.pop();
            }
            if(s.empty()){
                nsr[i]=n;//dont take -1
            }
            else{
                 nsr[i]=s.top();
            }
            s.push(i);
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            int height=heights[i];
            int width=nsr[i]-nsl[i]-1;
            int area=height * width;
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
};