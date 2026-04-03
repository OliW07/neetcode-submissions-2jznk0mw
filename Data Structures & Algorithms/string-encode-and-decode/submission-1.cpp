class Solution {
public:

    string encode(vector<string>& strs) {
        string code = to_string(strs.size()) + " ";
        
        for(const string &word : strs){
            code += to_string(word.size());
            code += " ";
        }


        for(const string &word : strs) code += word;

        return code;
    }

    vector<string> decode(string s) {

        stringstream ss(s);

        int operations;
        ss >> operations;

        vector<string> decoded = {};
        vector<int> lengths = {};

        for(int i = 0; i < operations; i++){
            int length;
            ss >> length;
            lengths.push_back(length);
        }


        int pos = ss.tellg();
        pos++;
        string msg = s.substr(pos);

        int currentPos = 0;
        for(int i = 0; i < operations; i++){
            string word = msg.substr(currentPos, lengths[i]);
            currentPos += lengths[i];
            decoded.push_back(word);
        }

        return decoded;

    }
};
