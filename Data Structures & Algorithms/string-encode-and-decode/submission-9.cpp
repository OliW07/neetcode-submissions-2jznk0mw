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
            
            string length_digits = "";
            
            while(s[i] != ' '){
                length_digits += s[i++];
            }
            int length = std::stoi(length_digits);
            //skip space
            i++;
            
            msg.push_back(s.substr(i,length));

            i += length;
            
        }

        return msg;
    }
};
