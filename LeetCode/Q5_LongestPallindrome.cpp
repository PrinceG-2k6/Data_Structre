#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string s1;
        s1.push_back('#');
        for(auto ch : s){
            s1.push_back(ch);
            s1.push_back('#');
        }
        int n=s1.size();
        vector<int> arr(n,0);
        int c=0,r=0;
        for(int i=1;i<n-1;i++){
            int mir=2*c-i;
            if (i < r){
                arr[i]=min(r-i,arr[mir]);
            }
            while((i-1-arr[i]>=0)&& (i+1+arr[i])<n&& s1[i +1+arr[i]]==s1[i-1-arr[i]]){
                arr[i]++;
            }
            if(i+arr[i]>r){
                r=i+arr[i];
                c=i;
            }
        }
        int maxlen=0,maxcen=0;
        for(int i=0;i<n;i++){
              if(arr[i]>maxlen){
                maxcen=i;
                maxlen=arr[i];
              }
        }
        int start=(maxcen-maxlen)/2;
        return s.substr(start,maxlen);
    }
};
int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.longestPalindrome(s);
    return 0;
}
