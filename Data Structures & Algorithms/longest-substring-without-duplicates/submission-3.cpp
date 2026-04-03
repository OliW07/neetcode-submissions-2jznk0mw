class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int length = 0;
        int cur = 0;
        map<char, int> char_to_index = {};
        map<int, char> index_to_char = {};

        int l = 0;
        for(int r = 0; r < s.size();){

            if(char_to_index.contains(s[r])){
            
                int duplicate_index = char_to_index[s[r]];
                while(l < (duplicate_index + 1)){
                    char char_to_remove = index_to_char[l];
                    index_to_char.erase(l);
                    char_to_index.erase(char_to_remove);
                    l++;
                }
                

                
            }

            char_to_index[s[r]] = r;
            index_to_char[r] = s[r];
 
            length = max(length, r-l+1);
            r++;
        }

        return length;
    }
};
