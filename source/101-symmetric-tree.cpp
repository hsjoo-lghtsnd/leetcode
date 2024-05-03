/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool isSymmetricallySame(TreeNode* l, TreeNode* r) {
        if (!l != !r) return false;
        else if (l == nullptr) return true;
        else if (l->val != r->val) return false;
        else return isSymmetricallySame(l->left, r->right) && isSymmetricallySame(l->right, r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetricallySame(root->left, root->right);
    }
};

