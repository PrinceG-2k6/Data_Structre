#include<bits/stdc++.h>

using namespace std;

void findSuperstarDishes(vector<long long> &arr) {
    sort(arr.begin(), arr.end()); 

    int n = arr.size();
    int threshold = n / 3;
    int count = 1;

    for (int i = 1; i <= n; i++) {
        if (i < n && arr[i] == arr[i - 1]) {
            count++;
        } else {
            if (count > threshold)
                cout << arr[i - 1] << " ";
            count = 1;
        }
    }
    cout << "\n";


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
