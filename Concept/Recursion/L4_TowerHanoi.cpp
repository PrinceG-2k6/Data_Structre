#include <bits/stdc++.h>
using namespace std;

void toh(int n,int A,int B,int C){
    if(n==0){
        return;
    }
    toh(n-1,A,C,B);
    cout<<n<<"["<<A<<"->"<<B<<"]"<<endl;;
    toh(n-1,C,B,A);
}

int main(){
    int n,A,B,C;
    cin>>n>>A>>B>>C;
    toh(n,A,B,C);
}