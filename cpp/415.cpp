class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int carry = 0, i = 1, s1 = num1.size(), s2 = num2.size(); // Converting size_t to int is important
        
        while (s1 - i >= 0 || s2 - i >= 0 || carry) {
            int current = 0;
            if (s1 - i >= 0) current += num1[s1 - i] - '0';
            if (s2 - i >= 0) current += num2[s2 - i] - '0';
            current += carry;
            
            carry = current / 10;
            result += to_string(current % 10);
            i++;
        }
        
        return string(result.rbegin(), result.rend());
    }
};

