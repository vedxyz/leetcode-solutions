class Solution {
    void backtrack(vector<int>& nums, vector<vector<int>>& permutations, int first) {
        if (first == nums.size() - 1)
            permutations.push_back(nums);
        
        for (int i = first; i != nums.size(); i++) {
            swap(nums[first], nums[i]);
            backtrack(nums, permutations, first + 1);
            swap(nums[first], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        backtrack(nums, permutations, 0);
        return permutations;
    }
};

