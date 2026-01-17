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
        for(int i=0;i<n;i++) cin>>arr[i];
        bool valid = true;
        for(int i=0;i<n-1;i++) {
            if((arr[i]%2==0 && arr[i+1]%2==0) || (arr[i]%2!=0 && arr[i+1]%2!=0)){
                cout<<"NO\n";
                valid = false;
                break;
            }
        }
        if(valid) cout<<"YES\n";
    }
}