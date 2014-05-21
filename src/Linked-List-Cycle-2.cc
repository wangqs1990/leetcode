/*Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return NULL;
        }
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                break;
            }
        }
        if (slow != fast) {
            return NULL;
        }
        if (fast == head) {
            return head;
        }
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};