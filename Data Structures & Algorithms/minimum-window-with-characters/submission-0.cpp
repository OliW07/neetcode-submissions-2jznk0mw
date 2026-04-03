class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> have = {};
        unordered_map<char, int> need = {};
        int min_window = 1001;
        int min_l = -1, min_r = -1;
        for(const char &c : t) need[c]++;

        int l = 0;
        for(int r = 0; r < (int)s.size(); r++){

            have[s[r]]++;

            while(is_valid(have, need)){

                if(r-l+1 < min_window){
                    min_window = r-l+1;
                    min_l = l;
                    min_r = r;
                }

                if(need.count(s[l])) have[s[l]]--;
                l++;
            }

            
        }

        return min_l == -1 ? "" : s.substr(min_l, min_window);

    }

    inline bool is_valid(const unordered_map<char,int> &have, const unordered_map<char,int> &need){
        for(auto &[c,need_val] : need){
            if(!have.count(c) || have.at(c) < need_val) return false;
        }

        return true;
    }
};
