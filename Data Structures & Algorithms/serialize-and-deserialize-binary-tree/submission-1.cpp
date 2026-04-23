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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(!root) return res;

        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()){
            TreeNode* node = nodes.front();
            nodes.pop();

            if(!node){
                res += "-";
                res+= " ";
                continue;
            }
                
            int n = node->val;
            res += to_string(n);
            
            
            res += " ";
            nodes.push(node->left);
            nodes.push(node->right);
        }
        cout << res;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        string word;
        stringstream ss(data);
        queue<TreeNode*> nodes;
        TreeNode* root = nullptr;
        bool isLeft = true;

        while(ss >> word){

            TreeNode* node = nullptr;
            if(word != "-") {
                node =  new TreeNode(stoi(word));
                nodes.push(node);
            }

            if(!root){
                root = node;
                continue;
            }
           
            TreeNode* parent = nodes.front();

          
            if(isLeft){
                parent->left = node;
            }
            else{
                parent->right = node;
                nodes.pop();
            }

            isLeft = !isLeft;
            

        }

        return root;

    }
};
