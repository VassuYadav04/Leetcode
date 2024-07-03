class Solution {
public:
    bool isValidSudoku(const vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            if (anyDuplicate(board, i, i + 1, 0, board.size(), board.size())) {
                return false;
            }
        }

        for (int j = 0; j < board.size(); ++j) {
            if (anyDuplicate(board, 0, board.size(), j, j + 1, board.size())) {
                return false;
            }
        }

        int region_size = sqrt(board.size());
        for (int i = 0; i < board.size(); i += region_size) {
            for (int j = 0; j < board.size(); j += region_size) {
                if (anyDuplicate(board,
                                 i, i + region_size,
                                 j, j + region_size,
                                 board.size())) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool anyDuplicate(const vector<vector<char>>& board, int start_row, int end_row,
                      int start_col, int end_col, int num_elements) {
        vector<bool> is_present(num_elements + 1, false);
        for (int i = start_row; i < end_row; ++i) {
            for (int j = start_col; j < end_col; ++j) {
                if (board[i][j] != '.') {
                    if (is_present[board[i][j] - '0']) {
                        return true;
                    }
                    is_present[board[i][j] - '0'] = true;
                }
            }
        }
        return false;
    }
};