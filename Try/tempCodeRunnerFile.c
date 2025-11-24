#include <stdio.h>
#include <stdlib.h>
void PrintArray(int r,int c,int a[r][c]){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
};
int main(){
    int a[3][3];
    int b[3][3];
    int nz1=0,nz2=0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0){
                nz1++;
            }
        }
    }
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&b[i][j]);
            if(b[i][j]==0){
                nz2++;
            }
        }
    }
    PrintArray(3,3,a);
    int s1[nz1][3];
    int count;
    count =0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(count!=0){
                s1[count][0]=i;
                s1[count][1]=j;
                s1[count][2]=a[i][j];
                count++;
            }   
        }
    }

    int s2[nz2][3];
    count =0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(count!=0){
                s2[count][0]=i;
                s2[count][1]=j;
                s2[count][2]=b[i][j];
                count++;
            }   
        }
    }
}