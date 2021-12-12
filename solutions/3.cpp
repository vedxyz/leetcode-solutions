class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastseen(128, -1);
        int max = 0, left = -1;
        
        for (int right = 0; right != s.size(); right++) {
            if (left < lastseen[s[right]])
                left = lastseen[s[right]];
            
            lastseen[s[right]] = right;
            
            if (max < right - left)
                max = right - left;
        }
        
        return max;
    }
    
    // OR (my original solution)
    
    int lengthOfLongestSubstringOriginal(string s) {
        vector<bool> table(128, false);
        int max = 0, left = 0;
        
        for (int right = 0; right != s.size(); right++) {
            if (table[s[right]]) {
                while (s[left] != s[right])
                    table[s[left++]] = false;
                left++;
            } else table[s[right]] = true;
            
            if (max < right - left + 1)
                max = right - left + 1;
        }
        
        return max;
    }
};

