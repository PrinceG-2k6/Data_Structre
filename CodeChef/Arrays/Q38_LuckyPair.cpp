#include <bits/stdc++.h>
using namespace std;


int* findPair(vector<int>& nums, int target) {
    int* result = new int[2];

    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.find(complement) != mp.end()) {
            result[0] = mp[complement];
            result[1] = i;
            return result;
        }
        mp[nums[i]] = i;
    }

    return result; 
};


int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int x;
    cin >> x;

   int* a = findPair(a,x);
   cout<<a[0]<<" "<<a[1];
    return 0;
}

