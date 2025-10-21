#include <stdio.h>
#include <stdlib.h>

void peak(int* a,int n){
    if (n <= 0) {
        printf("-1\n");
        return;
    }

    int b[n];
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (n == 1) {
            b[count++] = a[i];
        } else if (i == 0) {
            if (a[i] > a[i + 1]) {
                b[count++] = a[i];
            }
        } else if (i == n - 1) {
            if (a[i] > a[i - 1]) {
                b[count++] = a[i];
            }
        } else {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                b[count++] = a[i];
            }
        }
    }

    if (count == 0) {
        printf("-1\n");
    } else {
        for (int j = 0; j < count; j++) {
            if (j) printf(" ");
            printf("%d", b[j]);
        }
        printf("\n");
    }
}

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

    printf("Enter Size : ");
    scanf("%d", &n);

    int a[n];
    printf("Enter Elements \n");
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &a[j]);
    }

    peak(a,n);

    return 0;
}
