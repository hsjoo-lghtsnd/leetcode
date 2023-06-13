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
    void preset_height(TreeNode* root) {
        if (root==nullptr) return;
        preset_height(root->left);
        preset_height(root->right);
        if (root->left==nullptr) {
            if (root->right==nullptr) {
                root->val = 1;
            }
            else {
                root->val = root->right->val + 1;
            }
        }
        else {
            if (root->right==nullptr) {
                root->val = root->left->val + 1;
            }
            else {
                root->val = (root->left->val > root->right->val) ? root->left->val+1 : root->right->val+1;
            }
        }
    }
public:
    int maxDepth(TreeNode* root) {
        if (root==nullptr) return 0; // why LeetCode contains this testcase for only some problems?
        preset_height(root);
        return root->val;
    }
};

