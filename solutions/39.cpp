class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> combs(target + 1);
        combs[0].push_back({});
        
        for (int i = 1; i <= target; i++)
            for (int j = 0; j != candidates.size(); j++)
                if (i - candidates[j] >= 0) {
                    vector<vector<int>>& combsRow = combs[i - candidates[j]];
                    
                    for (int k = 0; k != combsRow.size(); k++) {
                        vector<int> comb = combsRow[k];
                        comb.push_back(candidates[j]);
                        sort(comb.begin(), comb.end());
                        if (find(combs[i].begin(), combs[i].end(), comb) == combs[i].end())
                            combs[i].push_back(comb);
                    }
                }
        
        return combs[target];
    }
};

