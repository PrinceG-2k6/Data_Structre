#include <bits/stdc++.h>
using namespace std;
void factorialDec(int n){
    if(n==1 || n==0){
        cout<<n;
        return;
    }
    cout<<n<<" ";
    factorialDec(n-1);
}

void factorialInc(int a,int b){
    if(a<=b){
        cout<<a<<" ";
    }
    else{return;}
    factorialInc(a+1,b);
}
int main()
{   
    factorialDec(5);
    cout<<endl;
    factorialInc(1,10);
}