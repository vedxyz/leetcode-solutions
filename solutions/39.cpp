class BacktrackSolution {
    void backtrackDFS(vector<vector<int>>& combs, vector<int>& comb, vector<int>& candidates, int target, int sum = 0, int last = 0) {
        if (sum > target)
            return;
        else if (sum == target) {
            combs.push_back(comb);
            return;
        }
        
        for (int i = last; i != candidates.size(); i++) {
            comb.push_back(candidates[i]);
            backtrackDFS(combs, comb, candidates, target, sum + candidates[i], i);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combs;
        vector<int> comb;
        backtrackDFS(combs, comb, candidates, target);
        return combs;
    }
};

class DynProgSolution {
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
