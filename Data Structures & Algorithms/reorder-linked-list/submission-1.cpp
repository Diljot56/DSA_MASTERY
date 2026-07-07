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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next != NULL && fast -> next -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode* temp = slow -> next;
        slow -> next = NULL;
        ListNode* latest = temp -> next;
        temp -> next = NULL;
        while(latest != NULL){
            ListNode* n = latest -> next;
            latest -> next = temp;
            temp = latest;
            latest = n;
        }
        while(temp != NULL){
            ListNode* n = temp -> next;
            temp -> next = head -> next;
            head -> next = temp;
            head = temp -> next;
            temp = n;
        }
    }
};