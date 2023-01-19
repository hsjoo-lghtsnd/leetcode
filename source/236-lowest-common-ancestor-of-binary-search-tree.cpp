/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int t1 = p->val;
        int t2 = q->val;
        int cur = root->val;

        while (root) {
            if ((cur > t1) && (cur > t2)) {
                root = root->left;
            }
            else if ((cur < t1) && (cur < t2)) {
                root = root->right;
            }
            else {
                return root;
            }
            cur = root->val;
        }
        return root;
    }
};
