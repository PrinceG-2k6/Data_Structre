#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count =0;
    int ans =0;
    for(int num:nums){
        if(num){
            count ++;
        }
        else{
            ans =max(ans,count);
            count=0;
        }
    }
    ans =max(ans,count);

    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout<< findMaxConsecutiveOnes(a) << endl;
}
