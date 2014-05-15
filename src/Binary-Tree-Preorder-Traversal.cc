/*Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
 */
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v;
        stack<TreeNode *> pStack;
        pStack.push(NULL);
        TreeNode *p = root;
        while (1) {
    
            //root and left
            while (p != NULL) {
                v.push_back(p->val);
                pStack.push(p);
                p = p->left;
            }
    
            //right
            p = pStack.top();
            
            pStack.pop();
            if (p == NULL) {
                break;
            }
    
            p = p->right;
        }
        return v;
    }
};