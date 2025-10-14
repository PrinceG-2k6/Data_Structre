#include <stdio.h>

void printArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n, i, x, pos;
    printf("ENTER THE SIZE OF ARRAY: ");
    scanf("%d", &n);

    int a[n];
    printf("\nENTER THE ELEMENTS OF ARRAY:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nOriginal Array: ");
    printArray(a, n);

   
    int b[n + 1];
    printf("\nEnter the element you want to insert at the beginning: ");
    scanf("%d", &x);

    b[0] = x;
    for (i = 0; i < n; i++) {
        b[i + 1] = a[i];
    }

    printf("Array after inserting at beginning: ");
    printArray(b, n + 1);

    
    int c[n + 2];
    for (i = 0; i < n + 1; i++) {
        c[i] = b[i];
    }
    printf("\nEnter the element you want to insert at the end: ");
    scanf("%d", &x);
    c[n + 1] = x;

    printf("Array after inserting at end: ");
    printArray(c, n + 2);
  int d[n + 3];
    for (i = 0; i < n + 2; i++) {
        d[i] = c[i];
    }
    printf("\nEnter the element you want to insert: ");
    scanf("%d", &x);
    printf("Enter the index (0-based): ");
    scanf("%d", &pos);

    if (pos < 0 || pos > n + 2) {
        printf("Invalid index!\n");
        return 0;
    }

    for (i = n + 2; i > pos; i--) {
        d[i] = d[i - 1];
    }
    d[pos] = x;

    printf("Array after inserting at index %d: ", pos);
    printArray(d, n + 3);

    return 0;
}
