#include <stdio.h>
#include <stdlib.h>
void PrintArray(int r,int c,int a[r][c]){
    printf("\n");
    printf("\n");
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
            if(a[i][j]!=0){
                nz1++;
            }
        }
    }
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&b[i][j]);
            if(b[i][j]!=0){
                nz2++;
            }
        }
    }
    // PrintArray(3,3,a);
    // PrintArray(3,3,b);
    int s1[nz1][3];
    int count;
    count =0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i][j]!=0){
                s1[count][0]=i;
                s1[count][1]=j;
                s1[count][2]=a[i][j];
                count++;
            }   
        }
    }
    PrintArray(nz1,3,s1);
    int s2[nz2][3];
    count =0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(b[i][j]!=0){
                s2[count][0]=i;
                s2[count][1]=j;
                s2[count][2]=b[i][j];
                count++;
            }   
        }
    }
    PrintArray(nz2,3,s2);

    int s3[nz1+nz2][3];
    int mark =0;
    int i=0,j=0,k=0,l=0;
    while(i<nz1 && k<nz2){
        if(s1[i][0]==s2[k][0]){
            if(s1[i][1]<s2[k][1]){
                s3[mark][0]=i;
                s3[mark][1]=s1[i][1];
                s3[mark][2]=s1[i][2];
                mark++;
                i++;

            }
            else if(s1[i][1]>s2[k][1]){
                s3[mark][0]=k;
                s3[mark][1]=s2[k][1];
                s3[mark][2]=s2[k][2];
                mark++;
                k++;
            }
            else{
                s3[mark][0]=i;
                s3[mark][1]=s2[k][1];
                s3[mark][2]=s2[k][2] + s1[i][2] ;
                mark++;
                i++;
                k++;
            }
        }
        else{
            if(s1[i][0]<s2[k][0]){
                s3[mark][0]=i;
                s3[mark][1]=s1[i][1];
                s3[mark][2]=s1[i][2];
                mark++;
                i++;
            }
            else{
                s3[mark][0]=k;
                s3[mark][1]=s2[k][1];
                s3[mark][2]=s2[k][2];
                mark++;
                k++;
            }
        }
    }
    if(i<nz1){
        s3[mark][0]=i;
                s3[mark][1]=s1[i][1];
                s3[mark][2]=s1[i][2];
                mark++;
                i++;
    }
    if(k<nz2){
        s3[mark][0]=k;
                s3[mark][1]=s2[k][1];
                s3[mark][2]=s2[k][2];
                mark++;
                k++;
    }

    
    PrintArray(mark,3,s3);



    return 0;
}