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
    map<int,int,std::greater<int>> dict;
    TreeNode* acc;
    void parseTree(TreeNode* root) {
        if (root==nullptr) return;
        dict[root->val]++;
        parseTree(root->left);
        parseTree(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        parseTree(root);

        int answer = 100000; // MAX_INT
        int past = -1;
        vector<int> list;

        for (auto i : dict) {
            if (i.second == 2)
                return 0;
            list.push_back(i.first);
        }
        sort(list.begin(), list.end());

        for (int i=1; i<list.size(); i++) {
            if (answer > list[i]-list[i-1]) {
                answer = list[i]-list[i-1];
            }
        }
        return answer;
    }
};
