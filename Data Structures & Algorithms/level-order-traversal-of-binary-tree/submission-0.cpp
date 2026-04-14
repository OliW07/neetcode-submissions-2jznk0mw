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
        if(!root) return {};
        queue<TreeNode*> nodes = {};
        nodes.push(root);
        vector<vector<int>> res = {};

        while(!nodes.empty()){
            vector<int> level = {};
            int amount = nodes.size();
            for(int i = 0; i < amount; i++){
                TreeNode* node = nodes.front();
                level.push_back(node->val);
                
                if(node->left) nodes.push(node->left);
                if(node->right) nodes.push(node->right);
                nodes.pop();
            }
            res.push_back(level);
        }

        return res;

    }
};
