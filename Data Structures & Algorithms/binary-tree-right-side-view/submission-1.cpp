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
    vector<int> rightSideView(TreeNode* root) {

        if(!root) return {};
        queue<TreeNode*> nodes;
        vector<int> ans;

        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* rightMost = nullptr;
            int amount = nodes.size();

            for(int i = 0; i < amount; i++){
                TreeNode* node = nodes.front();
                rightMost = node;
                if(node->left) nodes.push(node->left);
                if(node->right) nodes.push(node->right);
                nodes.pop();

            }
            ans.push_back(rightMost->val);
        }

        return ans;
    }
};
