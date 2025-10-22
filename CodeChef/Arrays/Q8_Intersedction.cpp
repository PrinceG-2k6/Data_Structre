#include<bits/stdc++.h>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    // Write your code here
}

int main() {
    int nums1Size, nums2Size;
    cin >> nums1Size >> nums2Size;

    vector<int> nums1(nums1Size), nums2(nums2Size);
    for (int i = 0; i < nums1Size; ++i) {
        cin >> nums1[i];
    }
    for (int i = 0; i < nums2Size; ++i) {
        cin >> nums2[i];
    }

    vector<int> result = intersect(nums1, nums2);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
