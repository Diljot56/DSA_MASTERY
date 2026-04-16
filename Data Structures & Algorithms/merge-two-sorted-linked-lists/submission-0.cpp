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
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* temp = new ListNode(0);
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        if(temp1 -> val <= temp2 -> val){
            ListNode* head = new ListNode(temp1 -> val);
            temp1 = temp1 -> next;
            temp = head;
        }  
        else{
            ListNode* head = new ListNode(temp2 -> val);
            temp2 = temp2 -> next;
            temp = head;
        }
        ListNode* newHead = temp;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1 -> val <= temp2 -> val){
                ListNode* n = new ListNode(temp1 -> val);
                temp1 = temp1 -> next;
                temp -> next = n;
                temp = n;
            }  
            else{
                ListNode* n = new ListNode(temp2 -> val);
                temp2 = temp2 -> next;
                temp -> next = n;
                temp = n;
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
        return newHead;
    }
};
