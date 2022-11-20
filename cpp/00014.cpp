class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        
        for (int i = 0; i != strs[0].size(); i++) {
            
            for (int j = 1; j != strs.size(); j++)
                if (strs[j].size() == i || strs[j][i] != strs[0][i])
                    return result;
            
            result += strs[0][i];
        }
        
        return result;
    }
};

