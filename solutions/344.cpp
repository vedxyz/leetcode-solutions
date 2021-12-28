class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i != s.size() / 2; i++) {
            char temp = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = temp;
        }
    }
    
    // Possibly slightly better to do as below
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }
};

