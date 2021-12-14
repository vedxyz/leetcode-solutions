class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        
        for (int i = 0; i != s.size(); i++) {
            int sign = 1;
            if (i + 1 != s.size())
                switch (s[i]) {
                    case 'C': sign = s[i + 1] == 'D' || s[i + 1] == 'M' ? -1 : 1; break;
                    case 'X': sign = s[i + 1] == 'L' || s[i + 1] == 'C' ? -1 : 1; break;
                    case 'I': sign = s[i + 1] == 'V' || s[i + 1] == 'X' ? -1 : 1; break;
                }
            
            switch (s[i]) {
                case 'M': result += 1000; break;
                case 'D': result += 500; break;
                case 'C': result += sign * 100; break;
                case 'L': result += 50; break;
                case 'X': result += sign * 10; break;
                case 'V': result += 5; break;
                case 'I': result += sign * 1; break;
            }
        }
        
        return result;
    }
};

