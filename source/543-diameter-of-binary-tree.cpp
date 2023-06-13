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
    int solution(TreeNode* root) {
        if (root==nullptr) return 0;
        int r = solution(root->right);
        int l = solution(root->left);
        int result = (r>l) ? r : l;

        int thru_root_solution;

        if (root->left==nullptr) {
            if (root->right==nullptr) {
                thru_root_solution = 0;
            }
            else {
                thru_root_solution = root->right->val;
            }
        }
        else {
            if (root->right==nullptr) {
                thru_root_solution = root->left->val;
            }
            else {
                thru_root_solution = root->left->val + root->right->val;
            }
        }

        result = thru_root_solution>result ? thru_root_solution : result;
        return result;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        preset_height(root);
        return solution(root);
    }
};

