/*Sort a linked list in O(n log n) time using constant space complexity.
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
  /* quick sort but time limit!
  ListNode *sortList(ListNode *head) {
    ListNode *pFirst = head, *pSecond, *pEnd = NULL, *pHead;
    int tmp;
    stack<ListNode *> s;
    while(1) {
      if (pFirst == NULL) {
        if (s.empty()) {
          break;
        }
        pEnd = s.top();
        s.pop();
        pFirst = s.top();
        s.pop(); 
        continue;
      }
      pHead = pFirst;
      if (pFirst->next == pEnd) {
        pFirst = NULL;
        continue;
      }
      pSecond = pFirst->next;
      tmp = pFirst->val;
      while (pSecond != pEnd) {
        if (tmp > pSecond->val) {
          pFirst->val = pSecond->val;
          pFirst = pFirst->next;
          pSecond->val = pFirst->val;
          pFirst->val = tmp;
        }
        pSecond = pSecond->next;
      }
      if (pFirst->next != pEnd) {
        s.push(pFirst->next);
        s.push(pEnd);
      }
      pEnd = pFirst;
      pFirst = pHead == pFirst ? NULL: pHead;
    }
    return head;
  }*/

  ListNode *merge(ListNode *first, ListNode *second) {
    ListNode *head, *current;

    if (first->val > second->val) {
      head = second;
      second = second->next;
    } else {
      head = first;
      first = first->next;
    }
    current = head;
    while (first != NULL && second != NULL) {
      if (first->val > second->val) {
        current->next = second;
        second = second->next;
      } else {
        current->next = first;
        first = first->next;
      }
      current = current->next;
    }
    if (first != NULL) {
      current->next = first;
    }

    if (second != NULL) {
      current->next = second;
    }
    return head;
  }
  /*
  //make it merge short
  ListNode *sortList(ListNode *head) {
    ListNode *pFirst = head , *pSecond, *pEnd = NULL, *pHead;
    
    if (head == NULL || head->next == NULL) {
      return head;
    }
    
    this->splice(pFirst, pSecond);

    return this->merge(this->sortList(head), this->sortList(pSecond));
  }

  void splice(ListNode *&head, ListNode *&second) {
    ListNode *first = head;
    second = first;
    while (second->next != NULL && second->next->next != NULL) {
      first = first->next;
      second = second->next->next;
    }
    second = first->next;
    first->next = NULL;
  }*/

  ListNode *sortList(ListNode *head) {
    ListNode *pFirst , *pSecond, *pNext, *prevEnd, *pHead;
    
    int length = 0, tmp;

    if (head == NULL || head->next == NULL) {
      return head;
    }
    
    pSecond = head;

    while (pSecond != NULL) {
      length++;
      pSecond = pSecond->next;
    }

    for (int i = 1; i < length; i+=i) {
      pFirst = head;
      this->splice(pFirst, pSecond, pNext, i);
      head = this->merge(pFirst, pSecond);
      prevEnd = head;
      //find the last node
      while (prevEnd->next != NULL) {
        prevEnd = prevEnd->next;
      }
      pFirst = pNext;
      while (pFirst != NULL) {
        this->splice(pFirst, pSecond, pNext, i);
        if (pSecond == NULL) {
          prevEnd->next = pFirst;
          break;
        }
        pHead = prevEnd->next = this->merge(pFirst, pSecond);
        pFirst = pNext;
        while (prevEnd->next != NULL) {
          prevEnd = prevEnd->next;
        }
      }
    }

    return head;
  }

  //splice a list into three list
  void splice(ListNode *&left,
              ListNode *&right,
              ListNode *&next,
              int length) {
    ListNode *first = left, *second;
    int tmp = length;
    while (--tmp && first->next != NULL) {
      first = first->next;
    }
    right = first->next;
    if (right == NULL ) {
      next = NULL;
      right = NULL;
      return ;
    }
    first->next = NULL;
    second = right;
    tmp = length;
    while (--tmp && second->next != NULL) {
      second = second->next;
    }
    next = second->next;
    second->next = NULL;
  }
};