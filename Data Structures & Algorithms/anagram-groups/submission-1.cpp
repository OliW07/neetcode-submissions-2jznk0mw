class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashtable = {};
        //hashtable.reserve(1000);

        vector<vector<string>> grouped = {};

        for(const string &word : strs){
            string hash = word;
            sort(hash.begin(), hash.end());

            if(hashtable.count(hash)){
                hashtable[hash].push_back(word);
            }else{
                hashtable[hash] = {word};
            }
        }

        for(auto const &element : hashtable){
            grouped.push_back(element.second);
        }

        return grouped;
    }
};
