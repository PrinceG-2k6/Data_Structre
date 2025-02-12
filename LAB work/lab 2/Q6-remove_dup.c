#include <stdio.h>

void rem_dup(int arr[], int *n) {
    int temp[*n];
    int j = 0;

    for (int i = 0; i < *n; i++)
    {
        int k;
        for (k = 0; k < j; k++) 
        {
            if (arr[i] == temp[k]) 
            {
                break;
            }
        }
        if (k == j) 
        {
            temp[j++] = arr[i];
        }
    }

    for (int i = 0; i < j; i++) {
        arr[i] = temp[i];
    }

    *n = j;
}

int main() {
    int i,j,k;
    int arr[] = {1,2,1,2,2,3,3,4,5,6,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("\nArray before removing duplicates:  ");
    for (i = 0; i < 11; i++)
    {
        printf("%d |", arr[i]);
    }

    rem_dup(arr, &n);

    printf("\nArray after removing duplicates:  ");
    for (int i = 0; i < n; i++) {
        printf("%d |", arr[i]);
    }

    return 0;
}