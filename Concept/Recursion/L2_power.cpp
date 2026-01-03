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

int powerLog(int *count ,int x, int n)
{
    if (n == 0)
        return 1;
    *count +=1;
    int half = powerLog(count,x, n / 2);

    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}


int main()
{
    cout << power(2, 0) << endl;
    int count =0;
    cout << powerLog(&count,2, 8) << endl;
    cout<<count<<endl;
}