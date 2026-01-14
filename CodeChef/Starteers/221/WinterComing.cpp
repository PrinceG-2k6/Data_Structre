#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	bool wear = false;
	int count =0;
	int T;
	cin>>T;
	while(T--){
	    count =0;
	    wear = false;
	    int n,a,b;
	    cin>>n>>a>>b;
	    vector<int> temp(n);
	    for(int i =0;i<n;i++){
	        cin>>temp[i];
	    }
	    for(int t : temp){
	        if(!wear && t<a){
	           wear = true;
	           count++;
	        }
	        if(wear && t>=a && t<=b){
	            continue;
	        }
	        if(wear && t>b){
	            wear = false;
	        }
	    }
	    
	    cout<<count<<endl;
	}

}
