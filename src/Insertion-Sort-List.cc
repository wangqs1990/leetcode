/**
 * Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
      ListNode *p1 = head, *p2;
      int tmp;
      if (head == NULL || head->next == NULL) {
        return head;
      }
      while (p1->next != NULL) {
        p2 = p1;
        while (p2 != NULL) {
          if (p1->val > p2->val) {
            tmp = p1->val;
            p1->val = p2->val;
            p2->val = tmp;
          }
          p2 = p2->next;
        }
        p1 = p1->next;
      }
      return head;
    }
};