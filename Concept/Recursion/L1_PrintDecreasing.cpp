#include <bits/stdc++.h>
using namespace std;
void PrintDec(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    PrintDec(n-1);
}

// ===========================================
// void PrintInc(int a,int b){
//     if(a<=b){
//         cout<<a<<" ";
//     }
//     else{return;}
//     PrintInc(a+1,b);
// }

void PrintInc(int n){
    
    if(n==0){
        return;
    }
    PrintInc(n-1);
    cout<<n<<" ";
    
}


// ===========================================

void PrintDecInc(int n){
    // PrintDec(n);
    // PrintInc(n);
    if(n==0) return;
    cout<<n<<" ";
    PrintDecInc(n-1);
    cout<<n<<" ";
}



int main()
{   
    PrintDec(5);
    cout<<endl;
    // PrintInc(1,10)
    PrintInc(10);
    printf("\n");
    PrintDecInc(10);

}