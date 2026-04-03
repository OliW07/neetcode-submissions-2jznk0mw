class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> compliment_to_index = {};
        std::vector<int> ans = {};

        for(int i = 0; i < nums.size(); i++){
            compliment_to_index[target-nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            if((compliment_to_index.contains(nums[i])) && 
                (i != compliment_to_index[nums[i]])){

                ans = {i, compliment_to_index[nums[i]]};
                return ans;
            }
        }
        
        return {};
    }
};
