class Solution {
public:
    int findMin(vector<int> &nums) {

        int cur_min = numeric_limits<int>::max();
        int l = 0, r = nums.size()-1;

        while(l < r){

            int k = l + (r-l)/2;

            if(nums[k] < nums[l]){
                cur_min = min(cur_min , nums[k]);
                r = k -1;

            }else{
                cur_min = min(cur_min, nums[l]);
                l = k +1;
            }
        }

        return min(cur_min, nums[l]);

        
    }
};
