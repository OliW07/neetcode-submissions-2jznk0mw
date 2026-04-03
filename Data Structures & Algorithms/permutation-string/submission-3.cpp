class Solution {
public:
    bool checkInclusion(string s1, string s2) {

       unordered_map<char,int> char_freq = {};
       unordered_map<char,int> cur_freq = {};

        for(const char &c: s1) char_freq[c]++;

        int l = 0;
        for(int r = 0; r < s2.size(); r++){
            
            if(char_freq[s2[r]] == 0){
                for(auto &[c,_] : cur_freq) cur_freq[c] = 0;
                l = r + 1;
                continue;
            }

            cur_freq[s2[r]]++;
            while(cur_freq[s2[r]] > char_freq[s2[r]]) cur_freq[s2[l++]]--;

            
            if(r-l+1 == s1.size()) return true;

        }

        return false;
        
    }
};
