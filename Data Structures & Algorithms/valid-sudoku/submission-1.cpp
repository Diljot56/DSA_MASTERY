class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rows, cols;
        unordered_map<int, unordered_set<int>> squares;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int square = (i / 3) * 3 + (j / 3);
                if(rows[i].count(board[i][j]) || cols[j].count(board[i][j])
                || squares[square].count(board[i][j])){
                    return false;
                }
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                squares[square].insert(board[i][j]);
            }
        }
        return true;
    }
};
