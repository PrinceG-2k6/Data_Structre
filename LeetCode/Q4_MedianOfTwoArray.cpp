#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>  // or include individual headers like <vector>, <climits>, <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Ensure nums1 is the smaller array
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int l = 0, r = n1;

        while (l <= r) {
            int partition1 = (l + r) / 2;
            int partition2 = (n1 + n2 + 1) / 2 - partition1;

            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == n1) ? INT_MAX : nums1[partition1];

            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n2) ? INT_MAX : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Found the correct partition
                if ((n1 + n2) % 2 == 0)
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                else
                    return max(maxLeft1, maxLeft2);
            }
            else if (maxLeft1 > minRight2)
                r = partition1 - 1;
            else
                l = partition1 + 1;
        }

        // Should never reach here if inputs are valid
        throw runtime_error("Invalid input arrays");
    }
};

int main()
{

    int n, m;
    cin >> n;

    Solution sol;

    vector<int> nums1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }

    cin >> m;

    vector<int> nums2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> nums2[i];
    }

    double ans = sol.findMedianSortedArrays(nums1, nums2);
    cout << ans;
    return 0;
}