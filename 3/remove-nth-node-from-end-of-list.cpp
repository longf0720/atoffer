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
private:
    ListNode * findNthFromEnd(ListNode * head, int n) {
        ListNode * k1 = head, * k2 = head;
        int i = n;
        while(i  && k1 != NULL) {
            k1 = k1->next;
        }
        while(k1 != NULL && k2 != NULL) {
            k1 = k1->next;
            k2 = k2->next;
        }
        return k2;
    }
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL) return NULL;
       
        ListNode * del = findNthFromEnd(head, n);
        // 1
        if(del == head) {
            head = del->next;
        }
        // 5
        else if(del->next == NULL) {
            ListNode * iter = head;
            while(iter->next != del) {
                iter = iter->next;
            } 
            iter->next = NULL;
        }
        //others
        else {
            ListNode * node = del->next;
            del->val = node->val;
            del->next = node->next;
        }
        return head;
    }
};



