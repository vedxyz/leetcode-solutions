class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t bitmask = 1;
        
        while (bitmask) {
            count += n & bitmask ? 1 : 0;
            bitmask <<= 1;
        }
        
        return count;
    }
};

