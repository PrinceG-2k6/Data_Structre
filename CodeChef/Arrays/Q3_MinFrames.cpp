#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int Minimize(vector<int> &arr)
    {
        if (arr.size() <= 0)
            return 0;
        int count = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] != arr[i - 1])
            {
                count++;
            }
        }
        return count;
    }
};


void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int t, n, k;
    Solution sol;
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }

        cout << sol.Minimize(a) << endl;
        t--;
    }

    return 0;
}