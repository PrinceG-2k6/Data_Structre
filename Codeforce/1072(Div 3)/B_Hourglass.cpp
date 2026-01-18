#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        long long s, k, m;
        cin >> s >> k >> m;
        
        if(s<k){
            cout<<s-min(m%k,s)<<"\n";
        }
        else{
            if(((m/k)%2)==0){
                cout<<s-min(m%k,s)<<"\n";
            }
            else{
                cout<<k-min(m%k,s)<<"\n";
            }
        }
    }
    return 0;
}
