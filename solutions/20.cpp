class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> complement = {{'{', '}'}, {'(', ')'}, {'[', ']'}};
        stack<char> stk;
        
        for (int i = 0; i != s.size(); i++)
            if (complement.find(s[i]) != complement.end())
                stk.push(complement[s[i]]);
            else if (!stk.empty() && s[i] == stk.top())
                stk.pop();
            else return false;
        
        return stk.empty();
    }
};

