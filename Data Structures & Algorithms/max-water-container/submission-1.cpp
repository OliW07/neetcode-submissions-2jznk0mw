
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_val = -1;

        int l = 0;
        int r = heights.size() - 1;

        while(l < r){
            int area = (r-l) * std::min(heights[l],heights[r]);
            max_val = std::max(max_val, area);

            if(heights[l] < heights[r]){
                l++;
            }else{
                r--;
            }
        }
        
        return max_val;
    }
};
