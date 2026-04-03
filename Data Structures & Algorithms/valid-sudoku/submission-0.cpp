#include <set>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<char>> lines = {};

        for(const vector<char> &row : board){
            lines.push_back(row);
        }

        
        for(int i = 0; i < 9; i++){
            vector<char> line = {};
            for(int j = 0; j < 9; j++){
                
                line.push_back(board[j][i]);
            }
            lines.push_back(line);
        }

        int right_shift = 0;
        int down_shift = 0;

        for(int k = 0; k < 9; k++){
            vector<char> line = {};
            for(int i = 3 * right_shift; i < (3 * right_shift + 3); i++){
                for(int j = 3 * down_shift; j < (3 * down_shift + 3); j++){
                    line.push_back(board[j][i]);
                }
            }

            if(right_shift == 2){
                right_shift = 0;
                down_shift++;
            }else{
                right_shift++;
            }

            lines.push_back(line);

        }
        

        for(const vector<char> &line : lines){
            if(!is_valid_line(line)) return false;
        }
        return true;
    }

    bool is_valid_line(const vector<char> &line){
        set<char> seen = {};
        for(const char &c : line){
            if(isdigit(c)){
                if(seen.contains(c)) return false;
                seen.insert(c);
            }
        }

        return true;
    }

};
