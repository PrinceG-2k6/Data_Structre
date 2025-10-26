#include <stdio.h>

int majorityElement(int* nums, int n) {
    int count = 0;
    int candidate = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0)
            candidate = nums[i];
        count += (nums[i] == candidate) ? 1 : -1;
    }

    return candidate;
}

int main() {
    int arr[] = {2, 2, 1, 1, 1, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Majority element: %d\n", majorityElement(arr, n));
    return 0;
}
