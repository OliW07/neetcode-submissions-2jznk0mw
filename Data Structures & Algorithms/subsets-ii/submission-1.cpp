class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, subset, res);
        return res;
    }

    void backtrack(vector<int> &nums, int pos, vector<int> &subset, vector<vector<int>> &res){
        if(pos == nums.size()) {
            res.push_back(subset);
            return;
        }

        int num = nums[pos];
        subset.push_back(num);
        backtrack(nums, pos+1, subset, res);
        subset.pop_back();
        while (pos + 1 < nums.size() && nums[pos] == nums[pos + 1]) pos++;
        backtrack(nums, pos+1, subset, res);
    }
};
