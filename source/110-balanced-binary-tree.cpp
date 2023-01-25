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
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (root->left == NULL) {
            if (root->right == NULL) {
                // root is leaf.
                root->val = 0;
            }
            else {
                // root->right should be leaf.
                if (!((root->right->left == NULL) && (root->right->right == NULL))) {
                    return false;
                }
                else {
                    root->val = 1;
                }
            }
        }
        else {
            if (root->right == NULL) {
                // root->left should be leaf.
                if (!((root->left->left == NULL) && (root->left->right == NULL))) {
                    return false;
                }
                else {
                    root->val = 1;
                }
            }
            else {
                // left and right depth should differ by max 1.
                if (isBalanced(root->left) && isBalanced(root->right)) {
                    int l = root->left->val;
                    int r = root->right->val;
                    int temp = l - r;
                    temp = temp * temp;
                    if (temp < 2) {
                        if (l>r) {
                            root->val = l+1;
                        }
                        else {
                            root->val = r+1;
                        }
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
