class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string result = "";
        
        map<int, int> todo;
        for (int i = 0; i != indices.size(); i++)
            todo[indices[i]] = i;
        map<int, int>::iterator idx = todo.begin();
        
        int i = 0;
        while (i != s.size()) {
            if (idx != todo.end() && i == idx->first) {
                int k = idx->second, j = 0;
                
                for (; j != sources[k].size(); j++)
                    if (s[i + j] != sources[k][j])
                        break;
                
                if (j == sources[k].size()) {
                    result += targets[k];
                    i += j;
                } else result += s[i++];
                idx++;
            } else result += s[i++];
        }
        
        return result;
    }
};

