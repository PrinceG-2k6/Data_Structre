#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        int j = 0;
        int ans =0;
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[j]){
                j=i;
            }else{
                ans++;
            }
        }

        cout<<ans<<endl;        
    }
}