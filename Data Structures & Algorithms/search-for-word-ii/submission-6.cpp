struct TrieNode {

    array<TrieNode*, 26> children{};
    string word = "";
    TrieNode() {};
};

class Solution {
private:
    TrieNode* root;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        initTrie(words);
        set<string> found;

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                char c = board[i][j];
                dfs(board, root, i, j, found);
            }
        }

        vector<string> res(found.begin(), found.end());
        return res;
    }

    void dfs(auto &board, TrieNode* cur, int i, int j, set<string> &res){
        
        char temp = board[i][j];
        
        if(!cur || 
            i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] ==  '-' ||
            !cur->children[temp-'a'])

            return;

        TrieNode* next = cur->children[temp-'a'];

        if(next->word != ""){
            res.insert(next->word);
        }
        
        board[i][j] = '-';

        dfs(board, next, i, j-1, res);
        dfs(board, next, i, j+1, res);
        dfs(board, next, i+1, j, res);
        dfs(board, next, i-1, j, res);

        board[i][j] = temp;

    }

    void initTrie(vector<string> &words){
        root = new TrieNode();
        TrieNode* cur;
        for(const string & word : words){
            cur = root;
            for(const char & c : word){
                
                if(!cur->children[c-'a']){
                    cur->children[c-'a'] = new TrieNode();
                }
                cur = cur->children[c-'a'];
            }
            cur->word = word;
        }
    }

};
