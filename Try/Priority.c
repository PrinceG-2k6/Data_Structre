#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    int priority;
    struct node *next;
} prio;

prio* enq(prio*head ,int x,int p){
    prio * n = (prio*)malloc(sizeof(prio));
    n->val =x;
    n->priority =p;
    if(head==NULL || head->priority<p){
        n->next=head;
        head = n;
    }else{
        prio * temp =head;
        while(temp->next!=NULL && temp->next->priority>=p){
            temp=temp->next;
        }
        n->next = temp->next;
        temp->next=n;
    }
    return head;
}

void print(prio* head){
    prio* temp =head;
    while(temp->next!=NULL){
        printf("%d + ",temp->val);
        temp=temp->next;
    }
    printf("%d ",temp->val);
}

int main(){
    prio* head = NULL;
    head = enq(head,2,3);
    head = enq(head,1,5);
    head = enq(head,3,4);
    head = enq(head,6,1);
    head = enq(head,5,2);
    
    print(head);

    return 0;
}