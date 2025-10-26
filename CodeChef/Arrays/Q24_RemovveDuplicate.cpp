#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(vector<int>& nums) {   
   set<int> s(nums.begin(), nums.end());
   cout <<s.size()<<endl;
   for (int x : s) {
        cout << x << " ";
    }
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
    removeDuplicates(a);
}
