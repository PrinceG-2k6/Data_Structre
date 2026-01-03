#include <bits/stdc++.h>
using namespace std;

int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return x * power(x, n - 1);
}

int powerLog(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return x*powerLog(x, n / 2) * powerLog(x, n / 2);
    }
    else
    {
        return x*powerLog(x, n / 2) * powerLog(x, n / 2) * powerLog(x, 1);
    }
}

int main()
{
    cout << power(2, 0) << endl;
    ;
    cout << powerLog(2, 8) << endl;
}