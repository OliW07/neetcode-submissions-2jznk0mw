class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        //O(nlogn)
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> res = {};

        for(int i = 0; i < nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int target = nums[i];
            int j = i+1;
            int k = nums.size()-1;

            while(j < k){

                if(nums[k]+nums[j] > -target) k--;

                else if(nums[k]+nums[j] < -target) j++; 

                else{
                    vector<int> entry = {nums[i],nums[j],nums[k]};
                    res.push_back(entry);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                }

            }
        }

        return res;
    }
};
