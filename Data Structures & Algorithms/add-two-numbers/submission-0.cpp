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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(1);
        ListNode* temp = head;
        int c = 0;
        while(l1 != NULL && l2 != NULL){
            int sum = l1 -> val + l2 -> val + c;
            c = 0;
            if(sum > 9){
                c = sum / 10;
                sum = sum % 10;
            }
            ListNode* node = new ListNode(sum);
            temp -> next = node;
            temp = node;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        int s = 0;
        while(l1 != NULL){
            s = l1 -> val + c;
            c = 0;
            if(s > 9){
                c = s / 10;
                s = s % 10; 
            }
            ListNode* node = new ListNode(s);
            temp -> next = node;
            temp = node;
            l1 = l1 -> next;
        }
        while(l2 != NULL){
            s = l2 -> val + c;
            c = 0;
            if(s > 9){
                c = s / 10;
                s = s % 10; 
            }
            ListNode* node = new ListNode(s);
            temp -> next = node;
            temp = node;
            l2 = l2 -> next;
        }
        if(c){
            temp -> next = new ListNode(c);
        }
        return head -> next;
    }
};
