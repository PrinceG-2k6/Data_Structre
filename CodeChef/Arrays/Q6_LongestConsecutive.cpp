#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    // Create a hash set for O(1) lookup
    unordered_set<int> numSet(nums.begin(), nums.end());
    
    int longestStreak = 0;
    
    // Check each number
    for(int num : numSet) {
        // Only start checking sequences from the smallest number
        if(!numSet.count(num - 1)) {
            int currentNum = num;
            int currentStreak = 1;
            
            // Count consecutive numbers
            while(numSet.count(currentNum + 1)) {
                currentNum++;
                currentStreak++;
            }
            
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    
    return longestStreak;
}

int main() {
    // Test cases
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    
    cout << "Length of longest consecutive sequence in nums1: " 
         << longestConsecutive(nums1) << endl;  // Should output 4
    cout << "Length of longest consecutive sequence in nums2: " 
         << longestConsecutive(nums2) << endl;  // Should output 9
    
    return 0;
}