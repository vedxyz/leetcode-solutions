class Solution {
    bool findWord(vector<vector<char>>& board, string& word, /*unordered_set<int>& visited,*/ int x, int y, int i = 0) {
        // int idx = x + y * board[0].size();
        if (i == word.size()) return true;
        else if (x < 0 || x >= board[0].size() || y < 0 || y >= board.size() ||
                 /*visited.count(idx) ||*/ word[i] != board[y][x]) return false;
        // visited.insert(idx);
        char original = board[y][x];
        board[y][x] = '#';
        
        if (findWord(board, word, /*visited,*/ x, y - 1, i + 1))
            return true;
        if (findWord(board, word, /*visited,*/ x + 1, y, i + 1))
            return true;
        if (findWord(board, word, /*visited,*/ x, y + 1, i + 1))
            return true;
        if (findWord(board, word, /*visited,*/ x - 1, y, i + 1))
            return true;
        
        // visited.erase(idx);
        board[y][x] = original;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int y = 0; y != board.size(); y++)
            for (int x = 0; x != board[0].size(); x++)
                // unordered_set<int> visited;
                if (findWord(board, word, /*visited,*/ x, y))
                    return true;
        return false;
    }
};

