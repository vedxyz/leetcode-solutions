class Solution {
    int getCount(uint32_t n) {
        int count = 0;
        uint32_t bitmask = 1;
        
        while (bitmask) {
            count += n & bitmask ? 1 : 0;
            bitmask <<= 1;
        }
        
        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int> bitcounts(n + 1);
        
        for (int i = 0; i <= n; i++)
            bitcounts[i] = getCount(i);
        
        return bitcounts;
    }
};

