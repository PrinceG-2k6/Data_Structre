#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    // int hash[13]={0};
    int arr[n];
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        // hash[arr[i]]++;
        mpp[arr[i]]++;
    }



    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    // cout<<endl<<"Frequency of 1 : "<<hash[1];
    int target;
    cout<<endl<<"Enter the Number to check frequency : ";
    cin>>target;
    cout<<endl<<"Frequency of target : "<<mpp[target];
}