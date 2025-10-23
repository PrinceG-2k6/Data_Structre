#include<bits/stdc++.h>

using namespace std;

void findSuperstarDishes(vector<long long> &arr) {
    int n = arr.size();
    vector<long long> a;
    int super = n/3;
    for(int i =0;i<n;i++){
        int cnt = count(arr.begin(),arr.end(),arr[i]);
        if(cnt >= super && !(find(a.begin(), a.end(), arr[i]) == a.end())){
            a.push_back(arr[i]);
        }
    }

    n = a.size();
    for(int i = 0; i < n; i++){
            cout << a[i] << " ";
    }

}

int main() {
    
    int t,n;
    
    cout<<"\nEnter The Size : "<<endl;
    cin>>n;
    vector<long long> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    findSuperstarDishes(nums);
    
    return 0;
}
