class Solution {
public:
    // Dynamic programming
    int longestValidParentheses(string s) {
        int max = 0;
        vector<int> dp(s.size(), 0);
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
                else if (i - dp[i - 1] >= 1 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = 2 + dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0);
            }
            
            if (max < dp[i])
                max = dp[i];
        }
        
        return max;
    }
    
    // Stack
    int longestValidParentheses(string s) {
        int max = 0;
        stack<int> stk;
        stk.push(-1);
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                stk.push(i);
            else {
                stk.pop();
                
                if (stk.empty())
                    stk.push(i);
                
                if (max < i - stk.top())
                    max = i - stk.top();
            }
        }
        
        return max;
    }
};

