    #include <bits/stdc++.h>
    using namespace std;

    class Solution {
    public:
        int minNumberOperations(vector<int>& target) {
            int n = target.size();
            vector<int> a(n, 0); // start from 0, not 1
            int count = 0;

            while (true) {
                bool allMatch = true;
                for (int i = 0; i < n; i++) {
                    if (a[i] != target[i]) {
                        allMatch = false;
                        break;
                    }
                }
                if (allMatch) break;

                int i = 0;
                while (i < n) {
                    // find start of segment that needs increment
                    while (i < n && a[i] == target[i]) i++;
                    if (i == n) break;

                    // perform one operation on continuous unequal segment
                    bool modified = false;
                    while (i < n && a[i] < target[i]) {
                        a[i]++;
                        modified = true;
                        i++;
                    }
                    if (modified) count++; // one operation applied
                }
            }

            // optional: print final array
            // cout << "Final array: ";
            // for (int i = 0; i < n; i++) {
            //     cout << a[i] << " ";
            // }
            // cout << endl;

            return count;
        }
    };

    int main() {
        Solution s;
        vector<int> target = {1, 2, 3, 2, 1};
        cout << "Operations: " << s.minNumberOperations(target) << endl;
        return 0;
    }
