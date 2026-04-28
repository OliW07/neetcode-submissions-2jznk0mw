class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums,0,res);
        return res;
    }

    void dfs(vector<int> &nums, int i, vector<vector<int>> &res){

        res.push_back(nums);
        if(i == nums.size()){
            return;
        }

        for(; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                swap(nums[i], nums[j]);
                dfs(nums, i+1, res);
                swap(nums[i], nums[j]);
            }
        }
    }
};
