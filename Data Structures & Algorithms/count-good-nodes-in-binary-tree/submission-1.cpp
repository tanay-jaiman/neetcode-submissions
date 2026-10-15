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
    int find_count(TreeNode* root, int max) {
        if (!root) return 0;
        if (root->val >= max) return 1 + find_count(root->left, root->val) + find_count(root->right, root->val);
        else return find_count(root->left, max) + find_count(root->right, max);
    }

    int goodNodes(TreeNode* root) {
        return find_count(root, -101);
    }
};
