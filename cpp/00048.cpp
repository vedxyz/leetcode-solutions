class Solution {
    void swap4(int& a, int& b, int& c, int& d) {
        int tmp = a;
        a = d;
        d = c;
        c = b;
        b = tmp;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int y = 0; y != matrix.size() / 2; y++) {
            int end = matrix[0].size() - y - 1;
            for (int x = y; x != end; x++)
                swap4(matrix[y][x], matrix[x][end], matrix[end][end + y - x], matrix[end + y - x][y]);
        }
    }
};
