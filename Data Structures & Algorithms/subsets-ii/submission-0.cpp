class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());

        backtrack(nums, 0, subset, res);
        vector<vector<int>> vres(res.begin(), res.end());
        return vres;
    }

    void backtrack(vector<int> &nums, int pos, vector<int> &subset, set<vector<int>> &res){
        if(pos == nums.size()) {
            res.insert(subset);
            return;
        }

        int num = nums[pos];
        subset.push_back(num);
        backtrack(nums, pos+1, subset, res);
        subset.pop_back();
        backtrack(nums, pos+1, subset, res);
    }
};
