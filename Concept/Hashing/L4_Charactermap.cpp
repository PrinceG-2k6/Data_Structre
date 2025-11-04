#include <bits/stdc++.h>
using namespace std;

int main(){
   
    map<char,int> mpp;
    char word[10];
    for(int i =0;i<10;i++){
        cin>>word[i];
        // hash[word[i]-'a']++;
        mpp[word[i]]++;
    }
    
    for(auto it: mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }

    char target;
    cout<<"Enter the character to check frequency : ";
    cin>>target;
    cout<<endl<<"Frequency of target : "<<mpp[target];
}