class Solution {
public:
    int climbStairs(int n) {
        vector<int> last2(2, 1);
        
        for (int i = 0; i != n - 1; i++) {
            int next = last2[0] + last2[1];
            last2[0] = last2[1];
            last2[1] = next;
        }
        
        return last2[1];
    }
};

