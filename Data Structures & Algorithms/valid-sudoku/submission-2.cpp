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

                uint16_t mask = 1 << (board[i][j] - '1');
                int box_index = get_index_box(i,j);
                if(mask & rows[i] || mask & cols[j] || mask & boxes[box_index]){
                    return false;
                }

                rows[i] |= mask;
                cols[j] |= mask;
                boxes[box_index] |= mask;
            }
        }

        return true;
    }

    uint8_t get_index_box(const int &i, const int &j) {
        //Integer division magic
        return (j / 3 * 3) + (i / 3);
    }
};
