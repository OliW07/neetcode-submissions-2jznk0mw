class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() * matrix[0].size() -1;

        while(l <= r){

            int m = l + ((r-l)/2);
            pair ij = get_ij(m, matrix[0].size());
            if(matrix[ij.first][ij.second] > target){
                r = m-1;
            }else if(matrix[ij.first][ij.second] < target){
                l = m+1;
            }else{
                return true;
            }
        }

        return false;
    }

    inline pair<int,int> get_ij(const int &x, const int &size_j){
        return std::make_pair(x / size_j, x % size_j);
    }
};
