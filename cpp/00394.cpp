// Recursive Solution
class RecursiveSolution {
    string decodeRecursive(string& s, int l = 0, int r = 0, int multiplier = 1) {
        if (!r) r = s.size();
        string result = "", current = "";
        
        int i = l;
        while (i != r) {
            if (s[i] == '[') {
                int m = 0, digit = 1;
                for (int j = i - 1; j >= 0 && isdigit(s[j]); j--) {
                    m += (s[j] - '0') * digit;
                    digit *= 10;
                }
                
                int open = 1, close = 0, end = i + 1;
                while (open != close) {
                    if (s[end] == '[') open++;
                    else if (s[end] == ']') close++;
                    end++;
                }
                
                current += decodeRecursive(s, i + 1, --end, m);
                i = end;
            } else if (!isdigit(s[i]))
                current += s[i];
            i++;
        }
        
        for (int j = 0; j != multiplier; j++)
            result += current;
        
        return result;
    }
public:
    string decodeString(string s) { return decodeRecursive(s); }
};

// Iterative Solution
class IterativeSolution {
public:
    string decodeString(string s) {
        string result = "";
        stack<int> stk;
        stack<string> curr;
        
        for (int i = 0; i != s.size(); i++) {
            if (s[i] == '[') {
                if (stk.empty() && !curr.empty()) {
                    result += curr.top();
                    curr.pop();
                }
                
                int m = 0, digit = 1;
                for (int j = i - 1; j >= 0 && isdigit(s[j]); j--) {
                    m += (s[j] - '0') * digit;
                    digit *= 10;
                }
                
                stk.push(m);
                curr.push("");
            } else if (s[i] == ']') {
                string addition = "";
                for (int j = 0; j != stk.top(); j++) {
                    addition += curr.top();
                }
                stk.pop();
                curr.pop();
                
                (stk.empty() ? result : curr.top()) += addition;
            } else if (!isdigit(s[i])) {
                if (curr.empty()) curr.push("");
                curr.top() += s[i];
            }
        }
        
        if (!curr.empty()) result += curr.top();
        
        return result;
    }
};

