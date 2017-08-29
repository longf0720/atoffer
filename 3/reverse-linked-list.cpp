/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
typedef ListNode* List;
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }
        List current = head, origin_next = NULL;
        head = NULL;
        while (current != NULL) {
            origin_next = current->next;
            if (head == NULL) {
                head = current;
                head->next = NULL;
            } else {
                // 头插法
                ListNode *tmp = head;
                head = current;
                head->next = tmp;
            }
            current = origin_next;
        }
        return head;
    }
};
