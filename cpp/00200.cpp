class Solution {
    // DFS Solution
    void destroyIsland(vector<vector<char>>& grid, int x, int y) {
        if (0 <= x && x < grid[0].size() && 
            0 <= y && y < grid.size() &&
            grid[y][x] == '1') {
            grid[y][x] = '0';
            
            destroyIsland(grid, x, y + 1);
            destroyIsland(grid, x + 1, y);
            destroyIsland(grid, x, y - 1);
            destroyIsland(grid, x - 1, y);
        }
    }
    
    // BFS Solution
    void destroyIsland(vector<vector<char>>& grid, int x, int y) {
        queue<pair<int, int>> q;
        q.push(pair(x, y));
        
        while (!q.empty()) {
            int curX = q.front().first, curY = q.front().second;
            
            if (0 <= curX && curX < grid[0].size() && 
                0 <= curY && curY < grid.size() &&
                grid[curY][curX] == '1') {
                grid[curY][curX] = '0';
                
                q.push(pair(curX, curY + 1));
                q.push(pair(curX + 1, curY));
                q.push(pair(curX, curY - 1));
                q.push(pair(curX - 1, curY));
            }
            q.pop();
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for (int y = 0; y != grid.size(); y++)
            for (int x = 0; x != grid[0].size(); x++)
                if (grid[y][x] == '1') {
                    count++;
                    destroyIsland(grid, x, y);
                }
        
        return count;
    }
};

