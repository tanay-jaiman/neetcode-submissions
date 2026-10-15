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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((!p && q) || (p && !q)) return false;
        if (!p && !q) return true;
        if (p->val == q->val) return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // TreeNode * node = find(root, subRoot->val);
        if (!root) return false;
        if (isSameTree(root, subRoot)) return true;
        else return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
    }
};
