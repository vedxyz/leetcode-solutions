class Solution {
public:
    bool isPalindrome(string s) {
        string pure = "";
        for (int i = 0; i != s.size(); i++)
            if (isalnum(s[i]))
                pure += tolower(s[i]);
        
        for (int i = 0; i != pure.size() / 2; i++)
            if (pure[i] != pure[pure.size() - i - 1])
                return false;
        return true;
    }
};

