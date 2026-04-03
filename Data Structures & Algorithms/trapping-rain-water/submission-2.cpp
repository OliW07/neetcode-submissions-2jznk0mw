class Solution {
public:
    int trap(vector<int>& height) {

        int area = 0;
        int l = 0;
        int r = height.size() - 1;
        int max_left = height[l];
        int max_right = height[r];

        while(l < r){
            if(height[l] < height[r]){
                l++;
                max_left = std::max(max_left, height[l]);
                area += max_left - height[l];
            }else{
                r--;
                max_right = std::max(max_right, height[r]);
                area += max_right - height[r];
            }
        }

        return area;
    }

};