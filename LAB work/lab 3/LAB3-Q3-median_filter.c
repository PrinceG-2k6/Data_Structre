#include <stdio.h>
int main(){
    int i, j, k,l,n, m, sum = 0,median, multi;
    int a[7][7] = {1, 3, 5, 2, 5, 3, 5,
                   7, 5, 4, 8, 6, 6, 4,
                   9, 5, 7, 5, 6, 3, 5,
                   7, 8, 5, 6, 4, 9, 5,
                   1, 2, 5, 4, 8, 3, 5,
                   8, 3, 4, 6, 3, 7, 9,
                   5, 6, 8, 4, 9, 5, 7};
    int b[7][7];
    
    printf("Matrix:\n");
    for(i = 0; i < 7; i++)
    {
        for(j = 0; j < 7; j++)
        {
            printf("%d\t", a[i][j]);
            b[i][j] = a[i][j];
        }
        printf("\n");
    }

    printf("ON APPLYING MEDIAN FILTER FILTER \n\n");
    int c[9];
    int ctr=0;
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            for(k = 0; k < 3; k++)
            {
                for(l = 0; l < 3; l++)
                {
                    c[ctr] = a[i + k][j + l];
                    ctr++;
                }
            }
            // Bubble sort to sort the 3x3 window
            for (int x = 0; x < 9-1; x++) {
                for (int y = 0; y < 9-x-1; y++) {
                    if (c[y] > c[y+1]) {
                        int temp = c[y];
                        c[y] = c[y+1];
                        c[y+1] = temp;
                    }
                }
            } 
            b[i + 1][j + 1] = c[4];           
        }
        break;
    }
    for(i = 0; i < 7; i++)
    {
        for(j = 0; j < 7; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
return 0;
}