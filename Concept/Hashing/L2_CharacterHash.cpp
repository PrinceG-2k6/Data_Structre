#include <bits/stdc++.h>
using namespace std;

int main(){
    
    
    int hash[26]={0};
    char word[10];
    for(int i =0;i<10;i++){
        cin>>word[i];
        hash[word[i]-'a']++;
    }
    char target;
    cout<<"Enter the character to check frequency : ";
    cin>>target;
    cout<<endl<<"Frequency of target : "<<hash[target-'a'];
}