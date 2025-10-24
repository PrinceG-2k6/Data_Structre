#include <bits/stdc++.h>
using namespace std;

int Freshness(int* a,int* b,int n,int x){
    int sum =0;
    for(int i=0;i<n;i++){
        if(a[i]>=x){
            sum+=b[i];
        }
    }
    return sum;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int j=0;j<n;j++){
            cin>>b[j];
        }
        cout<< Freshness(a,b,n,x)<<endl;
    }

}
