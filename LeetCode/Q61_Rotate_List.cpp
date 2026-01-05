#include <bits/stdc++.h>
using namespace std;    


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode* p=head;
        int size =1;
        for(int i=0;i<k;i++){
            if(p->next ==NULL){
                size = size +i;
                k=k%size;
                p=head;
                i = -1;
            }else{p=p->next;}
            
        }
        ListNode* q = head;
        if(q==p) return head;

        while(p->next!=NULL){
            p=p->next;
            q=q->next;
        }
        ListNode * h = q->next;
        q->next = NULL;
        p->next = head;
        head = h;
        
        return head;
    }
};
