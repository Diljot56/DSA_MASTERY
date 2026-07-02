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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(1);
        ListNode* temp = head;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1 -> val < temp2 -> val){
                ListNode* n = new ListNode(temp1 -> val);
                temp -> next = n;
                temp = n;
                temp1 = temp1 -> next;
            }
            else{
                ListNode* n = new ListNode(temp2 -> val);
                temp -> next = n;
                temp = n;
                temp2 = temp2 -> next;
            }
        }

        while(temp1 != NULL){
            ListNode* n = new ListNode(temp1 -> val);
            temp -> next = n;
            temp = n;
            temp1 = temp1 -> next;
        }
        while(temp2 != NULL){
            ListNode* n = new ListNode(temp2 -> val);
            temp -> next = n;
            temp = n;
            temp2 = temp2 -> next;
        }
        return head -> next;
    }
};
