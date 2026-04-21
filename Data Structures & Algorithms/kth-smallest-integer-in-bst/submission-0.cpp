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
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        dfs(root, k, res);
        return res;
    }

    int dfs(TreeNode* node, int k, int &res){
        if(!node) return 0;
        
        int left = dfs(node->left, k, res);
        int cur = left + 1;

        if(cur == k){
            res = node->val;
            return 1001;
        }

        int right = dfs(node->right, k - cur, res);

        return cur + right;

    }
};
