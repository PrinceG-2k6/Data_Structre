#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int hash[13]={0};
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        hash[arr[i]]++;
    }



    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    cout<<endl<<"Frequency of 1 : "<<hash[1];
}