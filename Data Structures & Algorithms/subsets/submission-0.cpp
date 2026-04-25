class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> res;
       res.push_back({});

       for(int num : nums){
            int size = res.size();
            for(int i = 0; i < size; i++){
                vector<int> sub = res[i];
                sub.push_back(num);
                res.push_back(sub);
            }
       }

       return res;
    }
};
