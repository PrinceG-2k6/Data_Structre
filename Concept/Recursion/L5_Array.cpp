#include<bits/stdc++.h>
using namespace std;

void traverse(int a[],int n,int size){
    if(n>=size)return;
    cout<<a[n]<<" ";
    traverse(a,n+1,size);
}
void traverseRev(int a[],int n,int size){
    if(n>=size)return;
    traverseRev(a,n+1,size);
    cout<<a[n]<<" ";
}


int MaxArray(int a[],int n,int size){
    if(n>=size)return INT_MIN;
    return max(a[n],MaxArray(a,n+1,size));
}

void allIndices(int arr[], int n, int idx, int target, vector<int>& res) {
    if (idx == n) return;

    if (arr[idx] == target)
        res.push_back(idx);

    allIndices(arr, n, idx + 1, target, res);
}

int main(){
    int a[]={1,2,3,4,5,6};
    int size = 6;
    int b[]={2,5,2,4,8,4};
    traverse(a,0,size);
    printf("\n");
    traverseRev(a,0,size);
    printf("\n");
    // i.e. (array,start_idx,end_idx)
    cout<<MaxArray(b,0,6)<<endl;

}