class Solution {
public:
    int climbStairs(int n) {
        // Solution found after playing around with
        // modeling the question using bitstrings
        // Turns out it's just Fibonacci
        vector<int> last2(2, 1);
        
        for (int i = 0; i != n - 1; i++) {
            int next = last2[0] + last2[1];
            last2[0] = last2[1];
            last2[1] = next;
        }
        
        return last2[1];
    }
    
    // Dynamic programming solution
    int climbStairs(int n) {
        vector<int> steps(n + 1, 0);
        steps[0] = 1;
        
        for (int i = 1; i <= n; i++)
            steps[i] += steps[i - 1] + (i >= 2 ? steps[i - 2] : 0);
        
        return steps[n];
    }
};

