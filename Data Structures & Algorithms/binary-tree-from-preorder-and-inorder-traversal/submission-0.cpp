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
    unordered_map<int,int> indicies;
    int preorder_loc = 0;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            indicies[inorder[i]] = i;
        }

        return dfs(preorder, 0, preorder.size()-1);
    }

    TreeNode* dfs(vector<int> &preorder, int l, int r){
        if(l > r) return nullptr;
        
        int root_val = preorder[preorder_loc++];
        TreeNode* root = new TreeNode(root_val);
        int mid = indicies[root_val];

        root->left = dfs(preorder, l, mid-1);
        root->right = dfs(preorder, mid+1, r);

        return root;
    }
};
