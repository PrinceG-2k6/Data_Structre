#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coef;
    int exp;
    struct node *next;
} poly;

poly * create(poly* head,int c,int e){
    poly * n = (poly*)malloc(sizeof(poly));
    n->coef=c;
    n->exp=e;
    if(head==NULL){
        head = n;
    }else{
        poly * temp =head;
        while(temp->next!=NULL && temp->next->coef>=c){
            temp=temp->next;
        }
        temp->next=n;
    }
    return head;
}

void print(poly* head){
    poly * temp =head;
    while(temp->next!=NULL){
        printf("%dx^%d + ",temp->coef,temp->exp);
        temp=temp->next;
    }
    printf("%dx^%d",temp->coef,temp->exp);
}

int main(){
    poly* head = NULL;
    head = create(head,5,2);
    
    head = create(head,3,7);
    
    head = create(head,2,3);
    
    head = create(head,1,1);

    print(head);

    return 0;
}