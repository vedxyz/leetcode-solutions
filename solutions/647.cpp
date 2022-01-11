class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() == 0) return 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int count = 0;
        
        for (int i = 0; i != s.size(); i++) // Base case, single character
            count += dp[i][i] = true;
        
        for (int i = 0; i != s.size() - 1; i++) // Base case, two characters
            count += dp[i][i + 1] = s[i] == s[i + 1];
        
        for (int len = 3; len <= s.size(); len++) // All other lengths
            for (int i = 0, j = i + len - 1; j != s.size(); i++, j++)
                count += dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
        
        return count;
    }
};
