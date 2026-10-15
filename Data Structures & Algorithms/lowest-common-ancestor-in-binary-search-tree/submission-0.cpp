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
    bool exists(TreeNode * root, int val) {
        if (!root) return false;
        if (root->val == val) return true;
        if (root->val > val) return exists(root->left, val);
        else return exists(root->right, val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p || root == q) return root;

        if (exists(root->left, p->val) && exists(root->right, q->val)) return root;
        else if (exists(root->left, q->val) && exists(root->right, p->val)) return root;

        else return lowestCommonAncestor(root->left, p, q) 
                ? lowestCommonAncestor(root->left, p, q) 
                : lowestCommonAncestor(root->right, p, q);
    }
};
