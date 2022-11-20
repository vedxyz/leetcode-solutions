class Solution {
    void reverseString(vector<char>& s, int left, int right) {
        while (left < right) {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }
public:
    string reverseStr(string s, int k) {
        vector<char> chars(s.begin(), s.end());
        
        int i = 0;
        while (i + k < s.size()) {
            reverseString(chars, i, i + k - 1);
            i += 2 * k;
        }
        
        if (i < s.size())
            reverseString(chars, i, s.size() - 1);
        
        return string(chars.begin(), chars.end());
    }
    
    // Or a bit more concise
    string reverseStr(string s, int k) {
        vector<char> chars(s.begin(), s.end());
        
        for (int i = 0; i < s.size(); i += 2 * k) {
            int end = min(i + k - 1, (int) s.size() - 1);
            reverseString(chars, i, end);
        }
        
        return string(chars.begin(), chars.end());
    }
};

