class Solution {
public:
    // Bad solution. Need to do better.
    vector<string> generateParenthesis(int n) {
        typedef unordered_map<string, int> gen_map;
        vector<string> result;
        gen_map mp;
        mp["()"] = 1;
        
        for (int c = 0; c != 8; c++)
            for (gen_map::iterator i = mp.begin(); i != mp.end(); i++)
                for (gen_map::iterator j = mp.begin(); j != mp.end(); j++)
                    if (i->second + j->second <= n) {
                        mp[i->first + j->first] = i->second + j->second;
                        mp[j->first + i->first] = i->second + j->second;
                        mp["(" + i->first + ")"] = i->second + 1;
                    }
        
        for (gen_map::iterator i = mp.begin(); i != mp.end(); i++)
            if (i->second == n)
                result.push_back(i->first);
        
        return result;
    }
};
