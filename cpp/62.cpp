class Solution {
public:
    int uniquePaths(int h, int w) {
        vector<vector<int>> dp(h, vector(w, 1));
        
        for (int y = 1; y != h; y++)
            for (int x = 1; x != w; x++)
                dp[y][x] = dp[y - 1][x] + dp[y][x - 1];
        
        return dp[h - 1][w - 1];
    }
};
