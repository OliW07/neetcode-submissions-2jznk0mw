struct Subset {
    vector<int> nums;
    int remaining = 0;
};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        Subset subset;
        subset.remaining = target;


        dfs(nums, 0, subset, res);
        return res;
    }

    void dfs(vector<int> &nums, int i, Subset &subset,vector<vector<int>> &res){

        if(subset.remaining == 0){
            res.push_back(subset.nums);
            return;
        }
        if(i == nums.size() || subset.remaining < 0){
            return;
        }

        subset.nums.push_back(nums[i]);
        subset.remaining -= nums[i];
        dfs(nums, i+1, subset, res);
        subset.nums.pop_back();
        subset.remaining += nums[i];
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        dfs(nums, i+1, subset, res);
    }
};
