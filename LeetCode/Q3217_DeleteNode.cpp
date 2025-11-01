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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100001> map;
        for(int i = 0, n = nums.size(); i < n; ++i) map.set(nums[i]);
        while(head && map.test(head->val)) head = head->next;
        ListNode *curr = head;
        while(curr && curr->next){
            if(map.test(curr->next->val)) curr->next = curr->next->next;
            else curr = curr->next;
        }
        return head;
    }
};

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original Linked List: ";
    ListNode* temp = head;
    while (temp) {
        cout << temp->val;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;

    // nums = [2, 4]
    vector<int> nums = {1,2,3};

    Solution sol;
    ListNode* newHead = sol.modifiedList(nums, head);

    cout << "Modified Linked List: ";
    temp = newHead;
    while (temp) {
        cout << temp->val;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
