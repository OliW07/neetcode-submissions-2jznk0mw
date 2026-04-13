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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
        
    }

    int dfs(TreeNode* node, int &res_out){
        if(!node) return 0;

        int left = dfs(node->left, res_out);
        int right = dfs(node->right, res_out);

        res_out = max(res_out, left+right);
        return max(left,right) + 1;
    }
    
};
