class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse = 0;
        uint32_t mask = 1;
        
        while (mask) {
            reverse += n & mask ? 1 : 0;
            mask <<= 1;
            if (mask) reverse <<= 1;
        }
        
        return reverse;
    }
};

