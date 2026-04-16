/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* temp = head;
        ListNode* latest = new ListNode(head -> val);
        temp = temp -> next;
        while(temp != NULL){
            ListNode* n = new ListNode(temp -> val, latest);
            temp = temp -> next;
            latest = n;
        }
        return latest;
    }
};
