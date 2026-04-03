class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest = 0;

        for(const int &num : nums){
            if(num_set.contains(num - 1)) continue;
            //num is the start of a sequence
            int length = 1;
            while(num_set.contains(num + length)){
                length++;
            }
            longest = max(longest, length);
        }

        return longest;
    }
};
