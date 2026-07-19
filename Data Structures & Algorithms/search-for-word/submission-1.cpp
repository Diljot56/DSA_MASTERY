class Solution {
public:
    int R;
    int C;
    vector<vector<bool>> visited;
    bool search(vector<vector<char>> &board, string word, int idx, int i, int j){
        if(idx == word.length()){
            return true;
        }
        if(i < 0 || i >= R || j < 0 || j >= C || visited[i][j] || board[i][j] != word[idx]){
            return false;
        }
        visited[i][j] = true;
        bool res = search(board, word, idx + 1, i + 1, j) ||
                   search(board, word, idx + 1, i - 1, j) ||
                   search(board, word, idx + 1, i, j + 1) ||
                   search(board, word, idx + 1, i, j - 1);
        visited[i][j] = false;

        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        R = board.size();
        C = board[0].size();

        visited = vector<vector<bool>>(R, vector<bool>(C, false));

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(search(board, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
};
