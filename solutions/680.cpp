class Solution {
public:
    bool validPalindrome(string s, bool deletion = false) {
        for (int i = 0; i != s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) {
                if (deletion) return false;
                return validPalindrome(s.substr(i,     s.size() - 2 * i - 1), true) || 
                       validPalindrome(s.substr(i + 1, s.size() - 2 * i - 1), true);
            }
        }
        return true;
    }
};

