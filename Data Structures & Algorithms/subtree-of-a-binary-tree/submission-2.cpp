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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root) return false;
        if(!subRoot) return true;

        if(isIdentical(root,subRoot)) return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }

    bool isIdentical(TreeNode* p1, TreeNode* p2){
        if(!p1 && !p2) return true;
        if(!p1 || !p2 || p1->val != p2->val) return false;

        return isIdentical(p1->left, p2->left) && isIdentical(p1->right, p2->right);
    }
};
