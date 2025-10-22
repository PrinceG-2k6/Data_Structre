#include<bits/stdc++.h>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> result;
    int i = 0, j = 0;

    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            result.push_back(nums1[i]);
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return result;
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
