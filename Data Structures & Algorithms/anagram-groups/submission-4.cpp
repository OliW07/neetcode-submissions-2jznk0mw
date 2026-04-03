class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashtable = {};
        hashtable.reserve(1001);

        vector<vector<string>> grouped = {};

        for(const string &word : strs){
            string hash = word;
            sort(hash.begin(), hash.end());

            hashtable[hash].push_back(word);
           
        }

        for(auto const &element : hashtable){
            grouped.push_back(element.second);
        }

        return grouped;
    }
};
