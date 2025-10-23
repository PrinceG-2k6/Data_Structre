#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int j =i+1;
                while(j<n){
                    if(nums[j]!=0){
                        int temp = nums[i];
                        nums[i]=nums[j];
                        nums[j]=temp;
                        /*
                        1003403
                        1300403
                        1340003

                        10430
                        14030
                        */
                       i+=1;
                    }

                    j++;
                }
            }
        }
        
    }
};

int main() {
    
    Solution sol;
    int t,n;
    cout<<"Enter The Number Of test Case : "<<endl;
    cin>>t;
    while(t>0){

        cout<<"Enter The Size : "<<endl;
        cin>>n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            scanf("%d", &nums[i]);
        }

        sol.moveZeroes(nums);

        for(int i = 0; i < n; i++){
            printf("%d ",nums[i]);
        }

        t--;
    }

    return 0;
}
