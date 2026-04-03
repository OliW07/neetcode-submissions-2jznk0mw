class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int length = 0;
        int cur = 0;
        set<char> char_set = {};

        int l = 0;
        for(int r = 0; r < s.size();r++){

            while(char_set.contains(s[r])){
                char_set.erase(s[l]);
                l++;
            }

            char_set.insert(s[r]);
            length = max(length, r-l+1);

        }

        return length;
    }
};
