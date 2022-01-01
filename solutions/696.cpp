class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 0, prev = 0, cur = 1;
        
        for (int i = 1; i != s.size(); i++) {
            if (s[i] != s[i - 1]) {
                count += min(prev, cur);
                prev = cur;
                cur = 1;
            } else cur++;
        }
        
        return count + min(prev, cur);
    }
};

