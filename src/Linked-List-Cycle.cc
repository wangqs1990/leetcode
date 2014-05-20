/*Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?*/
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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            head = head->next;
            if (head == fast) {
                return true;
            }
        }
        return false;
    }
};