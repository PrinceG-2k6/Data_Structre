#include<bits/stdc++.h>
using namespace std;

int main(){
    
    stack<pair<int,int>> st;
    int m = INT_MAX;
    int arr[]={12,15,10,8};
    for(int i=0;i<4;i++){
        m = min(m,arr[i]);
        st.push({arr[i],m});
    }

    for(int i=3;i>=0;i--){
        cout << "Min element from index 0 to " << i << ": " << st.top().second << endl;
        st.pop();
    }
    
}