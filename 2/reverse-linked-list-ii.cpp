/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */


class Solution {
private:
    ListNode * reverse_list(ListNode * head) {
        ListNode * res = NULL;
        ListNode * curr = head;
        while(curr != NULL) {
            if(res == NULL) {
                res = curr;
                curr = curr->next;
                res->next = NULL;
            } else {
                ListNode * foo = curr->next;
                curr->next = res;
                res = curr;
                curr = foo;
            }
        }
        return res;
    }
public:
    /*
     * @param head: ListNode head is the head of the linked list 
     * @param m: An integer
     * @param n: An integer
     * @note: 不申请额外空间
     * @return: The head of the reversed ListNode
     */
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        if(head == NULL || m > n) return NULL;
        ListNode *m_1 = NULL, *n_1 = NULL, *pn = NULL;
        int counter = 0;
        ListNode * res = head;
        while(head != NULL) {
            counter++;
            if(counter == m - 1) {
                m_1 = head;
            } else if (counter == n + 1) {
                n_1 = head;
                break;
            } else if (counter == n) {
                pn = head;
            }
            head = head->next;
        }
        pn->next = NULL;
        //是否从链表的第一个节点开始反转
        ListNode * reverse_head = NULL;
        if(m_1 != NULL) {
            reverse_head = reverse_list(m_1->next);
            m_1->next = reverse_head;
        } else {
            reverse_head = reverse_list(res);
            res = reverse_head;
        }
        while(reverse_head->next != NULL) {
            reverse_head = reverse_head->next;
        }
        reverse_head->next = n_1;
        return res;
    }
};
