class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> dup;
        vector<string> result;
        
        for (int i = 0; i != words.size(); i++) {
            for (int j = 0; j != words.size(); j++) {
                if (words[j].size() >= words[i].size()) continue;
                
                int len = 0, k = 0;
                while (k != words[i].size()) {
                    if (words[i][k] == words[j][len]) len++;
                    else if (len == words[j].size()) break;
                    else if (len != 0) { k -= len; len = 0; }
                    k++;
                }
                
                if (len == words[j].size() && dup.find(words[j]) == dup.end()) {
                    result.push_back(words[j]);
                    dup.insert(words[j]);
                }
            }
        }
        
        return result;
    }
};

