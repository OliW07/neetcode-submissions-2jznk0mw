#include <array>
#include <string>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        std::array<uint16_t,9> rows = {};
        std::array<uint16_t,9> cols = {};
        std::array<uint16_t,9> boxes = {};

        for(int i = 0; i < board.size(); i++){

            for(int j = 0; j < board[i].size(); j++){

                if(board[i][j] == '.') continue;

                uint16_t mask = (1 << (board[i][j] - '1'));
                int box_index = get_box_index(i,j);
                
                
                if(rows[i] & mask || cols[j] & mask || boxes[box_index] & mask){
                    return false;
                }

                rows[i] |= mask;
                cols[j] |= mask;
                boxes[box_index] |= mask;

            }
        }

        return true;
    }

    int get_box_index(const int &i, const int &j){

        return 3 * (i / 3) + (j / 3);
    }

};
