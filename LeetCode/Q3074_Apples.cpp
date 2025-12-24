#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum =0;
        for(int a : apple){
            sum+=a;
        }
        int count = 0;
        int i =1;
        sort(capacity.begin(), capacity.end());
        while(sum>0){
            sum -= capacity[capacity.size()-i];
            i++;
            count++;
        }

        return count;
    }
};


int main(){
    Solution sol;
    vector<int> apple = {1,3,2};
    vector<int> capacity = {4,3,1,5,2};
    cout<<sol.minimumBoxes(apple,capacity)<<endl;
}