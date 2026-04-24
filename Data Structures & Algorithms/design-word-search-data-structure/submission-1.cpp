struct TrieNode {
    array<TrieNode*, 26> children = {};
    bool isWord = false;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() : root(new TrieNode) {
        
    }
    
    void addWord(string word) {
        TrieNode* cur = root;

        for(const char &c : word){
            if(!cur->children[c-'a']){
                cur->children[c-'a'] = new TrieNode();
            }

            cur = cur->children[c-'a'];
        }

        cur->isWord = true;
        
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        return searchRange(word, cur); 
    }

    bool searchRange(string_view word, TrieNode* cur){

        if(word.size() == 0) return cur->isWord;

        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(TrieNode* child : cur->children){
                    if(child && searchRange(word.substr(i+1), child)) return true;
                }
                return false;
            }

            else if(!cur->children[c-'a']){
                return false;
            }
            cur = cur->children[c-'a'];
        }

        return cur->isWord;
       
    }
};
