class Solution {
public:
    int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]) return 0;
        int h = obstacleGrid.size(), w = obstacleGrid[0].size();
        vector<vector<int>> dp(h, vector(w, 0));
        dp[0][0] = 1;
        
        for (int y = 1; y != h; y++)
            dp[y][0] = !obstacleGrid[y][0] && dp[y - 1][0] ? 1 : 0;
        
        for (int x = 1; x != w; x++)
            dp[0][x] = !obstacleGrid[0][x] && dp[0][x - 1] ? 1 : 0;
        
        for (int y = 1; y != h; y++)
            for (int x = 1; x != w; x++)
                if (!obstacleGrid[y][x]) dp[y][x] = dp[y - 1][x] + dp[y][x - 1];
        
        return dp[h - 1][w - 1];
    }
};
