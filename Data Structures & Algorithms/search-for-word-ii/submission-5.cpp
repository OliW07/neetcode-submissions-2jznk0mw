struct TrieNode {
    char val;
    int index = -1;
    array<vector<TrieNode*>, 26> children;
    TrieNode() {};
    TrieNode(char val, int idx) : val(val), index(idx) {}
};

class Solution {
private:
    TrieNode* root;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        init(board);
        vector<string> found_words;
        for(const string &word : words){
            set<int> seen = {};
            if(findWord(word, 0, root, seen)){
                found_words.push_back(word);
            }
        }


        return found_words;
    }

    bool findWord(const string &word, int i, TrieNode* cur, set<int> &seen){

        
        if(i == word.size()) {
            return true;
        }
        seen.insert(cur->index);

        for(; i < word.size(); i++){
            char c = word[i];
            
            for(TrieNode* child : cur->children[c-'a']){
 
                if(seen.contains(child->index)) continue;
                if(findWord(word, i+1, child, seen)) return true;
            }
            seen.erase(cur->index);
            return false;
        }
        
        // Safety
        return false;

    }

    void init(vector<vector<char>> & board){
        root = new TrieNode();
        vector<vector<TrieNode*>> nodes(board.size(), vector<TrieNode*>(board[0].size(), nullptr));

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                int index = i * board.size() + j;
                TrieNode* node = new TrieNode(board[i][j], index);
                root->children[board[i][j]-'a'].push_back(node);
                nodes[i][j] = node;
                
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){

                TrieNode* node = nodes[i][j];
                if(j != 0){
                    TrieNode* neighbour = nodes[i][j-1];
                    node->children[neighbour->val-'a'].push_back(neighbour);
                }
                if(j != board[i].size()-1){
                    TrieNode* neighbour = nodes[i][j+1];
                    node->children[neighbour->val-'a'].push_back(neighbour);
                }
                if(i != 0){
                    TrieNode* neighbour = nodes[i-1][j];
                    node->children[neighbour->val-'a'].push_back(neighbour);
                }
                if(i != board.size()-1){
                    TrieNode* neighbour = nodes[i+1][j];
                    node->children[neighbour->val-'a'].push_back(neighbour);
                }
            }
        } 
        
    }
};
