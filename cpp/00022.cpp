class Solution {
    void genParenthesisRecursive(vector<string>& result, string& current, int open, int close, int max) {
        if (current.size() == max * 2) {
            result.push_back(current);
            return;
        }
        
        if (open < max) {
            current += '(';
            genParenthesisRecursive(result, current, open + 1, close, max);
            current.pop_back();
        }
        if (close < open) {
            current += ')';
            genParenthesisRecursive(result, current, open, close + 1, max);
            current.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result; 
        string current = "";
        genParenthesisRecursive(result, current, 0, 0, n);
        return result;
    }
};
