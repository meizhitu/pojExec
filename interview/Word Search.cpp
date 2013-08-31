class Solution {
public:
    bool find(vector< vector<char> > &board, int i, int j, string &word, int idx)
    {
        if (idx == word.size()) return true;
        if (i < board.size() && j < board[i].size()
        && i >= 0 && j >= 0 && board[i][j] == word[idx])
        {
            board[i][j] = '#';
            ++idx;
            return find(board, i+1, j, word, idx)
            | find(board, i-1, j, word, idx)
            | find(board, i, j-1, word, idx)
            | find(board, i, j+1, word, idx);
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                    vector<vector<char> > tmp (board);
                    bool result = find(tmp, i, j, word, 0);
                    if (result == true)
                        return true;
                }
            }
        }
    }
};