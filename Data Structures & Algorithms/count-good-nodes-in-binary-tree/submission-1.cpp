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
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, -101, res);
        return res;
    }

    void dfs(TreeNode* node, int biggest, int &res_out){
        if(!node) return;
        if(node->val >= biggest) res_out++;
        dfs(node->left, max(biggest,node->val), res_out);
        dfs(node->right, max(biggest,node->val), res_out);

    }
};
