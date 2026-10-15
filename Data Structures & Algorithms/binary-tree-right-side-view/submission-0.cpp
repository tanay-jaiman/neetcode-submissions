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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> parent;
        parent.push(root);

        vector<vector<int>> ret;

        while (true) {
            queue<TreeNode*> child;
            TreeNode * temp;
            vector<int> result;

            while (!parent.empty()) {
                temp = parent.front(); parent.pop();

                if (temp) {
                    result.push_back(temp->val);
                    child.push(temp->left); child.push(temp->right);
                }
            }

            if (child.empty()) break;
            else {
                parent = child;
                ret.push_back(result);
            }
        }

        return ret;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret; vector<vector<int>> levels = levelOrder(root);
        for (vector<int> level : levels) {
            ret.push_back(level.back());
        }
        return ret;
    }
};
