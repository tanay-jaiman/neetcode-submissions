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

    bool isValidBST(TreeNode* root) {
        if (!(root->left || root->right)) return true;
        vector<int> l;
        flatten(l, root);

        for (int i = 1; i < l.size(); i++) {
            if (l[i] <= l[i-1]) return false;
        }

        return true;
    }
};
