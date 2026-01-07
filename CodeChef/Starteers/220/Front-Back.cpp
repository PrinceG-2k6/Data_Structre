#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool check = false;
        unordered_map<char,int> freq;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
            if(freq[s[i]]>1){
                check = true;
                break;
            }
        }
        if(check){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;}
    }
}
