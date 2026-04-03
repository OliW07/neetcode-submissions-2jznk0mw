class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);

        int total = 1;
        for(int i = 0; i < nums.size(); i++){
            result[i] *= total;
            total *= nums[i];
        }

        total = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            result[i] *= total;
            total *= nums[i];
        }

        return result;

    }
};
