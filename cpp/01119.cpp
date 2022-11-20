class Solution {
public:
    string removeVowels(string s) {
        unordered_set<char> vowels({'a', 'e', 'o', 'i', 'u'});
        string result = "";
        
        for (int i = 0; i != s.size(); i++)
            if (vowels.find(s[i]) == vowels.end())
                result += s[i];
        
        return result;
    }
};

