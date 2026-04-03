#include <array>

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        std::array<int,26> char_count = {};  

        for(const char &c : s){
            char_count[c - 'a']++;
        }

        for(const char &c : t){
            char_count[c - 'a']--;
        }

        return std::all_of(char_count.begin(), char_count.end(), [](int i){return i == 0;});
    }
};
