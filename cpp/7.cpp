class Solution {
public:
    int reverse(int x) {
        int result = 0;
        
        while (x) {
            result *= 10;
            
            result += x % 10;
            x /= 10;
            
            if (x != 0 && (result > INT_MAX / 10 || result < INT_MIN / 10))
                return 0;
        }
        
        return result;
    }
};

