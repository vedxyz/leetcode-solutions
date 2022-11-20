class Solution {
    void twoSum(vector<vector<int>>& triplets, vector<int>& nums, int i) {
        int left = i + 1, right = nums.size() - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                triplets.push_back({nums[i], nums[left], nums[right]});
                left++; right--;
                while (left < right && nums[left] == nums[left - 1])
                    left++;
            }
            else if (sum < 0) left++;
            else right--;
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        
        for (int i = 0; i != nums.size(); i++)
            if (i == 0 || nums[i] != nums[i - 1])
                twoSum(triplets, nums, i);
        
        return triplets;
    }
};
