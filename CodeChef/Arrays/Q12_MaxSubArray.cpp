#include <bits/stdc++.h>

using namespace std;

int totalSubarrays(int arr[], int N, int K) {
    int ans = 0, i = 0;

    while (i < N) {
        if (arr[i] > K) {
            i++;
            continue;
        }

        int count = 0;
        while (i < N && arr[i] <= K) {
            i++;
            count++;
        }

        ans += ((count * (count + 1)) / 2);
    }

    return ans;
}

int countSubarrays(int arr[], int N, int K) {
    int count1 = totalSubarrays(arr, N, K - 1);
    int count2 = totalSubarrays(arr, N, K);
    int ans = count2 - count1;
    return ans;
}
/* Alternate solution using monotonic stack 
   int countSubarraysWithMaxK(const vector<int>& arr, int K) {
    int n = arr.size();
    vector<int> nextGreater(n, n); // Next greater element index
    vector<int> prevGreater(n, -1); // Previous greater element index
    stack<int> s;

    // Find next greater elements for each position
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            nextGreater[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    // Clear the stack for the next loop
    while (!s.empty()) {
        s.pop();
    }

    // Find previous greater elements for each position
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            prevGreater[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    // Count the number of subarrays where the maximum value is K
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == K) {
            int left = i - prevGreater[i];
            int right = nextGreater[i] - i;
            count += left * right;
        }
    }

    return count;
}

*/
int main() {
    int N, K;
    cin >> N;
    cin >> K;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << countSubarrays(arr, N, K) << endl;
    return 0;
}
