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
    void flatten(vector<int>& l, TreeNode* root) {
        if (!root) return;
        flatten(l, root->left);
        l.push_back(root->val);
        flatten(l, root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> l; flatten(l, root);
        return l[k-1];
    }
};
