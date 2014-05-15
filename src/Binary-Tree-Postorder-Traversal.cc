/*Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        stack<TreeNode *> pStack;
        stack<int> traversalCount;
        int c;
        pStack.push(NULL);
        traversalCount.push(0);
        TreeNode *p = root;
        while (1) {

        //root and left
            while (p != NULL) {
                pStack.push(p);
                traversalCount.push(1);
                p = p->left;
            }
    
    
            //right
            p = pStack.top();
            c = traversalCount.top();
    
            if (p == NULL) {
                break;
            }
    
            if (c == 0) {
                v.push_back(p->val);
                traversalCount.pop();
                pStack.pop();
                p = NULL;
            } else {
                traversalCount.pop();
                traversalCount.push(0);
                p = p->right;
            }
        }
        return v;
    }
};