class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> chars(26, 0);
        
        for (int i = 0; i != t.size(); i++)
            chars[t[i] - 'a']++;
        
        for (int i = 0; i != s.size(); i++)
            chars[s[i] - 'a']--;
        
        for (int i = 0; i != chars.size(); i++)
            if (chars[i]) return 'a' + i;
        return '\0';
    }
    
    // Or using bit manipulation (XOR)
    char findTheDifference(string s, string t) {
        char extra = 0;
        for (int i = 0; i != s.size(); i++)
            extra ^= s[i] ^ t[i];
        
        return extra ^ t[t.size() - 1];
    }
};

