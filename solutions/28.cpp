class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (needle.size() > haystack.size()) return -1;
        
        for (int lPtr = 0; lPtr != haystack.size() - needle.size() + 1; lPtr++) {
            int rPtr = 0;
            
            for (; rPtr != needle.size(); rPtr++)
                if (haystack[lPtr + rPtr] != needle[rPtr])
                    break;
            
            if (rPtr == needle.size()) return lPtr;
        }
        
        return -1;
    }
};

