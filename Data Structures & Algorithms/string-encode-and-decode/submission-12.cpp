#include <string>

class Solution {
public:

    string encode(vector<string>& strs) {
        string code = "";

        for(const string &word : strs){
            code += to_string(word.size()) + ' ' + word;
            
        }

        return code;
    }

    vector<string> decode(string s) {
        vector<string> msg = {};
        int i = 0;
        while(i < s.size()){
            
            int j = i; 
            while(s[j] != ' '){
                j++;
            }
            int length = std::stoi(s.substr(i,j));
            //skip space
            i = j + 1;
            
            msg.push_back(s.substr(i,length));

            i += length;
            
        }

        return msg;
    }
};
