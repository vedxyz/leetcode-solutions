class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        stack<char> word;
        
        for (int i = 0; i != s.size(); i++) {
            if (s[i] == ' ') {
                while (!word.empty()) {
                    result += word.top(); word.pop();
                }
                result += s[i];
            } else word.push(s[i]);
        }
        while (!word.empty()) {
            result += word.top(); word.pop();
        }
        
        return result;
    }
};

