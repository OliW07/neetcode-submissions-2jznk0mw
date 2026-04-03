#include <array>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int max_length = 0;
        int max_freq = 0;
        unordered_map<char,int> char_freq = {};

        int l = 0;
        for(int r = 0; r < (int)s.size(); r++){
            
            max_freq = max(max_freq, ++char_freq[s[r]]);
            while(r-l+1-k > max_freq) char_freq[s[l++]]--;

            max_length = max(max_length, r-l+1);
        }

        return max_length;
    }
};