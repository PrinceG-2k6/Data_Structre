#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    int count = 0; 

    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            count++; 
        }
        arr[j + 1] = key;
    }

    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nNumber of comparisons: %d\n", count);
}

int main() {
    int arr[] = {1,2,1,2,2,3,3,4,5,6,6};
    int n = sizeof(arr) / sizeof(arr[0]); // OR int n=11;

    insertionSort(arr, n);

    return 0;
}
