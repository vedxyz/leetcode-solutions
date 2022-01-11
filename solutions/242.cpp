class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(128, 0);
        for (int i = 0; i != s.size(); i++) freq[s[i]]++;
        for (int i = 0; i != t.size(); i++) freq[t[i]]--;
        
        for (int i = 0; i != freq.size(); i++)
            if (freq[i]) return false;
        return true;
    }
};
