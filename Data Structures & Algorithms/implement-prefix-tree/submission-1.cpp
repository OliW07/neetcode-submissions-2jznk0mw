struct node {
    array<node*, 26> children = {};
    char val;
    bool included = false;
    node() {}
    node(char val) : val(val) {}

}; 

class PrefixTree {
private:
    node* root;
public:
    PrefixTree() :  root(new node()) {
    }
    
    void insert(string word) {
        node* cur = root;
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(!cur->children[c-'a']){
                cur->children[c-'a'] = new node(c);
            }
            cur = cur->children[c-'a'];
            if(i == word.size()-1){
                cur->included = true;
            }
        }  
    }
    
    bool search(string word) {
        node* cur = root;
        for(const char &c : word){
            if(!cur->children[c-'a']) return false;
            cur = cur->children[c-'a'];
        } 
        return cur->included;
    }
    
    bool startsWith(string prefix) {
        node* cur = root;
        for(const char &c : prefix){
            if(!cur->children[c-'a']) return false;
            cur = cur->children[c-'a'];
        } 
        return true;
    }
};
