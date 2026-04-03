class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hashmap = {};

        for(const int &num : nums){
            hashmap[num]++;
        }

        multimap<int, int, std::greater<int>> reversed = {};

        for(auto const &pair : hashmap){
            reversed.insert({pair.second, pair.first});
        }

        vector<int> result = {};

        int i = 0;
        for(auto it = reversed.begin(); it != reversed.end(); ++it){
            if(i == k) break;
            result.push_back(it->second);
            i++;
        }

        return result;
    }
};
