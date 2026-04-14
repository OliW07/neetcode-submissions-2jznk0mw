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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = root;
        dfs(root, lca, p, q);
        return lca;
    }

    void dfs(TreeNode* node, TreeNode* &lca_out, TreeNode* p, TreeNode*q){
        if(!node) return;
        bool foundLeft = foundIt(node->left, p, q);
        bool foundRight = foundIt(node->right, p, q);
        if(node == p || node == q){
            if(foundLeft || foundRight){
                lca_out = node;
            }
            return;
        }
        if(foundLeft && foundRight){
            lca_out = node;
            return;
        }
        if(foundLeft){
            dfs(node->left, lca_out, p, q);
            return;
        }

        dfs(node->right, lca_out, p, q);
    }

    bool foundIt(TreeNode* node, TreeNode* t1, TreeNode* t2){
        if(!node) return false;
        if(node == t1 || node == t2) return true;

        return foundIt(node->left, t1, t2) || foundIt(node->right, t1, t2);

    }
};
