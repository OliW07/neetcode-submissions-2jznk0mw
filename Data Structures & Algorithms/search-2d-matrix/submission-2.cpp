class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() * matrix[0].size() -1;

        while(l <= r){

            int m = l + ((r-l)/2);
            int i = m / matrix[0].size();
            int j = m % matrix[0].size();

            if(matrix[i][j] > target){
                r = m-1;
            }else if(matrix[i][j] < target){
                l = m+1;
            }else{
                return true;
            }
        }

        return false;
    }
};
