/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode * res = NULL, * curr = NULL;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                if(curr == NULL) {
                    curr = l1;
                    res = curr;
                } else {
                    curr->next = l1; 
                    curr = curr->next;
                }
                l1 = l1->next;
            } else {
                if(curr == NULL) {
                    curr = l2;
                    res = curr;
                } else {
                    curr->next = l2;
                    curr = curr->next;
                }
                l2 = l2->next;
            }
        }
        if(l1 != NULL) {
            if(curr != NULL) curr->next = l1;
            else res = l1;
        }
        if(l2 != NULL) {
            if(curr != NULL) curr->next = l2;
            else res = l2;
        }
        return res;
    } 
};
