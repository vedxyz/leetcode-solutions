class Solution {
    int getPalindromeLength(const string& s, int left, int right) {
        int maxLen = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            maxLen = right - left + 1;
            left--;
            right++;
        }
        return maxLen;
    }
public:
    string longestPalindrome(string s) {
        int maxLen = 1, start = 0;
        for (int i = 0; i != s.size() - 1; i++) {
            int currentMax = maxLen;
            maxLen = max(maxLen, getPalindromeLength(s, i, i));
            maxLen = max(maxLen, getPalindromeLength(s, i, i + 1));
            if (currentMax < maxLen)
                start = i - (maxLen - 1) / 2;
        }
        return s.substr(start, maxLen);
    }
};
