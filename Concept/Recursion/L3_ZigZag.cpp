#include <bits/stdc++.h>
using namespace std;

void pzz(int n){
    if(n==0)return;
    cout<<"Pre \t"<<n<<endl;
    pzz(n-1);
    cout<<"In \t"<<n<<endl;
    pzz(n-1);
    cout<<"Post \t"<<n<<endl;
}

int main(){
    pzz(2); 
}