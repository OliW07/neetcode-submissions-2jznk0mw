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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int res = root->val;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* node, int &resOut){
        if(!node) return 0;

        int leftMax = max(0, dfs(node->left, resOut));
        int rightMax = max(0, dfs(node->right, resOut));
        int val = node->val + leftMax + rightMax;

        resOut = max(resOut, val);
        // Can only have one branch above this node
        return node->val + max(leftMax, rightMax);
    }
};
