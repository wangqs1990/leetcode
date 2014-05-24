/**
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode *fast = head, *slow = head, *current, *current2;
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return ;
        }
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        current = slow->next;
        slow->next = NULL;

        //make current as the list head
        if (current->next != NULL) {
            fast = current->next;
            current->next = NULL;
            while (fast != NULL) {
                slow = fast->next;
                fast->next = current;
                current = fast;
                fast = slow;
            }
        }

        slow = head;
        fast = current;
        while (fast != NULL) {
            current = slow->next;
            current2 = fast->next;
            slow->next = fast;
            fast->next = current;
            slow = current;
            fast = current2;
        }
    }
};